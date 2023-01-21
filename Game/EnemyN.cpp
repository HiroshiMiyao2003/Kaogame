#include "stdafx.h"
#include "EnemyN.h"
#include "Testshot.h"
#include "MakeUI.h"
#include"Oresiten.h"

#include "graphics/effect/EffectEmitter.h"


EnemyN::~EnemyN()
{
	DeleteGO(m_ecol);
}


bool EnemyN::Start()
{
	//アニメーション読み込み
	m_anima[Clip_taiki].Load("Assets/enemy/hakoniwaN/Ntaiki.tka");
	m_anima[Clip_taiki].SetLoopFlag(true);
	m_anima[Clip_tyouhatu].Load("Assets/enemy/hakoniwaN/Ntyouhatu.tka");
	m_anima[Clip_tyouhatu].SetLoopFlag(true);
	m_anima[Clip_totugeki].Load("Assets/enemy/hakoniwaN/Ntotugeki.tka");
	m_anima[Clip_totugeki].SetLoopFlag(true);

	//モデル読み込み
	m_ml.Init("Assets/enemy/hakoniwaN/hakoniwaN.tkm",m_anima,Clip_Num,enModelUpAxisZ);



	//待機場所へ誘導
	m_enowpos = { 0.0f,TAIKIY,0.0f };

	//モデル絵師に待機場所を連絡
	m_ml.SetPosition(m_enowpos);

	//当たり判定呼び出し
	m_ecol = NewGO<CollisionObject>(0);

	//判定サイズ指定
	
	m_size.x = COLXYZ;
	m_size.y = COLXYZ;
	m_size.z = COLXYZ;

	//判定に諸情報を教える
	m_ecol->CreateBox(m_enowpos, Quaternion::Identity, m_size);
	m_ecol->SetIsEnableAutoDelete(false);
	m_ecol->SetName("enet");

	//弾の情報を取得
	c_ts0 = FindGO<Testshot>("ts0");
	c_ts1 = FindGO<Testshot>("ts1");
	c_ts2 = FindGO<Testshot>("ts2");
	c_ts3 = FindGO<Testshot>("ts3");
	c_ts4 = FindGO<Testshot>("ts4");
	c_ts5 = FindGO<Testshot>("ts5");

	//己の情報を取得
	c_makeui = FindGO<MakeUI>("makeui");

	//己の視点を取得
	c_oresiten = FindGO<Oresiten>("oresiten");

	//エフェクト読み込み
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/baku/bakuD.efk");
	EffectEngine::GetInstance()->ResistEffect(1, u"Assets/effect/deru/deru0.efk");

	m_touE = NewGO <EffectEmitter>(1);
	m_touE->Init(1);

	return true;
}

void EnemyN::Update()
{
	if (m_deban == 1)
	{
		Han();
	}
	if (m_deban == 1)
	{
		Live();
		Haaku();
	}
	Anima();

}


void EnemyN::Han()
{

	if (m_ecol->IsHit(c_ts0->m_col)
		|| m_ecol->IsHit(c_ts1->m_col)
		|| m_ecol->IsHit(c_ts2->m_col)
		|| m_ecol->IsHit(c_ts3->m_col)
		|| m_ecol->IsHit(c_ts4->m_col)
		|| m_ecol->IsHit(c_ts5->m_col)
		)
	{

		m_touE->Stop();

		m_bakuE = NewGO <EffectEmitter>(0);
		m_bakuE->Init(0);

		m_bakuE->SetPosition(m_enowpos);
		m_bakuE->SetScale(m_size * BAKUKAKE);
		m_bakuE->SetRotation(m_qua);
		m_bakuE->Play();

		//弾に退場を告げる
		if (m_ecol->IsHit(c_ts0->m_col))
		{
			c_ts0->Bye();
		}
		else if(m_ecol->IsHit(c_ts1->m_col))
		{
			c_ts1->Bye();
		}
		else if (m_ecol->IsHit(c_ts2->m_col))
		{
			c_ts2->Bye();
		}
		else if (m_ecol->IsHit(c_ts3->m_col))
		{
			c_ts3->Bye();
		}
		else if (m_ecol->IsHit(c_ts4->m_col))
		{
			c_ts4->Bye();
		}
		else if (m_ecol->IsHit(c_ts5->m_col))
		{
			c_ts5->Bye();
		}

		

		m_enowpos = { 0.0f,TAIKIY,0.0f };

		//座標反映
		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
		//当たり判定反映
		m_ecol->SetPosition(m_enowpos);
		m_ecol->Update();

		//初見と出番のリセット
		m_deban = 0;
		m_shoken = 0;
		//得点の反映
		c_makeui->ScoreAdd(m_nowscore);

	}
}

void EnemyN::Live()
{
	switch (m_act)
	{
	case 0:
		ActGuru();
		break;
	case 1:
		ActTotu();
		break;
	case 2:
		ActHudou();
		break;
	case 3:
		ActTate_U();
		break;
	case 4:
		ActTate_D();
		break;
	case 5:
		ActGurun_R();
		break;
	case 6:
		ActGurun_L();
		break;
	default:
		ActGuru();
		break;
	}
	//登場エフェクトを与える
	if (m_shoken == 0)
	{
		

		m_touE = NewGO <EffectEmitter>(1);
		m_touE->Init(1);

		m_touE->SetPosition(m_enowpos);
		m_touE->SetScale(m_size * TOUKAKE);
		m_touE->SetRotation(m_qua);
		m_touE->Play();
		m_shoken = 1;

		//スコアを設定する
		m_nowscore = MAXSCORE;


	}


	if (m_shoken >= TOUESTOP)
	{
		m_touE->Stop();
		//DeleteGO(m_touE);
	}

	//角度を整える
	
		//右に行きすぎたら
	if (m_zrad > 180.0f)
	{
		//マイナスの値に変えている
		m_zrad = 360.0f - m_zrad;
		m_zrad *= -1.0f;
	}

	//左に行きすぎたら
	if (m_zrad < -180.0f)
	{
		//プラスの値に変えている
		m_zrad = 360.0f + m_zrad;
	}
	//登場してからカウントと得点カウントの変更

	m_nowscore--;
	m_shoken++;
}

void EnemyN::ActGuru()
{
	//負の数のフレームのみ実行される処理
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;

		m_ugoki = 1;
	}
	else if (m_kouc >= 60)
	{
		m_zrad = m_zrad - (SOKUDO * 10);
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
	}
	else
	{
		m_zrad = m_zrad + (SOKUDO * 10);
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
	}

	m_enowpos.y = m_koudo;

	//向きを調整する
	m_qua.SetRotationDegY(m_zrad + 180.0f);

	//座標反映
	m_ml.SetPosition(m_enowpos);

	//向き反映
	m_ml.SetRotation(m_qua);



	m_ml.Update();

	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	//カウント加算
	m_kouc++;
	if (m_kouc == KOUCFIN)
	{
		m_kouc = 0;
	}
}

void EnemyN::ActTotu()
{
	//事前準備
	if (m_totuc >= 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
		if (m_totuc == 0)
		{
			/*
			m_hureichi.x = m_enowpos.x/ WARI;
			m_hureichi.z = m_enowpos.z/ WARI;
			m_hureichi.y = m_enowpos.y - 100.0f;
			m_hureichi.y = m_hureichi.y / WARI;
			*/
			
			m_hureichi = m_enowpos;
			m_hureichi.y -= 100.0f;
			m_hureichi.Normalize();
			m_hureichi *= m_totusoku;


			m_ugoki = 2;
		}
	}
	//突撃実行
	else
	{
		m_etop = m_oreiru - m_enowpos;

		if (m_etop.Length() <= ZIBA)
		{
			m_enowpos = { 0.0f,TAIKIY,0.0f };

			//座標反映
			m_ml.SetPosition(m_enowpos);
			m_ml.Update();
			//当たり判定反映
			m_ecol->SetPosition(m_enowpos);
			m_ecol->Update();
			
			//色々リセットする
			m_ugoki = 0;
			m_shoken = 0;
			m_deban = 0;
			m_totusoku = M_TOTUC;
			//HPを減らす
			c_makeui->m_nowhp -= 1;

		}
		else
		{
			m_enowpos.x = m_enowpos.x - m_hureichi.x;
			m_enowpos.y = m_enowpos.y - m_hureichi.y;
			m_enowpos.z = m_enowpos.z - m_hureichi.z;
		}
	}
	//向きを調整する
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//座標反映
	m_ml.SetPosition(m_enowpos);
	//向き反映
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	m_totuc--;
}

void EnemyN::ActHudou()
{
	//負の数のフレームのみ実行される処理
	if (m_kouc != 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}

	//向きを調整する
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//座標反映
	m_ml.SetPosition(m_enowpos);
	//向き反映
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	if (m_kouc != 0)
	{
		m_kouc = 0;
	}
}

void EnemyN::ActTate_U()
{
	//負の数のフレームのみ実行される処理
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	else if(m_kouc < KOUCFIN /2)
	{
		m_enowpos.y += m_sokudo_y;
	}
	else
	{
		m_enowpos.y -= m_sokudo_y;
	}

	//向きを調整する
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//座標反映
	m_ml.SetPosition(m_enowpos);
	//向き反映
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	if (m_kouc >= KOUCFIN)
	{
		m_kouc = 0;
	}
	else
	{
		m_kouc++;
	}

}

void EnemyN::ActTate_D()
{
	//負の数のフレームのみ実行される処理
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	else if (m_kouc < KOUCFIN / 2)
	{
		m_enowpos.y -= m_sokudo_y;
	}
	else
	{
		m_enowpos.y += m_sokudo_y;
	}

	//向きを調整する
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//座標反映
	m_ml.SetPosition(m_enowpos);
	//向き反映
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	if (m_kouc >= KOUCFIN)
	{
		m_kouc = 0;
	}
	else
	{
		m_kouc++;
	}
}

void EnemyN::ActGurun_R()
{
	//負の数のフレームのみ実行される処理
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
//右回りに回転する処理
	else
	{
		m_zrad = m_zrad + m_sokudo_xz;
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
	}

	//向きを調整する
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//座標反映
	m_ml.SetPosition(m_enowpos);
	//向き反映
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	if (m_kouc != 0)
	{
		m_kouc = 0;
	}
}

void EnemyN::ActGurun_L()
{
	//負の数のフレームのみ実行される処理
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	//右回りに回転する処理
	else
	{
		m_zrad = m_zrad - m_sokudo_xz;
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
	}

	//向きを調整する
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//座標反映
	m_ml.SetPosition(m_enowpos);
	//向き反映
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	if (m_kouc != 0)
	{
		m_kouc = 0;
	}
}

void EnemyN::Haaku()
{
	/*
	//m_zrad = m_zrad % 360.0f;
	int dairi = m_zrad;
	//数を整えて-360~360までにおさめる
	dairi = dairi % 360;
	dairi = dairi - c_oresiten->Zrad;
	*/

	
	float dairi = m_zrad - c_oresiten->Zrad;

	

	//視界外かどうかのif
	if (dairi>SIYAKAKU||dairi<-SIYAKAKU)
	{
		//0.0f < dairi <= 180.0f or -180.0f > dairi > -360.0f(右に敵がいたとき)
		if (dairi <= 180.0f&&dairi > 0.0f || dairi < -180.0f&&dairi > -360.0f)
		{
			m_sikasoto = 1;
			c_makeui->m_keiR = 1;
		}
		//180.0f < dairi < 360.0f or 0.0f > dairi >= -180.0f (左に敵がいたとき)
		if (dairi > 180.0f && dairi < 360.0f || dairi >= -180.0f && dairi < 0.0f)
		{
			m_sikasoto = 2;
			c_makeui->m_keiL = 1;
		}
	}
	else
	{
		m_sikasoto = 0;
	}
}

void EnemyN::Anima()
{
	switch (m_ugoki)
	{
	case 0:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	case 1:
		m_ml.PlayAnimation(Clip_tyouhatu);
		break;
	case 2:
		m_ml.PlayAnimation(Clip_totugeki);
		break;
	default:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	}
}

void EnemyN::Render(RenderContext& rc)
{
	if (m_deban == 1)
	{
		m_ml.Draw(rc);
	} 

}


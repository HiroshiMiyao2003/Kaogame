#include "stdafx.h"
#include "EnemyT.h"
#include "Testshot.h"
#include "MakeUI.h"
#include"Oresiten.h"
#include"TestshotE.h"

#include "graphics/effect/EffectEmitter.h"


EnemyT::~EnemyT()
{
	DeleteGO(c_tse);
	DeleteGO(m_ecol);
}


bool EnemyT::Start()
{
	//アニメーション読み込み
	m_anima[Clip_taiki].Load("Assets/enemy/hakoniwaT/Ttaiki.tka");
	m_anima[Clip_taiki].SetLoopFlag(true);
	m_anima[Clip_tyouhatu].Load("Assets/enemy/hakoniwaT/Ttyouhatu.tka");
	m_anima[Clip_tyouhatu].SetLoopFlag(true);
	m_anima[Clip_hassya].Load("Assets/enemy/hakoniwaT/Thassya.tka");
	m_anima[Clip_hassya].SetLoopFlag(false);

	//モデル読み込み
	m_ml.Init("Assets/enemy/hakoniwaT/hakoniwaT.tkm", m_anima, Clip_Num, enModelUpAxisZ);

	

	//待機場所へ誘導
	m_enowpos = { 0.0f,TAIKIY,0.0f };

	//モデル絵師に待機場所を連絡
	m_ml.SetPosition(m_enowpos);

	//当たり判定呼び出し
	m_ecol = NewGO<CollisionObject>(0);

	//判定サイズ指定

	m_size.x = COLXZ;
	m_size.y = COLY;
	m_size.z = COLXZ;


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

	//敵の弾を生成
	c_tse = NewGO<TestshotE>(0,"testshote");

	//エフェクト読み込み
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/baku/bakuD.efk");
	EffectEngine::GetInstance()->ResistEffect(1, u"Assets/effect/deru/deru0.efk");




	return true;
}

void EnemyT::Update()
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


void EnemyT::Han()
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
		m_bakuE->SetScale({COLXZ * BAKUKAKE,COLXZ * BAKUKAKE,COLXZ * BAKUKAKE });
		m_bakuE->SetRotation(m_qua);
		m_bakuE->Play();

		//弾に退場を告げる
		if (m_ecol->IsHit(c_ts0->m_col))
		{
			c_ts0->Bye();
		}
		else if (m_ecol->IsHit(c_ts1->m_col))
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
		m_shoken = 0;
		m_deban = 0;

		c_tse->Bye();

		//得点の反映
		c_makeui->ScoreAdd(m_nowscore);

	}
}

void EnemyT::Live()
{
	switch (m_act)
	{
	case 0:
		ActGuru();
		break;
	case 1:
		ActHassya();
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
		//DeleteGO(m_bakuE);
		m_touE = NewGO <EffectEmitter>(1);
		m_touE->Init(1);

		m_touE->SetPosition(m_enowpos);
		m_touE->SetScale({ COLXZ * TOUKAKE,COLY * TOUKAKE,COLXZ * TOUKAKE });
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

	m_shoken++;
}

void EnemyT::ActGuru()
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

void EnemyT::ActHassya()
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

		if (m_totuc == HASSYAMADE)
		{
			c_tse->ToujoSiro(m_enowpos,m_totusoku);
		}
		else if (m_totuc == HASSYAEND)
		{
			m_ugoki = 1;
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

	if (m_totuc == m_totufin)
	{
		m_totuc = M_TOTUC;
	}
	else
	{
		m_totuc--;
	}
	if (m_nowscore > 0)
	{
		m_nowscore--;
	}

}

void EnemyT::ActHudou()
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

void EnemyT::ActTate_U()
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

void EnemyT::ActTate_D()
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

void EnemyT::ActGurun_R()
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

void EnemyT::ActGurun_L()
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

void EnemyT::Haaku()
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
	if (dairi > SIYAKAKU || dairi < -SIYAKAKU)
	{
		//0.0f < dairi <= 180.0f or -180.0f > dairi > -360.0f(右に敵がいたとき)
		if (dairi <= 180.0f && dairi > 0.0f || dairi < -180.0f && dairi > -360.0f)
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

void EnemyT::Anima()
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
		m_ml.PlayAnimation(Clip_hassya);
		break;
	default:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	}
}


//敵の退場を簡単に行えるクラス
void EnemyT::Taijou()
{
	m_enowpos = { 0.0f,TAIKIY,0.0f };

	//座標反映
	m_ml.SetPosition(m_enowpos);
	m_ml.Update();
	//当たり判定反映
	m_ecol->SetPosition(m_enowpos);
	m_ecol->Update();

	//初見と出番のリセット
	m_shoken = 0;
	m_deban = 0;

	c_tse->Bye();
}

void EnemyT::Render(RenderContext& rc)
{
	if (m_deban == 1)
	{
		m_ml.Draw(rc);
	}
	

}


#include "stdafx.h"
#include "Heart.h"

#include "Testshot.h"
#include"MakeUI.h"

#include "graphics/effect/EffectEmitter.h"
#include "sound/SoundSource.h"



Heart::~Heart()
{

}

bool Heart::Start()
{
	m_ml.Init("Assets/item/heart/heart2.tkm");
	//待機場所へ誘導
	m_hnowpos = { 0.0f,TAIKIY,0.0f };

	//モデル絵師に待機場所を連絡
	m_ml.SetPosition(m_hnowpos);

	//当たり判定呼び出し
	m_hcol = NewGO<CollisionObject>(0);

	//bgm
	g_soundEngine->ResistWaveFileBank(3, "Assets/music/kao_heart.wav");
	m_ensou = NewGO<SoundSource>(0);
	m_ensou->Init(3);

	//判定に諸情報を教える
	m_hcol->CreateBox(m_hnowpos, Quaternion::Identity, COLXYZ);
	m_hcol->SetIsEnableAutoDelete(false);
	m_hcol->SetName("heartdayo");

	//弾の情報を取得
	c_ts0 = FindGO<Testshot>("ts0");
	c_ts1 = FindGO<Testshot>("ts1");
	c_ts2 = FindGO<Testshot>("ts2");
	c_ts3 = FindGO<Testshot>("ts3");
	c_ts4 = FindGO<Testshot>("ts4");
	c_ts5 = FindGO<Testshot>("ts5");

	//己の情報を取得
	c_makeui = FindGO<MakeUI>("makeui");


	return true;
}

void Heart::Update()
{


	if (m_deban == 1)
	{
		Han();

	}

	if (m_deban == 1)
	{
		MoveH();
	}
}



void Heart::Han()
{

	if (m_hcol->IsHit(c_ts0->m_col)
		|| m_hcol->IsHit(c_ts1->m_col)
		|| m_hcol->IsHit(c_ts2->m_col)
		|| m_hcol->IsHit(c_ts3->m_col)
		|| m_hcol->IsHit(c_ts4->m_col)
		|| m_hcol->IsHit(c_ts5->m_col)
		)
	{
		m_ensou->Stop();

		//爆発エフェクト読み込み
		EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/baku/bakuD.efk");
		m_bakuE = NewGO <EffectEmitter>(0);
		m_bakuE->Init(0);

		m_bakuE->SetPosition(m_hnowpos);
		m_bakuE->SetScale(COLXYZ * BAKUKAKE);
		m_bakuE->SetRotation(m_qua);
		m_bakuE->Play();

		//弾に退場を告げる
		if (m_hcol->IsHit(c_ts0->m_col))
		{
			c_ts0->Bye();
		}
		else if (m_hcol->IsHit(c_ts1->m_col))
		{
			c_ts1->Bye();
		}
		else if (m_hcol->IsHit(c_ts2->m_col))
		{
			c_ts2->Bye();
		}
		else if (m_hcol->IsHit(c_ts3->m_col))
		{
			c_ts3->Bye();
		}
		else if (m_hcol->IsHit(c_ts4->m_col))
		{
			c_ts4->Bye();
		}
		else if (m_hcol->IsHit(c_ts5->m_col))
		{
			c_ts5->Bye();
		}

		m_hnowpos = { 0.0f,TAIKIY,0.0f };


		//HPを回復させる
		if (c_makeui->m_nowhp != 10)
		{
			c_makeui->m_nowhp += KAIHUKU;
		}
		
		
		//座標反映
		m_ml.SetPosition(m_hnowpos);
		m_ml.Update();
		//当たり判定反映
		m_hcol->SetPosition(m_hnowpos);
		m_hcol->Update();


		m_myaku = 0;

		m_deban = 0;
		
	}
}

void Heart::MoveH()
{


	//呼ばれたときのみ行う処理
	if (m_myaku == 0)
	{
		m_hnowpos.x = m_firstpos.x;
		m_hnowpos.y = m_firstpos.y;
		m_hnowpos.z = m_firstpos.z;

		//座標反映
		m_ml.SetPosition(m_hnowpos);
		m_ml.Update();
		//当たり判定反映
		m_hcol->SetPosition(m_hnowpos);
		m_hcol->Update();

		m_myaku++;
	}
	//退場させるかどうか判定
	else if (m_myaku == m_finalf)
	{
		
		if (jun == 1)
		{
			m_idouv *= -1;
			m_myaku = 1;
		
			//座標反映
			m_ml.SetPosition(m_hnowpos);
			m_ml.Update();
			//当たり判定反映
			m_hcol->SetPosition(m_hnowpos);
			m_hcol->Update();
		
		}
		else
		{
			m_hnowpos = { 0.0f,TAIKIY,0.0f };

			//座標反映
			m_ml.SetPosition(m_hnowpos);
			m_ml.Update();
			//当たり判定反映
			m_hcol->SetPosition(m_hnowpos);
			m_hcol->Update();

			m_myaku = 0;

			m_ensou->Stop();

			m_deban = 0;
		}
		
		
	}
	//移動の処理
	else
	{
		m_hnowpos.x += m_idouv.x;
		m_hnowpos.y += m_idouv.y;	
		m_hnowpos.z += m_idouv.z;

		//向きを調整する
		m_qua.AddRotationDegY(10.0f);

		//座標反映
		m_ml.SetPosition(m_hnowpos);
		m_ml.SetRotation(m_qua);
		m_ml.Update();
		//当たり判定反映
		m_hcol->SetPosition(m_hnowpos);
		m_hcol->Update();

		m_myaku++;
	}
	
}



void Heart::Render(RenderContext& rc)
{
	if (m_deban == 1)
	{
		m_ml.Draw(rc);
	}

}

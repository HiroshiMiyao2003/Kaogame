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
	//‘Ò‹@êŠ‚Ö—U“±
	m_hnowpos = { 0.0f,TAIKIY,0.0f };

	//ƒ‚ƒfƒ‹ŠGt‚É‘Ò‹@êŠ‚ğ˜A—
	m_ml.SetPosition(m_hnowpos);

	//“–‚½‚è”»’èŒÄ‚Ño‚µ
	m_hcol = NewGO<CollisionObject>(0);

	//bgm
	g_soundEngine->ResistWaveFileBank(3, "Assets/music/kao_heart.wav");
	m_ensou = NewGO<SoundSource>(0);
	m_ensou->Init(3);

	//”»’è‚É”î•ñ‚ğ‹³‚¦‚é
	m_hcol->CreateBox(m_hnowpos, Quaternion::Identity, COLXYZ);
	m_hcol->SetIsEnableAutoDelete(false);
	m_hcol->SetName("heartdayo");

	//’e‚Ìî•ñ‚ğæ“¾
	c_ts0 = FindGO<Testshot>("ts0");
	c_ts1 = FindGO<Testshot>("ts1");
	c_ts2 = FindGO<Testshot>("ts2");
	c_ts3 = FindGO<Testshot>("ts3");
	c_ts4 = FindGO<Testshot>("ts4");
	c_ts5 = FindGO<Testshot>("ts5");

	//ŒÈ‚Ìî•ñ‚ğæ“¾
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

		//”š”­ƒGƒtƒFƒNƒg“Ç‚İ‚İ
		EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/baku/bakuD.efk");
		m_bakuE = NewGO <EffectEmitter>(0);
		m_bakuE->Init(0);

		m_bakuE->SetPosition(m_hnowpos);
		m_bakuE->SetScale(COLXYZ * BAKUKAKE);
		m_bakuE->SetRotation(m_qua);
		m_bakuE->Play();

		//’e‚É‘Şê‚ğ‚°‚é
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


		//HP‚ğ‰ñ•œ‚³‚¹‚é
		if (c_makeui->m_nowhp != 10)
		{
			c_makeui->m_nowhp += KAIHUKU;
		}
		
		
		//À•W”½‰f
		m_ml.SetPosition(m_hnowpos);
		m_ml.Update();
		//“–‚½‚è”»’è”½‰f
		m_hcol->SetPosition(m_hnowpos);
		m_hcol->Update();


		m_myaku = 0;

		m_deban = 0;
		
	}
}

void Heart::MoveH()
{


	//ŒÄ‚Î‚ê‚½‚Æ‚«‚Ì‚İs‚¤ˆ—
	if (m_myaku == 0)
	{
		m_hnowpos.x = m_firstpos.x;
		m_hnowpos.y = m_firstpos.y;
		m_hnowpos.z = m_firstpos.z;

		//À•W”½‰f
		m_ml.SetPosition(m_hnowpos);
		m_ml.Update();
		//“–‚½‚è”»’è”½‰f
		m_hcol->SetPosition(m_hnowpos);
		m_hcol->Update();

		m_myaku++;
	}
	//‘Şê‚³‚¹‚é‚©‚Ç‚¤‚©”»’è
	else if (m_myaku == m_finalf)
	{
		
		if (jun == 1)
		{
			m_idouv *= -1;
			m_myaku = 1;
		
			//À•W”½‰f
			m_ml.SetPosition(m_hnowpos);
			m_ml.Update();
			//“–‚½‚è”»’è”½‰f
			m_hcol->SetPosition(m_hnowpos);
			m_hcol->Update();
		
		}
		else
		{
			m_hnowpos = { 0.0f,TAIKIY,0.0f };

			//À•W”½‰f
			m_ml.SetPosition(m_hnowpos);
			m_ml.Update();
			//“–‚½‚è”»’è”½‰f
			m_hcol->SetPosition(m_hnowpos);
			m_hcol->Update();

			m_myaku = 0;

			m_ensou->Stop();

			m_deban = 0;
		}
		
		
	}
	//ˆÚ“®‚Ìˆ—
	else
	{
		m_hnowpos.x += m_idouv.x;
		m_hnowpos.y += m_idouv.y;	
		m_hnowpos.z += m_idouv.z;

		//Œü‚«‚ğ’²®‚·‚é
		m_qua.AddRotationDegY(10.0f);

		//À•W”½‰f
		m_ml.SetPosition(m_hnowpos);
		m_ml.SetRotation(m_qua);
		m_ml.Update();
		//“–‚½‚è”»’è”½‰f
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

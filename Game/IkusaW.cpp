#include "stdafx.h"
#include "IkusaW.h"

#include "TheSky.h"
#include "Daichi.h"
#include "Oresiten.h"
#include "MakeUI.h"

#include "EnemyT.h"
#include "EnemyN.h"
#include "Heart.h"
#include "Boss.h"

#include "NowLo.h"
#include "OverGame.h"
#include "Title.h"
#include "Kekka.h"

IkusaW::~IkusaW()
{

}

bool IkusaW::Start()
{
	//空のオブジェクトを作成する。
	m_skyCube = NewGO<SkyCube>(0, "skycube");
	//背景の種類を指定する
	m_skyCube->SetType(enSkyCubeType_Night);
	m_skyCube->SetLuminance(1.0f);
	//背景を表示できるようにする
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 0.1f);
	g_renderingEngine->SetCascadeNearAreaRates(0.01f, 0.1f, 0.5f);


	//重要なクラスを生成する
	c_daichi = NewGO<Daichi>(0, "daichi");
	c_oresiten = NewGO<Oresiten>(0, "oresiten");
	c_makeui = NewGO<MakeUI>(0, "makeui");

	c_oresiten->Lock();
	c_makeui->m_lock = 1;



	//敵を生成する
	c_enen0 = NewGO<EnemyN>(0, "enen");
	c_enen1 = NewGO<EnemyN>(1, "enen");
	c_enen2 = NewGO<EnemyN>(2, "enen");
	c_enen3 = NewGO<EnemyN>(3, "enen");
	c_enen4 = NewGO<EnemyN>(4, "enen");
	c_enet0 = NewGO<EnemyT>(0, "enen");

	c_boss = NewGO<Boss>(0, "boss");

	//ハートを生成する
	c_heart0 = NewGO<Heart>(0, "heart");



	//bgmを読み込む
	g_soundEngine->ResistWaveFileBank(11, "Assets/music/kao_stage01_1r.wav");
	g_soundEngine->ResistWaveFileBank(12, "Assets/music/kao_stage01_2r.wav");

	m_bgm01 = NewGO<SoundSource>(0);
	m_bgm01->Init(11);
	m_bgm02 = NewGO<SoundSource>(0);
	m_bgm02->Init(12);

	m_bgm02->Deactivate();

	m_bgm01->Play(true);
	m_bgm01->SetVolume(2.0f);

	//トーンマップを消去している
	g_renderingEngine->DisableTonemap();



	//ナウローディング画面を消す
	c_nl = FindGO<NowLo>("nowlo");
	DeleteGO(c_nl);

	return true;
}

void IkusaW::Update()
{
	Kaku();
	if (m_zikei == 0)
	{
		ZikeiZero();
	}
	if (m_zikei == 1)
	{
		Zikei_1();
	}
	if (m_zikei == 2)
	{
		Zikei_2();
	}
	if (m_zikei == 3)
	{
		Zikei_3();
	}
	if (m_zikei == 4)
	{
		Zikei_4();
	}
	if (m_zikei == 5)
	{
		Zikei_5();
	}
	if (m_zikei == 6)
	{
		Zikei_6();
	}

	m_zc++;
}

void IkusaW::Kaku()
{
	if (c_makeui->m_nowhp <= 0)
	{
		c_kekka = NewGO<Kekka>(0, "kekka");
		DeleteGO(this);
	}
}

void IkusaW::ZikeiZero()
{
	if (m_zc >= 120)
	{
		//m_ninmu.SetPosition({ 2000.0f,0.0f,0.0f });
		//m_ninmu.Update();

		c_oresiten->UnLock();
		c_makeui->m_lock = 0;

		UpZikei();
	}
}

void IkusaW::Zikei_1()
{
	if (m_zc == 30)
	{
		c_enen0->Toujou(ENEACT_1_1, ENERAD_1_1, ENEKYORI_1_1, ENEKOUDO_1_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == 30&&m_wave >= 2)
	{
		c_enen1->Toujou(ENEACT_1_1, ENERAD_1_2, ENEKYORI_1_1, ENEKOUDO_1_1, ENESOKUX, ENESOKUY);
		c_enen1->Totusiro(1.0f, 60.0f);
	}
	if (m_zc == 30 && m_wave > 2)
	{
		c_enen2->Toujou(ENEACT_1_1, ENERAD_1_3, ENEKYORI_1_1, ENEKOUDO_1_1, ENESOKUX, ENESOKUY);
		c_enen2->Totusiro(1.0f, 60.0f);
	}
	if (c_enen0->m_deban == 0 && m_zc > 30 && m_wave == 1)
	{
		UpZikei();
	}
}

void IkusaW::Zikei_2()
{
	if (m_zc == 30)
	{
		c_enen1->Toujou(ENEACT_2_1, ENERAD_2_1, ENEKYORI_2_1, ENEKOUDO_2_1, ENESOKUX, ENESOKUY);
		c_enen2->Toujou(ENEACT_2_2, ENERAD_2_2, ENEKYORI_2_2, ENEKOUDO_2_2, ENESOKUX, ENESOKUY);
		c_enen3->Toujou(ENEACT_2_3, ENERAD_2_3, ENEKYORI_2_3, ENEKOUDO_2_3, ENESOKUX, ENESOKUY);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen3->m_deban == 0 && m_zc > 30)
	{
		UpZikei();
	}
}

void IkusaW::Zikei_3()
{

		if (m_zc == ENETOU_3_1)
		{
			c_enen0->Toujou(ENEACT_3_1, ENERAD_3_1, ENEKYORI_3_1, ENEKOUDO_3_1, ENESOKUX, ENESOKUY);
		}
		if (m_zc == ENETOU_3_2)
		{
			c_enen1->Toujou(ENEACT_3_1, ENERAD_3_1, ENEKYORI_3_1, ENEKOUDO_3_1, ENESOKUX, ENESOKUY);
		}
		if (c_enen1->m_deban == 0 && c_enen0->m_deban == 0 && m_zc > ENETOU_3_3)
		{
			UpZikei();
		}
	
}

void IkusaW::Zikei_4()
{
	if (m_zc == ENETOU_4_1)
	{
		c_enen1->Toujou(ENEACT_4_1, ENERAD_4_1, ENEKYORI_4_1, ENEKOUDO_4_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_4_2)
	{
		c_enen2->Toujou(ENEACT_4_1, ENERAD_4_1, ENEKYORI_4_1, ENEKOUDO_4_1, ENESOKUX, ENESOKUY);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && m_zc > ENETOU_4_3)
	{
		UpZikei();
	}
}

void IkusaW::Zikei_5()
{
	if (m_zc == ENETOU_5_1)
	{
		c_enen1->Toujou(ENEACT_5_1, ENERAD_5_1, ENEKYORI_5_1, ENEKOUDO_5_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_5_1)
	{
		c_enen2->Toujou(ENEACT_5_2, ENERAD_5_2, ENEKYORI_5_2, ENEKOUDO_5_2, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_5_1)
	{
		c_enen3->Toujou(ENEACT_5_3, ENERAD_5_3, ENEKYORI_5_3, ENEKOUDO_5_3, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_5_1)
	{
		//c_enen2->Totusiro(ENETOTUSOKU_5_2, ENEYUU_5_2);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen3->m_deban == 0 && m_zc > ENETOU_5_1)
	{
		UpZikei();
	}
}

void IkusaW::Zikei_6()
{
	if (m_zc == ENETOU_6_1)
	{
		c_enen1->Toujou(ENEACT_6_1, ENERAD_6_1, ENEKYORI_6_1, ENEKOUDO_6_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_6_1)
	{
		c_enen2->Toujou(ENEACT_6_2, ENERAD_6_2, ENEKYORI_6_2, ENEKOUDO_6_2, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_6_1)
	{
		c_enen3->Toujou(ENEACT_6_3, ENERAD_6_3, ENEKYORI_6_3, ENEKOUDO_6_3, ENESOKUX, ENESOKUY);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen3->m_deban == 0 && m_zc > ENETOU_6_1)
	{

		UpZikei();
	}
}

void IkusaW::UpZikei()
{
	m_zikei++;

	m_zc = -1;
}

void IkusaW::Render(RenderContext& rc)
{

}

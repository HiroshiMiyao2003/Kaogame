#include "stdafx.h"
#include "Ikusa01.h"

#include "Daichi.h"
#include "Oresiten.h"
#include "MakeUI.h"

#include "EnemyT.h"
#include "EnemyN.h"
#include "Heart.h"
#include "Boss.h"

#include "NowLo.h"
#include "OverGame.h"

#include "Kekka.h"


#include "sound/SoundSource.h"


Ikusa01::~Ikusa01()
{
	

	DeleteGO(m_skyCube);
	DeleteGO(c_daichi);
	DeleteGO(c_oresiten);
	DeleteGO(c_makeui);

	DeleteGO(m_bgm01);
	DeleteGO(m_bgm02);
	DeleteGO(m_bgmB);


	DeleteGO(c_enen0);
	DeleteGO(c_enen1);
	DeleteGO(c_enen2);
	DeleteGO(c_enen3);
	DeleteGO(c_enen4);

	DeleteGO(c_enet0);


	DeleteGO(c_heart0);

	DeleteGO(c_boss);

}

bool Ikusa01::Start()
{
	
	//空のオブジェクトを作成する。
	m_skyCube = NewGO<SkyCube>(0, "skycube");
	//背景の種類を指定する


	m_skyCube->SetType(enSkyCubeType_NightToon);
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

	//任務を読み込む
	m_ninmu.Init("Assets/ui/stage01dayo.dds", 1920.0f, 1080.0f);
	m_ninmu2.Init("Assets/ui/clear.dds", 1920.0f, 1080.0f);

	//bgmを読み込む
	g_soundEngine->ResistWaveFileBank(11, "Assets/music/kao_stage01_1r.wav");
	g_soundEngine->ResistWaveFileBank(12, "Assets/music/kao_stage01_2r.wav");
	g_soundEngine->ResistWaveFileBank(13, "Assets/music/kao_boss1.wav");

	m_bgm01 = NewGO<SoundSource>(0);
	m_bgm01->Init(11);
	m_bgm02 = NewGO<SoundSource>(0);
	m_bgm02->Init(12);
	m_bgmB = NewGO<SoundSource>(0);
	m_bgmB->Init(13);

	m_bgm02->Deactivate();
	m_bgmB->Deactivate();

	m_bgm01->Play(true);
	m_bgm01->SetVolume(2.0f);

	//トーンマップを消去している
	g_renderingEngine->DisableTonemap();
	

	m_ninmu2.SetPosition({ 2000.0f,0.0f,0.0f });

	//ナウローディング画面を消す
	c_nl = FindGO<NowLo>("nowlo");
	DeleteGO(c_nl);

	return true;
}

void Ikusa01::Update()
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
	if (m_zikei == 7)
	{
		Zikei_7();
	}
	if (m_zikei == 8)
	{
		Zikei_8();
	}
	if (m_zikei == 9)
	{
		Zikei_9();
	}
	if (m_zikei == 10)
	{
		Zikei_10();
	}
	if (m_zikei == 11)
	{
		Zikei_11();
	}
	if (m_zikei == 12)
	{
		Zikei_Fin();
	}
	m_zc++;
}


void Ikusa01::Kaku()
{
	if (c_makeui->m_nowhp <= 0)
	{
		c_og = NewGO<OverGame>(0, "overgame");
		DeleteGO(this);
	}
}

void Ikusa01::ZikeiZero()
{
	if (m_zc >= 120)
	{
		m_ninmu.SetPosition({2000.0f,0.0f,0.0f});
		m_ninmu.Update();

		c_oresiten->UnLock();
		c_makeui->m_lock = 0;

		UpZikei();
	}
}

void Ikusa01::Zikei_1()
{
	if (m_zc == 30)
	{
		c_enen0->Toujou(ENEACT_1_1,ENERAD_1_1,ENEKYORI_1_1,ENEKOUDO_1_1,ENESOKUX,ENESOKUY);
	}
	if (c_enen0->m_deban == 0 && m_zc > 30)
	{
		UpZikei();
	}
}

void Ikusa01::Zikei_2()
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

void Ikusa01::Zikei_3()
{
	if (m_zc == ENETOU_3_1)
	{
		c_enen0->Toujou(ENEACT_3_1, ENERAD_3_1, ENEKYORI_3_1, ENEKOUDO_3_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_3_2)
	{
		c_enen1->Toujou(ENEACT_3_1, ENERAD_3_1, ENEKYORI_3_1, ENEKOUDO_3_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_3_3)
	{
		c_enen2->Toujou(ENEACT_3_1, ENERAD_3_1, ENEKYORI_3_1, ENEKOUDO_3_1, ENESOKUX, ENESOKUY);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen0->m_deban == 0 && m_zc > ENETOU_3_3)
	{
		UpZikei();
	}
}

void Ikusa01::Zikei_4()
{
	if (m_zc == ENETOU_4_1)
	{
		c_enen1->Toujou(ENEACT_4_1, ENERAD_4_1, ENEKYORI_4_1, ENEKOUDO_4_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_4_2)
	{
		c_enen2->Toujou(ENEACT_4_1, ENERAD_4_1, ENEKYORI_4_1, ENEKOUDO_4_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_4_3)
	{
		c_enen3->Toujou(ENEACT_4_1, ENERAD_4_1, ENEKYORI_4_1, ENEKOUDO_4_1, ENESOKUX, ENESOKUY);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen3->m_deban == 0 && m_zc > ENETOU_4_3)
	{
		UpZikei();
	}
}

void Ikusa01::Zikei_5()
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
		c_enen2->Totusiro(ENETOTUSOKU_5_2,ENEYUU_5_2);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen3->m_deban == 0 && m_zc > ENETOU_5_1)
	{
		UpZikei();
	}
}

void Ikusa01::Zikei_6()
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
	if (m_zc == ENETOU_6_1)
	{
		c_enen2->Totusiro(ENETOTUSOKU_6_3, ENEYUU_6_3);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen3->m_deban == 0 && m_zc > ENETOU_6_1)
	{

		UpZikei();
	}
}

void Ikusa01::Zikei_7()
{
	if (m_zc == ENETOU_7_1)
	{
		c_enen4->Toujou(ENEACT_7_1, ENERAD_7_1, ENEKYORI_7_1, ENEKOUDO_7_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_7_1)
	{
		c_enen3->Toujou(ENEACT_7_2, ENERAD_7_2, ENEKYORI_7_2, ENEKOUDO_7_2, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_7_1)
	{
		m_bgm01->Stop();
		m_bgm01->Deactivate();
	
		m_bgm02->Activate();
		m_bgm02->Play(true);
		m_bgm02->SetVolume(2.0f);
	}
	if (m_zc == ENETOU_7_1)
	{
		c_heart0->Toujou(HEAFIRST_7,HEAIDOU_7,HEAEND_7);
	}

	if (c_enen3->m_deban == 0 && c_enen4->m_deban == 0 && m_zc > ENETOU_7_1)
	{
		UpZikei();
	}
}

void Ikusa01::Zikei_8()
{
	if (m_zc == ENETOU_8_1)
	{
		c_enet0->Toujou(ENEACT_8_1, ENERAD_8_1, ENEKYORI_8_1, ENEKOUDO_8_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_8_23)
	{
		c_enen2->Toujou(ENEACT_8_2, ENERAD_8_2, ENEKYORI_8_2, ENEKOUDO_8_2, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_8_23)
	{
		c_enen3->Toujou(ENEACT_8_3, ENERAD_8_3, ENEKYORI_8_3, ENEKOUDO_8_3, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_8_1)
	{
		c_enet0->Totusiro(ENETOTUSOKU_8_1, ENEBEF_8_1,ENEAFT_8_1);
	}
	if (c_enet0->m_deban == 0 && c_enen2->m_deban == 0 && c_enen3->m_deban == 0 && m_zc > ENETOU_8_1)
	{

		UpZikei();
	}
}

void Ikusa01::Zikei_9()
{
	if (m_zc == ENETOU_9_1)
	{
		c_enen0->Toujou(ENEACT_9_123, ENERAD_9_1234, ENEKYORI_9_1234, ENEKOUDO_9_1234, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_9_2)
	{
		c_enen1->Toujou(ENEACT_9_123, ENERAD_9_1234, ENEKYORI_9_1234, ENEKOUDO_9_1234, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_9_3)
	{
		c_enen2->Toujou(ENEACT_9_123, ENERAD_9_1234, ENEKYORI_9_1234, ENEKOUDO_9_1234, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_9_4)
	{
		c_enet0->Toujou(ENEACT_9_4, ENERAD_9_1234, ENEKYORI_9_1234, ENEKOUDO_9_1234, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_9_4)
	{
		c_enet0->Totusiro(ENETOTUSOKU_9_4, ENEBEF_9_4, ENEAFT_9_4);
	}
	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 && c_enen0->m_deban == 0&&c_enet0->m_deban == 0 && m_zc > ENETOU_9_4)
	{
		UpZikei();
	}
}

void Ikusa01::Zikei_10()
{
	if (m_zc == ENETOU_10_1)
	{
		c_enen0->Toujou(ENEACT_10_1, ENERAD_10_1, ENEKYORI_10_1, ENEKOUDO_10_1, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_10_1)
	{
		c_enen1->Toujou(ENEACT_10_2, ENERAD_10_2, ENEKYORI_10_2, ENEKOUDO_10_2, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_10_3)
	{
		c_enen2->Toujou(ENEACT_10_3, ENERAD_10_3, ENEKYORI_10_3, ENEKOUDO_10_3, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_10_3)
	{
		c_enen3->Toujou(ENEACT_10_4, ENERAD_10_4, ENEKYORI_10_4, ENEKOUDO_10_4, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_10_5)
	{
		c_enen4->Toujou(ENEACT_10_5, ENERAD_10_5, ENEKYORI_10_5, ENEKOUDO_10_5, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_10_5)
	{
		c_enet0->Toujou(ENEACT_10_6, ENERAD_10_6, ENEKYORI_10_6, ENEKOUDO_10_6, ENESOKUX, ENESOKUY);
	}
	if (m_zc == ENETOU_10_5)
	{
		c_enen4->Totusiro(ENETOTUSOKU_10_6,ENEBEF_10_6);
		c_enet0->Totusiro(ENETOTUSOKU_10_6, ENEBEF_10_6, ENEAFT_10_6);
	}

	if (c_enen1->m_deban == 0 && c_enen2->m_deban == 0 &&
		c_enen0->m_deban == 0 && c_enen3->m_deban == 0 && 
		c_enen4->m_deban == 0 && c_enet0->m_deban == 0 && m_zc > ENETOU_10_5)
	{
		UpZikei();
	}

}

void Ikusa01::Zikei_11()
{
	if (m_zc == 60)
	{
		c_oresiten->Zrad = 0.0f;
		c_boss->ToujouKani(0.0f,150.0f,100.0f);
		m_bgm02->Stop();
		m_bgm02->Deactivate();

		m_bgmB->Activate();
		m_bgmB->Play(true);
		m_bgmB->SetVolume(2.0f);
	}
	if (c_boss->m_deban == 0&& m_zc > 60)
	{
		UpZikei();
	}
}

void Ikusa01::Zikei_Fin()
{
	if (m_zc == 1)
	{
		c_oresiten->Lock();
		c_makeui->Lock();
		m_ninmu2.SetPosition({0.0f,0.0f,0.0f });
	}
	if (m_zc == 120)
	{
		//c_title = NewGO<Title>(0,"title");
		c_kekka = NewGO<Kekka>(0, "kekka");
		DeleteGO(this);
	}
}

void Ikusa01::UpZikei()
{
	m_zikei++;

	m_zc = -1;
};

void Ikusa01::Render(RenderContext& rc)
{
	if (m_zikei == 0)
	{
		m_ninmu.Draw(rc);
	}
	if (m_zikei == 12)
	{
		m_ninmu2.Draw(rc);
	}
}

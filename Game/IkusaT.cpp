#include "stdafx.h"
#include "IkusaT.h"
#include "Daichi.h"

#include "Oresiten.h"
#include"MakeUI.h"
#include"NowLo.h"

#include "EnemyN.h"
#include "Heart.h"

#include"Title.h"
#include"Ikusa01.h";

IkusaT::~IkusaT()
{
	DeleteGO(m_skyCube);
	//DeleteGO(c_thesky);
	DeleteGO(c_daichi);
	DeleteGO(c_oresiten);
	DeleteGO(c_makeui);





	DeleteGO(c_enen0);
	DeleteGO(c_enen1);





	DeleteGO(c_heart0);
}

bool IkusaT::Start()
{
	//空のオブジェクトを作成する。
	m_skyCube = NewGO<SkyCube>(0, "skycube");
	//背景の種類を指定する
	m_skyCube->SetType(enSkyCubeType_DayToon_4);
	m_skyCube->SetLuminance(1.0f);
	//背景を表示できるようにする
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 0.1f);
	g_renderingEngine->SetCascadeNearAreaRates(0.01f, 0.1f, 0.5f);


	//重要なクラスを生成する
	//c_thesky = NewGO<TheSky>(0,"thesky");
	c_daichi = NewGO<Daichi>(0, "daichi");
	c_oresiten = NewGO<Oresiten>(0, "oresiten");
	c_makeui = NewGO<MakeUI>(0, "makeui");

	c_oresiten->Lock();
	c_makeui->m_lock = 1;



	//敵を生成する
	c_enen0 = NewGO<EnemyN>(0, "enen");
	c_enen1 = NewGO<EnemyN>(1, "enen");


	//ハートを生成する
	c_heart0 = NewGO<Heart>(0, "heart");

	//任務を読み込む
	m_gairo1.Init("Assets/ui/gaido1.dds", 1920.0f, 1080.0f);
	m_gairo2.Init("Assets/ui/gaido2.dds", 1920.0f, 1080.0f);
	m_gairo3.Init("Assets/ui/gaido3.dds", 1920.0f, 1080.0f);
	m_gairo4.Init("Assets/ui/gaido4.dds", 1920.0f, 1080.0f);
	m_gairo5.Init("Assets/ui/gaido5.dds", 1920.0f, 1080.0f);
	m_gairo6.Init("Assets/ui/gaido6.dds", 1920.0f, 1080.0f);
	m_gairo7.Init("Assets/ui/gaido7.dds", 1920.0f, 1080.0f);
	m_gairo8.Init("Assets/ui/gaido8.dds", 1920.0f, 1080.0f);
	m_gairo9.Init("Assets/ui/gaido9.dds", 1920.0f, 1080.0f);
	m_gairo0.Init("Assets/ui/gaido0.dds", 1920.0f, 1080.0f);

	m_gairo1.SetPosition(TAIKIV);
	m_gairo1.Update();
	m_gairo2.SetPosition(TAIKIV);
	m_gairo2.Update();
	m_gairo3.SetPosition(TAIKIV);
	m_gairo3.Update();
	m_gairo4.SetPosition(TAIKIV);
	m_gairo4.Update();
	m_gairo5.SetPosition(TAIKIV);
	m_gairo5.Update();
	m_gairo9.SetPosition(TAIKIV);
	m_gairo9.Update();
	m_gairo0.SetPosition(TAIKIV);
	m_gairo0.Update();


	g_renderingEngine->DisableTonemap();
	


	c_makeui->Lock();
	//ナウローディング画面を消す
	c_nl = FindGO<NowLo>("nowlo");
	DeleteGO(c_nl);

	return true;

}

void IkusaT::Update()
{
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
	if (m_zikei == 4.5)
	{
		Zikei_4_5();
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
	if (m_zikei == 12&&m_yn == 1)
	{
		Zikei_Yes();
	}
	if (m_zikei == 12&& m_yn == 0)
	{
		Zikei_No();
	}
	m_zc++;
}

void IkusaT::Kaku()
{

}

void IkusaT::ZikeiZero()
{
	if (m_zc <= 10)
	{
		m_gairo1.SetPosition(DEBANV);
		m_gairo1.Update();
	}
	if (m_zc > 10 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo1.SetPosition(TAIKIV);
		UpZikei();
	}
}

void IkusaT::Zikei_1()
{
	if (m_zc <= 15)
	{
		m_gairo2.SetPosition(DEBANV);
		m_gairo2.Update();
	}
	if (m_zc > 15 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo2.SetPosition(TAIKIV);

		UpZikei();
	}

}

void IkusaT::Zikei_2()
{
	if (m_zc == 30)
	{
		c_enen0->Toujou(ENEACT_2_1, ENERAD_2_1, ENEKYORI_2_1, ENEKOUDO_2_1, ENESOKUX, ENESOKUY);

	}
	if (m_zc == 35)
	{
		c_makeui->UnLock();
	}
	if (c_enen0->m_deban == 0 && m_zc > 30)
	{
		UpZikei();
	}
}

void IkusaT::Zikei_3()
{
	if (m_zc == 30)
	{
		c_enen0->Toujou(ENEACT_4_1, ENERAD_4_1, ENEKYORI_4_1, ENEKOUDO_4_1, ENESOKUX, ENESOKUY);

	}
	if (m_zc == 60)
	{
		c_makeui->Lock();
		m_gairo9.SetPosition(DEBANV);
		m_gairo9.Update();
	}
	if (m_zc >= 70 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo9.SetPosition(TAIKIV);

		UpZikei();

	}
}

void IkusaT::Zikei_4()
{
	if (m_zc <= 15)
	{
		c_makeui->Lock();
		m_gairo3.SetPosition(DEBANV);
		m_gairo3.Update();
	}
	if (m_zc > 15 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo3.SetPosition(TAIKIV);
		m_gairo3.Update();
		c_oresiten->UnLock();

		UpZikei();
	}


	
}

void IkusaT::Zikei_4_5()
{
	if (m_zc == 3)
	{
		c_makeui->UnLock();
	}
	if (c_enen0->m_deban == 0 && m_zc > 3)
	{
		c_makeui->Lock();
		c_oresiten->Lock();
		UpZikei();
	}
}

void IkusaT::Zikei_5()
{
	if (m_zc == 65)
	{
		m_gairo0.SetPosition(DEBANV);
		m_gairo0.Update();
	}
	if (m_zc >= 85 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo0.SetPosition(TAIKIV);

		UpZikei();
	}
}

void IkusaT::Zikei_6()
{
	if (m_zc == 15)
	{
		m_gairo4.SetPosition(DEBANV);
		m_gairo4.Update();
	}
	if (m_zc > 15 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo4.SetPosition(TAIKIV);

		UpZikei();
	}
}

void IkusaT::Zikei_7()
{
	if (m_zc == 15)
	{
		m_gairo5.SetPosition(DEBANV);
		m_gairo5.Update();
	}
	if (m_zc > 15 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo5.SetPosition(TAIKIV);
		c_oresiten->UnLock();
		UpZikei();
	}
}

void IkusaT::Zikei_8()
{
	if (m_zc == 5)
	{
		c_makeui->UnLock();
	}

	if (m_zc == 30)
	{
		c_heart0->jun = 1;
		c_heart0->Toujou(HEAFIRST_8, HEAIDOU_8, HEAEND_8);
	}

	if (c_heart0->m_deban == 0 && m_zc > 30)
	{
		c_makeui->Lock();
		c_oresiten->Lock();
		UpZikei();
	}
}

void IkusaT::Zikei_9()
{
	if (m_zc == 15)
	{
		m_gairo6.SetPosition(DEBANV);
		m_gairo6.Update();
	}
	if (m_zc > 25 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo6.SetPosition(TAIKIV);

		UpZikei();
	}
}

void IkusaT::Zikei_10()
{
	if (m_zc == 15)
	{
		m_gairo7.SetPosition(DEBANV);
		m_gairo7.Update();
	}
	if (m_zc > 25 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_gairo7.SetPosition(TAIKIV);

		UpZikei();
	}
}

void IkusaT::Zikei_11()
{
	if (m_zc == 15)
	{
		m_gairo6.SetPosition(DEBANV);
		m_gairo6.Update();
	}
	//はいの処理
	if (m_zc > 25 && g_pad[0]->IsTrigger(enButtonA))
	{
		m_yn = 1;
		UpZikei();

	}
//いいえの処理
	else if (m_zc > 25 && g_pad[0]->IsTrigger(enButtonB))
	{
		m_yn = 0;
		UpZikei();
	}
}

void IkusaT::Zikei_Yes()
{
	if (m_zc == 1)
	{
		c_nl = NewGO < NowLo > (0,"nowlo");
	}
	if (m_zc == 11)
	{

		c_ikusa01 = NewGO<Ikusa01>(0,"ikusa01");
		DeleteGO(this);
	}
}

void IkusaT::Zikei_No()
{
	if (m_zc == 11)
	{

		c_title = NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}



void IkusaT::UpZikei()
{
	if (m_zikei == 4 || m_zikei == 4.5)
	{
		m_zikei += 0.5;
	}
	else
	{
		m_zikei++;
	}


	m_zc = -1;
}

void IkusaT::Render(RenderContext& rc)
{
	if (m_zikei == 0)
	{
		m_gairo1.Draw(rc);
	}
	if (m_zikei == 1)
	{
		m_gairo2.Draw(rc);
	}

	if (m_zikei == 3)
	{
		m_gairo9.Draw(rc);
	}
	if (m_zikei == 4)
	{
		m_gairo3.Draw(rc);
	}
	if (m_zikei == 5)
	{
		m_gairo0.Draw(rc);
	}
	if (m_zikei == 6)
	{
		m_gairo4.Draw(rc);
	}
	if (m_zikei == 7)
	{
		m_gairo5.Draw(rc);
	}
	if (m_zikei == 9)
	{
		m_gairo6.Draw(rc);
	}
	if (m_zikei == 10)
	{
		m_gairo7.Draw(rc);
	}
	if (m_zikei == 11)
	{
		m_gairo8.Draw(rc);
	}
	
}

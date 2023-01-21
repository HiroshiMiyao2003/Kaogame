#include "stdafx.h"
#include "Ikusa00.h"

#include "Daichi.h"
#include "Oresiten.h"
#include "MakeUI.h"

#include "EnemyT.h"
#include "EnemyN.h"
#include "Heart.h"
#include "Boss.h"

#include "NowLo.h"
#include "OverGame.h"


Ikusa00::~Ikusa00()
{


	DeleteGO(m_skyCube);
	DeleteGO(c_daichi);
	DeleteGO(c_oresiten);
	DeleteGO(c_makeui);


	DeleteGO(c_enen0);
	DeleteGO(c_enen1);	
	DeleteGO(c_enen2);	
	DeleteGO(c_enen3);	
	DeleteGO(c_enen4);

	DeleteGO(c_enet0);

	DeleteGO(c_boss);

	DeleteGO(c_heart0);

}

bool Ikusa00::Start()
{
	//空のオブジェクトを作成する。
	m_skyCube = NewGO<SkyCube>(0, "skycube");
	//背景の種類を指定する
	m_skyCube->SetType(enSkyCubeType_SunriseToon);
	//背景を表示できるようにする
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 2.0f);

	c_daichi = NewGO<Daichi>(0, "daichi");
	c_oresiten = NewGO<Oresiten>(0, "oresiten");
	c_makeui = NewGO<MakeUI>(0, "makeui");
	
	//c_enet0 = NewGO<EnemyT>(0,"enen");
	//c_enet0->Toujou(2,0.0f,160.0f,100.0f,1.0f,1.0f);
	//c_enet0->Totusiro(0.8f,120,120);

	c_boss = NewGO<Boss>(0, "boss");
	c_boss->ToujouKani(0.0f,150.0f,100.0f);

	//ナウローディング画面を消す
	c_nl = FindGO<NowLo>("nowlo");
	DeleteGO(c_nl);

	return true;
}

void Ikusa00::Update()
{
	Kaku();

	m_zc++;
}

void Ikusa00::Kaku()
{
	if (c_makeui->m_nowhp <= 0 )
	{
		c_og = NewGO<OverGame>(0, "overgame");
		DeleteGO(this);
	}
}

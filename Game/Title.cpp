#include "stdafx.h"
#include "Title.h"

#include "Saisho.h"
#include"IkusaT.h"
#include "Ikusa00.h"
#include"Ikusa01.h";
#include"IkusaW.h"
#include "NowLo.h"

#include "sound/SoundSource.h"

Title::~Title()
{
	DeleteGO(m_bgm);
}

bool Title::Start()
{
	m_base.Init("Assets/ui/title.dds", 1920.0f, 1080.0f);
	m_base.Update();

	m_kaisi.Init("Assets/ui/titlesatagemode2.dds", 1920.0f, 1080.0f);
	m_tuto.Init("Assets/ui/titlewavemode2.dds", 1920.0f, 1080.0f);
	//m_settei.Init("Assets/ui/titleranking2.dds", 1920.0f, 1080.0f);
	m_kasoru.Init("Assets/ui/titlesankaku.dds", 1920.0f, 1080.0f);
	m_sizi.Init("Assets/ui/title2_sizi.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(0, "Assets/music/kao_title.wav");

	/*
	m_zikken.SetText(L"俺がポテトだ");
	m_zikken.SetPosition({ -600.0f,100.0f,0.0f });
	m_zikken.SetColor({0.5f, 0.5f, 0.5f, 1.0f});
	*/


	m_bgm = NewGO<SoundSource>(0);
	m_bgm->Init(0);
	m_bgm->Play(true);
	m_bgm->SetVolume(2.0f);

	m_kaisi.SetPosition(KAISI);
	m_tuto.SetPosition(TUTO);
	//m_settei.SetPosition(SETTEI);

	m_kasoru.SetPosition(KAISI);

	m_kaisi.Update();
	m_tuto.Update();
	//m_settei.Update();
	m_kasoru.Update();
	m_sizi.Update();

	c_saisho = FindGO<Saisho>("saisho");
	

	return true;
}

void Title::Update()
{
	Sousa();
	Hanei();
	Tenmetu();
}

void Title::Sousa()
{
	if (m_nextfate == YOMIHAZI)
	{

		m_nextfate++;
	
		if (m_kasorupos == 0)
		{
			//c_ikusa00 = NewGO<Ikusa00>(0, "ikusa00");
			c_ikusa01 = NewGO<Ikusa01>(0, "ikusa01");
		}
		else if (m_kasorupos == 1)
		{
			c_ikusaW = NewGO<IkusaW>(0, "ikusaw");
		}

		DeleteGO(this);
	}

	if (m_nextfate >= 0)
	{
		m_nextfate++;
	}
	else if (g_pad[0]->IsTrigger(enButtonA))
	{
		if (m_kasorupos == 0)
		{
			c_nowlo = NewGO<NowLo>(0, "nowlo");
			m_nextfate = 0;
		}
		if (m_kasorupos == 1)
		{
			c_nowlo = NewGO<NowLo>(0, "nowlo");
			m_nextfate = 0;
		}


	}

	//下ボタン
	else if (g_pad[0]->IsTrigger(enButtonDown))
	{
		m_kasorupos++;
		if (m_kasorupos == SOUSUU)
		{
			m_kasorupos = 0;
		}
	}

	//上ボタン
	else if (g_pad[0]->IsTrigger(enButtonUp))
	{
		m_kasorupos--;
		if (m_kasorupos < 0)
		{
			m_kasorupos = SOUSUU - 1;
		}
	}
}

void Title::Hanei()
{
	if (m_kasorupos == 0)
	{
		m_kasoru.SetPosition(KAISI);
		m_kasoru.Update();
	}
	else if (m_kasorupos == 1)
	{
		m_kasoru.SetPosition(TUTO);
		m_kasoru.Update();
	}
	else if(m_kasorupos == 2)
	{
		m_kasoru.SetPosition(SETTEI);
		m_kasoru.Update();
	}
}

void Title::Tenmetu()
{
	if (m_tenhan == 0)
	{
		if (m_tc % 6 == 0)
		{
			m_aru += 0.05f;
		}
	}
	else if(m_tenhan == 1)
	{
		if (m_tc % 6 == 0)
		{
			m_aru -= 0.05f;
		}
	}

	if (m_tc == TENGEN)
	{
		if (m_tenhan == 1)
		{
			m_tenhan = 0;
		}
		else if(m_tenhan == 0)
		{
			m_tenhan = 1;
		}
	
		m_tc = -1;
	}


		m_tc++;

	
	m_sizi.SetMulColor(Vector4(1.0f, 1.0f, 1.0f,m_aru));
	m_sizi.Update();
}

void Title::Render(RenderContext& rc)
{
	m_base.Draw(rc);
	m_kaisi.Draw(rc);
	m_tuto.Draw(rc);
	//m_settei.Draw(rc);
	m_kasoru.Draw(rc);
	m_sizi.Draw(rc);
	//m_zikken.Draw(rc);

}

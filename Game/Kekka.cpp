#include "stdafx.h"
#include "Kekka.h"
#include "Title.h"
#include "Saisho.h" 

Kekka::~Kekka()
{

}

bool Kekka::Start()
{
	c_saisho = FindGO<Saisho>("saisho");


    m_og.Init("Assets/ui/osorasora.dds", 1920.0f, 1080.0f);
    m_og.Update();

	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"YOUR SCORE\n %07d", int(c_saisho->m_score));

	m_scoren.SetText(wcsbuf);
	m_scoren.SetScale(4.0f);
	m_scoren.SetPosition({-450.0f,150.0f,0.0f });
	m_scoren.SetColor({ 0.9f, 0.9f, 0.9f, 1.0f });
	m_scoren.SetShadowParam(true, 3.0f, { 0.0f,0.0f,0.0f,1.0f });

    return true;
}

void Kekka::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		c_title = NewGO<Title>(0, "title");
		DeleteGO(this);
	}

}

void Kekka::Render(RenderContext& rc)
{
	m_og.Draw(rc);

	m_scoren.Draw(rc);
}
#include "stdafx.h"
#include "OverGame.h"
#include "Title.h"

OverGame::~OverGame()
{
}

bool OverGame::Start()
{
	m_og.Init("Assets/ui/gameover.dds", 1920.0f, 1080.0f);
	//m_og.Init("Assets/ui/osorasora.dds", 1920.0f, 1080.0f);
	m_og.Update();
	return true;
}

void OverGame::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		c_title = NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void OverGame::Render(RenderContext& rc)
{
	m_og.Draw(rc);
}

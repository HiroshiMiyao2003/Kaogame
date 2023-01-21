#include "stdafx.h"
#include "NowLo.h"

NowLo::~NowLo()
{

}

bool NowLo::Start()
{
	m_nl.Init("Assets/ui/nowlo2.dds", 1920.0f, 1080.0f);
	m_nl.Update();
	return true;
}

void NowLo::Update()
{

}

void NowLo::Render(RenderContext& rc)
{
	m_nl.Draw(rc);
}

#include "stdafx.h"
#include "Daichi.h"
#include "Saisho.h"

Daichi::Daichi()
{
}

Daichi::~Daichi()
{
	
}

bool Daichi::Start()
{
	c_saisho = FindGO<Saisho>("saisho");
	
	if(c_saisho->m_stage == 1)
	{
		modelRender.Init("Assets/haikei/kakunouko.tkm");
	}
	else
	{
		modelRender.Init("Assets/haikei/shougiboard5.tkm");
	}

	//座標
	modelRender.SetPosition(m_position);
	//大きさを設定する。
	modelRender.SetScale(m_scale);
	//回転を設定する。
	modelRender.SetRotation(m_rotation);

	

	//モデルを更新する。
	modelRender.Update();



	return true;
}

void Daichi::Update()
{

}

void Daichi::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}

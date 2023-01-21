#include "k2EnginePreCompile.h"
#include "stdafx.h"
#include "TheSky.h"

TheSky::~TheSky()
{
}

bool TheSky::Start()
{
	modelRender.Init("Assets/haikei/thesky5.tkm");
	//座標
	modelRender.SetPosition(m_position);
	//大きさを設定する。
	modelRender.SetScale(m_scale);
	//回転を設定する。
	modelRender.SetRotation(m_rotation);

	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());

	//モデルを更新する。
	modelRender.Update();
	return true;
}

void TheSky::Update()
{
	m_coucou++;
}

void TheSky::Render(RenderContext& rc)
{

		modelRender.Draw(rc);
}

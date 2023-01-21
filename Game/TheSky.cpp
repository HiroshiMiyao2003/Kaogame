#include "k2EnginePreCompile.h"
#include "stdafx.h"
#include "TheSky.h"

TheSky::~TheSky()
{
}

bool TheSky::Start()
{
	modelRender.Init("Assets/haikei/thesky5.tkm");
	//���W
	modelRender.SetPosition(m_position);
	//�傫����ݒ肷��B
	modelRender.SetScale(m_scale);
	//��]��ݒ肷��B
	modelRender.SetRotation(m_rotation);

	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());

	//���f�����X�V����B
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

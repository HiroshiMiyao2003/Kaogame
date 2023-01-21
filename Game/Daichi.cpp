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

	//���W
	modelRender.SetPosition(m_position);
	//�傫����ݒ肷��B
	modelRender.SetScale(m_scale);
	//��]��ݒ肷��B
	modelRender.SetRotation(m_rotation);

	

	//���f�����X�V����B
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

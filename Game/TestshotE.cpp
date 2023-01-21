#include "stdafx.h"
#include "TestshotE.h"
#include "Oresiten.h"
#include "MakeUI.h"
#include "Testshot.h"

#include "graphics/effect/EffectEmitter.h"

TestshotE::~TestshotE()
{
	DeleteGO(m_col);
}

bool TestshotE::Start()
{
	m_modelrender.Init("Assets/shot/enemyshot2.tkm");

	//m_modelrender.SetScale({2.0f,2.0f,2.0f});

	c_oresiten = FindGO<Oresiten>("oresiten");


	m_nowpos = { 0.0f,MACHIY,0.0f };

	m_modelrender.SetPosition(m_nowpos);

	//�R���W�����i�����蔻��j���쐬
	m_col = NewGO<CollisionObject>(0);


	m_size.x = COLXYZ;
	m_size.y = COLXYZ;
	m_size.z = COLXYZ;

	m_col->CreateBox(m_nowpos, Quaternion::Identity, m_size);
	m_col->SetIsEnableAutoDelete(false);
	m_col->SetName("testtama");

	//UI�N���X��F�m����
	c_makeui = FindGO<MakeUI>("makeui");

	c_ts0 = FindGO<Testshot>("ts0");
	c_ts1 = FindGO<Testshot>("ts1");
	c_ts2 = FindGO<Testshot>("ts2");
	c_ts3 = FindGO<Testshot>("ts3");
	c_ts4 = FindGO<Testshot>("ts4");
	c_ts5 = FindGO<Testshot>("ts5");

	//�G�t�F�N�g�ǂݍ���
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/baku/bakuD.efk");

	return true;
}

void TestshotE::Update()
{

	if (m_taideba == 1)
	{
		Han();
	}
	//�o�Ԃ̂Ƃ��݂̂ɍs������
	if (m_taideba == 1)
	{
		if (m_count == 0)
		{
			Toujo();
		}
		else
		{
			Move();
		}




		m_count++;
	}
}

void TestshotE::Han()
{

	if (m_col->IsHit(c_ts0->m_col)
		|| m_col->IsHit(c_ts1->m_col)
		|| m_col->IsHit(c_ts2->m_col)
		|| m_col->IsHit(c_ts3->m_col)
		|| m_col->IsHit(c_ts4->m_col)
		|| m_col->IsHit(c_ts5->m_col)
		)
	{

		//�e�ɑޏ��������
		if (m_col->IsHit(c_ts0->m_col))
		{
			c_ts0->Bye();
		}
		else if (m_col->IsHit(c_ts1->m_col))
		{
			c_ts1->Bye();
		}
		else if (m_col->IsHit(c_ts2->m_col))
		{
			c_ts2->Bye();
		}
		else if (m_col->IsHit(c_ts3->m_col))
		{
			c_ts3->Bye();
		}
		else if (m_col->IsHit(c_ts4->m_col))
		{
			c_ts4->Bye();
		}
		else if (m_col->IsHit(c_ts5->m_col))
		{
			c_ts5->Bye();
		}

		//��������
		m_bakuE = NewGO <EffectEmitter>(0);
		m_bakuE->Init(0);
		m_bakuE->SetPosition(m_nowpos);
		m_bakuE->SetScale(m_size * BAKUKAKE);
		m_bakuE->SetRotation({0.0f,0.0f,0.0f,0.0f});
		m_bakuE->Play();
		//�������ޏꂷ��
		Bye();


	}


}

void TestshotE::Move()
{
	m_etop = m_oreiru - m_nowpos;

	if (m_etop.Length() <= ZIBA)
	{
		Bye();
	
		//HP�����炷
		c_makeui->m_nowhp -= 1;

	}
	else
	{
		m_nowpos = m_nowpos - m_hureichi;
	}




	//���W���f
	m_modelrender.SetPosition(m_nowpos);
	m_modelrender.Update();

	//�����蔻�蔽�f
	m_col->SetPosition(m_nowpos);

	m_col->Update();
}

void TestshotE::Toujo()
{
	m_hureichi = m_nowpos - m_oreiru;
	//m_hureichi.y -= 100.0f;
	m_hureichi.Normalize();
	m_hureichi *= m_totusoku;


	//���W���f
	m_modelrender.SetPosition(m_nowpos);
	m_modelrender.Update();

	//�����蔻�蔽�f
	m_col->SetPosition(m_nowpos);

	m_col->Update();
}

void TestshotE::Bye()
{
	m_taideba = 0;

	m_count = 0;

	m_nowpos = { 0.0f, MACHIY, 0.0f };
	m_col->SetPosition(m_nowpos);

	m_modelrender.SetPosition(m_nowpos);
	m_modelrender.Update();
}

void TestshotE::Render(RenderContext& rc)
{
	if (m_taideba == 1)
	{
		m_modelrender.Draw(rc);
	}

}

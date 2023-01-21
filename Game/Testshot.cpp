#include "stdafx.h"
#include "Testshot.h"
#include "Oresiten.h"

Testshot::~Testshot()
{
	DeleteGO(m_col);
}

bool Testshot::Start()
{
	m_modelrender.Init("Assets/shot/testshot2.tkm");

	m_oresiten = FindGO<Oresiten>("oresiten");


	m_nowpos = { 0.0f,MACHIY,0.0f };

	m_modelrender.SetPosition(m_nowpos);

	//コリジョン（当たり判定）を作成
	m_col = NewGO<CollisionObject>(0);

	Vector3 l_size;
	l_size.x = COLXYZ;
	l_size.y = COLXYZ;
	l_size.z = COLXYZ;

	m_col->CreateBox(m_nowpos, Quaternion::Identity, l_size);
	m_col->SetIsEnableAutoDelete(false);
	m_col->SetName("testtama");

	return true;
}

void Testshot::Update()
{
	//出番が終わって待機場所に戻るときの処理
	if (m_count >= SAYONARA)
	{
		Bye();
		
	}
	
	//出番のときのみに行う処理
	if (m_taideba == 1)
	{
		if (m_count == 0)
		{
			Toujo();
		}



		Move();

		m_col->SetPosition(m_nowpos);

		m_col->Update();

		//弾の描画を更新する処理
		if (m_count >= KAKIHAZI)
		{
			m_modelrender.SetPosition(m_nowpos);

			m_modelrender.Update();
		}


		m_count += 1;
	}
	/*
	else
	{
		m_nowpos.x = 100.0f;
		m_nowpos.y = 100.0f;
		m_nowpos.z = 100.0f;
		m_modelrender.SetPosition(m_nowpos);
		m_modelrender.Update();

	}
	*/
}

void Testshot::Move()
{
	m_nowpos.x = m_nowpos.x + m_hureichi.x;
	m_nowpos.y = m_nowpos.y + m_hureichi.y;
	m_nowpos.z = m_nowpos.z + m_hureichi.z;
}

void Testshot::Toujo()
{
	m_nowpos.x = 0.0f;
	m_nowpos.y = 100.0f;
	m_nowpos.z = 0.0f;

	m_hureichi.x = m_oresiten->TARX / WARI;
	m_hureichi.z = m_oresiten->TARZ / WARI;

	m_hureichi.y = m_oresiten->TARY - 100.0f;
	m_hureichi.y = m_hureichi.y / WARI;
}

void Testshot::Bye()
{
	m_taideba = 0;

	m_count = 0;

	m_nowpos = {0.0f, MACHIY, 0.0f};
	m_col->SetPosition(m_nowpos);

	m_modelrender.SetPosition(m_nowpos);
	m_modelrender.Update();
}

void Testshot::Render(RenderContext& rc)
{
	if (m_taideba == 1)
	{
		m_modelrender.Draw(rc);
	}

}

#include "stdafx.h"
#include "Oresiten.h"


Oresiten::~Oresiten()
{

}

bool Oresiten::Start()
{
	g_camera3D->SetNear(KINHEI);
	g_camera3D->SetFar(ENHEI);
	g_camera3D->SetTarget(TARX, TARY, TARZ);
	g_camera3D->SetPosition(POSX, POSY, POSZ);

	m_position.x = (POSX);
	m_position.y = (POSY);
	m_position.z = (POSZ);

	TARZ = cos(Zrad * (PAI / 180)) * 5.0f;
	TARX = sin(Zrad * (PAI / 180)) * 5.0f;
	g_camera3D->SetTarget(TARX, TARY, TARZ);

	
	c_poi.Init();
	c_poi.SetAffectPowParam(1.00f);
	c_poi.SetColor({12,12,12});
	c_poi.SetPosition({ POSX,1200.0f,POSZ });
	c_poi.SetRange(1400.0f);
	c_poi.Update();
	



	return true;
}

void Oresiten::Update()
{
	if (m_lock == 0)
	{
		Rotation();
	}

	g_camera3D->SetTarget(TARX, TARY, TARZ);

	Keisan();

	

	
	Vector3 dirA = m_sisen;
	dirA.y = 0.0f;
	Vector3 IROHIKARI{ 0.0f,0.0f,0.0f };
	
	g_renderingEngine->SetDirectionLight
	(
		0,				// ライトの番号
		dirA, 	// 方向
		IROHIKARI	// カラー
	);
	/*
	Vector3 dirB = m_sisen;
	dirB.y = 0.0f;
	dirB.z = cos(40.0f * (PAI / 180));
	dirB.x = sin(40.0f * (PAI / 180));
	g_renderingEngine->SetDirectionLight
	(
		1,				// ライトの番号
		dirB, 	// 方向
		IROHIKARI	// カラー
	);

	Vector3 dirC = m_sisen;
	dirC.y = 0.0f;
	dirC.z = cos(-40.0f * (PAI / 180));
	dirC.x = sin(-40.0f * (PAI / 180));
	g_renderingEngine->SetDirectionLight
	(
		2,				// ライトの番号
		dirC, 	// 方向
		IROHIKARI	// カラー
	);
	*/
}

void Oresiten::Keisan()
{
	//変数セット
	m_tar = {TARX,TARY,TARZ};
	//ベクトルセット
	m_sisen = m_tar - m_position;
	m_sisen_gyaku = m_position - m_tar;

}

void Oresiten::Rotation()
{
	/*
	Zrad = Zrad + 0.5f;
	TARZ = cos(Zrad * (PAI / 180));
	TARX = sin(Zrad * (PAI / 180));
	*/

	//XZ調整
	m_ljoyx = g_pad[0]->GetLStickXF();
	if (m_ljoyx >= 0.5f)
	{
		float xz;

		xz = KANDOXZ * 10;

		if (g_pad[0]->IsPress(enButtonLB1))
		{
			xz *= DASH;
		}

		Zrad = Zrad + xz;
		TARZ = cos(Zrad * (PAI / 180)) * 5.0f;
		TARX = sin(Zrad * (PAI / 180)) * 5.0f;
	}
	
	else if (m_ljoyx <= -0.5f)
	{
		float xz;

		xz = KANDOXZ * 10;

		if (g_pad[0]->IsPress(enButtonLB1))
		{
			xz *= DASH;
		}

		Zrad = Zrad - xz;

		TARZ = cos(Zrad * (PAI / 180)) * 5.0f;
		TARX = sin(Zrad * (PAI / 180)) * 5.0f;
	}
	
	//Y調整
	m_ljoyy = g_pad[0]->GetLStickYF();
	if (m_ljoyy >= 0.5f)
	{
		if (TARY <= UEGEN)
		{
			float y = KANDOY;
			if (g_pad[0]->IsPress(enButtonLB1))
			{
				y *= DASH;
			}
			TARY += y;
		}
	
	}
	
	else if (m_ljoyy <= -0.5f)
	{
		if (TARY >= SITAGEN)
		{
			float y = KANDOY;
			if (g_pad[0]->IsPress(enButtonLB1))
			{
				y *= DASH;
			}
			TARY -= y;
		}
	}
	
	//角度を整える

	//右に行きすぎたら
	if (Zrad > 180.0f)
	{
		//マイナスの値に変えている
		Zrad = 360.0f - Zrad;
		Zrad *= -1.0f;
	}

	//左に行きすぎたら
	if (Zrad < -180.0f)
	{
		//プラスの値に変えている
		Zrad = 360.0f + Zrad;
	}
}

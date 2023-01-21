#include "stdafx.h"
#include "MakeUI.h"
#include "Testshot.h"
#include "Saisho.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

MakeUI::~MakeUI()
{

	DeleteGO(c_ts0);
	DeleteGO(c_ts1);
	DeleteGO(c_ts2);
	DeleteGO(c_ts3);
	DeleteGO(c_ts4);
	DeleteGO(c_ts5);

}

bool MakeUI::Start()
{
	m_cross.Init("Assets/ui/crosshear.dds", 1152.0f, 648.0f);

	m_hp1.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp2.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp3.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp4.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp5.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp6.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp7.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp8.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp9.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);
	m_hp10.Init("Assets/ui/heart3.dds", 1920.0f, 1080.0f);

	m_hpk1.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk2.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk3.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk4.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk5.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk6.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk7.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk8.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk9.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);
	m_hpk10.Init("Assets/ui/heart_null3.dds", 1920.0f, 1080.0f);


	m_eneR.Init("Assets/ui/migiteki.dds", 1920.0f, 1080.0f);
	m_eneL.Init("Assets/ui/hidariteki.dds", 1920.0f, 1080.0f);

	m_redda0.Init("Assets/ui/redgamen.dds", 1920.0f, 1080.0f);
	m_redda1.Init("Assets/ui/redgamen.dds", 1920.0f, 1080.0f);
	m_redda2.Init("Assets/ui/redgamen.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(1, "Assets/music/kaoshot.wav");
	g_soundEngine->ResistWaveFileBank(2, "Assets/music/damageon.wav");

	m_hp2.SetPosition({ 128.0f,0.0f,0.0f });
	m_hp2.Update();
	m_hp3.SetPosition({ 256.0f,0.0f,0.0f });
	m_hp3.Update();
	m_hp4.SetPosition({ 384.0f,0.0f,0.0f });
	m_hp4.Update();
	m_hp5.SetPosition({ 512.0f,0.0f,0.0f });
	m_hp5.Update();

	m_hpk2.SetPosition({ 128.0f,0.0f,0.0f });
	m_hpk2.Update();
	m_hpk3.SetPosition({ 256.0f,0.0f,0.0f });
	m_hpk3.Update();
	m_hpk4.SetPosition({ 384.0f,0.0f,0.0f });
	m_hpk4.Update();
	m_hpk5.SetPosition({ 512.0f,0.0f,0.0f });
	m_hpk5.Update();
	m_hpk6.SetPosition({ 640.0f,0.0f,0.0f });
	m_hpk6.Update();
	m_hpk7.SetPosition({ 768.0f,0.0f,0.0f });
	m_hpk7.Update();
	m_hpk8.SetPosition({ 896.0f,0.0f,0.0f });
	m_hpk8.Update();
	m_hpk9.SetPosition({ 1024.0f,0.0f,0.0f });
	m_hpk9.Update();
	m_hpk10.SetPosition({ 1152.0f,0.0f,0.0f });
	m_hpk10.Update();

	m_redda0.SetPosition(TAIKITEN);
	m_redda1.SetPosition(TAIKITEN);
	m_redda2.SetPosition(TAIKITEN);

	m_redda0.Update();
	m_redda1.Update();
	m_redda2.Update();

	c_ts0 = NewGO<Testshot>(0, "ts0");
	c_ts1 = NewGO<Testshot>(1, "ts1");
	c_ts2 = NewGO<Testshot>(2, "ts2");
	c_ts3 = NewGO<Testshot>(3, "ts3");
	c_ts4 = NewGO<Testshot>(4, "ts4");
	c_ts5 = NewGO<Testshot>(5, "ts5");

	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"SCORE %07d", int(m_score));

	m_scoren.SetText(wcsbuf);
	m_scoren.SetScale(2.1f);
	m_scoren.SetPosition({ 330.0f,520.0f,0.0f });
	m_scoren.SetColor({ 0.9f, 0.9f, 0.9f, 1.0f });
	m_scoren.SetShadowParam(true,3.0f,{0.0f,0.0f,0.0f,1.0f});
	
	c_saisho = FindGO<Saisho>("saisho");

	return true;
}

void MakeUI::Update()
{
	HPkaku();
	if (m_lock == 0)
	{
		Botakaku();
	}
	Tamakaku();
	Cool();
	Crosskime();
	Hpkime();
	Keikime();
	if (m_dacount >= 0)
	{
		Damemode();
	}
	c_saisho->m_score = m_score;
}

void MakeUI::HPkaku()
{
	if (m_nowhp < m_beforeHP)
	{
		m_dacount = 0;
	}

	m_beforeHP = m_nowhp;

}

void MakeUI::Botakaku()
{
	if (g_pad[0]->IsTrigger(enButtonA)&&m_cool == 0)
	{
		//すべての弾の状況を確認する
		for (int i = 0; i < 6; i++)
		{
			//その弾が出番じゃないかどうかを判定
			if (m_tsjoutai[i] == 0)
			{
				//クールタイムを加算する
				m_cool = COOLTIME;

				//変数iに応じた弾を出撃させる
				switch (i)
				{
				case 0:
					c_ts0->m_taideba = 1;
	
					break;
				case 1:
					c_ts1->m_taideba = 1;

				case 2:
					c_ts2->m_taideba = 1;

					break;
				case 3:
					c_ts3->m_taideba = 1;

					break;
				case 4:
					c_ts4->m_taideba = 1;

					break;
				case 5:
					c_ts5->m_taideba = 1;

					break;
				default:
					//たどり着かない処理
					break;
				}
	
				//SoundSourceのインスタンスを作成する。
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(1);
				se->Play(false);
				//音量を上げる。
				se->SetVolume(2.5f);

				//ループを終わらせる
				i = 6;

			}
		}

	}
}

void MakeUI::Tamakaku()
{
	for (int ii = 0; ii < 6; ii++)
	{
		switch (ii)
		{
		case 0:
			m_tsjoutai[ii] = c_ts0->m_taideba;
			break;
		case 1:
			m_tsjoutai[ii] = c_ts1->m_taideba;
			break;
		case 2:
			m_tsjoutai[ii] = c_ts2->m_taideba;
			break;
		case 3:
			m_tsjoutai[ii] = c_ts3->m_taideba;
			break;
		case 4:
			m_tsjoutai[ii] = c_ts4->m_taideba;
			break;
		case 5:
			m_tsjoutai[ii] = c_ts5->m_taideba;
			break;
		default:
			break;
		}
	}
}

void MakeUI::Cool()
{
	if (m_cool != 0)
	{
		m_cool--;
	}
}

void MakeUI::Crosskime()
{

}

void MakeUI::Hpkime()
{
	if (m_nowhp > 10)
	{
		m_nowhp = 10;
	}

	if (m_nowhp >= 1)
	{
		m_hp1.SetPosition({ 0.0f,0.0f,0.0f });
	}
	else
	{
		m_hp1.SetPosition({ 0.0f,1000.0f,0.0f });
	}

	if (m_nowhp >= 2)
	{
		m_hp2.SetPosition({128.0f,0.0f,0.0f});
	}
	else
	{
		m_hp2.SetPosition({ 0.0f,1000.0f,0.0f });
	}

	if (m_nowhp >= 3)
	{
		m_hp3.SetPosition({256.0f,0.0f,0.0f});
	}
	else
	{
		m_hp3.SetPosition({ 0.0f,1000.0f,0.0f });
	}

	if (m_nowhp >= 4)
	{
		m_hp4.SetPosition({384.0f,0.0f,0.0f});
	}
	else
	{
		m_hp4.SetPosition({ 0.0f,1000.0f,0.0f });
	}
	
	if (m_nowhp >= 5)
	{
		m_hp5.SetPosition({512.0f,0.0f,0.0f});
	}
	else
	{
		m_hp5.SetPosition({ 0.0f,1000.0f,0.0f });
	}
	if (m_nowhp >= 6)
	{
		m_hp6.SetPosition({ 640.0f,0.0f,0.0f });
	}
	else
	{
		m_hp6.SetPosition({ 0.0f,1000.0f,0.0f });
	}
	if (m_nowhp >= 7)
	{
		m_hp7.SetPosition({ 768.0f,0.0f,0.0f });
	}
	else
	{
		m_hp7.SetPosition({ 0.0f,1000.0f,0.0f });
	}
	if (m_nowhp >= 8)
	{
		m_hp8.SetPosition({ 896.0f,0.0f,0.0f });
	}
	else
	{
		m_hp8.SetPosition({ 0.0f,1000.0f,0.0f });
	}
	if (m_nowhp >= 9)
	{
		m_hp9.SetPosition({ 1024.0f,0.0f,0.0f });
	}
	else
	{
		m_hp9.SetPosition({ 0.0f,1000.0f,0.0f });
	}
	if (m_nowhp >= 10)
	{
		m_hp10.SetPosition({ 1152.0f,0.0f,0.0f });
	}
	else
	{
		m_hp10.SetPosition({ 0.0f,1000.0f,0.0f });
	}

	m_hp1.Update();
	m_hp2.Update();
	m_hp3.Update();
	m_hp4.Update();
	m_hp5.Update();
	m_hp6.Update();
	m_hp7.Update();
	m_hp8.Update();
	m_hp9.Update();
	m_hp10.Update();

	m_hpk1.Update();
	m_hpk2.Update();
	m_hpk3.Update();
	m_hpk4.Update();
	m_hpk5.Update();
	m_hpk6.Update();
	m_hpk7.Update();
	m_hpk8.Update();
	m_hpk9.Update();
	m_hpk10.Update();

}

void MakeUI::Keikime()
{
	if (m_keiR == 1)
	{
		m_eneR.SetPosition({0.0f,0.0f,0.0f});
	}
	else
	{
		m_eneR.SetPosition({ 0.0f,3000.0f,0.0f });
	}
	m_keiR = 0;
	if (m_keiL == 1)
	{
		m_eneL.SetPosition({ 0.0f,0.0f,0.0f });
	}
	else
	{
		m_eneL.SetPosition({ 0.0f,3000.0f,0.0f });
	}
	m_keiL = 0;

	m_eneR.Update();
	m_eneL.Update();
}

void MakeUI::Damemode()
{
	if (m_dacount == 0)
	{
		m_redda0.SetPosition(GENTEN);
		//SoundSourceのインスタンスを作成する。
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(2);
		se->Play(false);
		//音量を上げる。
		se->SetVolume(2.5f);
	}
	if (m_dacount == DAMEFIVE)
	{
		m_redda1.SetPosition(GENTEN);
	}
	if (m_dacount == DAMEFIVE * 2)
	{
		m_redda1.SetPosition(TAIKITEN);
	}
	if (m_dacount == DAMEFIVE * 3)
	{
		m_redda0.SetPosition(TAIKITEN);
		m_dacount = -1;
	}
	else
	{
		m_dacount++;
	}
	m_redda0.Update();
	m_redda1.Update();
	m_redda2.Update();
}

void MakeUI::Render(RenderContext& rc)
{
	if (m_lock == 0)
	{
		m_cross.Draw(rc);
	}



	m_eneR.Draw(rc);
	m_eneL.Draw(rc);

	if (m_nowhp < 1)
	{
		m_hpk1.Draw(rc);
	}
	if (m_nowhp < 2)
	{
		m_hpk2.Draw(rc);
	}
	if (m_nowhp < 3)
	{
		m_hpk3.Draw(rc);
	}
	if (m_nowhp < 4)
	{
		m_hpk4.Draw(rc);
	}
	if (m_nowhp < 5)
	{
		m_hpk5.Draw(rc);
	}
	if (m_nowhp < 6)
	{
		m_hpk6.Draw(rc);
	}
	if (m_nowhp < 7)
	{
		m_hpk7.Draw(rc);
	}
	if (m_nowhp < 8)
	{
		m_hpk8.Draw(rc);
	}
	if (m_nowhp < 9)
	{
		m_hpk9.Draw(rc);
	}
	if (m_nowhp < 10)
	{
		m_hpk10.Draw(rc);
	}

	if (m_nowhp >= 1)
	{
		m_hp1.Draw(rc);
	}
	if (m_nowhp >= 2)
	{
		m_hp2.Draw(rc);
	}
	if (m_nowhp >= 3)
	{
		m_hp3.Draw(rc);
	}
	if (m_nowhp >= 4)
	{
		m_hp4.Draw(rc);
	}
	if (m_nowhp >= 5)
	{
		m_hp5.Draw(rc);
	}
	if (m_nowhp >= 6)
	{
		m_hp6.Draw(rc);
	}
	if (m_nowhp >= 7)
	{
		m_hp7.Draw(rc);
	}
	if (m_nowhp >= 8)
	{
		m_hp8.Draw(rc);
	}
	if (m_nowhp >= 9)
	{
		m_hp9.Draw(rc);
	}
	if (m_nowhp >= 10)
	{
		m_hp10.Draw(rc);
	}


	if (m_dacount != -1)
	{
		m_redda0.Draw(rc);
		m_redda1.Draw(rc);
		m_redda2.Draw(rc);
	}


	m_scoren.Draw(rc);
}

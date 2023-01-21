#include "stdafx.h"
#include "Boss.h"

#include "EnemyN.h"
#include "EnemyT.h"

#include "Testshot.h"
#include "MakeUI.h"
#include"Oresiten.h"

#include <stdlib.h>

#include "graphics/effect/EffectEmitter.h"

Boss::~Boss()
{
	DeleteGO(m_ecol);
	DeleteGO(c_buka1);
	DeleteGO(c_buka2);
}

bool Boss::Start()
{
	//�A�j���[�V�����ǂݍ���
	m_anima[Clip_taiki].Load("Assets/enemy/boss/taiki.tka");
	m_anima[Clip_taiki].SetLoopFlag(true);
	m_anima[Clip_toujou].Load("Assets/enemy/boss/toujou.tka");
	m_anima[Clip_toujou].SetLoopFlag(false);
	m_anima[Clip_warpR].Load("Assets/enemy/boss/warpR.tka");
	m_anima[Clip_warpR].SetLoopFlag(false);
	m_anima[Clip_warpL].Load("Assets/enemy/boss/warpL.tka");
	m_anima[Clip_warpL].SetLoopFlag(false);
	m_anima[Clip_suki].Load("Assets/enemy/boss/sukiari.tka");
	m_anima[Clip_suki].SetLoopFlag(true);
	m_anima[Clip_bou].Load("Assets/enemy/boss/mamori.tka");
	m_anima[Clip_bou].SetLoopFlag(false);
	m_anima[Clip_yarare].Load("Assets/enemy/boss/yarare.tka");
	m_anima[Clip_yarare].SetLoopFlag(true);

	//���f���ǂݍ���
	m_ml.Init("Assets/enemy/boss/boss.tkm", m_anima, Clip_Num, enModelUpAxisZ);

	//c_buka2 = NewGO<EnemyN>(0, "buka1");
	c_buka1 = NewGO<EnemyT>(0, "buka2");

	//�ҋ@�ꏊ�֗U��
	m_enowpos = { 0.0f,TAIKIY,0.0f };

	//���f���G�t�ɑҋ@�ꏊ��A��
	m_ml.SetPosition(m_enowpos);

	//�����蔻��Ăяo��
	m_ecol = NewGO<CollisionObject>(0);

	//����T�C�Y�w��

	m_size.x = COLXYZ;
	m_size.y = COLXYZ;
	m_size.z = COLXYZ;

	//����ɏ�����������
	m_ecol->CreateBox(m_enowpos, Quaternion::Identity, m_size);
	m_ecol->SetIsEnableAutoDelete(false);
	m_ecol->SetName("enet");

	//�e�̏����擾
	c_ts0 = FindGO<Testshot>("ts0");
	c_ts1 = FindGO<Testshot>("ts1");
	c_ts2 = FindGO<Testshot>("ts2");
	c_ts3 = FindGO<Testshot>("ts3");
	c_ts4 = FindGO<Testshot>("ts4");
	c_ts5 = FindGO<Testshot>("ts5");

	//�Ȃ̏����擾
	c_makeui = FindGO<MakeUI>("makeui");

	//�Ȃ̎��_���擾
	c_oresiten = FindGO<Oresiten>("oresiten");

	//�G�t�F�N�g�ǂݍ���
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/baku/bakuD.efk");
	EffectEngine::GetInstance()->ResistEffect(1, u"Assets/effect/deru/deru0.efk");

	//m_ml.Update();

    return true;
}

void Boss::Update()
{
	if (m_deban == 1&&m_muteki == 0)
	{
		Han();
	}
	if (m_deban == 1)
	{
		Live();

		if (m_warp == 0)
		{
			Haaku();
		}

		Haaku();

	}

	Anima();
}



void Boss::Han()
{
	if (m_ecol->IsHit(c_ts0->m_col)
		|| m_ecol->IsHit(c_ts1->m_col)
		|| m_ecol->IsHit(c_ts2->m_col)
		|| m_ecol->IsHit(c_ts3->m_col)
		|| m_ecol->IsHit(c_ts4->m_col)
		|| m_ecol->IsHit(c_ts5->m_col)
		)
	{

		//�e�ɑޏ��������
		if (m_ecol->IsHit(c_ts0->m_col))
		{
			c_ts0->Bye();
		}
		else if (m_ecol->IsHit(c_ts1->m_col))
		{
			c_ts1->Bye();
		}
		else if (m_ecol->IsHit(c_ts2->m_col))
		{
			c_ts2->Bye();
		}
		else if (m_ecol->IsHit(c_ts3->m_col))
		{
			c_ts3->Bye();
		}
		else if (m_ecol->IsHit(c_ts4->m_col))
		{
			c_ts4->Bye();
		}
		else if (m_ecol->IsHit(c_ts5->m_col))
		{
			c_ts5->Bye();
		}
		//�c��HP�ɂ���ĈقȂ鏈������
		if (m_bosshp == 1)
		{

			m_bakuE = NewGO <EffectEmitter>(0);
			m_bakuE->Init(0);
			m_bakuE->SetPosition(m_enowpos);
			m_bakuE->SetScale(m_size * BAKUKAKE * 2);
			m_bakuE->SetRotation(m_qua);
			m_bakuE->Play();

			m_enowpos = { 0.0f,TAIKIY,0.0f };

			//���W���f
			m_ml.SetPosition(m_enowpos);
			m_ml.Update();
			//�����蔻�蔽�f
			m_ecol->SetPosition(m_enowpos);
			m_ecol->Update();

			//�����Əo�Ԃ̃��Z�b�g
			m_deban = 0;
			c_buka1->Taijou();


		}
		else
		{
			m_kouc = 0;
			m_bosshp -= 1;
			m_act = 7;
			m_bakuE = NewGO <EffectEmitter>(0);
			m_bakuE->Init(0);

			m_bakuE->SetPosition(m_enowpos);
			m_bakuE->SetScale(m_size * BAKUKAKE);
			m_bakuE->SetRotation(m_qua);
			m_bakuE->Play();
		}
		


	}
}

void Boss::Live()
{
	if (m_act == 1)
	{
		ActToujou();
	}
	if (m_act == 2)
	{
		ActHudou();
	}
	if (m_act == 3)
	{
		ActWarpR();
	}
	if (m_act == 4)
	{
		ActWarpL();
	}
	if (m_act == 5)
	{
		ActSuki();
	}
	if (m_act == 6)
	{
		ActMamori();
	}
	if (m_act == 7)
	{
		ActYarare();
	}

	//�p�x�𐮂���

		//�E�ɍs����������
	if (m_zrad > 180.0f)
	{
		//�}�C�i�X�̒l�ɕς��Ă���
		m_zrad = 360.0f - m_zrad;
		m_zrad *= -1.0f;
	}

	//���ɍs����������
	if (m_zrad < -180.0f)
	{
		//�v���X�̒l�ɕς��Ă���
		m_zrad = 360.0f + m_zrad;
	}
	//�o�ꂵ�Ă���J�E���g�Ɠ��_�J�E���g�̕ύX

	//m_nowscore--;
	//m_shoken++;
}

void Boss::ActToujou()
{
	m_muteki = 1;
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc != 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}

	//�����𒲐�����
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//���W���f
	m_ml.SetPosition(m_enowpos);
	//�������f
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	if (m_kouc < 0)
	{
		m_kouc = 0;
	}
	else if(m_kouc >= 120)
	{
		int nextkime = ("%d\n", 3 + rand() % 2);
		m_act = nextkime;
		m_kouc = 0;
	}
	else 
	{
		m_kouc++;
	}
}

void Boss::ActHudou()
{
	m_muteki = 1;
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc != 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}

	//�����𒲐�����
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//���W���f
	m_ml.SetPosition(m_enowpos);
	//�������f
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();

	if (m_kouc != 0)
	{
		m_kouc = 0;
	}
}

void Boss::ActWarpR()
{
	m_muteki = 1;
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc != 0&&m_kouc < 120)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 2;
	}

	//�����𒲐�����
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//���W���f
	m_ml.SetPosition(m_enowpos);
	//�������f
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();
	if (m_kouc < 0)
	{
		m_kouc = 0;
	}
	else if (m_kouc == 120)
	{
		m_enowpos = { 0.0f,1000.0f,0.0f };
		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
		m_kouc++;
		m_warp = 1;
	}
	else if (m_kouc >= 180)
	{
		m_zrad -= 120.0f;
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_kouc = 0;
		m_act = 5;
	}
	else
	{
		m_kouc++;
	}

}

void Boss::ActWarpL()
{
	m_muteki = 1;
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc != 0 && m_kouc < 120)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 3;
		
	}

	//�����𒲐�����
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//���W���f
	m_ml.SetPosition(m_enowpos);
	//�������f
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();
	if (m_kouc < 0)
	{
		m_kouc = 0;
	}
	else if(m_kouc >= 180)
	{
		m_zrad += 120.0f;
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_kouc = 0;
		m_act = 5;
	}
	else if (m_kouc == 120)
	{
		m_enowpos = {0.0f,1000.0f,0.0f};
		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
		m_kouc++;
		m_warp = 1;
	}
	else
	{
		m_kouc++;
	}
}

void Boss::ActSuki()
{
	m_muteki = 0;
	m_warp = 0;

	//0�ȊO�̐��̃J�E���g���̂ݎ��s����鏈��
	if (m_kouc != 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		//m_ugoki = 4;
	}
	if (m_kouc == 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 4;
		if (c_buka1->m_deban == 0)
		{
			c_buka1->Toujou(ENEACT_B1, m_zrad, ENEKYORI_B1, ENEKOUDO_B1, 1.0f, 0.5f);
			c_buka1->Totusiro(ENETOTUSOKU_B1, ENEBEF_B1, ENEAFT_B1);
		}

	}
	//�����𒲐�����
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//���W���f
	m_ml.SetPosition(m_enowpos);
	//�������f
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();
	if (m_kouc < 0)
	{
		m_kouc = 0;
	}
	else if (m_kouc >= 300)
	{
		m_kouc = 0;
		m_act = 6;
	}
	else
	{
		m_kouc++;
	}
}

void Boss::ActMamori()
{
	m_muteki = 1;

	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc != 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 5;
	}

	//�����𒲐�����
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//���W���f
	m_ml.SetPosition(m_enowpos);
	//�������f
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();
	if (m_kouc < 0)
	{
		m_kouc = 0;
	}
	else if (m_kouc >= 180)
	{
		m_kouc = 0;
		int nextkime = ("%d\n", 3 + rand() % 2);
		m_act = nextkime;
	}
	else
	{
		m_kouc++;
	}

}

void Boss::ActYarare()
{
	m_muteki = 1;

	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc != 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 6;
	}

	//�����𒲐�����
	m_qua.SetRotationDegY(m_zrad + 180.0f);
	//���W���f
	m_ml.SetPosition(m_enowpos);
	//�������f
	m_ml.SetRotation(m_qua);

	m_ml.Update();

	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);

	m_ecol->Update();
	if (m_kouc < 0)
	{
		m_kouc = 0;
	}
	else if (m_kouc >= 60)
	{
		m_kouc = 0;
		int nextkime = ("%d\n", 3 + rand() % 2);
		m_act = nextkime;
	}
	else
	{
		m_kouc++;
	}
}

void Boss::Haaku()
{
	float dairi = m_zrad - c_oresiten->Zrad;



	//���E�O���ǂ�����if
	if (dairi > SIYAKAKU || dairi < -SIYAKAKU)
	{
		//0.0f < dairi <= 180.0f or -180.0f > dairi > -360.0f(�E�ɓG�������Ƃ�)
		if (dairi <= 180.0f && dairi > 0.0f || dairi < -180.0f && dairi > -360.0f)
		{
			m_sikasoto = 1;
			c_makeui->m_keiR = 1;
		}
		//180.0f < dairi < 360.0f or 0.0f > dairi >= -180.0f (���ɓG�������Ƃ�)
		if (dairi > 180.0f && dairi < 360.0f || dairi >= -180.0f && dairi < 0.0f)
		{
			m_sikasoto = 2;
			c_makeui->m_keiL = 1;
		}
	}
	else
	{
		m_sikasoto = 0;
	}
}

void Boss::Anima()
{
	switch (m_ugoki)
	{
	case 0:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	case 1:
		m_ml.PlayAnimation(Clip_toujou);
		break;
	case 2:
		m_ml.PlayAnimation(Clip_warpR);
		break;
	case 3:
		m_ml.PlayAnimation(Clip_warpL);
		break;
	case 4:
		m_ml.PlayAnimation(Clip_suki);
		break;
	case 5:
		m_ml.PlayAnimation(Clip_bou);
		break;
	case 6:
		m_ml.PlayAnimation(Clip_yarare);
		break;
	default:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	}
}

void Boss::Render(RenderContext& rc)
{
	if (m_deban == 1)
	{
		m_ml.Draw(rc);
	}
}

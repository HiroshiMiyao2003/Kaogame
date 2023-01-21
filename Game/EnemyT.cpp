#include "stdafx.h"
#include "EnemyT.h"
#include "Testshot.h"
#include "MakeUI.h"
#include"Oresiten.h"
#include"TestshotE.h"

#include "graphics/effect/EffectEmitter.h"


EnemyT::~EnemyT()
{
	DeleteGO(c_tse);
	DeleteGO(m_ecol);
}


bool EnemyT::Start()
{
	//�A�j���[�V�����ǂݍ���
	m_anima[Clip_taiki].Load("Assets/enemy/hakoniwaT/Ttaiki.tka");
	m_anima[Clip_taiki].SetLoopFlag(true);
	m_anima[Clip_tyouhatu].Load("Assets/enemy/hakoniwaT/Ttyouhatu.tka");
	m_anima[Clip_tyouhatu].SetLoopFlag(true);
	m_anima[Clip_hassya].Load("Assets/enemy/hakoniwaT/Thassya.tka");
	m_anima[Clip_hassya].SetLoopFlag(false);

	//���f���ǂݍ���
	m_ml.Init("Assets/enemy/hakoniwaT/hakoniwaT.tkm", m_anima, Clip_Num, enModelUpAxisZ);

	

	//�ҋ@�ꏊ�֗U��
	m_enowpos = { 0.0f,TAIKIY,0.0f };

	//���f���G�t�ɑҋ@�ꏊ��A��
	m_ml.SetPosition(m_enowpos);

	//�����蔻��Ăяo��
	m_ecol = NewGO<CollisionObject>(0);

	//����T�C�Y�w��

	m_size.x = COLXZ;
	m_size.y = COLY;
	m_size.z = COLXZ;


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

	//�G�̒e�𐶐�
	c_tse = NewGO<TestshotE>(0,"testshote");

	//�G�t�F�N�g�ǂݍ���
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/baku/bakuD.efk");
	EffectEngine::GetInstance()->ResistEffect(1, u"Assets/effect/deru/deru0.efk");




	return true;
}

void EnemyT::Update()
{
	if (m_deban == 1)
	{
		Han();
	}
	if (m_deban == 1)
	{
		Live();
		Haaku();
	}
	Anima();

}


void EnemyT::Han()
{

	if (m_ecol->IsHit(c_ts0->m_col)
		|| m_ecol->IsHit(c_ts1->m_col)
		|| m_ecol->IsHit(c_ts2->m_col)
		|| m_ecol->IsHit(c_ts3->m_col)
		|| m_ecol->IsHit(c_ts4->m_col)
		|| m_ecol->IsHit(c_ts5->m_col)
		)
	{

		m_touE->Stop();

		m_bakuE = NewGO <EffectEmitter>(0);
		m_bakuE->Init(0);

		m_bakuE->SetPosition(m_enowpos);
		m_bakuE->SetScale({COLXZ * BAKUKAKE,COLXZ * BAKUKAKE,COLXZ * BAKUKAKE });
		m_bakuE->SetRotation(m_qua);
		m_bakuE->Play();

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



		m_enowpos = { 0.0f,TAIKIY,0.0f };

		//���W���f
		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
		//�����蔻�蔽�f
		m_ecol->SetPosition(m_enowpos);
		m_ecol->Update();

		//�����Əo�Ԃ̃��Z�b�g
		m_shoken = 0;
		m_deban = 0;

		c_tse->Bye();

		//���_�̔��f
		c_makeui->ScoreAdd(m_nowscore);

	}
}

void EnemyT::Live()
{
	switch (m_act)
	{
	case 0:
		ActGuru();
		break;
	case 1:
		ActHassya();
		break;
	case 2:
		ActHudou();
		break;
	case 3:
		ActTate_U();
		break;
	case 4:
		ActTate_D();
		break;
	case 5:
		ActGurun_R();
		break;
	case 6:
		ActGurun_L();
		break;
	default:
		ActGuru();
		break;
	}
	//�o��G�t�F�N�g��^����
	if (m_shoken == 0)
	{
		//DeleteGO(m_bakuE);
		m_touE = NewGO <EffectEmitter>(1);
		m_touE->Init(1);

		m_touE->SetPosition(m_enowpos);
		m_touE->SetScale({ COLXZ * TOUKAKE,COLY * TOUKAKE,COLXZ * TOUKAKE });
		m_touE->SetRotation(m_qua);
		m_touE->Play();
		m_shoken = 1;

		//�X�R�A��ݒ肷��
		m_nowscore = MAXSCORE;

	}
	if (m_shoken >= TOUESTOP)
	{
		m_touE->Stop();
		//DeleteGO(m_touE);
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

	m_shoken++;
}

void EnemyT::ActGuru()
{
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;

		m_ugoki = 1;
	}
	else if (m_kouc >= 60)
	{
		m_zrad = m_zrad - (SOKUDO * 10);
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
	}
	else
	{
		m_zrad = m_zrad + (SOKUDO * 10);
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
	}

	m_enowpos.y = m_koudo;

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

	//�J�E���g���Z
	m_kouc++;
	if (m_kouc == KOUCFIN)
	{
		m_kouc = 0;
	}
}

void EnemyT::ActHassya()
{
	//���O����
	if (m_totuc >= 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;

		if (m_totuc == 0)
		{

			m_hureichi = m_enowpos;
			m_hureichi.y -= 100.0f;
			m_hureichi.Normalize();
			m_hureichi *= m_totusoku;


			m_ugoki = 2;
		}
	}
	//�ˌ����s
	else
	{

		if (m_totuc == HASSYAMADE)
		{
			c_tse->ToujoSiro(m_enowpos,m_totusoku);
		}
		else if (m_totuc == HASSYAEND)
		{
			m_ugoki = 1;
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

	if (m_totuc == m_totufin)
	{
		m_totuc = M_TOTUC;
	}
	else
	{
		m_totuc--;
	}
	if (m_nowscore > 0)
	{
		m_nowscore--;
	}

}

void EnemyT::ActHudou()
{
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

void EnemyT::ActTate_U()
{
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	else if (m_kouc < KOUCFIN / 2)
	{
		m_enowpos.y += m_sokudo_y;
	}
	else
	{
		m_enowpos.y -= m_sokudo_y;
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

	if (m_kouc >= KOUCFIN)
	{
		m_kouc = 0;
	}
	else
	{
		m_kouc++;
	}
}

void EnemyT::ActTate_D()
{
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	else if (m_kouc < KOUCFIN / 2)
	{
		m_enowpos.y -= m_sokudo_y;
	}
	else
	{
		m_enowpos.y += m_sokudo_y;
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

	if (m_kouc >= KOUCFIN)
	{
		m_kouc = 0;
	}
	else
	{
		m_kouc++;
	}
}

void EnemyT::ActGurun_R()
{
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	//�E���ɉ�]���鏈��
	else
	{
		m_zrad = m_zrad + m_sokudo_xz;
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
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

void EnemyT::ActGurun_L()
{
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	//�E���ɉ�]���鏈��
	else
	{
		m_zrad = m_zrad - m_sokudo_xz;
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
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

void EnemyT::Haaku()
{
	/*
	//m_zrad = m_zrad % 360.0f;
	int dairi = m_zrad;
	//���𐮂���-360~360�܂łɂ����߂�
	dairi = dairi % 360;
	dairi = dairi - c_oresiten->Zrad;
	*/


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

void EnemyT::Anima()
{
	switch (m_ugoki)
	{
	case 0:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	case 1:
		m_ml.PlayAnimation(Clip_tyouhatu);
		break;
	case 2:
		m_ml.PlayAnimation(Clip_hassya);
		break;
	default:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	}
}


//�G�̑ޏ���ȒP�ɍs����N���X
void EnemyT::Taijou()
{
	m_enowpos = { 0.0f,TAIKIY,0.0f };

	//���W���f
	m_ml.SetPosition(m_enowpos);
	m_ml.Update();
	//�����蔻�蔽�f
	m_ecol->SetPosition(m_enowpos);
	m_ecol->Update();

	//�����Əo�Ԃ̃��Z�b�g
	m_shoken = 0;
	m_deban = 0;

	c_tse->Bye();
}

void EnemyT::Render(RenderContext& rc)
{
	if (m_deban == 1)
	{
		m_ml.Draw(rc);
	}
	

}


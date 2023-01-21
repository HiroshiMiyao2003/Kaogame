#include "stdafx.h"
#include "EnemyN.h"
#include "Testshot.h"
#include "MakeUI.h"
#include"Oresiten.h"

#include "graphics/effect/EffectEmitter.h"


EnemyN::~EnemyN()
{
	DeleteGO(m_ecol);
}


bool EnemyN::Start()
{
	//�A�j���[�V�����ǂݍ���
	m_anima[Clip_taiki].Load("Assets/enemy/hakoniwaN/Ntaiki.tka");
	m_anima[Clip_taiki].SetLoopFlag(true);
	m_anima[Clip_tyouhatu].Load("Assets/enemy/hakoniwaN/Ntyouhatu.tka");
	m_anima[Clip_tyouhatu].SetLoopFlag(true);
	m_anima[Clip_totugeki].Load("Assets/enemy/hakoniwaN/Ntotugeki.tka");
	m_anima[Clip_totugeki].SetLoopFlag(true);

	//���f���ǂݍ���
	m_ml.Init("Assets/enemy/hakoniwaN/hakoniwaN.tkm",m_anima,Clip_Num,enModelUpAxisZ);



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

	m_touE = NewGO <EffectEmitter>(1);
	m_touE->Init(1);

	return true;
}

void EnemyN::Update()
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


void EnemyN::Han()
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
		m_bakuE->SetScale(m_size * BAKUKAKE);
		m_bakuE->SetRotation(m_qua);
		m_bakuE->Play();

		//�e�ɑޏ��������
		if (m_ecol->IsHit(c_ts0->m_col))
		{
			c_ts0->Bye();
		}
		else if(m_ecol->IsHit(c_ts1->m_col))
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
		m_deban = 0;
		m_shoken = 0;
		//���_�̔��f
		c_makeui->ScoreAdd(m_nowscore);

	}
}

void EnemyN::Live()
{
	switch (m_act)
	{
	case 0:
		ActGuru();
		break;
	case 1:
		ActTotu();
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
		

		m_touE = NewGO <EffectEmitter>(1);
		m_touE->Init(1);

		m_touE->SetPosition(m_enowpos);
		m_touE->SetScale(m_size * TOUKAKE);
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
	//�o�ꂵ�Ă���J�E���g�Ɠ��_�J�E���g�̕ύX

	m_nowscore--;
	m_shoken++;
}

void EnemyN::ActGuru()
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

void EnemyN::ActTotu()
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
			/*
			m_hureichi.x = m_enowpos.x/ WARI;
			m_hureichi.z = m_enowpos.z/ WARI;
			m_hureichi.y = m_enowpos.y - 100.0f;
			m_hureichi.y = m_hureichi.y / WARI;
			*/
			
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
		m_etop = m_oreiru - m_enowpos;

		if (m_etop.Length() <= ZIBA)
		{
			m_enowpos = { 0.0f,TAIKIY,0.0f };

			//���W���f
			m_ml.SetPosition(m_enowpos);
			m_ml.Update();
			//�����蔻�蔽�f
			m_ecol->SetPosition(m_enowpos);
			m_ecol->Update();
			
			//�F�X���Z�b�g����
			m_ugoki = 0;
			m_shoken = 0;
			m_deban = 0;
			m_totusoku = M_TOTUC;
			//HP�����炷
			c_makeui->m_nowhp -= 1;

		}
		else
		{
			m_enowpos.x = m_enowpos.x - m_hureichi.x;
			m_enowpos.y = m_enowpos.y - m_hureichi.y;
			m_enowpos.z = m_enowpos.z - m_hureichi.z;
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

	m_totuc--;
}

void EnemyN::ActHudou()
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

void EnemyN::ActTate_U()
{
	//���̐��̃t���[���̂ݎ��s����鏈��
	if (m_kouc < 0)
	{
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
	}
	else if(m_kouc < KOUCFIN /2)
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

void EnemyN::ActTate_D()
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

void EnemyN::ActGurun_R()
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

void EnemyN::ActGurun_L()
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

void EnemyN::Haaku()
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
	if (dairi>SIYAKAKU||dairi<-SIYAKAKU)
	{
		//0.0f < dairi <= 180.0f or -180.0f > dairi > -360.0f(�E�ɓG�������Ƃ�)
		if (dairi <= 180.0f&&dairi > 0.0f || dairi < -180.0f&&dairi > -360.0f)
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

void EnemyN::Anima()
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
		m_ml.PlayAnimation(Clip_totugeki);
		break;
	default:
		m_ml.PlayAnimation(Clip_taiki);
		break;
	}
}

void EnemyN::Render(RenderContext& rc)
{
	if (m_deban == 1)
	{
		m_ml.Draw(rc);
	} 

}


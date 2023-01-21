#pragma once

class Testshot;
class Saisho;
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

class MakeUI :public IGameObject
{

public:

	//�I�����̏���
	~MakeUI();
	//�J�n���̏���
	bool Start();
	//���t���[�����s����鏈��
	void Update();
	//HP���m�F���邽�߂̏����B���t���[�����s�����
	void HPkaku();
	//�{�^�����͂��m�F���邽�߂̏����B���t���[�����s�����
	void Botakaku();
	//�e�̏o����Ԃ��m�F���邽�߂̏����B���t���[���s����
	void Tamakaku();
	//�e�̃N�[���^�C�����Ǘ����鏈���B���t���[���s����
	void Cool();
	//�N���X�w�A��`�����ǂ������߂鏈���g���Ă��Ȃ�
	void Crosskime();
	//HP�̕`����ǂ����邩���߂鏈���B���t���[���s����
	void Hpkime();
	//�G�N���X���瑗���Ă����������ƂɁA�G�x���̕`������邩�ǂ��������߂鏈���B
	void Keikime();
	//�_���[�W�`�ʃ��[�h�̎��Ɏ��s����鏈��
	void Damemode();
	//���t���[���`��̂��߂ɂȂ���鏈��
	void Render(RenderContext& rc);

	//�e�̔��˂𕕈󂵁A�N���X�w�A���\���ɂ���֐�
	void Lock()
	{
		m_lock = 1;
		m_cross.SetPosition(TAIKITEN);
		m_cross.Update();
	};
	//�e�̔��˂����ւ��A�N���X�w�A��\��������֐�
	void UnLock()
	{
		m_lock = 0;
		m_cross.SetPosition(GENTEN);
		m_cross.Update();
	}
	//���_�����Z�����鏈��
	void ScoreAdd(int as)
	{
		m_score += as;
		wchar_t wcsbuf[256];
		swprintf_s(wcsbuf, 256, L"SCORE %07d", int(m_score));

		m_scoren.SetText(wcsbuf);

	}


	//HP�̌��ݒl
	int m_nowhp = 1;

	//�E�x�����o�����ǂ����B�P�ŏo��
	int m_keiR = 0;
	//���x�����o�����ǂ����B�P�ŏo��
	int m_keiL = 0;

	//���b�N�B0�����ցA�P���֎~
	int m_lock = 0;

private:
	//�e�X�g�V���b�g�N���X
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;

	//�ŏ��N���X
	Saisho* c_saisho;

	

	//�e�X�g�V���b�g�̏�Ԋm�F�B1�Ȃ�o�����A0�Ȃ�ҋ@���B
	int m_tsjoutai[6] = {0,0,0,0,0,0};

	//���̒e�����Ă�܂ł̃N�[���^�C��
	const int COOLTIME = 8;
	//�N�[���^�C���J�E���g
	int m_cool = 0;

	//�N���X�w�A�S���G�t
	SpriteRender m_cross;
	//HP�S���G�t�̊F�l�B�������傫���G�t���S�����Ă���HP�قǐ^����ɂȂ��Ȃ�
	SpriteRender m_hp1;
	SpriteRender m_hp2;
	SpriteRender m_hp3;
	SpriteRender m_hp4;
	SpriteRender m_hp5;
	SpriteRender m_hp6;
	SpriteRender m_hp7;
	SpriteRender m_hp8;
	SpriteRender m_hp9;
	SpriteRender m_hp10;
	//HP�i��j�S���G�t�̊F�l
	SpriteRender m_hpk1;
	SpriteRender m_hpk2;
	SpriteRender m_hpk3;
	SpriteRender m_hpk4;
	SpriteRender m_hpk5;
	SpriteRender m_hpk6;
	SpriteRender m_hpk7;
	SpriteRender m_hpk8;
	SpriteRender m_hpk9;
	SpriteRender m_hpk10;
	//�G��UI�S���G�t�̊F�l
	SpriteRender m_eneR;
	SpriteRender m_eneL;
	//�_���[�W�\���S���G�t�݂̂Ȃ���
	SpriteRender m_redda0;
	SpriteRender m_redda1;
	SpriteRender m_redda2;
	
	//HP�̏���l
	const int HPMAX = 10;

	//�O�t���[����HP���L�^����ϐ�
	int m_beforeHP = m_nowhp;

	//�_���[�W�`�ʃ��[�h���s�ϐ��A���i��-1
	int m_dacount = -1;
	//�_���[�W�`�ʃ��[�h���n�܂��Ă���I���܂ł̎��Ԃ�3���̂P�̒l
	const int DAMEFIVE = 10;

	//�X�R�A
	long int m_score = 0;

	FontRender m_scoren;
	FontRender m_scoren2;

	//���_
	const Vector3 GENTEN ={0.0f,0.0f,0.0f};
	//�ҋ@�_
	const Vector3 TAIKITEN = { 0.0f,2000.0f,0.0f };

};
/*
MakeUI�N���X�͂��ׂẴX�e�[�W�ɂ����ČĂяo�����N���X�ł�
�������g�̒e�̐e�N���X�ł�����܂�
��Ƀv���C���[�̏�Ԃ��Ǘ����A�Q�[���̐R���I�������͂����Ă��܂�
�Ȃ��A�Q�[���I�[�o�[�͊e�X�e�[�W�\����S�����Ă���N���X�������ǂ��Ă��܂��B
*/

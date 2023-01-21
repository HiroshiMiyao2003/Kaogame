#pragma once

class Testshot;
class MakeUI;
#include "sound/SoundSource.h"


class Heart :public IGameObject
{
public:
	//��������Ƃ��̏���
	~Heart();
	//�������Ɏ��s����鏈��
	bool  Start();
	//���t���[���s���鏈��
	void Update();

	//�����ꂽ���ǂ����̔���
	void Han();
	//���������̏���
	void MoveH();
	//���t���[���`��̂��߂ɂȂ���鏈��
	void Render(RenderContext& rc);



	//�o�Ԃ��ǂ������Ǘ�����ϐ��B0�Ȃ�ҋ@�A�P�Ȃ�o��
	int m_deban = 0;

	//�����ʒu���L�^����ϐ�����
	Vector3 m_firstpos;
	//1�t���[�����ƂɈړ�����x�N�g�������߂�ϐ�����
	Vector3 m_idouv;
	//���ł���t���[�������L�^����ϐ�
	int m_finalf = 9999;

	//Heart�N���X���o�����߂̐ݒ���s���֐��B�������W�A�ړ��x�N�g���A���Ńt���[������`����
	
	//�n�[�g��o�ꂳ���郁�\�b�h�Bp�������ʒu�Ai���P�t���[�����ƂɈړ����钷���Af�����ł���^�C�~���O
	void Toujou(Vector3 p, Vector3 i, int f)
	{
		m_firstpos = p;
		m_idouv = i;
		m_finalf = f;
		m_deban = 1;
		m_ensou->Play(true);
		m_ensou->SetVolume(1.0f);
	};
	

	//�z�ɂ��邽�߂̕ϐ��A1�Ȃ�z����
	int jun = 0;

private:
	//3D���f���S���G�t
	ModelRender m_ml;
	//���t��
	SoundSource* m_ensou;
	//��]�E�l
	Quaternion m_qua;
	//�����蔻��
	CollisionObject* m_hcol;
	//���W
	Vector3 m_hnowpos;
	//�R���W�����T�C�Y
	Vector3 COLXYZ = {20.0f,20.0f,20.0f};

	//ts�N���X
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;
	//UI�N���X
	MakeUI* c_makeui;

	//�ҋ@�ʒu��Y���W�̐ݒ�
	const float TAIKIY = -400.0f;

	//�����G�t�F�N�g�E�l
	EffectEmitter* m_bakuE = nullptr;
	//�����G�t�F�N�g�̑傫����ς��邽�߂ɓ����蔻��ɂ�����l
	const float BAKUKAKE = 0.2f;

	//�o�ꂵ�Ă���̃t���[�������J�E���g��������ϐ�
	int m_myaku = 0;

	//HP�̉񕜗�
	int KAIHUKU = 1;


};


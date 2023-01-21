#pragma once


class Daichi;
class Oresiten;
class MakeUI;

class EnemyT;
class EnemyN;
class Heart;
class Boss;

class NowLo;
class OverGame;

class Ikusa00 :public IGameObject
{

public:
	~Ikusa00();
	bool Start();
	void Update();
	//�����݂̃v���C���[�̗̑͂��m�F���A���₦�Ă�����Q�[���I�[�o�[���Ăяo������
	void Kaku();

	//�q�N���X�݂̂Ȃ���
	SkyCube* m_skyCube = nullptr;
	Daichi* c_daichi;
	Oresiten* c_oresiten;
	MakeUI* c_makeui;

	//�Ăяo�����G�݂̂Ȃ���


	EnemyN* c_enen0;
	EnemyN* c_enen1;
	EnemyN* c_enen2;
	EnemyN* c_enen3;
	EnemyN* c_enen4;

	EnemyT* c_enet0;

	Heart* c_heart0;

	Boss* c_boss;

private:
	//�X�e�[�W���n��
	int m_zikei = 0;
	//���n��J�E���g�B���n�񂪏オ��x�Ƀ��Z�b�g�����
	int m_zc = 0;
	//�i�E�����
	NowLo* c_nl;
	//�Q�[���I�[�o�[���
	OverGame* c_og;

	//�n�[�g�P��ڂ̏��X�̃f�[�^
	//�n�[�g�����ʒu
	Vector3 HEARTP = {80.0f,100.0f,50.0f};
	//�n�[�g�̃x�N�g��
	Vector3 HEARTV = {0.0f,0.0f,-0.3f};
	//�n�[�g�̏��Ńt���[��
	int HEARTF = 600;

};


#pragma once

#include "sound/SoundSource.h"

class Daichi;
class Oresiten;
class MakeUI;


class EnemyN;
class Heart;

class NowLo;
class OverGame;
class Title;
class Ikusa01;

class IkusaT :public IGameObject
{

public:
	~IkusaT();
	bool Start();
	void Update();
	//�����݂̃v���C���[�̗̑͂��m�F���A���₦�Ă�����Q�[���I�[�o�[���Ăяo������
	void Kaku();
	//���n��O�̎��̂ݍs���鏈��
	void ZikeiZero();
	void Zikei_1();
	void Zikei_2();
	void Zikei_3();
	void Zikei_4();
	void Zikei_4_5();
	void Zikei_5();
	void Zikei_6();
	void Zikei_7();
	void Zikei_8();
	void Zikei_9();
	void Zikei_10();
	void Zikei_11();

	void Zikei_Yes();
	void Zikei_No();

	void UpZikei();
	void Render(RenderContext& rc);

private:

	//�X�e�[�W���n��
	double m_zikei = 0.0;
	//���n��J�E���g�B���n�񂪏オ��x�Ƀ��Z�b�g�����
	int m_zc = 0;
	//�I���J�E���g�A�͂���1�������͂O�f�t�H���g�͂Q
	int m_yn = 2;

	//�K�C�h�p�̊G�t����
	SpriteRender m_gairo1;
	SpriteRender m_gairo2;
	SpriteRender m_gairo3;
	SpriteRender m_gairo4;
	SpriteRender m_gairo5;
	SpriteRender m_gairo6;
	SpriteRender m_gairo7;
	SpriteRender m_gairo8;
	SpriteRender m_gairo9;
	SpriteRender m_gairo0;

	Vector3 DEBANV{0.0f,0.0f,0.0f};
	Vector3 TAIKIV{ 0.0f,2000.0f,0.0f };
	//�i�E�����
	NowLo* c_nl;




	//��{�I�ȑ��x
	const float ENESOKUX = 1.0f;
	const float ENESOKUY = 0.5f;

	//���n��2�̓G���
	const int ENEACT_2_1 = 2;
	const float ENERAD_2_1 = 0.0f;
	const float ENEKYORI_2_1 = 100.0f;
	const float ENEKOUDO_2_1 = 100.0f;


	//���n��4�̓G���
	const int ENEACT_4_1 = 2;
	const float ENERAD_4_1 = 100.0f;
	const float ENEKYORI_4_1 = 100.0f;
	const float ENEKOUDO_4_1 = 100.0f;

	//���n��8�̃n�[�g���
	const Vector3 HEAFIRST_8 = { 85.0f,100.0f,100.0f };
	const Vector3 HEAIDOU_8 = { 0.0f,0.0f,-1.0f };
	const float HEAEND_8 = 200;

	//�q�N���X�݂̂Ȃ���
	SkyCube* m_skyCube = nullptr;
	Daichi* c_daichi;
	Oresiten* c_oresiten;
	MakeUI* c_makeui;

	Title* c_title;
	Ikusa01* c_ikusa01;

	//�Ăяo�����G�݂̂Ȃ���
	EnemyN* c_enen0;
	EnemyN* c_enen1;

	Heart* c_heart0;

};
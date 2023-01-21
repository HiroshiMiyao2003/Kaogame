#pragma once

class Oresiten;
class MakeUI;
class Testshot;

class TestshotE :public IGameObject
{

public:
	~TestshotE();
	bool Start();
	void Update();
	//�v���C���[�e�ɓ����������ǂ������肷�鏈��
	void Han();
	//�L�����R���̑���ɒe�𓮂�������
	void Move();
	//�e��o�ꂳ�������ɂ̂ݎ��s����鏈��
	void Toujo();
	//�ޏꂳ���鏈��
	void Bye();
	void Render(RenderContext& rc);

	//�G�e��o�ꂳ���鏈���Bpos�͒e�̏����ʒu�Asoku�͒e�̑��x
	void ToujoSiro(Vector3 pos,float soku)
	{
		m_nowpos = pos;

		m_totusoku = soku;

		m_taideba = 1;

	}


	Vector3 m_tamaend;
	ModelRender m_modelrender;



	//�ҋ@���o�Ԃ��ҋ@�͂O�A�o�Ԃ͂P
	int m_taideba = 0;

	//�R���W�����I�u�W�F�N�g
	CollisionObject* m_col;

private:

	//�ҋ@�ꏊ��Y���W
	const float MACHIY = -500.0f;

	//�e�̍��̍��W
	Vector3 m_nowpos;
	//�ˌ����x�����߂鐔�l�B���K�����ꂽ���x�l�ɂ�����̂ŁA���x�Ɛ��l�̑傫������Ⴗ��
	float m_totusoku = 5.0f;
	

	int m_count;

	//�P�t���[�����ƂɈړ������鋗�����L�^����ϐ�
	Vector3 m_hureichi;
	//�P�t���[�����ƂɈړ����鑬�x�����߂銄��Z�̕���B���̒l��傫������΂���قǑ��x�͒x���Ȃ�
	const float  WARI = 0.30f;

	//�v���C���[�̍��W
	const Vector3 m_oreiru = { 0.0f,100.0f,0.0f };
	//�G�e����v���C���[�ւ̃x�N�g��
	Vector3 m_etop;
	//���������s�����v���C���[�ƓG�Ƃ̋���
	const float ZIBA = 50.0f;


	//�R���W�����̃T�C�Y
	const float COLXYZ = 15.0f;
	Vector3 m_size;


	//�����G�t�F�N�g�E�l
	EffectEmitter* m_bakuE = nullptr;
	//�����G�t�F�N�g�̑傫����ς��邽�߂ɓ����蔻��ɂ�����l
	const float BAKUKAKE = 0.15f;

	//�ق��̃N���X����
	Oresiten* c_oresiten;
	MakeUI* c_makeui;

	//ts�N���X
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;
};


#pragma once

class Oresiten;

class Testshot :public IGameObject
{

public:
	~Testshot();
	bool Start();
	void Update();
	//�L�����R���̑���ɒe�𓮂�������
	void Move();
	//�e��o�ꂳ�������ɂ̂ݎ��s����鏈��
	void Toujo();
	//�ޏꂳ���鏈��
	void Bye();
	void Render(RenderContext& rc);


	//CharacterController m_characon;

	Vector3 m_tamaend;

	Oresiten* m_oresiten;

	ModelRender m_modelrender;

	//�e�̍��̍��W
	Vector3 m_nowpos;
	//�ҋ@���o�Ԃ��ҋ@�͂O�A�o�Ԃ͂P
	int m_taideba = 0;

	//�R���W�����I�u�W�F�N�g
	CollisionObject* m_col;

private:

	//�ҋ@�ꏊ��Y���W
	const float MACHIY = -100.0f;

	//���ł܂ł̌ۓ�
	int m_count;
	//���ł̃^�C�~���O
	const int SAYONARA = 34;
	//�e�̕`�悪�n�܂�^�C�~���O
	const int KAKIHAZI = 4;

	//�P�t���[�����ƂɈړ������鋗�����L�^����ϐ�
	Vector3 m_hureichi;
	//�P�t���[�����ƂɈړ����鑬�x�����߂銄��Z�̕���B���̒l��傫������΂���قǑ��x�͒x���Ȃ�
	const float  WARI = 0.30f;


	//�R���W�����̃T�C�Y
	const float COLXYZ = 10.0f;
};


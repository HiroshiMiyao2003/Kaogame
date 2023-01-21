#pragma once



class Oresiten :public IGameObject
{

public:
	~Oresiten();
	bool Start();
	void Update();
	//���_���璍���_�ւ̃x�N�g�����v�Z����֐�
	void Keisan();
	//��]����
	void Rotation();

	//�`�����o�ϐ��`

//�ߕ��ʂ̒l
	const float KINHEI = 1.0f;
	//�����ʂ̒l
	const float ENHEI = 40000.0f;
	//�����_�̈ʒu�̒l�Z�b�g
	 float TARX = 0.0f;
	 float TARY = 100.0f;
	 float TARZ = 50.0f;
	 //�����_��\�����W
	 Vector3 m_tar;

	//���_�̈ʒu�̒l�Z�b�g
	const float POSX = 0.0f;
	const float POSY = 100.0f;
	const float POSZ = 0.0f;
	//���_��\�����W
	Vector3 m_position;

	//������\���x�N�g��
	Vector3 m_sisen;
	//�t������\���x�N�g��
	Vector3 m_sisen_gyaku;

	//�J������]�p�N�H�[�^�j�I��
	Quaternion m_kamekaku;
	//�~����
	double PAI = 3.14159265359;
	//�����������Ă���p�x0~359�܂ł���Ǝv����
	float Zrad = 0.0f;
	//�����W���C�X�e�B�b�N��X�l������ϐ�
	float m_ljoyx;
	//�����W���C�X�e�B�b�N��Y�l������ϐ�
	float m_ljoyy;
	//����������ϐ�
	void Lock()
	{
		m_lock = 1;
	};
	//������������ϐ�
	void UnLock() 
	{
		m_lock = 0;
	};

private:
	//����������l
	const float UEGEN = 103.0f;
	//�����������l
	const float SITAGEN = 100.0f;

	//�J������XZ���x
	const float KANDOXZ = 0.15f;
	//�J������Y���x
	const float KANDOY = 0.15f;

	//�_�b�V�����ɂ����鐔�l
	const float DASH = 1.5f;

	//����\���ϐ��A�P�����b�N���
	int m_lock = 0;

	//�ŏ���sisen��Y�̒l���L�^����ϐ�
	float FIRSTSISENY;

	//�|�C���g���C�g
	PointLight c_poi;
};

#pragma once

class Ikusa00;
class Title;

class Saisho:public IGameObject
{

public:
	~Saisho();
	bool Start();
	void Update();

	//���ׂĂ̏�ʂɂ����Ďg�p�\�ȕϐ�
	
	//�ǂ̃X�e�[�W��ǂݍ��ނ����w������ϐ��A�P�Ȃ�i�[��
	int m_stage = 0;
	//bgm����
	float m_bgmnum;
	//se����
	float m_senum;
	//�������x
	float m_kandXZnum;
	//�c�����x
	float m_kandoYnum;

	//���_
	long int m_score;

	Ikusa00* m_ikusa00;
	Title* c_title;
	std::vector<PointLight*>	m_pointLightList;
};


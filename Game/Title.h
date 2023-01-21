#pragma once

class IkusaT;
class Ikusa00;
class Ikusa01;
class IkusaW;
class NowLo;

class Saisho;

#include "sound/SoundSource.h"

class Title :public IGameObject
{
public:
	~Title();
	bool Start();
	void Update();
	//������󂯕t����
	void Sousa();
	//����ɑ΂��锽�f
	void Hanei();
	//sizi�̕��������������ɓ_�ł�����
	void Tenmetu();
	void Render(RenderContext& rc);

private:
	//�_�ł����邽�߂̃J�E���g
	int m_tc = 0;
	//�_�ŉ��Z�����Z���̏���.�P�Ȃ猸�Z
	int m_tenhan = 1;
	//�A���t�@�l�����߂鐔�l
	float m_aru = 1.0f;
	//�_�ł̏��
	const int  TENGEN = 120;

	//�X�e�[�W0
	Ikusa00* c_ikusa00;
	//�X�e�[�W1
	Ikusa01* c_ikusa01;
	//�X�e�[�WT
	IkusaT* c_ikusaT;
	//�X�[�e�W
	IkusaW* c_ikusaW;
	//���t���[���̉^�������߂鏈���B
	int m_nextfate = -1;
	//�X�e�[�W�ǂݍ��݂��n�܂�^�C�~���O
	const int YOMIHAZI = 10;

	//�J�[�\���̌��݈ʒu�B�O���J�n�A2���ݒ�
	int m_kasorupos = 0;
	//�^�C�g����ʂɂ���{�^���̑���
	int SOUSUU = 2;

	//�J�n�{�^����Y���W
	const Vector3 KAISI = {0.0f,-400.0f,0.0f };
	//�ݒ�{�^����Y���W
	const Vector3 TUTO = {0.0f, -530.0f ,0.0f};
	//�ݒ�{�^����Y���W
	const Vector3 SETTEI = { 0.0f, -660.0f ,0.0f };

	//�^�C�g���̃x�[�X��ʊG�t
	SpriteRender m_base;
	//�J�n�{�^���G�t
	SpriteRender m_kaisi;
	//�����L���O�{�^���G�t
	SpriteRender m_tuto;
	//�ݒ�{�^���G�t
	//SpriteRender m_settei;
	//�J�[�\���G�t
	SpriteRender m_kasoru;
	//�w���G�t
	SpriteRender m_sizi;

	//�����I�t�H���g�G�t�i���Ƃł����j
	FontRender m_zikken;

	//BGM
	SoundSource* m_bgm;

	//�i�E���[�f�B���O�N���X
	NowLo* c_nowlo;

	//�ŏ��N���X
	Saisho* c_saisho;

};


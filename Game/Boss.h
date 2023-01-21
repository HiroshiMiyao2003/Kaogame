#pragma once

class Testshot;
class MakeUI;
class Oresiten;

class EnemyN;
class EnemyT;

class Boss :public IGameObject
{
public:
	~Boss();
	bool Start();
	void Update();
	//�����ꂽ���ǂ����̔���
	void Han();
	//�o�Ԃ̎��̍s���p�^�[�������߂�֐�
	void Live();
	//�o�ꂷ�鏈���B�P�Ŕ���
	void ActToujou();
	//������W�������Ȃ��s���B2�Ŕ���
	void ActHudou();
	//�E�Ƀ��[�v���鏈���A3�Ŕ���
	void ActWarpR();
	//���Ƀ��[�v���鏈���A4�Ŕ���
	void ActWarpL();
	//�������鏈���B5�Ŕ���
	void ActSuki();
	//��鏈���B6�Ŕ���
	void ActMamori();
	//����Ă�낯�鏈��
	void ActYarare();
	//�����Ǝ��E�̈ʒu�֌W��c������MakeUI�N���X�ɏ��𑗂����肷��֐�
	void Haaku();
	//�A�j���[�V����
	void Anima();
	//���t���[���`��̂��߂ɂȂ���鏈��
	void Render(RenderContext& rc);

	//�A�j���[�V�����W
	enum EnAnimationClip
	{
		Clip_taiki,//�ҋ@
		Clip_toujou,//�o��
		Clip_warpR,//���[�vR
		Clip_warpL,//���[�vL
		Clip_suki,//��
		Clip_bou,//�h��
		Clip_yarare,//����
		Clip_Num
	};

	//�G���g�̌��݈ʒu
	Vector3 m_enowpos;

	//�o�Ԃ��ǂ������Ǘ�����ϐ��B0�Ȃ�ҋ@�A�P�Ȃ�o�ԁA�����l��0
	int m_deban = 0;

	//�G�̍s���p�^�[�������߂�ϐ�
	int m_act = 0;
	//�G�����G���ǂ��������߂�N���X�B�P�Ȃ疳�G
	int m_muteki = 0;

	//�G�̉�]�p�x�����߂�ϐ��B�ǂ��������Ɉړ����邩�ɂ���Đ��l���ς�邽�߃f�t�H���g�ł͂O�ɂȂ��Ă���
	float m_zrad;

	//�G�ƃv���C���[�Ƃ̋��������߂�ϐ�
	float m_kyori = 75.0f;

	//�G��Y���W�����߂�ϐ�
	float m_koudo = 100.0f;

	//�����Ǝ��E�̈ʒu��c�����Ă���ɂ���ĕς��ϐ��B���E�O�E�Ȃ�P�A���E�O���Ȃ�Q
	int m_sikasoto = 0;

	//�G�̓o����ȒP�ɍs����N���X�Br�͊p�x�Ak�͋����At�͍��x�ɂȂ�
	void ToujouKani(float r, float k, float t)
	{
		m_deban = 1;

		m_act = 1;
		m_muteki = 1;

		m_zrad = r;
		m_kyori = k;
		m_koudo = t;

		//�Ƃ肠�����̍��W�����߂Ă���鏈��
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;

		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
	};

	//�{�X��HP
	int m_bosshp = 5;
	//���[�v���Ă邩�ǂ����B�P�Ȃ炵�Ă���
	int m_warp = 0;

private:
	//3D���f���S���G�t
	ModelRender m_ml;
	//��]�E�l
	Quaternion m_qua;

	//�A�j���[�V����
	AnimationClip m_anima[Clip_Num];
	//�A�j���[�V�����w��
	int m_ugoki = 0;

	//�����G�t�F�N�g�E�l
	EffectEmitter* m_bakuE = nullptr;
	//�����G�t�F�N�g�̑傫����ς��邽�߂ɓ����蔻��ɂ�����l
	const float BAKUKAKE = 0.2f;

	//�z�I�s���p�^�[������J�E���g�B
	int m_kouc = -1;
	//ts�N���X
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;
	//UI�N���X
	MakeUI* c_makeui;
	//���_�N���X
	Oresiten* c_oresiten;

	//�����̈�ʕ��N���X
	EnemyN* c_buka2;

	//�����̑�C���N���X
	EnemyT* c_buka1;

	//�ҋ@�ʒu��Y���W�̐ݒ�
	const float TAIKIY = -400.0f;
	//�R���W�����I�u�W�F�N�g
	CollisionObject* m_ecol;
	//�R���W�����̃T�C�Y
	const float ECOLXYZ = 30.0f;
	//�R���W�����̃T�C�Y�x�N�g��
	Vector3 m_size;
	//����p�̒�`
	const float SIYAKAKU = 55.0f;
	//�~����
	const double PAI = 3.14159265359;
	//�R���W�����̃T�C�Y
	const float COLXYZ =30.0f;

	//���Ă����̓��_
	const int ATESCORE = 3000;
	//���j�������̓��_
	const int GEKIHASCORE = 10000;

	//�����̃f�[�^
	const int ENEACT_B1 = 2;
	const float ENEKYORI_B1 = m_kyori + 50.0f;
	const float ENEKOUDO_B1 = m_koudo + 50.0f;

	const int ENEBEF_B1 = 120;
	const int ENEAFT_B1 = 180;
	const float ENETOTUSOKU_B1 = 1.0f;

};


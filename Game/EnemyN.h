#pragma once

class Testshot;
class MakeUI;
class Oresiten;

class EnemyN :public IGameObject
{

public:
	~EnemyN();
	bool Start();
	void Update();
	//�����ꂽ���ǂ����̔���
	void Han();
	//�o�Ԃ̎��̍s���p�^�[�������߂�֐�
	void Live();
	//�������E�ɒ��r���[�ɉ�邾���̍s���B0�Ŕ���
	void ActGuru();
	//�ˌ����s���s���B1�Ŕ���
	void ActTotu();
	//������W�������Ȃ��s���B2�Ŕ���
	void ActHudou();
	//�㉺�ɓ����Ē�������s���B3�Ŕ���
	void ActTate_U();
	//����ɓ����Ē�������s���B4�Ŕ���
	void ActTate_D();
	//�Ђ����玞�v���ɉ�葱���Ȃ��璧������s���B5�Ŕ���
	void ActGurun_R();
	//�Ђ����甽���v���ɉ�葱���Ȃ��璧������s���B6�Ŕ���
	void ActGurun_L();
	//�����Ǝ��E�̈ʒu�֌W��c������MakeUI�N���X�ɏ��𑗂����肷��֐�
	void Haaku();
	//�A�j���[�V����
	void Anima();
	//���t���[���`��̂��߂ɂȂ���鏈��
	void Render(RenderContext& rc);

	//�G���g�̌��݈ʒu
	Vector3 m_enowpos;

	//�o�Ԃ��ǂ������Ǘ�����ϐ��B0�Ȃ�ҋ@�A�P�Ȃ�o�ԁA�����l��0
	int m_deban = 0;

	//�G�̍s���p�^�[�������߂�ϐ�
	int m_act = 0;

	//�G�̉�]�p�x�����߂�ϐ��B�ǂ��������Ɉړ����邩�ɂ���Đ��l���ς�邽�߃f�t�H���g�ł͂O�ɂȂ��Ă���
	float m_zrad;

	//�G�ƃv���C���[�Ƃ̋��������߂�ϐ�
	float m_kyori = 75.0f;

	//�G��Y���W�����߂�ϐ�
	float m_koudo = 100.0f;

	//������XZ���x�����߂�ϐ�
	float m_sokudo_xz = 1.0f;
	//������Y���x�����߂�ϐ�
	float m_sokudo_y = 0.5f;

	//�����Ǝ��E�̈ʒu��c�����Ă���ɂ���ĕς��ϐ��B���E�O�E�Ȃ�P�A���E�O���Ȃ�Q
	int m_sikasoto = 0;

	//�A�j���[�V�����W
	enum EnAnimationClip
	{
		Clip_taiki,//�ҋ@
		Clip_tyouhatu,//����
		Clip_totugeki,//�ˌ�
		Clip_Num
	};

	//�G�̓o����ȒP�ɍs����N���X�Ba�͍s���p�^�[���Ar�͊p�x�Ak�͋����At�͍��x�ɂȂ�
	void Toujou(int a,float r,float k,float t,float x,float y)
	{
		m_deban = 1;
		
		m_act = a;
		m_zrad = r;
		m_kyori = k;
		m_koudo = t;
		m_sokudo_xz = x;
		m_sokudo_y = y;
		//�Ƃ肠�����̍��W�����߂Ă���鏈��
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
		
		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
	};
	//�o��ς݂̓G�ɓˌ������郁�\�b�h�As�̓X�s�[�h�At�͓ˌ��܂ł̗P�\�t���[����
	void Totusiro(float s,float t)
	{
		m_totuc = t;
		m_totusoku = s;
		m_act = 1;
	}

private:
	//3D���f���S���G�t
	ModelRender m_ml;
	//��]�E�l
	Quaternion m_qua;


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
	//�ҋ@�ʒu��Y���W�̐ݒ�
	const float TAIKIY = -400.0f;

	//�R���W�����I�u�W�F�N�g
	CollisionObject* m_ecol;
	//�R���W�����̃T�C�Y
	const float ECOLXYZ = 30.0f;
	//�R���W�����̃T�C�Y�x�N�g��
	Vector3 m_size;
	//�z�I�s���p�^�[������J�E���g�B
	int m_kouc = -1;
	//�z�I�s���p�^�[������J�E���g�̂����Z�b�g����l
	const int KOUCFIN = 120;
	//�G�̑��x
	const float SOKUDO = 0.1f;

	//�ˌ��s���p�^�[������J�E���g
	int m_totuc = M_TOTUC;
	//m_totuc�����l
	const int M_TOTUC = 60;
	//1�t���[�����ƂɈړ����鋗�����L�^����ϐ�
	Vector3 m_hureichi;
	//�ˌ����x�����߂鐔�l�B���K�����ꂽ���x�l�ɂ�����̂ŁA���x�Ɛ��l�̑傫������Ⴗ��
	float m_totusoku = 5.0f;
	//���������s�����v���C���[�ƓG�Ƃ̋���
	const float ZIBA = 60.0f;

	//�v���C���[�̍��W
	const Vector3 m_oreiru = {0.0f,100.0f,0.0f};
	//�G����v���C���[�ւ̃x�N�g��
	Vector3 m_etop;

	//�G�ƒ����_�Ƃ̊p�x��������ϐ�
	float m_ttkaku;
	//���ʂƒ����_�Ƃ̊p�x��������ϐ�
	float m_shoutar;
	//���ʂƓG���g�Ƃ̊p�x��������ϐ�
	float m_shouene;

	//����p�̒�`
	const float SIYAKAKU = 55.0f;



	//�~����
	const double PAI = 3.14159265359;
	//�R���W�����̃T�C�Y
	const float COLXYZ = 20.0f;

	//�A�j���[�V����
	AnimationClip m_anima[Clip_Num];
	//�A�j���[�V�����w��
	int m_ugoki = 0;

	//�����G�t�F�N�g�E�l
	EffectEmitter* m_bakuE = nullptr;
	//�����G�t�F�N�g�̑傫����ς��邽�߂ɓ����蔻��ɂ�����l
	const float BAKUKAKE = 0.2f;

	//�o��G�t�F�N�g�E�l
	EffectEmitter* m_touE = nullptr;
	//�o��G�t�F�N�g�̑傫����ς��邽�߂ɓ����蔻��ɂ�����l
	const float TOUKAKE = 0.2f;
	//�o�ꎞ�ɉ��Z����A�ޏꎞ�Ɍ��Y�����ϐ�
	int m_shoken;
	//�o��G�t�F�N�g���Ȃ��Ȃ�Ƃ�
	const int TOUESTOP = 30;

	//�X�R�A�ő�l
	const int MAXSCORE = 2001;
	//�����݁A���̓G�������Ă���X�R�A
	int m_nowscore;


};




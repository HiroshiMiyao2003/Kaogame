#pragma once

class TheSky;
class Daichi;
class Oresiten;
class MakeUI;

class EnemyN;
class EnemyT;
class Heart;
class Boss;

class NowLo;
class OverGame;
class Title;
class Kekka;

class IkusaW :public IGameObject
{
public:
	~IkusaW();
	bool Start();
	void Update();
	//今現在のプレイヤーの体力を確認し、息絶えていたらゲームオーバーを呼び出す処理
	void Kaku();
	//時系列０の時のみ行われる処理
	void ZikeiZero();
	//時系列ごとの処理
	void Zikei_1();
	void Zikei_2();
	void Zikei_3();
	void Zikei_4();
	void Zikei_5();
	void Zikei_6();

	//時系列を上げる処理
	void UpZikei();
	//毎フレーム描画のためになされる処理
	void Render(RenderContext& rc);

	//ステージ時系列
	int m_zikei = 0;
	//時系列カウント。時系列が上がる度にリセットされる
	int m_zc = 0;
	//ウェーブカウント
	int m_wave = 1;


private:

	//ナウロ画面
	NowLo* c_nl;
	//ゲームオーバー画面
	OverGame* c_og;
	//タイトル画面
	Title* c_title;
	//結果画面
	Kekka* c_kekka;

	//子クラスのみなさん
	SkyCube* m_skyCube = nullptr;
	TheSky* c_thesky;
	Daichi* c_daichi;
	Oresiten* c_oresiten;
	MakeUI* c_makeui;

	//呼び出される敵のみなさん
	EnemyN* c_enen0;
	EnemyN* c_enen1;
	EnemyN* c_enen2;
	EnemyN* c_enen3;
	EnemyN* c_enen4;
	EnemyN* c_enen5;

	EnemyT* c_enet0;
	Boss* c_boss;
	Heart* c_heart0;

	//BGM
	SoundSource* m_bgm01;
	SoundSource* m_bgm02;

	//基本的な速度
	const float ENESOKUX = 1.0f;
	const float ENESOKUY = 0.5f;

	//時系列１
	const int ENEACT_1_1 = 2;
	const float ENERAD_1_1 = 0.0f;
	const float ENEKYORI_1_1 = 100.0f;
	const float ENEKOUDO_1_1 = 100.0f;

	const float ENERAD_1_2 = -30.0f;
	const float ENERAD_1_3 = 30.0f;

	//時系列2の敵情報
	const int ENEACT_2_1 = 4;
	const float ENERAD_2_1 = -40.0f;
	const float ENEKYORI_2_1 = 120.0f;
	const float ENEKOUDO_2_1 = 130.0f;

	const int ENEACT_2_2 = 3;
	const float ENERAD_2_2 = 0.0f;
	const float ENEKYORI_2_2 = 120.0f;
	const float ENEKOUDO_2_2 = 100.0f;

	const int ENEACT_2_3 = 4;
	const float ENERAD_2_3 = 40.0f;
	const float ENEKYORI_2_3 = 120.0f;
	const float ENEKOUDO_2_3 = 130.0f;

	//時系列3の敵情報
	const int ENETOU_3_1 = 50;
	const int ENETOU_3_2 = 110;
	const int ENETOU_3_3 = 170;

	const int ENEACT_3_1 = 5;
	const float ENERAD_3_1 = 20.0f;
	const float ENEKYORI_3_1 = 115.0f;
	const float ENEKOUDO_3_1 = 120.0f;
	const float ENESOKUX_3_1 = 1.1f;

	//時系列4
	const int ENETOU_4_1 = 90;
	const int ENETOU_4_2 = 150;
	const int ENETOU_4_3 = 210;
	const float ENEKYORI_4_1 = 115.0f;
	const float ENEKOUDO_4_1 = 120.0f;
	const float ENESOKUX_4_1 = 0.9f;

	const int ENEACT_4_1 = 6;
	const float ENERAD_4_1 = 20.0f;

	//時系列5の敵情報
	const int ENEACT_5_1 = 4;
	const float ENERAD_5_1 = 0.0f;
	const float ENEKYORI_5_1 = 130.0f;
	const float ENEKOUDO_5_1 = 120.0f;

	const int ENEACT_5_2 = 2;
	const float ENERAD_5_2 = 40.0f;
	const float ENEKYORI_5_2 = 160.0f;
	const float ENEKOUDO_5_2 = 120.0f;

	const int ENEACT_5_3 = 4;
	const float ENERAD_5_3 = 80.0f;
	const float ENEKYORI_5_3 = 130.0f;
	const float ENEKOUDO_5_3 = 120.0f;

	const int ENETOU_5_1 = 45;

	//時系列6の敵情報
	const int ENEACT_6_1 = 3;
	const float ENERAD_6_1 = 110.0f;
	const float ENEKYORI_6_1 = 130.0f;
	const float ENEKOUDO_6_1 = 120.0f;

	const int ENEACT_6_2 = 4;
	const float ENERAD_6_2 = 140.0f;
	const float ENEKYORI_6_2 = 160.0f;
	const float ENEKOUDO_6_2 = 120.0f;

	const int ENEACT_6_3 = 3;
	const float ENERAD_6_3 = 170.0f;
	const float ENEKYORI_6_3 = 130.0f;
	const float ENEKOUDO_6_3 = 120.0f;

	const int ENETOU_6_1 = 55;
};


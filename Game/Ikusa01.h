#pragma once

#include "sound/SoundSource.h"

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
//class Title;
class Kekka;



class Ikusa01 :public IGameObject
{

public:
	~Ikusa01();
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
	//ここからBGMが変わる
	void Zikei_7();
	void Zikei_8();
	void Zikei_9();
	void Zikei_10();
	void Zikei_11();
	void Zikei_Fin();

	void UpZikei();

	//毎フレーム描画のためになされる処理
	void Render(RenderContext& rc);




private:
	//ステージ時系列
	int m_zikei = 0;
	//時系列カウント。時系列が上がる度にリセットされる
	int m_zc = 0;
	//ナウロ画面
	NowLo* c_nl;
	//ゲームオーバー画面
	OverGame* c_og;
	//タイトル画面
	//Title* c_title;
	//結果画面
	Kekka* c_kekka;

	//任務表示絵師
	SpriteRender m_ninmu;
	SpriteRender m_ninmu2;

	//基本的な速度
	const float ENESOKUX = 1.0f;
	const float ENESOKUY = 0.5f;

	//時系列１の敵情報
	const int ENEACT_1_1 = 2;
	const float ENERAD_1_1 = 0.0f;
	const float ENEKYORI_1_1 = 100.0f;
	const float ENEKOUDO_1_1 = 100.0f;

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
	//時系列4の敵情報
	const int ENETOU_4_1 = 90;
	const int ENETOU_4_2 = 150;
	const int ENETOU_4_3 = 210;

	const int ENEACT_4_1 = 6;
	const float ENERAD_4_1 = 20.0f;
	const float ENEKYORI_4_1 = 115.0f;
	const float ENEKOUDO_4_1 = 120.0f;
	const float ENESOKUX_4_1 = 0.9f;

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
	//突撃関連のステータス
	const int ENEYUU_5_2 = 260;
	const float ENETOTUSOKU_5_2 = 0.9f;

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
	//突撃関連のステータス
	const int ENEYUU_6_3 = 240;
	const float ENETOTUSOKU_6_3 = 1.0f;

	//時系列7の敵情報(回復誘導のための時系列)

	const int ENEACT_7_1 = 4;
	const float ENERAD_7_1 = -30.0f;
	const float ENEKYORI_7_1 = 120.0f;
	const float ENEKOUDO_7_1 = 130.0f;

	const int ENEACT_7_2 = 4;
	const float ENERAD_7_2 = 30.0f;
	const float ENEKYORI_7_2 = 120.0f;
	const float ENEKOUDO_7_2 = 100.0f;

	const int ENETOU_7_1 = 55;

	const Vector3 HEAFIRST_7 = {-250.0f,110.0f,100.0f};
	const Vector3 HEAIDOU_7 = { 1.0f,0.0f,0.0f };
	const float HEAEND_7 = 500;
	//時系列８の敵情報（大砲兵初登場）１が大砲兵
	const int ENEACT_8_1 = 2;
	const float ENERAD_8_1 = 30.0f;
	const float ENEKYORI_8_1 = 140.0f;
	const float ENEKOUDO_8_1 = 130.0f;

	const int ENEACT_8_2 = 4;
	const float ENERAD_8_2 = 0.0f;
	const float ENEKYORI_8_2 = 110.0f;
	const float ENEKOUDO_8_2 = 130.0f;

	const int ENEACT_8_3 = 4;
	const float ENERAD_8_3 = 60.0f;
	const float ENEKYORI_8_3 = 110.0f;
	const float ENEKOUDO_8_3 = 130.0f;

	const int ENETOU_8_23 = 90;
	const int ENETOU_8_1 = 120;

	const int ENEBEF_8_1 = 180;
	const int ENEAFT_8_1 = 240;
	const float ENETOTUSOKU_8_1 = 1.0f;
	//時系列9の敵情報（いっぱい出てくる、４がT、絶対被弾させる）
	const int ENEACT_9_123 = 5;
	const float ENERAD_9_1234 = 20.0f;
	const float ENEKYORI_9_1234 = 115.0f;
	const float ENEKOUDO_9_1234 = 120.0f;
	const float ENESOKUX_9_1234 = 1.0f;

	const float ENETOU_9_1 = 30.0f;
	const float ENETOU_9_2 = 90.0f;
	const float ENETOU_9_3 = 150.0f;
	const float ENETOU_9_4 = 210.0f;
	
	const float ENEACT_9_4 = 2;
	const int ENEBEF_9_4 = 180;
	const int ENEAFT_9_4 = 240;
	const float ENETOTUSOKU_9_4 = 1.0f;
	//時系列10(ラスト,６がT)
	const int ENEACT_10_1 = 4;
	const float ENERAD_10_1 = -20.0f;
	const float ENEKYORI_10_1 = 90.0f;
	const float ENEKOUDO_10_1 = 130.0f;

	const int ENEACT_10_2 = 4;
	const float ENERAD_10_2 = 20.0f;
	const float ENEKYORI_10_2 = 90.0f;
	const float ENEKOUDO_10_2 = 130.0f;

	const int ENEACT_10_3 = 5;
	const float ENERAD_10_3 = 165.0f;
	const float ENEKYORI_10_3 = 135.0f;
	const float ENEKOUDO_10_3 = 150.0f;

	const int ENEACT_10_4 = 5;
	const float ENERAD_10_4 = 135.0f;
	const float ENEKYORI_10_4 = 135.0f;
	const float ENEKOUDO_10_4 = 150.0f;

	const int ENEACT_10_5 = 2;
	const float ENERAD_10_5 = -80.0f;
	const float ENEKYORI_10_5 = 90.0f;
	const float ENEKOUDO_10_5 = 100.0f;

	const int ENEACT_10_6 = 2;
	const float ENERAD_10_6 = -110.0f;
	const float ENEKYORI_10_6 = 90.0f;
	const float ENEKOUDO_10_6 = 100.0f;
	const int ENEBEF_10_6 = 180;
	const int ENEAFT_10_6 = 240;
	const float ENETOTUSOKU_10_6 = 1.0f;


	const int ENETOU_10_1 = 30;
	const int ENETOU_10_3 = 120;
	const int ENETOU_10_5 = 210;

	//ボスのステータス



	//子クラスのみなさん
	SkyCube* m_skyCube;
	//TheSky* c_thesky;
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
	SoundSource* m_bgmB;

};




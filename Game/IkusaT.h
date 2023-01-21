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
	//今現在のプレイヤーの体力を確認し、息絶えていたらゲームオーバーを呼び出す処理
	void Kaku();
	//時系列０の時のみ行われる処理
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

	//ステージ時系列
	double m_zikei = 0.0;
	//時系列カウント。時系列が上がる度にリセットされる
	int m_zc = 0;
	//選択カウント、はいは1いいえは０デフォルトは２
	int m_yn = 2;

	//ガイド用の絵師たち
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
	//ナウロ画面
	NowLo* c_nl;




	//基本的な速度
	const float ENESOKUX = 1.0f;
	const float ENESOKUY = 0.5f;

	//時系列2の敵情報
	const int ENEACT_2_1 = 2;
	const float ENERAD_2_1 = 0.0f;
	const float ENEKYORI_2_1 = 100.0f;
	const float ENEKOUDO_2_1 = 100.0f;


	//時系列4の敵情報
	const int ENEACT_4_1 = 2;
	const float ENERAD_4_1 = 100.0f;
	const float ENEKYORI_4_1 = 100.0f;
	const float ENEKOUDO_4_1 = 100.0f;

	//時系列8のハート情報
	const Vector3 HEAFIRST_8 = { 85.0f,100.0f,100.0f };
	const Vector3 HEAIDOU_8 = { 0.0f,0.0f,-1.0f };
	const float HEAEND_8 = 200;

	//子クラスのみなさん
	SkyCube* m_skyCube = nullptr;
	Daichi* c_daichi;
	Oresiten* c_oresiten;
	MakeUI* c_makeui;

	Title* c_title;
	Ikusa01* c_ikusa01;

	//呼び出される敵のみなさん
	EnemyN* c_enen0;
	EnemyN* c_enen1;

	Heart* c_heart0;

};
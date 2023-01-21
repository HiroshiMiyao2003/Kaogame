#pragma once


class Daichi;
class Oresiten;
class MakeUI;

class EnemyT;
class EnemyN;
class Heart;
class Boss;

class NowLo;
class OverGame;

class Ikusa00 :public IGameObject
{

public:
	~Ikusa00();
	bool Start();
	void Update();
	//今現在のプレイヤーの体力を確認し、息絶えていたらゲームオーバーを呼び出す処理
	void Kaku();

	//子クラスのみなさん
	SkyCube* m_skyCube = nullptr;
	Daichi* c_daichi;
	Oresiten* c_oresiten;
	MakeUI* c_makeui;

	//呼び出される敵のみなさん


	EnemyN* c_enen0;
	EnemyN* c_enen1;
	EnemyN* c_enen2;
	EnemyN* c_enen3;
	EnemyN* c_enen4;

	EnemyT* c_enet0;

	Heart* c_heart0;

	Boss* c_boss;

private:
	//ステージ時系列
	int m_zikei = 0;
	//時系列カウント。時系列が上がる度にリセットされる
	int m_zc = 0;
	//ナウロ画面
	NowLo* c_nl;
	//ゲームオーバー画面
	OverGame* c_og;

	//ハート１回目の諸々のデータ
	//ハート初期位置
	Vector3 HEARTP = {80.0f,100.0f,50.0f};
	//ハートのベクトル
	Vector3 HEARTV = {0.0f,0.0f,-0.3f};
	//ハートの消滅フレーム
	int HEARTF = 600;

};


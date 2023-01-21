#pragma once

class Oresiten;
class MakeUI;
class Testshot;

class TestshotE :public IGameObject
{

public:
	~TestshotE();
	bool Start();
	void Update();
	//プレイヤー弾に当たったかどうか判定する処理
	void Han();
	//キャラコンの代わりに弾を動かす処理
	void Move();
	//弾を登場させた時にのみ実行される処理
	void Toujo();
	//退場させる処理
	void Bye();
	void Render(RenderContext& rc);

	//敵弾を登場させる処理。posは弾の初期位置、sokuは弾の速度
	void ToujoSiro(Vector3 pos,float soku)
	{
		m_nowpos = pos;

		m_totusoku = soku;

		m_taideba = 1;

	}


	Vector3 m_tamaend;
	ModelRender m_modelrender;



	//待機か出番か待機は０、出番は１
	int m_taideba = 0;

	//コリジョンオブジェクト
	CollisionObject* m_col;

private:

	//待機場所のY座標
	const float MACHIY = -500.0f;

	//弾の今の座標
	Vector3 m_nowpos;
	//突撃速度を決める数値。正規化された速度値にかけるので、速度と数値の大きさが比例する
	float m_totusoku = 5.0f;
	

	int m_count;

	//１フレームごとに移動させる距離を記録する変数
	Vector3 m_hureichi;
	//１フレームごとに移動する速度を決める割り算の分母。この値を大きくすればするほど速度は遅くなる
	const float  WARI = 0.30f;

	//プレイヤーの座標
	const Vector3 m_oreiru = { 0.0f,100.0f,0.0f };
	//敵弾からプレイヤーへのベクトル
	Vector3 m_etop;
	//自爆が実行されるプレイヤーと敵との距離
	const float ZIBA = 50.0f;


	//コリジョンのサイズ
	const float COLXYZ = 15.0f;
	Vector3 m_size;


	//爆発エフェクト職人
	EffectEmitter* m_bakuE = nullptr;
	//爆発エフェクトの大きさを変えるために当たり判定にかける値
	const float BAKUKAKE = 0.15f;

	//ほかのクラスたち
	Oresiten* c_oresiten;
	MakeUI* c_makeui;

	//tsクラス
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;
};


#pragma once

class Oresiten;

class Testshot :public IGameObject
{

public:
	~Testshot();
	bool Start();
	void Update();
	//キャラコンの代わりに弾を動かす処理
	void Move();
	//弾を登場させた時にのみ実行される処理
	void Toujo();
	//退場させる処理
	void Bye();
	void Render(RenderContext& rc);


	//CharacterController m_characon;

	Vector3 m_tamaend;

	Oresiten* m_oresiten;

	ModelRender m_modelrender;

	//弾の今の座標
	Vector3 m_nowpos;
	//待機か出番か待機は０、出番は１
	int m_taideba = 0;

	//コリジョンオブジェクト
	CollisionObject* m_col;

private:

	//待機場所のY座標
	const float MACHIY = -100.0f;

	//消滅までの鼓動
	int m_count;
	//消滅のタイミング
	const int SAYONARA = 34;
	//弾の描画が始まるタイミング
	const int KAKIHAZI = 4;

	//１フレームごとに移動させる距離を記録する変数
	Vector3 m_hureichi;
	//１フレームごとに移動する速度を決める割り算の分母。この値を大きくすればするほど速度は遅くなる
	const float  WARI = 0.30f;


	//コリジョンのサイズ
	const float COLXYZ = 10.0f;
};


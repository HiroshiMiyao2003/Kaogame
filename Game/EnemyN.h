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
	//撃たれたかどうかの判定
	void Han();
	//出番の時の行動パターンを決める関数
	void Live();
	//ただ左右に中途半端に回るだけの行動。0で発動
	void ActGuru();
	//突撃を行う行動。1で発動
	void ActTotu();
	//何一つ座標が動かない行動。2で発動
	void ActHudou();
	//上下に動いて挑発する行動。3で発動
	void ActTate_U();
	//下上に動いて挑発する行動。4で発動
	void ActTate_D();
	//ひたすら時計回りに回り続けながら挑発する行動。5で発動
	void ActGurun_R();
	//ひたすら反時計回りに回り続けながら挑発する行動。6で発動
	void ActGurun_L();
	//自分と視界の位置関係を把握してMakeUIクラスに情報を送ったりする関数
	void Haaku();
	//アニメーション
	void Anima();
	//毎フレーム描画のためになされる処理
	void Render(RenderContext& rc);

	//敵自身の現在位置
	Vector3 m_enowpos;

	//出番かどうかを管理する変数。0なら待機、１なら出番、初期値は0
	int m_deban = 0;

	//敵の行動パターンを決める変数
	int m_act = 0;

	//敵の回転角度を決める変数。どっち向きに移動するかによって数値が変わるためデフォルトでは０になっている
	float m_zrad;

	//敵とプレイヤーとの距離を決める変数
	float m_kyori = 75.0f;

	//敵のY座標を決める変数
	float m_koudo = 100.0f;

	//自分のXZ速度を決める変数
	float m_sokudo_xz = 1.0f;
	//自分のY速度を求める変数
	float m_sokudo_y = 0.5f;

	//自分と視界の位置を把握してそれによって変わる変数。視界外右なら１、視界外左なら２
	int m_sikasoto = 0;

	//アニメーション集
	enum EnAnimationClip
	{
		Clip_taiki,//待機
		Clip_tyouhatu,//挑発
		Clip_totugeki,//突撃
		Clip_Num
	};

	//敵の登場を簡単に行えるクラス。aは行動パターン、rは角度、kは距離、tは高度になる
	void Toujou(int a,float r,float k,float t,float x,float y)
	{
		m_deban = 1;
		
		m_act = a;
		m_zrad = r;
		m_kyori = k;
		m_koudo = t;
		m_sokudo_xz = x;
		m_sokudo_y = y;
		//とりあえずの座標を決めてくれる処理
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;
		
		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
	};
	//登場済みの敵に突撃させるメソッド、sはスピード、tは突撃までの猶予フレーム数
	void Totusiro(float s,float t)
	{
		m_totuc = t;
		m_totusoku = s;
		m_act = 1;
	}

private:
	//3Dモデル担当絵師
	ModelRender m_ml;
	//回転職人
	Quaternion m_qua;


	//tsクラス
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;
	//UIクラス
	MakeUI* c_makeui;
	//視点クラス
	Oresiten* c_oresiten;
	//待機位置のY座標の設定
	const float TAIKIY = -400.0f;

	//コリジョンオブジェクト
	CollisionObject* m_ecol;
	//コリジョンのサイズ
	const float ECOLXYZ = 30.0f;
	//コリジョンのサイズベクトル
	Vector3 m_size;
	//循環的行動パターン制御カウント。
	int m_kouc = -1;
	//循環的行動パターン制御カウントのをリセットする値
	const int KOUCFIN = 120;
	//敵の速度
	const float SOKUDO = 0.1f;

	//突撃行動パターン制御カウント
	int m_totuc = M_TOTUC;
	//m_totuc初期値
	const int M_TOTUC = 60;
	//1フレームごとに移動する距離を記録する変数
	Vector3 m_hureichi;
	//突撃速度を決める数値。正規化された速度値にかけるので、速度と数値の大きさが比例する
	float m_totusoku = 5.0f;
	//自爆が実行されるプレイヤーと敵との距離
	const float ZIBA = 60.0f;

	//プレイヤーの座標
	const Vector3 m_oreiru = {0.0f,100.0f,0.0f};
	//敵からプレイヤーへのベクトル
	Vector3 m_etop;

	//敵と注視点との角度を代入する変数
	float m_ttkaku;
	//正面と注視点との角度を代入する変数
	float m_shoutar;
	//正面と敵自身との角度を代入する変数
	float m_shouene;

	//視野角の定義
	const float SIYAKAKU = 55.0f;



	//円周率
	const double PAI = 3.14159265359;
	//コリジョンのサイズ
	const float COLXYZ = 20.0f;

	//アニメーション
	AnimationClip m_anima[Clip_Num];
	//アニメーション指定
	int m_ugoki = 0;

	//爆発エフェクト職人
	EffectEmitter* m_bakuE = nullptr;
	//爆発エフェクトの大きさを変えるために当たり判定にかける値
	const float BAKUKAKE = 0.2f;

	//登場エフェクト職人
	EffectEmitter* m_touE = nullptr;
	//登場エフェクトの大きさを変えるために当たり判定にかける値
	const float TOUKAKE = 0.2f;
	//登場時に加算され、退場時に減産される変数
	int m_shoken;
	//登場エフェクトがなくなるとき
	const int TOUESTOP = 30;

	//スコア最大値
	const int MAXSCORE = 2001;
	//今現在、この敵が持っているスコア
	int m_nowscore;


};




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
	//撃たれたかどうかの判定
	void Han();
	//出番の時の行動パターンを決める関数
	void Live();
	//登場する処理。１で発動
	void ActToujou();
	//何一つ座標が動かない行動。2で発動
	void ActHudou();
	//右にワープする処理、3で発動
	void ActWarpR();
	//左にワープする処理、4で発動
	void ActWarpL();
	//隙がある処理。5で発動
	void ActSuki();
	//守る処理。6で発動
	void ActMamori();
	//やられてよろける処理
	void ActYarare();
	//自分と視界の位置関係を把握してMakeUIクラスに情報を送ったりする関数
	void Haaku();
	//アニメーション
	void Anima();
	//毎フレーム描画のためになされる処理
	void Render(RenderContext& rc);

	//アニメーション集
	enum EnAnimationClip
	{
		Clip_taiki,//待機
		Clip_toujou,//登場
		Clip_warpR,//ワープR
		Clip_warpL,//ワープL
		Clip_suki,//隙
		Clip_bou,//防御
		Clip_yarare,//やられ
		Clip_Num
	};

	//敵自身の現在位置
	Vector3 m_enowpos;

	//出番かどうかを管理する変数。0なら待機、１なら出番、初期値は0
	int m_deban = 0;

	//敵の行動パターンを決める変数
	int m_act = 0;
	//敵が無敵かどうかを決めるクラス。１なら無敵
	int m_muteki = 0;

	//敵の回転角度を決める変数。どっち向きに移動するかによって数値が変わるためデフォルトでは０になっている
	float m_zrad;

	//敵とプレイヤーとの距離を決める変数
	float m_kyori = 75.0f;

	//敵のY座標を決める変数
	float m_koudo = 100.0f;

	//自分と視界の位置を把握してそれによって変わる変数。視界外右なら１、視界外左なら２
	int m_sikasoto = 0;

	//敵の登場を簡単に行えるクラス。rは角度、kは距離、tは高度になる
	void ToujouKani(float r, float k, float t)
	{
		m_deban = 1;

		m_act = 1;
		m_muteki = 1;

		m_zrad = r;
		m_kyori = k;
		m_koudo = t;

		//とりあえずの座標を決めてくれる処理
		m_enowpos.z = cos(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.x = sin(m_zrad * (PAI / 180)) * m_kyori;
		m_enowpos.y = m_koudo;
		m_ugoki = 1;

		m_ml.SetPosition(m_enowpos);
		m_ml.Update();
	};

	//ボスのHP
	int m_bosshp = 5;
	//ワープしてるかどうか。１ならしている
	int m_warp = 0;

private:
	//3Dモデル担当絵師
	ModelRender m_ml;
	//回転職人
	Quaternion m_qua;

	//アニメーション
	AnimationClip m_anima[Clip_Num];
	//アニメーション指定
	int m_ugoki = 0;

	//爆発エフェクト職人
	EffectEmitter* m_bakuE = nullptr;
	//爆発エフェクトの大きさを変えるために当たり判定にかける値
	const float BAKUKAKE = 0.2f;

	//循環的行動パターン制御カウント。
	int m_kouc = -1;
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

	//部下の一般兵クラス
	EnemyN* c_buka2;

	//部下の大砲兵クラス
	EnemyT* c_buka1;

	//待機位置のY座標の設定
	const float TAIKIY = -400.0f;
	//コリジョンオブジェクト
	CollisionObject* m_ecol;
	//コリジョンのサイズ
	const float ECOLXYZ = 30.0f;
	//コリジョンのサイズベクトル
	Vector3 m_size;
	//視野角の定義
	const float SIYAKAKU = 55.0f;
	//円周率
	const double PAI = 3.14159265359;
	//コリジョンのサイズ
	const float COLXYZ =30.0f;

	//当てた時の得点
	const int ATESCORE = 3000;
	//撃破した時の得点
	const int GEKIHASCORE = 10000;

	//部下のデータ
	const int ENEACT_B1 = 2;
	const float ENEKYORI_B1 = m_kyori + 50.0f;
	const float ENEKOUDO_B1 = m_koudo + 50.0f;

	const int ENEBEF_B1 = 120;
	const int ENEAFT_B1 = 180;
	const float ENETOTUSOKU_B1 = 1.0f;

};


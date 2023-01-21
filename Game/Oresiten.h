#pragma once



class Oresiten :public IGameObject
{

public:
	~Oresiten();
	bool Start();
	void Update();
	//視点から注視点へのベクトルを計算する関数
	void Keisan();
	//回転処理
	void Rotation();

	//～メンバ変数～

//近平面の値
	const float KINHEI = 1.0f;
	//遠平面の値
	const float ENHEI = 40000.0f;
	//注視点の位置の値セット
	 float TARX = 0.0f;
	 float TARY = 100.0f;
	 float TARZ = 50.0f;
	 //注視点を表す座標
	 Vector3 m_tar;

	//視点の位置の値セット
	const float POSX = 0.0f;
	const float POSY = 100.0f;
	const float POSZ = 0.0f;
	//視点を表す座標
	Vector3 m_position;

	//視線を表すベクトル
	Vector3 m_sisen;
	//逆視線を表すベクトル
	Vector3 m_sisen_gyaku;

	//カメラ回転用クォータニオン
	Quaternion m_kamekaku;
	//円周率
	double PAI = 3.14159265359;
	//自分が向いている角度0~359まであると思われる
	float Zrad = 0.0f;
	//左側ジョイスティックのX値を入れる変数
	float m_ljoyx;
	//左側ジョイスティックのY値を入れる変数
	float m_ljoyy;
	//鍵をかける変数
	void Lock()
	{
		m_lock = 1;
	};
	//鍵を解除する変数
	void UnLock() 
	{
		m_lock = 0;
	};

private:
	//上向ける上限値
	const float UEGEN = 103.0f;
	//下向ける上限値
	const float SITAGEN = 100.0f;

	//カメラのXZ感度
	const float KANDOXZ = 0.15f;
	//カメラのY感度
	const float KANDOY = 0.15f;

	//ダッシュ時にかける数値
	const float DASH = 1.5f;

	//鍵を表す変数、１がロック状態
	int m_lock = 0;

	//最初のsisenのYの値を記録する変数
	float FIRSTSISENY;

	//ポイントライト
	PointLight c_poi;
};

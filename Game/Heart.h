#pragma once

class Testshot;
class MakeUI;
#include "sound/SoundSource.h"


class Heart :public IGameObject
{
public:
	//消え去るときの処理
	~Heart();
	//生成時に実行される処理
	bool  Start();
	//毎フレーム行われる処理
	void Update();

	//撃たれたかどうかの判定
	void Han();
	//動きかたの処理
	void MoveH();
	//毎フレーム描画のためになされる処理
	void Render(RenderContext& rc);



	//出番かどうかを管理する変数。0なら待機、１なら出番
	int m_deban = 0;

	//初期位置を記録する変数たち
	Vector3 m_firstpos;
	//1フレームごとに移動するベクトルを決める変数たち
	Vector3 m_idouv;
	//消滅するフレーム数を記録する変数
	int m_finalf = 9999;

	//Heartクラスを出すための設定を行う関数。初期座標、移動ベクトル、消滅フレーム数を伝える
	
	//ハートを登場させるメソッド。pが初期位置、iが１フレームごとに移動する長さ、fが消滅するタイミング
	void Toujou(Vector3 p, Vector3 i, int f)
	{
		m_firstpos = p;
		m_idouv = i;
		m_finalf = f;
		m_deban = 1;
		m_ensou->Play(true);
		m_ensou->SetVolume(1.0f);
	};
	

	//循環にするための変数、1なら循環する
	int jun = 0;

private:
	//3Dモデル担当絵師
	ModelRender m_ml;
	//演奏者
	SoundSource* m_ensou;
	//回転職人
	Quaternion m_qua;
	//当たり判定
	CollisionObject* m_hcol;
	//座標
	Vector3 m_hnowpos;
	//コリジョンサイズ
	Vector3 COLXYZ = {20.0f,20.0f,20.0f};

	//tsクラス
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;
	//UIクラス
	MakeUI* c_makeui;

	//待機位置のY座標の設定
	const float TAIKIY = -400.0f;

	//爆発エフェクト職人
	EffectEmitter* m_bakuE = nullptr;
	//爆発エフェクトの大きさを変えるために当たり判定にかける値
	const float BAKUKAKE = 0.2f;

	//登場してからのフレーム数をカウントし続ける変数
	int m_myaku = 0;

	//HPの回復量
	int KAIHUKU = 1;


};


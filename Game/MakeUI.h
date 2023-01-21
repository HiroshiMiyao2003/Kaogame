#pragma once

class Testshot;
class Saisho;
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

class MakeUI :public IGameObject
{

public:

	//終了時の処理
	~MakeUI();
	//開始時の処理
	bool Start();
	//毎フレーム実行される処理
	void Update();
	//HPを確認するための処理。毎フレーム実行される
	void HPkaku();
	//ボタン入力を確認するための処理。毎フレーム実行される
	void Botakaku();
	//弾の出演状態を確認するための処理。毎フレーム行われる
	void Tamakaku();
	//弾のクールタイムを管理する処理。毎フレーム行われる
	void Cool();
	//クロスヘアを描くかどうか決める処理使われていない
	void Crosskime();
	//HPの描画をどうするか決める処理。毎フレーム行われる
	void Hpkime();
	//敵クラスから送られてきた情報をもとに、敵警告の描画をするかどうかを決める処理。
	void Keikime();
	//ダメージ描写モードの時に実行される処理
	void Damemode();
	//毎フレーム描画のためになされる処理
	void Render(RenderContext& rc);

	//弾の発射を封印し、クロスヘアを非表示にする関数
	void Lock()
	{
		m_lock = 1;
		m_cross.SetPosition(TAIKITEN);
		m_cross.Update();
	};
	//弾の発射を解禁し、クロスヘアを表示させる関数
	void UnLock()
	{
		m_lock = 0;
		m_cross.SetPosition(GENTEN);
		m_cross.Update();
	}
	//得点を加算させる処理
	void ScoreAdd(int as)
	{
		m_score += as;
		wchar_t wcsbuf[256];
		swprintf_s(wcsbuf, 256, L"SCORE %07d", int(m_score));

		m_scoren.SetText(wcsbuf);

	}


	//HPの現在値
	int m_nowhp = 1;

	//右警告を出すかどうか。１で出す
	int m_keiR = 0;
	//左警告を出すかどうか。１で出す
	int m_keiL = 0;

	//ロック。0が解禁、１が禁止
	int m_lock = 0;

private:
	//テストショットクラス
	Testshot* c_ts0;
	Testshot* c_ts1;
	Testshot* c_ts2;
	Testshot* c_ts3;
	Testshot* c_ts4;
	Testshot* c_ts5;

	//最初クラス
	Saisho* c_saisho;

	

	//テストショットの状態確認。1なら出演中、0なら待機中。
	int m_tsjoutai[6] = {0,0,0,0,0,0};

	//次の弾が撃てるまでのクールタイム
	const int COOLTIME = 8;
	//クールタイムカウント
	int m_cool = 0;

	//クロスヘア担当絵師
	SpriteRender m_cross;
	//HP担当絵師の皆様。数字が大きい絵師が担当しているHPほど真っ先になくなる
	SpriteRender m_hp1;
	SpriteRender m_hp2;
	SpriteRender m_hp3;
	SpriteRender m_hp4;
	SpriteRender m_hp5;
	SpriteRender m_hp6;
	SpriteRender m_hp7;
	SpriteRender m_hp8;
	SpriteRender m_hp9;
	SpriteRender m_hp10;
	//HP（空）担当絵師の皆様
	SpriteRender m_hpk1;
	SpriteRender m_hpk2;
	SpriteRender m_hpk3;
	SpriteRender m_hpk4;
	SpriteRender m_hpk5;
	SpriteRender m_hpk6;
	SpriteRender m_hpk7;
	SpriteRender m_hpk8;
	SpriteRender m_hpk9;
	SpriteRender m_hpk10;
	//敵報告UI担当絵師の皆様
	SpriteRender m_eneR;
	SpriteRender m_eneL;
	//ダメージ表現担当絵師のみなさま
	SpriteRender m_redda0;
	SpriteRender m_redda1;
	SpriteRender m_redda2;
	
	//HPの上限値
	const int HPMAX = 10;

	//前フレームのHPを記録する変数
	int m_beforeHP = m_nowhp;

	//ダメージ描写モード実行変数、普段は-1
	int m_dacount = -1;
	//ダメージ描写モードが始まってから終わるまでの時間の3分の１の値
	const int DAMEFIVE = 10;

	//スコア
	long int m_score = 0;

	FontRender m_scoren;
	FontRender m_scoren2;

	//原点
	const Vector3 GENTEN ={0.0f,0.0f,0.0f};
	//待機点
	const Vector3 TAIKITEN = { 0.0f,2000.0f,0.0f };

};
/*
MakeUIクラスはすべてのステージにおいて呼び出されるクラスです
自分自身の弾の親クラスでもあります
主にプレイヤーの状態を管理し、ゲームの審判的役割もはたしています
なお、ゲームオーバーは各ステージ構成を担当しているクラスがつかさどっています。
*/

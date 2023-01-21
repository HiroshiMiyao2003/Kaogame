#pragma once

class IkusaT;
class Ikusa00;
class Ikusa01;
class IkusaW;
class NowLo;

class Saisho;

#include "sound/SoundSource.h"

class Title :public IGameObject
{
public:
	~Title();
	bool Start();
	void Update();
	//操作を受け付ける
	void Sousa();
	//操作に対する反映
	void Hanei();
	//siziの文字をいい感じに点滅させる
	void Tenmetu();
	void Render(RenderContext& rc);

private:
	//点滅させるためのカウント
	int m_tc = 0;
	//点滅加算か減算かの処理.１なら減算
	int m_tenhan = 1;
	//アルファ値を決める数値
	float m_aru = 1.0f;
	//点滅の上限
	const int  TENGEN = 120;

	//ステージ0
	Ikusa00* c_ikusa00;
	//ステージ1
	Ikusa01* c_ikusa01;
	//ステージT
	IkusaT* c_ikusaT;
	//スーテジ
	IkusaW* c_ikusaW;
	//次フレームの運命を決める処理。
	int m_nextfate = -1;
	//ステージ読み込みが始まるタイミング
	const int YOMIHAZI = 10;

	//カーソルの現在位置。０が開始、2が設定
	int m_kasorupos = 0;
	//タイトル画面にあるボタンの総数
	int SOUSUU = 2;

	//開始ボタンのY座標
	const Vector3 KAISI = {0.0f,-400.0f,0.0f };
	//設定ボタンのY座標
	const Vector3 TUTO = {0.0f, -530.0f ,0.0f};
	//設定ボタンのY座標
	const Vector3 SETTEI = { 0.0f, -660.0f ,0.0f };

	//タイトルのベース画面絵師
	SpriteRender m_base;
	//開始ボタン絵師
	SpriteRender m_kaisi;
	//ランキングボタン絵師
	SpriteRender m_tuto;
	//設定ボタン絵師
	//SpriteRender m_settei;
	//カーソル絵師
	SpriteRender m_kasoru;
	//指示絵師
	SpriteRender m_sizi;

	//試験的フォント絵師（あとでけす）
	FontRender m_zikken;

	//BGM
	SoundSource* m_bgm;

	//ナウローディングクラス
	NowLo* c_nowlo;

	//最初クラス
	Saisho* c_saisho;

};


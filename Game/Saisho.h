#pragma once

class Ikusa00;
class Title;

class Saisho:public IGameObject
{

public:
	~Saisho();
	bool Start();
	void Update();

	//すべての場面において使用可能な変数
	
	//どのステージを読み込むかを指示する変数、１なら格納庫
	int m_stage = 0;
	//bgm音量
	float m_bgmnum;
	//se音量
	float m_senum;
	//横軸感度
	float m_kandXZnum;
	//縦軸感度
	float m_kandoYnum;

	//得点
	long int m_score;

	Ikusa00* m_ikusa00;
	Title* c_title;
	std::vector<PointLight*>	m_pointLightList;
};


#pragma once

class Title;
class Saisho;
class Kekka :public IGameObject
{
public:
	~Kekka();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:

	Title* c_title;
	Saisho* c_saisho;
	FontRender m_scoren;

	SpriteRender m_og;
	FontRender m_tokumoji;
};


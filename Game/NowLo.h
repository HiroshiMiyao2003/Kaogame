#pragma once
class NowLo :public IGameObject
{

public:
	~NowLo();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:

	SpriteRender m_nl;
};


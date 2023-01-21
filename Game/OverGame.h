#pragma once

class Title;

class OverGame :public IGameObject
{
	
	public:
		~OverGame();
		bool Start();
		void Update();
		void Render(RenderContext & rc);
	private:

		Title* c_title;

		SpriteRender m_og;
	
};


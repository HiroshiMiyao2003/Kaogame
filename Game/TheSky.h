#pragma once
class TheSky :public IGameObject
{
public:
	~TheSky();
	bool Start();
	void Update();
	void Render(RenderContext& rc)override final;

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
	}
private:
	ModelRender modelRender;
	Vector3 pos;
	Vector3 m_position = {0.0f,0.0f,0.0f};
	Quaternion m_rotation;
	Vector3						m_scale = Vector3::One;
	PhysicsStaticObject			physicsStaticObject;

	int m_coucou = 0;
};


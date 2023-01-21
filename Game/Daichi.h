#pragma once

class Saisho;
class Daichi : public IGameObject
{
public:
	Daichi();
	~Daichi();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
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
	Vector3 m_position;
	Quaternion m_rotation;
	Vector3						m_scale = Vector3::One;
	PhysicsStaticObject			physicsStaticObject;

	Saisho* c_saisho;
};



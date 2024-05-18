#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "Vector2D.hpp"
#define UNI_MASS 1.0f
#define GRAVITY 9.8f
#define FORWARD 1
#define BACKWARD -1
#define UPWARD -1
#define DOWNWARD 1

class RigidBody
{
public:
	RigidBody() {
		m_Gravity = GRAVITY;
		m_Mass = UNI_MASS;
	}
	// Setter
	inline void SetMass(float mass) { m_Mass = mass; }
	inline void SetGravity(float gravity) { m_Gravity = gravity; }
	// Getter
	inline float Mass() { return m_Mass; }
	inline Vector2D Position() { return m_Position; }
	inline Vector2D Velocity() { return m_Velocity; }
	inline Vector2D Acceleration() { return m_Acceleration; }
	// Apply Force
	inline void ApplyForce(Vector2D f) { m_Force = f; }
	inline void ApplyForceX(float force_x) { m_Force.X = force_x; }
	inline void ApplyForceY(float force_y) { m_Force.Y = force_y; }
	inline void UnsetForce() { m_Force = Vector2D(0, 0); }
	// Apply Friction
	inline void ApplyFriction(Vector2D fr) { m_Friction = fr; }
	inline void UnsetFriction() { m_Friction = Vector2D(0, 0); }
	// Update
	void Update(float dt) {
		m_Acceleration.X = (m_Force.X + m_Friction.X) / m_Mass;
		m_Acceleration.Y = m_Gravity + m_Force.Y / m_Mass;
		m_Velocity = m_Acceleration * dt;
		m_Position = m_Velocity * dt;
	}
private:
	float m_Gravity;
	float m_Mass;

	Vector2D m_Force;
	Vector2D m_Friction;
	Vector2D m_Position;
	Vector2D m_Velocity;
	Vector2D m_Acceleration;
};


#endif // !RIGIDBODY_H


#pragma once

#include "TransformComponent.h"
#include "Object.h"


class PhysicsBodyComponent : public Component 
{
public:
	PhysicsBodyComponent(b2World world)
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(transform->GetPosition().x, transform->GetPosition().y);
		body = world.CreateBody(&bodyDef);

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(1.0f, 1.0f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;

		body->CreateFixture(&fixtureDef);
	}

	bool Link() override
	{
		if (object->HasComponent<TransformComponent>()) {
			transform = &object->GetComponent<TransformComponent>();
			return true;
		}
		return false;
	}

private:
	TransformComponent* transform;
	b2Body* body;
};
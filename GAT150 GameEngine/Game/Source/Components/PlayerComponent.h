#pragma once
#include "Component/Component.h"

class PlayerComponent : public Component{
public:
	CLASS_DECLARATION(PlayerComponent)

	void Initialize() override;
	void Update(float dt) override;

	void OnCollisionEnter(Actor*);

public:
	float speed = 0.0f;

};
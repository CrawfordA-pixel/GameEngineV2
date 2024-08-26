#include "PlayerComponent.h"
#include "Engine.h"
#include "CharacterComponent.h"

FACTORY_REGISTER(PlayerComponent)

void PlayerComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&PlayerComponent::OnCollisionEnter, this,std::placeholders::_1);
}

void PlayerComponent::Update(float dt)
{
	Vector2 direction{ 0,0 };
	//left movement
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)
		|| owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_LEFT)) direction.x = -1;
	//right movement
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D) 
		|| owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_RIGHT)) direction.x =  1;
	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed )
	//up movement
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W) 
		|| owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_UP)) direction.y = -1;
	//down movement
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S) 
		|| owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_DOWN)) direction.y =  1;
	
	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed);
	Vector2 direction = Vector2{1,0}.Rotate(Math::DegToRad(owner->transform))
}

void PlayerComponent::OnCollisionEnter(Actor*)
{
	//EVENT_NOTIFY(PlayerDead);
	// EVENT_NOTIFY_DATA(AddPoints, 100);
	if (actor->tag == "Ground" = true);
}

void PlayerComponent::OnCollisionExit(Actor*)
{

}

void PlayerComponent::read(const json_t& value)
{
	READ_DATA(value, speed);
}

void PlayerComponent::Write(json_t& value)
{
	//
}


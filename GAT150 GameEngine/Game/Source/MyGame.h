#pragma once
#include "Framework/Game.h"
#include "Event/Observer.h"
#include <memory>

class MyGame : public Game, Observer
{
public:

	MyGame() = default;
	MyGame(Engine* engine) : Game{engine} {}

	bool Initialize() override;
	void ShutDown() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	//events
	void OnPlayerDead(const Event& event);
	void OnAddPoints(const Event& event);
private:
	std::unique_ptr<Scene> m_scene;
};
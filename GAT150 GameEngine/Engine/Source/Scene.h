#pragma once
#include <list>
#include <memory>

class Renderer;
class Actor;
class Game;

class Scene {
public:
	Scene() = default;
	Scene(Game* game) : m_game{ game } {}

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor);
	void RemoveAll();

	void Hit() { hits++; };
	void Shot() { shots++; };
	int Hits() { return hits; };
	int Shots() { return shots; };

	template<typename T>
	T* GetActor();

	Game* GetGame() { return m_game; };
protected:
	std::list<std::unique_ptr<Actor>> m_actors;
	int hits = 0;
	int shots = 0;
	Game* m_game{ nullptr };
};

template<typename T>
T* Scene::GetActor() {

	for (auto& actor : m_actors) {
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}

	return nullptr;
}
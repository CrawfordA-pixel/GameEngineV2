#include "MyGame.h"
#include "Engine.h"

bool MyGame::Initialize()
{
	//create read intialize scene
	m_scene = std::make_unique<Scene>(m_engine);
	std::string sceneNames[] = { "Scenes/tilemap.json", "Scenes/game.json" };
	for (auto sceneName : sceneNames)
	{
		//read json
		rapidjson::Document doc;
		Json::Load("Scenes/scene.json", doc);
		m_scene->read(doc);
	}
	m_scene->Initialize();

	//ADD_OBSERVER(PlayerDead, MyGame::OnPlayerDead);
	//ADD_OBSERVER(AddPoints, MyGame::OnAddPoints);

	return true;
}

void MyGame::ShutDown()
{
	m_scene->RemoveAll();
}

void MyGame::Update(float dt)
{
	m_scene->Update(dt);
}

void MyGame::Draw(Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnPlayerDead(const Event& event)
{
	std::cout << "game player dead\n";
}

void MyGame::OnAddPoints(const Event& event)
{
	m_score += std::get<int>(event.data);
	std::cout << m_score << std::endl;
}


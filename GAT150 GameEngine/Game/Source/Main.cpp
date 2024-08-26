#include "Engine.h"
#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char* argv[]) 
{

	//create engine
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	//std::unique_ptr<MyGame> game = std::make_unique<MyGame>();
	//game->Initialize();

	//create scene

	//load assets
	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;
	res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("sillycat.png", engine->GetRenderer());
	res_t<Font> font = ResourceManager::Instance().Get<Font>("Aadhunik.ttf", 12);

	//creating text
	std::unique_ptr<Text> text = std::make_unique<Text>(font);
	text->Create(engine->GetRenderer(), "WHAAAAAAAAAAA!", { 1,1,0,1 });

	//creating texture component
	std::unique_ptr<TextureComponent> textureComponent = std::make_unique<TextureComponent>();
	textureComponent->texture = texture;

	while (!engine->IsQuit()) {
		engine->Update();

		engine->GetRenderer().BeginFrame();

		engine->GetRenderer().DrawTexture(texture.get(), 200, 100, 0);
		text->Draw(engine->GetRenderer(), 200, 200);

		engine->GetRenderer().EndFrame();
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}
#include "StageSelectScene.hpp"
#include "PlayScene.hpp"
#include "AudioHelper.hpp"
#include "Slider.hpp"
#include "LOG.hpp"
#include "StartScene.hpp"

void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    AddNewObject(new Engine::Label("Tower Defense", "pirulen.ttf", 48, halfW, halfH / 2, 255, 255, 255, 255, 0.5, 0.5));
	btn = new Engine::ImageButton("start/dirt.png", "start/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
	btn->SetOnClickCallback(std::bind(&StartScene::StartOnClick, this, 2));
	AddNewControlObject(btn);

	AddNewObject(new Engine::Label("Start", "pirulen.ttf", 48, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
	AudioHelper::PlayAudio("lose.wav");
}
void StartScene::StartOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}


#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"

class StartScene final : public Engine::IScene {
private:
	ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
	explicit StartScene() = default;
	void Initialize() override;
	void StartOnClick(int stage);
};

#endif // STAGESELECTSCENE_HPP

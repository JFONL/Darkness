#ifndef IRONTURRET_HPP
#define IRONTURRET_HPP
#include "PlayScene.hpp"
#include "Bullet.hpp"
#include "Turret.hpp"

class PlayScene;
class IronTurret: public Turret {
public:
	static const int Price;
    IronTurret(float x, float y);
    void CreateBullet() override;
};
#endif // LASERTURRET_HPP



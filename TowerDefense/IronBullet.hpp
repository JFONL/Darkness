#ifndef IRONBULLET_HPP
#define IRONBULLET_HPP
#include "Bullet.hpp"

class IronBullet : public Bullet {
public:
	explicit IronBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // FIREBULLET_HPP


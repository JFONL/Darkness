#include "PlayScene.hpp"
#include "IronBullet.hpp"
#include "IronTurrent.hpp"
#include "AudioHelper.hpp"

const int IronTurret::Price = 1;
IronTurret::IronTurret(float x, float y) :
	Turret("play/tower-base.png", "play/turret-8.png", x, y, 300, Price, 0.5) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void IronTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	Engine::Point normal = Engine::Point(-normalized.y, normalized.x);
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new IronBullet(Position + normalized * 36 - normal * 6, diff, rotation, this));
	getPlayScene()->BulletGroup->AddNewObject(new IronBullet(Position + normalized * 36 + normal * 6, diff, rotation, this));
	AudioHelper::PlayAudio("laser.wav");
}


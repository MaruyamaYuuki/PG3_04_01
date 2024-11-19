#include "IScene.h"
#include "math/Vector2.h"

// ゲームシーン
class StageScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	KamataEngine::Vector2 playerPos = { 640,360 };
	KamataEngine::Vector2 bulletPos = { 0,0 };
	KamataEngine::Vector2 enemyPos = { 640,30 };

	float playerSpeed = 7.0f;
	float enemySpeed = 1.0f;

	float radius = 10.0f;

	bool isShot = false;
};
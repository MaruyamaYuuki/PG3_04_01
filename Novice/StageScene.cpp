#include "StageScene.h"
#include <Novice.h>

void StageScene::Init()
{
}

void StageScene::Update()
{
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);

	// 弾
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && !isShot) {
		isShot = true;
		bulletPos.x = playerPos.x;
		bulletPos.y = playerPos.y;
	}
	if (isShot) {
		bulletPos.y -= 15.0f;
		if (bulletPos.y <= 0) {
			isShot = false;
		}
	}

	if (Novice::CheckHitKey(DIK_A)) {
		if (playerPos.x >= 17) {
			playerPos.x -= playerSpeed;
		}
	}
	if (Novice::CheckHitKey(DIK_D)) {
		if (playerPos.x <= 1263) {
			playerPos.x += playerSpeed;
		}
	}

	//敵
	enemyPos.x += enemySpeed;
	if (enemyPos.x >= 1263) {
		enemySpeed *= -1;
	}
	if (enemyPos.x <= 17) {
		enemySpeed *= -1;
	}
	
		// シーン切り替え
	float a = enemyPos.x - bulletPos.x;
	float b = enemyPos.y - bulletPos.y;
	float r = radius + radius;
	if (r * r >= a * a + b * b) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
    Novice::ScreenPrintf(0, 0, "StageScene");
	Novice::DrawEllipse(int(playerPos.x), int(playerPos.y), int(radius), int(radius), 0.0f, WHITE, kFillModeSolid);
	if (isShot) {
    	Novice::DrawEllipse(int(bulletPos.x), int(bulletPos.y), int(radius), int(radius), 0.0f, BLUE, kFillModeSolid);
	}
	Novice::DrawEllipse(int(enemyPos.x), int(enemyPos.y), int(radius), int(radius), 0.0f, RED, kFillModeSolid);
}

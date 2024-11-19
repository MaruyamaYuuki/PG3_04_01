#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Init()
{
}

void ClearScene::Update()
{
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);

    if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
        sceneNo = TITLE;
    }
}

void ClearScene::Draw()
{
    Novice::ScreenPrintf(0, 0, "ClearScene");
}

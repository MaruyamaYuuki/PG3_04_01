#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Init()
{
}

void TitleScene::Update()
{
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);

    if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
        sceneNo = STAGE;
    }
}

void TitleScene::Draw()
{
    Novice::ScreenPrintf(0, 0, "Title Scene");
}

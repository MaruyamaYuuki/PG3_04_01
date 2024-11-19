#include "IScene.h"

// クリアシーン
class ClearScene : public IScene {
	void Init() override;
	void Update() override;
	void Draw() override;

};
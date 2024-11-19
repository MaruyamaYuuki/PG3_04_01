#include "IScene.h"

// タイトルシーン
class TitleScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

};
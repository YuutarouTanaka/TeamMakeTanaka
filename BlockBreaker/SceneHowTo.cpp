#include "ManageScene.h"
#include "Howto.h"
#include"DirectShowSound.h"
CSound howto;
void HowToScene::InitData()
{
	howto.LoadFile(TEXT("BlockBreakersBGM\\howto_bgm.mp3"));
	Data.HowtoSelectNum = HOWTO_KEY;

	howto.PlayRoop();
	fadestep = InMidstream;
}
void HowToScene::Input(InputKey** ppInput, ManageScene** ppManageScene, GamePad** ppGamePad)
{
	if (fadestep == OutEnd)
	{
		(*ppManageScene)->ChangeScene(NULL);
	}
	if (fadestep != free)return;

	//ここにコントローラー更新関数
	bool padCheck[2];

	for (int i = 0; i < 2; i++)
	{
		if ((*ppGamePad)->ChkPadConect(i)) padCheck[i] = TRUE;
		else{

			padCheck[i] = FALSE;
		}
	}
	(*ppGamePad)->UpdateControllerState();

	if ((*ppInput)->CheckKey(LEFT) == PUSH || (*ppInput)->CheckKey(A) == PUSH ||
		(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_LEFT) == GamePad::KEY_PUSH)
		|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_LEFT) == GamePad::KEY_PUSH))
	{
		if (Data.HowtoSelectNum >HOWTO_KEY)
		{
			Data.HowtoSelectNum--;
		}
	}
	if (
		(*ppInput)->CheckKey(RIGHT) == PUSH || (*ppInput)->CheckKey(D) == PUSH ||
		(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_PUSH)
		|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_PUSH)
)
	{
		if (Data.HowtoSelectNum<HOWTO_CRE)
		{
			Data.HowtoSelectNum++;
		}
	}
	if ((*ppInput)->CheckKey(ENTER) == PUSH || (*ppInput)->CheckKey(E) == PUSH ||
		(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadBtn_B) == GamePad::KEY_ON)
		|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadBtn_B) == GamePad::KEY_ON))
	{
		howto.Stop();
		fadestep = OutMidstream;
	}
	(*ppInput)->KeyUpdate();
}
void HowToScene::Render(MnageRender** ppRender)
{
	if (fadestep == OutMidstream){
		if ((*ppRender)->FedeOut() == true)fadestep = OutEnd;
	}
	if (fadestep == InMidstream){
		if ((*ppRender)->FedeIn() == true)fadestep = free;
	}
	switch (Data.HowtoSelectNum)
	{
	case HOWTO_KEY:
		(*ppRender)->DrawBox(0, "howto_key.png", 0.0, 0.0);
		break;
	case HOWTO_CONTROL:
			(*ppRender)->DrawBox(0, "howto_control.png", 0.0, 0.0);
			break;
	case HOWTO_ITEM:
		(*ppRender)->DrawBox(0, "howto_back.png", 0.0, 0.0);
		(*ppRender)->DrawBox(0, "howto_item.png", 0.0, 0.0);
		(*ppRender)->DrawCustomBox(4, "lightning.png", 65.5, 283.0, 1.7);
		(*ppRender)->DrawCustomBox(4, "poison.png",65.5,473.0, 1.7);
		(*ppRender)->DrawCustomBox(4, "change.png", 65.5, 663.0,1.7);
		(*ppRender)->DrawCustomBox(4, "tornado.png",685.5,283.0, 1.7);
		(*ppRender)->DrawCustomBox(4, "barrier.png",685.5,473.0, 1.7);
		break;
	case HOWTO_RULE:
		(*ppRender)->DrawBox(0, "howto_back.png", 0.0, 0.0);
		(*ppRender)->DrawBox(0, "howto_rule.png", 0.0, 0.0);
		break;
	case HOWTO_GAMESCENE:
		(*ppRender)->DrawBox(0, "howto_game.png", 0.0, 0.0);
		break;
	case HOWTO_CRE:
		(*ppRender)->DrawBox(0, "howto_cre.png", 0.0, 0.0);

	default:
		break;
	}
}
void HowToScene::Colison()
{

}
void HowToScene::Control(ManageScene** ppManageScene)
{

}
Scene* HowToScene::ChangeScene(int)
{
	return Scene::GO_Title();
}
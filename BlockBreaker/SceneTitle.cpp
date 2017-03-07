#include "ManageScene.h"
#include "DataTitle.h"
#include"DirectShowSound.h"
CSound title;
CSound select1;
CSound decision;

void TitleScene::InitData()
{
	title.LoadFile(TEXT("BlockBreakersBGM\\title.mp3"));
	select1.LoadFile(TEXT("BlockBreakersBGM\\select.mp3"));
	decision.LoadFile(TEXT("BlockBreakersBGM\\decision.mp3"));
	Data.TitleSelectnum = SELECT_HOWTO;
	title.Play();

	fadestep = InMidstream;
}
void TitleScene::Input(InputKey** ppInput, ManageScene** ppManageScene, GamePad** ppGamePad)
{
	if (fadestep == OutEnd)
	{
		(*ppManageScene)->ChangeScene(Data.TitleSelectnum);
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

	if ((*ppInput)->CheckKey(UP) == PUSH || (*ppInput)->CheckKey(W) == PUSH||
		(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH)
		|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH))
	{
		select1.PlayFromStart();
		if (Data.TitleSelectnum  >SELECT_HOWTO)
			Data.TitleSelectnum--;

	}

	if ((*ppInput)->CheckKey(DOWN) == PUSH || (*ppInput)->CheckKey(S) == PUSH ||
		(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH)
		|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH))
	{
		select1.PlayFromStart();
		if (Data.TitleSelectnum < SELECT_END)
		{
			Data.TitleSelectnum++;
		}
	}

	if ((*ppInput)->CheckKey(ENTER) == PUSH || (*ppInput)->CheckKey(E) == PUSH ||
		(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadBtn_B) == GamePad::KEY_ON)
		|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadBtn_B) == GamePad::KEY_ON))
	{
		title.Stop();
		fadestep = OutMidstream;
		decision.Play();

	}
	(*ppInput)->KeyUpdate();
}
void TitleScene::Render(MnageRender** ppRender)
{
	if (fadestep == OutMidstream){
		if ((*ppRender)->FedeOut() == true)fadestep = OutEnd;
	}
	if (fadestep == InMidstream){
		if ((*ppRender)->FedeIn() == true)fadestep = free;
	}
	(*ppRender)->DrawBox(0, "title_back.png", 0, 0);
	(*ppRender)->DrawBox(1, "title_logo.png",80, 160);
	(*ppRender)->DrawBox(2, "howto_logo.png", 440, 500);
	(*ppRender)->DrawBox(2, "battle_logo.png", 440, 640);
	(*ppRender)->DrawBox(2, "end_logo.png", 440, 780);
	switch (Data.TitleSelectnum)
	{
	case SELECT_HOWTO:
		(*ppRender)->DrawBox(2, "howto_logo_select.png", 440, 500 + ((float)Data.TitleSelectnum * MENU_HEIGHT));
		break;
	case SELECT_BATTLE:
		(*ppRender)->DrawBox(2, "battle_logo_select.png", 440, 500 + ((float)Data.TitleSelectnum * MENU_HEIGHT));
		break;
	case SELECT_END:
		(*ppRender)->DrawBox(2, "end_logo_select.png", 440, 500 + ((float)Data.TitleSelectnum * MENU_HEIGHT));
		break;
	default:
		break;
	}

	
}
void TitleScene::Colison()
{

}
void TitleScene::Control(ManageScene** ppManageScene)
{
	
}
Scene* TitleScene::ChangeScene(int Scenenum)
{
	switch (Scenenum)
	{

	case SELECT_HOWTO :
		return Scene::GO_HowTo();
		break;
	case SELECT_BATTLE:
		return Scene::GO_Battle();
		break;
	case SELECT_END:
		return  Scene::GO_End();
		break;
	default:
		return Scene::GO_HowTo();
	}
}
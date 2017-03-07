#include "ManageScene.h" 
#include "ManageRender.h"
#include "Inputkey.h"
Scene* Scene::GO_Title()
{
	static TitleScene Scene;
	return &Scene;
}
Scene* Scene::GO_Battle()
{
	static MainScene Scene;
	return &Scene;
}
Scene* Scene::GO_HowTo()
{
	static HowToScene Scene;
	return &Scene;
}
Scene* Scene::GO_End()
{
	PostQuitMessage(0);
	static TitleScene Scene;
	return &Scene;
}
#pragma once
//メニューの高さ
#define MENU_HEIGHT 140.0f
//タイトルメニューで選択している箇所
enum TITLESELECT
{
	SELECT_HOWTO,
	SELECT_BATTLE,
	SELECT_END
};
//タイトルの情報
struct DataTitle
{
	int TitleSelectnum;
};
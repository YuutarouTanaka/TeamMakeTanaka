#include "WindowCreate.h"
#include "main.h"
//ウィンドウ生成クラス
WindowCreate::WindowCreate(HINSTANCE h_Ins, WNDPROC WPC)
{
	
	m_winc.style = CS_HREDRAW | CS_VREDRAW;									   //ウィンドウスタイル HREDRAW:縦サイズが変わったら再描写
																			   //ウィンドウスタイル VREDRAW:横サイズが変わったら再描写
	m_winc.lpfnWndProc = WPC;									               //コールバック関数（ウィンドプロシージャWPC）へのポインタ
	m_winc.cbClsExtra = m_winc.cbWndExtra = 0;								   //ウィンドクラス構造体とうウィンドウインスタンスの後ろに割り当てる補足バイト数
	m_winc.hInstance = h_Ins;     //このクラスのためのウィンドウプロシージャがあるインスタンドハンドル
	m_winc.hIcon = LoadIcon(h_Ins,TEXT("ICON")); 
	//アイコン設定　NULL:システム定義のアイコン IDI_APPLICATION:規定のアプリアイコン
	m_winc.hCursor = LoadCursor(NULL, IDC_ARROW);                              //カーソル設定  NULL:システム定義のアイコン IDC_ARROW標準の矢印カーソル
	m_winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);                //ウィンドウの背景を設定
	m_winc.lpszMenuName = NULL;                                                //デフォルトメニューなんか難しいことができる
	m_winc.lpszClassName = TEXT("TEST"); //このウィンドウクラスにつける
	RegisterClass(&m_winc);
	int dH = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYFRAME) * 2;//縦幅(タイトルバーとフレーム２個分の幅)を
	//GetsystemMetricsでもとめてる
	int dW = GetSystemMetrics(SM_CXFRAME);                                 //横幅(フレーム二個分の幅)を
	//GetSystemMetricsでもとめてる
	m_hWnd = CreateWindow(                                                     //Createwindow:ウィンドウを作る関数
		TEXT("TEST"),                                                          //ウィンンドウクラスの名前を指定
		TEXT("BlockBreakers"),														   //ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,                                      //VISIBLE:最初に生成されるウィンドウOVERLAPPEDWINDOW:縁が沈んで盛り上がった
		CW_USEDEFAULT,                                                         //ウィンドウの横方向の初期位置x
		CW_USEDEFAULT,                                                         //ウィンドウの縦方向の初期位置y
		1280+dW ,                                                              //枠も合わせた横幅
		960+dH ,                                                              //枠も合わせた縦幅
		NULL,																       //オーナーウィンドウのハンドル
		NULL,															       //子供ウィンドウのＩＤ
		h_Ins,															   //アプリケーションインスタンスのハンドル
		NULL
		);
}

HWND WindowCreate::GethWnd()
{
	return m_hWnd;
}
#include "main.h"
//ウィンドウ作成のクラス
class WindowCreate
{
public:
	//コンストラクタ
		WindowCreate(HINSTANCE h_Ins, WNDPROC WPC);
	//デストラクタ
	~WindowCreate(){};
	//ウィンドウハンドウ取得
	HWND GethWnd();
private:
	//ウィンドウクラスのメンバ
	WNDCLASS m_winc;
	//ウィンドウハンドルのメンバ
	HWND m_hWnd;
};
#include <windows.h>
#include <iostream>
#include <winuser.h>

constexpr auto VK_F = 0x46;
constexpr BYTE vkFKey = VK_F;

HHOOK keyboardHook;
HHOOK mouseHook;

// 触发按键 1：左键 0：右键
INT LeftorRight = 1;
// 模拟点击方式 0：mouse_event 1：SendInput 2：WinIO
INT Func = 0;
// 点击时间间隔(ms)
INT dig_TL = 100;
//按下释放间隔时间(ms)
INT interval = 5;
// 选定的热键编号
INT HK_Index = 0;
// 标志配置是否锁定
BOOL CfgLocked = FALSE;
// 字符串形式的点击时间间隔
TCHAR str_TL[20] = { 0 };
// 标记连点是否正在进行
BOOL ClickRunning = FALSE;
// 连点线程句柄
HANDLE hClickThread = NULL;
HANDLE hClickThread_1 = NULL;


// 连点执行者，循环放在最里层，减少不必要的重复判断
DWORD WINAPI ClickRunner(LPVOID lpParam)
{
	while (TRUE){
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(interval);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(dig_TL);
	}
	return 0;
}

DWORD WINAPI FRunner(LPVOID lpParam)
{
	while (TRUE){
		keybd_event(vkFKey, 0, 0, 0);
		Sleep(interval);
		keybd_event(vkFKey, 0, KEYEVENTF_KEYUP, 0);
		Sleep(dig_TL / 2);
	}
	return 0;
}

// 键盘钩子处理函数
//LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
//    if (nCode >= 0) {
//        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
//        if (wParam == WM_KEYDOWN) {
//            std::cout << "Key Down: " << p->vkCode << std::endl;
//        }
//    }
//    return CallNextHookEx(NULL, nCode, wParam, lParam);
//}

// 鼠标钩子处理函数
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode >= 0) {
		MSLLHOOKSTRUCT* pMouse = (MSLLHOOKSTRUCT*)lParam;
		//侧键按下
		if (wParam == WM_XBUTTONDOWN) {
			if (pMouse->mouseData >> 16 == XBUTTON1) {
				hClickThread = CreateThread(NULL, 0, ClickRunner, NULL, 0, NULL);
				//ClickRunning = TRUE;
				std::cout << "Mouse XButton1 Pressed" << std::endl;
			}
			if (pMouse->mouseData >> 16 == XBUTTON2) {
				hClickThread_1 = CreateThread(NULL, 0, FRunner, NULL, 0, NULL);
				//ClickRunning = TRUE;
				std::cout << "Mouse XButton2 Pressed" << std::endl;
			}
		}
		//侧键释放
		if (wParam == WM_XBUTTONUP) {
			if (pMouse->mouseData >> 16 == XBUTTON1) {
				TerminateThread(hClickThread, 0);
				//ClickRunning = FALSE;
				std::cout << "Mouse XButton1 Released" << std::endl;
			}
			if (pMouse->mouseData >> 16 == XBUTTON2) {
				TerminateThread(hClickThread_1, 0);
				//ClickRunning = FALSE;
				std::cout << "Mouse XButton2 Released" << std::endl;
			}
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}



int main() {
	//HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, 0, 0);
	HHOOK hhkLowLevelMouse = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, 0, 0);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//UnhookWindowsHookEx(hhkLowLevelKybd);
	UnhookWindowsHookEx(hhkLowLevelMouse);

	return 0;
}


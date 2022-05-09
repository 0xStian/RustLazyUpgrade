#include <iostream>
#include <windows.h>
void LeftClick();
void RightClickUp();
void RightClickDown();
void Selector();
void Action();
void MouseMove(float x, float y);
float wood_x = 1025;
float wood_y = 370;
float stone_x = 1234;
float stone_y = 551;
float metal_x = 1115;
float metal_y = 745;
float hq_x = 755;
float hq_y = 770;
float current_x;
float current_y;

int main()
{
	printf("Y = Upgrade to Wood\n");
	printf("U = Upgrade to Stone\n");
	printf("I = Upgrade to Sheet Metal\n");
	printf("O = Upgrade to HQ Metal\n");
	Selector();
}

void Action() {
	RightClickDown();
	Sleep(20);
	MouseMove(current_x, current_y);
	Sleep(50);
	LeftClick();
	Sleep(20);
	RightClickUp();
	Sleep(100);
}

void Selector() {
	while (true) {
		if (GetAsyncKeyState(0x59)){ // Y
			current_x = wood_x;
			current_y = wood_y;
			Action();
		}
		else if (GetAsyncKeyState(0x55)){ // U
			current_x = stone_x;
			current_y = stone_y;
			Action();
		}
		else if (GetAsyncKeyState(0x49)){ // I
			current_x = metal_x;
			current_y = metal_y;
			Action();
		}
		else if (GetAsyncKeyState(0x4F)){ // O
			current_x = hq_x;
			current_y = hq_y;
			Action();
		}
		else {
			Sleep(100);
		}
	}
}

void MouseMove(float x, float y) {
	double fScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	double fScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);

	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = (long)fx;
	Input.mi.dy = (long)fy;
	SendInput(1, &Input, sizeof(INPUT));
}

void LeftClick()
{
	INPUT Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}

void RightClickDown()
{
	INPUT Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
}

void RightClickUp()
{
	INPUT Input = { 0 };
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &Input, sizeof(INPUT));
}



/*
Windows VK keys
0x41	A key
0x42	B key
0x43	C key
0x44	D key
0x45	E key
0x46	F key
0x47	G key
0x48	H key
0x49	I key
0x4A	J key
0x4B	K key
0x4C	L key
0x4D	M key
0x4E	N key
0x4F	O key
0x50	P key
0x51	Q key
0x52	R key
0x53	S key
0x54	T key
0x55	U key
0x56	V key
0x57	W key
0x58	X key
0x59	Y key
0x5A	Z key

0x30	0 key
0x31	1 key
0x32	2 key
0x33	3 key
0x34	4 key
0x35	5 key
0x36	6 key
0x37	7 key
0x38	8 key
0x39	9 key
*/
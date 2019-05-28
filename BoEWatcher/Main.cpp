#include <Windows.h>
#include <stdio.h>
extern int Main();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	AllocConsole(); //for printf help messages during development. 
	freopen("CON", "w", stdout);
	freopen("CON", "r", stdin);


	Main();
	return 0;
}
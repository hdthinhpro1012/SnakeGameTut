#include "Input.h"

Input::Input()
{
}

void Input::Process(MainWindow& wnd)
{
	//Snake only 1 direction per frame
	up = wnd.kbd.KeyIsPressed(VK_UP);
	down = wnd.kbd.KeyIsPressed(VK_DOWN);
	left = wnd.kbd.KeyIsPressed(VK_LEFT);
	right = wnd.kbd.KeyIsPressed(VK_RIGHT);
}

bool Input::Up()
{
	return up;
}

bool Input::Down()
{
	return down;
}

bool Input::Left()
{
	return left;
}

bool Input::Right()
{
	return right;
}



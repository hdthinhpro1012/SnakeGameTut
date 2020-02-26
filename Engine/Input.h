#pragma once

#include "MainWindow.h"

class Input
{
public:
	Input();
	void Process(MainWindow& wnd);
	bool Up();
	bool Down();
	bool Left();
	bool Right();

private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
};

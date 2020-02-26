#pragma once

struct Position
{
	void operator+= (Position another)
	{
		x += another.x;
		y += another.y;
	}
	bool operator== (Position another)
	{
		return (x == another.x) && (y == another.y);
	}
	int x;
	int y;
};
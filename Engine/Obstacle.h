#pragma once

#include "Position.h"
#include "Board.h"
#include "Snake.h"
#include <random>

class Obstacle
{
private:
	class oSegment
	{
	public:
		void Draw(Board& brd);
		Position& getPos();
	private:
		Position pos;
	};

public:
	Obstacle(Board& brd);

	//ComposeFrame()
	void Draw(Board& brd);

	//UpdateModel()
	void InitObstacle(Snake& snake);

	//IfSnakeCollapse()
	oSegment* getObstacleSegment();
	int getSize();

private:
	Board& brd;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xPosDist;
	std::uniform_int_distribution<int> yPosDist;
	static constexpr int maxSize = 100;
	int Size = 0;
	oSegment Segments[maxSize];
};

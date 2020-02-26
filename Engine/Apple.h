#pragma once

#include "Colors.h"
#include "Position.h"
#include "Snake.h"
#include "Board.h"
#include "Obstacle.h"
#include <random>

class Apple
{
public:
	Apple(Board& brd);
	void ChangePosition(Snake& snake, Obstacle& obstacle);
	void Draw(Board& brd) const;
	Position& getApplePos();
	
private:
	Board& brd;
	Position pos;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xPosDist;
	std::uniform_int_distribution<int> yPosDist;
	static constexpr Color color = Colors::Red;
};

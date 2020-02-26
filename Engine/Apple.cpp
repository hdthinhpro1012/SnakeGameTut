#include "Apple.h"

Apple::Apple(Board& brd)
	:
	brd(brd),
	rng(rd()),
	xPosDist(brd.getGridLeft() + 1,brd.getGridRight() - 1),
	yPosDist(brd.getGridTop() + 1,brd.getGridBottom() - 1)
{
	pos.x = xPosDist(rng);
	pos.y = yPosDist(rng);
}

void Apple::ChangePosition(Snake& snake, Obstacle& obstacle)
{
	bool IsAppleOnSnake = false;
	bool IsOnObstacle = false;
	do
	{
		pos.x = xPosDist(rng);
		pos.y = yPosDist(rng);
		IsAppleOnSnake = false;
		IsOnObstacle = false;
		for (int i = 0; i <= snake.getSize() - 1; ++i)
		{
			if (snake.getSnakeSegment()[i].getPos() == pos)
			{
				IsAppleOnSnake = true;
			}
		}
		for (int i = 0; i <= obstacle.getSize() - 1; ++i)
		{
			if (obstacle.getObstacleSegment()[i].getPos() == pos)
			{
				IsOnObstacle = true;
			}
		}
	} while ((IsAppleOnSnake) || (IsOnObstacle));
}

void Apple::Draw(Board& brd) const
{
	brd.DrawCell(pos, color);
}

Position& Apple::getApplePos()
{
	return pos;
}

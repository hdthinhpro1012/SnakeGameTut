#include "Obstacle.h"

Obstacle::Obstacle(Board& brd)
	:
	brd(brd),
	rd(),
	rng(rd()),
	xPosDist(brd.getGridLeft() + 1, brd.getGridRight() - 1),
	yPosDist(brd.getGridTop() + 1, brd.getGridBottom() - 1)
{
}

void Obstacle::Draw(Board& brd)
{
	for (int i = 0; i <= Size - 1; i++)
	{
		Segments[i].Draw(brd);
	}
}

void Obstacle::InitObstacle(Snake& snake)
{
	if (Size >= maxSize)
	{
		return;
	}
	Size++;
	bool IsOnSnake = false;
	do
	{
		IsOnSnake = false;
		Segments[Size - 1].getPos().x = xPosDist(rng);
		Segments[Size - 1].getPos().y = yPosDist(rng);
		for (int i = 0; i <= snake.getSize() - 1; ++i)
		{
			if (snake.getSnakeSegment()[i].getPos() == Segments[Size - 1].getPos())
			{
				IsOnSnake = true;
			}
		}
	} while (IsOnSnake);
}

Obstacle::oSegment* Obstacle::getObstacleSegment()
{
	return Segments;
}

int Obstacle::getSize()
{
	return Size;
}

//void Obstacle::oSegment::Draw() cannot identify its member variable: brd ???
void Obstacle::oSegment::Draw(Board& brd)
{
	brd.DrawCell(pos, Colors::White);
}

Position& Obstacle::oSegment::getPos()
{
	return pos;
}

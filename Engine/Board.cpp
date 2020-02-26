#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Position& pos, Color c)
{
	assert(pos.x >= left);
	assert(pos.y >= top);
	assert(pos.x <= right);
	assert(pos.y <= bottom);
	gfx.DrawRectDim(pos.x * dimension, pos.y * dimension, dimension, dimension, c);
}

void Board::DrawCellSnake(const Position& pos, Color c)
{
	assert(pos.x >= left);
	assert(pos.y >= top);
	assert(pos.x <= right);
	assert(pos.y <= bottom);
	gfx.DrawRectDim(pos.x * dimension + 1, pos.y * dimension + 1, dimension - 2, dimension - 2, c);
}

void Board::DrawGrid()
{
	Position temp;
	for (int i = left; i <= right; i++)
	{
		temp.x = i;
		temp.y = top;
		DrawCell(temp,Colors::Gray);
		temp.y = bottom;
		DrawCell(temp, Colors::Gray);
	}
	for (int i = top + 1; i <= bottom - 1; i++)
	{
		temp.x = left;
		temp.y = i;
		DrawCell(temp, Colors::Gray);
		temp.y = i;
		temp.x = right;
		DrawCell(temp, Colors::Gray);
	}
}

int Board::getGridRight()
{
	return right;
}

int Board::getGridBottom()
{
	return bottom;
}

int Board::getGridLeft()
{
	return left;
}

int Board::getGridTop()
{
	return top;
}
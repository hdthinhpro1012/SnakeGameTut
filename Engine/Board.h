#pragma once

#include "Graphics.h"
#include "Position.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Position& pos, Color c);
	void DrawCellSnake(const Position& pos, Color c);
	void DrawGrid();

	int getGridRight();
	int getGridBottom();
	int getGridLeft();
	int getGridTop();
private:
	static constexpr int dimension = 10;
	static constexpr int right = 74;
	static constexpr int bottom = 54;
	static constexpr int left = 5;
	static constexpr int top = 5;
	Graphics& gfx;
};
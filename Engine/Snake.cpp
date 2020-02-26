#include "Snake.h"

//Snake
Snake::Snake(Board& brd)
	:
	brd(brd),
	rd(),
	rng(rd()),
	xPosDist(brd.getGridLeft() + 1, brd.getGridRight() - 1),
	yPosDist(brd.getGridTop() + 1, brd.getGridBottom() - 1)
{
	//Head Initialize
	Position initial_pos = { xPosDist(rng), yPosDist(rng) };
	Segments[0].InitHead(initial_pos);
	//Body Initialize
	Color BodyColor[4] =
	{
		{10,100,32},
		{10,130,48},
		{18,160,48},
		{10,130,48}
	};
	for (int i = 1; i <= MaxSize - 1; i++)
	{
		Segments[i].InitBody(BodyColor[i%4]);
	}
}

Position& Snake::getSnakeHead()
{
	return Segments[0].getPos();
}

void Snake::Draw(Board& brd)
{
	brd.DrawCell(Segments[0].getPos(), Colors::Green);
	for (int i = Size - 1; i >= 1; i--)
	{
		Segments[i].Draw(brd);
	}
}

void Snake::Move(const Position delta_move) 
{
	for (int i = Size - 1; i >= 1; i--)
	{
		Segments[i].Follow(Segments[i - 1]);
	}
	Segments[0].MoveBy(delta_move);
}

void Snake::Eat(const Position delta_move)
{
	Size++;
	Move(delta_move);
}

Snake::Segment* Snake::getSnakeSegment()
{
	return Segments;
}

int Snake::getSize()
{
	return Size;
}


//Segment
void Snake::Segment::InitHead(const Position initial_pos)
{
	color = Snake::colorHead;
	pos = initial_pos;
}

void Snake::Segment::InitBody(const Color& c)
{
	color = c;
}

void Snake::Segment::Follow(Segment next)
{
	pos = next.pos;
}

void Snake::Segment::MoveBy(const Position delta_move)
{
	pos += delta_move;
}

void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCellSnake(pos,color);
}

Position& Snake::Segment::getPos()	//Position getPos(); will get assertion fail when run to left and bottom border. Why?
{
	return pos;
}

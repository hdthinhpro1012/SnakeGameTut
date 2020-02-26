#pragma once

#include "Colors.h"
#include "Board.h"
#include "Position.h"
#include <random>

class Snake
{
private:
	class Segment
	{
	public:
		//Two init function to redefine the color and snake head every game loop
		//Which the head uses
		void InitHead(const Position initial_pos);

		//Which every segments else uses
		void InitBody(const Color& c);
		
		//Body Segment move
		void Follow(Segment next);

		//Head move
		void MoveBy(const Position delta_move);

		void Draw(Board& brd) ;

		//Return 'Position&' breaks encapsulation since External element can value to private member: pos
		Position& getPos();    //Position getPos(); will get assertion fail when run to left and bottom border. Why ?
	private:
		Position pos;
		Color color;
	};

public:
	Snake(Board& brd);
	
	//IfSnakeCollapse()
	Position& getSnakeHead();
	Segment* getSnakeSegment();
	int getSize();

	//UpdateModel()
	void Draw(Board& brd) ;
	void Move(const Position delta_move);
	void Eat(const Position delta_move);

private:
	Board& brd;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xPosDist;
	std::uniform_int_distribution<int> yPosDist;

	static constexpr int MaxSize = 250;
	Segment Segments[MaxSize];
	int Size = 1;

	static constexpr Color colorHead = Colors::Green;
	static constexpr Color colorBody = Colors::Yellow;
};

/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	snake(brd),
	apple(brd),
	obstacle(brd),
	input()
{
	delta_move = { 0,0 };
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	Sleep(time_delay);
	input.Process(wnd);
	if (input.Up())
	{
		if (!((delta_move.x == 0) && (delta_move.y == 1)))
		{
			delta_move = { 0, -1 };
		}
	}
	else if (input.Down())
	{
		if (!((delta_move.x == 0) && (delta_move.y == -1)))
		{
			delta_move = { 0, 1 };
		}
	}
	else if (input.Left())
	{
		if (!((delta_move.x == 1) && (delta_move.y == 0)))
		{
			delta_move = { -1, 0 };
		}
	}
	else if (input.Right())
	{
		if (!((delta_move.x == -1) && (delta_move.y == 0)))
		{
			delta_move = { 1, 0 };
		}
	}
	/*		Cause a bug that you can move backward because there are 20 loops processes before 1 move
			so between 1/3 second assuming moving upward, can change to left but not move yet and then press downward
			since delta move now is {-1,0} you can change it to {0,1} causing snake to move to opposite direction
	++time_counter;
	if (time_counter == game_period)
	{
		time_counter = 0;
		if (IfSnakeEatApple(snake, apple))
		{
			snake.Eat(delta_move);
			apple.ChangePosition(snake);
		}
		else
		{
			snake.Move(delta_move);
		}

		if (IfSnakeCollapse(snake) || (snake.getSize() == 100))
		{
			IsGameOver = true;
		}
	}*/
	if (IfSnakeEatApple(snake, apple))
	{
		snake.Eat(delta_move);
		apple.ChangePosition(snake,obstacle);
		if (time_delay > 75)
		{
			obstacle.InitObstacle(snake);
			obstacle.InitObstacle(snake);
			obstacle.InitObstacle(snake);
			obstacle.InitObstacle(snake);
			time_delay -= 5;
		}
	}
	else
	{
		snake.Move(delta_move);
	}

	if (IfSnakeCollapse(snake) || (snake.getSize() == 100))
	{
		IsGameOver = true;
	}
}

bool Game::IfSnakeEatApple(Snake& snake, Apple& apple)
{
	return snake.getSnakeSegment()[0].getPos() == apple.getApplePos();
}

//More convenient way: include this function as a Snake class function member
bool Game::IfSnakeCollapse(Snake& snake)
{
	for (int i = snake.getSize() - 1; i > 0; i--)
	{
		if (snake.getSnakeSegment()[i].getPos() == snake.getSnakeSegment()[0].getPos())
		{
			flag = true;
		}
	}
	//Activate when using Position& Snake::getPos() but not Position Snake::getPos()
	if (!((snake.getSnakeHead().x >= brd.getGridLeft() + 1) && (snake.getSnakeHead().x <= brd.getGridRight() - 1)
		&& (snake.getSnakeHead().y >= brd.getGridTop() + 1) && (snake.getSnakeHead().y <= brd.getGridBottom() - 1)))
	{
		flag = true;
	}

	for (int i = 0; i <= obstacle.getSize() - 1; i++)
	{
		if (snake.getSnakeHead() == obstacle.getObstacleSegment()[i].getPos())
		{
			flag = true;
		}
	}

	return flag;
}

void Game::ComposeFrame()
{
	if ((delta_move.x == 0) && (delta_move.y == 0))
	{
		SpriteCodex::DrawTitle(300, 50, gfx);
	}
	if (IsGameOver)
	{
		SpriteCodex::DrawGameOver(0, 0, gfx);
	}
	else
	{
		brd.DrawGrid();
		obstacle.Draw(brd);
		apple.Draw(brd);
		snake.Draw(brd);
	}
}

#include "ColissionManager.h"

#include <iostream>

#include "GameData.h"

using namespace Colission;

void CheckWalls(Ball& ball, Player& player)
{
	if (ball.position.x + ball.radius > screenWidth)
	{
		ball.speed.x = (ball.speed.x * -1.0f);
		ball.position.x = (screenWidth - ball.radius);
	}
	else if (ball.position.x - ball.radius < 0.0f)
	{
		ball.speed.x = (ball.speed.x * -1.0f);
		ball.position.x = ball.radius;
	}
	else if (ball.position.y + ball.radius > screenHeight)
	{
		ball.speed.y = ball.speed.y * -1.0f;
		ball.position.y = screenHeight - ball.radius;
	}
	else if (ball.position.y < 0)
	{
		player.availableLives--;
		ball.position.x = player.position.x;
		ball.position.y = player.position.y + ball.radius + player.size.y;
		ball.speed.y *= -1.0f;
		ball.speed.x = 0.0f;
	}
}

void CheckPlayer(Ball& ball, Player& player)
{
	pointsQnty = 100;
	dyP1 = 0;
	dxP1 = player.size.x / (float)pointsQnty;


	for (int i = 0; i <= pointsQnty; ++i)
	{
		y = player.position.y + (player.size.y / 2) + i * dyP1;
		x = player.position.x - (player.size.x / 2) + i * dxP1;

		hickX = abs(x - ball.position.x);
		hickY = abs(y - ball.position.y);

		hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

		if (hypotenuse <= ball.radius)
		{
			ball.position.y = (player.position.y + (player.size.y / 2) + ball.radius);

			if (i < 50)
			{
				i = 50 - i;
				ball.speed.x = -1.0f;
			}
			else
			{
				i -= 50;
				ball.speed.x = 1.0f;
			}

			if (i < 10)
			{
				i = 10;
			}
			else if (i > 40)
			{
				i = 40;
			}

			ball.speed.x = ((ball.maxSpeed / 50) * i) * ball.speed.x;
			ball.speed.y = ball.maxSpeed - (ball.maxSpeed / 50) * i;

			break;
		}
	}

}

void CheckBricks(Ball& ball, Brick& brick, bool& collides)
{
	pointsQnty = 100;
	dyP1 = 0;
	dxP1 = brick.size.x / (float)pointsQnty;


	for (int i = 0; i <= pointsQnty; ++i)
	{
		y = brick.position.y - (brick.size.y / 2) + i * dyP1;
		x = brick.position.x - (brick.size.x / 2) + i * dxP1;

		hickX = abs(x - ball.position.x);
		hickY = abs(y - ball.position.y);

		hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

		if (hypotenuse <= ball.radius)
		{
			ball.speed.y *= - 1.0f;
			brick.isAlive = false;
			collides = true;
			ball.position.y = brick.position.y - (brick.size.y / 2) - ball.radius;

			break;
		}
	}

	if (!collides)
	{
		for (int i = 0; i <= pointsQnty; ++i)
		{
			y = brick.position.y + (brick.size.y / 2) + i * dyP1;
			x = brick.position.x - (brick.size.x / 2) + i * dxP1;

			hickX = abs(x - ball.position.x);
			hickY = abs(y - ball.position.y);

			hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

			if (hypotenuse <= ball.radius)
			{
				ball.speed.y *= -1.0f;
				brick.isAlive = false;
				collides = true;
				ball.position.y = brick.position.y + (brick.size.y / 2) + ball.radius;

				break;
			}
		}
	}

	if (!collides)
	{
		dyP1 = brick.size.y / (float)pointsQnty;
		dxP1 = 0;

		for (int i = 0; i <= pointsQnty; ++i)
		{
			y = brick.position.y - (brick.size.y / 2) + i * dyP1;
			x = brick.position.x - (brick.size.x / 2) + i * dxP1;

			hickX = abs(x - ball.position.x);
			hickY = abs(y - ball.position.y);

			hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

			if (hypotenuse <= ball.radius)
			{
				ball.speed.x *= -1.0f;
				ball.speed.y *= -1.0f;
				brick.isAlive = false;
				collides = true;
				ball.position.x = brick.position.x - (brick.size.x / 2) - ball.radius;

				break;
			}
		}
	}

	if (!collides)
	{
		for (int i = 0; i <= pointsQnty; ++i)
		{
			y = brick.position.y - (brick.size.y / 2) + i * dyP1;
			x = brick.position.x + (brick.size.x / 2) + i * dxP1;

			hickX = abs(x - ball.position.x);
			hickY = abs(y - ball.position.y);

			hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

			if (hypotenuse <= ball.radius)
			{
				ball.speed.x *= -1.0f;
				ball.speed.y *= -1.0f;
				brick.isAlive = false;
				collides = true;
				ball.position.x = brick.position.x + (brick.size.x / 2) + ball.radius;

				break;
			}
		}
	}
}

void CheckColissions(Ball& ball, Player& player, Brick bricks[])
{
	CheckWalls(ball, player);

	CheckPlayer(ball, player);

	bool collides = false;

	for (int i = 0; i < bricksQnty; i++)
	{
		if (bricks[i].isAlive)
		{
			CheckBricks(ball, bricks[i], collides);

			if (collides)
			{
				break;
			}
		}
	}
}

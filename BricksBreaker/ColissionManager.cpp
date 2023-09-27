#include "ColissionManager.h"

#include <iostream>

#include "sl.h"
#include "GameData.h"


using namespace Colission;
using namespace Assets;

void CheckWalls(Ball& ball, Player& player)
{
	if (ball.position.x + ball.radius > screenWidth)
	{
		ball.speed.x = (ball.speed.x * -1.0f);
		ball.position.x = (screenWidth - ball.radius);
		
		slSoundPlay(ballWall);
	}
	else if (ball.position.x - ball.radius < 0.0f)
	{
		ball.speed.x = (ball.speed.x * -1.0f);
		ball.position.x = ball.radius;
		slSoundPlay(ballWall);
	}
	else if (ball.position.y + ball.radius > screenHeight)
	{
		ball.speed.y = ball.speed.y * -1.0f;
		ball.position.y = screenHeight - ball.radius;
		slSoundPlay(ballWall);
	}
	else if (ball.position.y < 0 && !ball.isOut)
	{
		ball.isOut = true;
		player.availableLives--;
		slSoundPlay(missBall);
	}
	else if (ball.position.y < -200)
	{
		ball.isOut = false;
		ball.position.x = player.position.x;
		ball.position.y = player.position.y + ball.radius + (player.size.y / 2);
		ball.speed.y *= -1.8f;
		ball.speed.x = 0.0f;
	}

}

void CheckPlayer(Ball& ball, Player& player, bool& collides)
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
			collides = true;

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


			if (i < 10)
			{
				if (ball.speed.x > 0.0f)
				{
					ball.speed.x *= -1.0f;
				}

				if (ball.speed.y > 0)
				{
					ball.speed.y *= -1.0f;
				}
			}
			else if (i > 90)
			{
				if (ball.speed.x < 0)
				{
					ball.speed.x *= -1.0f;

				}

				if (ball.speed.y > 0)
				{
					ball.speed.y *= -1.0f;
				}
			}

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
				ball.speed.x *= -1.0f;
				brick.isAlive = false;
				collides = true;
				ball.position.y = brick.position.y + (brick.size.y / 2) + ball.radius;

				if (i < 10)
				{
					if (ball.speed.x > 0.0f)
					{
						ball.speed.x *= -1.0f;
					}

					if (ball.speed.y > 0)
					{
						ball.speed.y *= -1.0f;
					}
				}
				else if (i > 90)
				{
					if (ball.speed.x < 0)
					{
						ball.speed.x *= -1.0f;

					}

					if (ball.speed.y > 0)
					{
						ball.speed.y *= -1.0f;
					}
				}

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
				ball.speed.y = abs(ball.speed.y) * -1.0f;
				brick.isAlive = false;
				collides = true;
				ball.position.x = brick.position.x - (brick.size.x / 2) - ball.radius;

				if (ball.speed.y > 0.0f)
				{

				}
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
				ball.speed.y = abs(ball.speed.y) * -1.0f;
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
	bool collides = false;

	CheckWalls(ball, player);

	CheckPlayer(ball, player, collides);

	for (int i = 0; i < bricksQnty; i++)
	{
		if (bricks[i].isAlive)
		{
			CheckBricks(ball, bricks[i], collides);

			if (collides)
			{
				slSoundPlay(ballBrick);
				break;
			}
		}
	}
}

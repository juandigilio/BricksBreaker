#include "GameFunctions.h"

#include <iostream>


#include "GameData.h"

void CheckColissions(Ball& ball, Player& player, Brick bricks[])
{
	int pointsQnty = 100;
	float dyP1 = 0;
	float dxP1 = player.size.x / (float)pointsQnty;

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

	for (int i = 0; i <= pointsQnty; ++i)
	{
		float y = player.position.y + (player.size.y / 2) + i * dyP1;
		float x = player.position.x - (player.size.x / 2) + i * dxP1;

		float hickX = abs(x - ball.position.x);
		float hickY = abs(y - ball.position.y);

		float hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

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

	dxP1 = bricks[0].size.x / 10;
	dyP1 = bricks[0].size.y / 10;

	for (int i = 0; i < bricksQnty; i++)
	{
		if (bricks[i].isAlive)
		{
			for (int j = 0; j <= 10; ++j)
			{
				float y = bricks[i].position.y - (bricks[i].size.y / 2) + j * dyP1;
				float x = bricks[i].position.x - (bricks[i].size.x / 2) + j * dxP1;

				float hickX = abs(x - ball.position.x);
				float hickY = abs(y - ball.position.y);

				float hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

				if (hypotenuse <= ball.radius)
				{
					if (hickX > hickY)
					{
						//ball.position.y = (bricks[i].position.y - (bricks[i].size.y / 2) - ball.radius);
						bricks[i].isAlive = false;
						ball.speed.y *= -1.0f;
					}
					else
					{
						bricks[i].isAlive = false;
						ball.speed.x *= -1.0f;
					}	

					break;
				}
				else
				{
					y = bricks[i].position.y + (bricks[i].size.y / 2) + j * dyP1;
					x = bricks[i].position.x - (bricks[i].size.x / 2) + j * dxP1;

					hickX = abs(x - ball.position.x);
					hickY = abs(y - ball.position.y);

					hypotenuse = sqrt((hickY * hickY) + (hickX * hickX));

					if (hypotenuse <= ball.radius)
					{
						if (hickX > hickY)
						{
							//ball.position.y = (bricks[i].position.y - (bricks[i].size.y / 2) - ball.radius);
							bricks[i].isAlive = false;
							ball.speed.x *= -1.0f;
						}
						else
						{
							bricks[i].isAlive = false;
							ball.speed.y *= -1.0f;
						}

						break;
					}
				}
			}
		}
		
	}
}

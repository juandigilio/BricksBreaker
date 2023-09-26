#include "Entities.h"

#include <iostream>

#include "sl.h"

#include "GameFunctions.h"
#include "ColissionManager.h"


void SetEntities(Player& player, Ball& ball, Brick bricks[])
{
	player.size = { 100.0f, 100.0f };
	player.textureSize = { player.size.x , -player.size.y };
	player.position = { screenWidth * 0.5f, 50.0f };
	player.availableLives = 3;
	player.points = 0;
	player.speed = { 0.0f, 0.0f };
	player.texture = slLoadTexture("../Assets/Images/Ship.png");


	ball.radius = 8.0f;
	ball.textureSize.x = ball.radius * 2;
	ball.textureSize.y = ball.radius * 2;
	ball.position = { screenWidth * 0.5f, 50.0f };
	ball.speed = { 250.0f, 250.0f };
	ball.maxSpeed = 500.0f;
	ball.texture = slLoadTexture("../Assets/Images/Enemy.png");

	int image1 = slLoadTexture("../Assets/Images/brick1.png");
	int image2 = slLoadTexture("../Assets/Images/brick2.png");
	int image3 = slLoadTexture("../Assets/Images/brick3.png");
	int image4 = slLoadTexture("../Assets/Images/brick4.png");
	int image5 = slLoadTexture("../Assets/Images/brick5.png");
	int image6 = slLoadTexture("../Assets/Images/brick6.png");

	Vector2 position = { 90.0f, screenHeight - 50.0f };
	int iterator = 0;
	float brickSizeX = 60;
	float brickSizeY = 17;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			bricks[iterator].size.x = brickSizeX;
			bricks[iterator].size.y = brickSizeY;
			bricks[iterator].textureSize.x = brickSizeX;
			bricks[iterator].textureSize.y = brickSizeY;
			bricks[iterator].position = position;

			position.x += bricks[iterator].size.x + 10.0f;

			int ran = (rand() % 6) + 1;

			switch (ran)
			{
				case 1:
				{
					bricks[iterator].texture = image1;
					break;
				}
				case 2:
				{
					bricks[iterator].texture = image2;
					break;
				}
				case 3:
				{
					bricks[iterator].texture = image3;
					break;
				}
				case 4:
				{
					bricks[iterator].texture = image4;
					break;
				}
				case 5:
				{
					bricks[iterator].texture = image5;
					break;
				}
				case 6:
				{
					bricks[iterator].texture = image6;
					break;
				}
			}

			iterator++;
		}

		position.x = 90.0f;
		position.y -= brickSizeY + 10.0f;
	}
}

void GetInput(Player& player)
{
	if (slGetKey(SL_KEY_LEFT))
	{
		player.speed.x = -500.0f;
	}
	else if (slGetKey(SL_KEY_RIGHT))
	{
		player.speed.x = 500.0f;
	}
	else
	{
		player.speed.x = 0.0f;
	}

	if (player.position.x < 0.0f + (player.size.x / 2))
	{
		player.position.x = 0.0f + (player.size.x / 2);
	}

	if (player.position.x > screenWidth - (player.size.x / 2))
	{
		player.position.x = screenWidth - (player.size.x / 2);
	}
}

void Move(Player& player, Ball& ball)
{
	player.position.x += player.speed.x * slGetDeltaTime();
	player.position.y += player.speed.y * slGetDeltaTime();

	ball.position.x += ball.speed.x * slGetDeltaTime();
	ball.position.y += ball.speed.y * slGetDeltaTime();
}

void Draw(Ball& ball, Player& player, Brick bricks[])
{
	for (int i = 0; i < bricksQnty; i++)
	{
		if (bricks[i].isAlive)
		{

			slSprite(bricks[i].texture, bricks[i].position.x, bricks[i].position.y, bricks[i].textureSize.x, bricks[i].textureSize.y);
		}
	}

	slSprite(ball.texture, ball.position.x, ball.position.y, ball.textureSize.x, ball.textureSize.y);
	slSprite(player.texture, player.position.x, player.position.y, player.textureSize.x, player.textureSize.y);
}

void Loop(Ball& ball, Player& player, Brick bricks[])
{
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		if (slGetKey(SL_KEY_TAB))
		{
			player.textureSize.y++;
		}

		GetInput(player);
		CheckColissions(ball, player, bricks);
		Move(player, ball);

		slSetBackColor(0.1, 0.1, 0.1);
		Draw(ball, player, bricks);

		slRender();
	}	
}

void StartUp()
{
	srand(NULL);

	slWindow(screenWidth, screenHeight, "Brick-Breaker", false);

	Player player = Player();
	Brick bricks[bricksQnty];
	Ball ball = Ball();

	SetEntities(player, ball, bricks);

	Loop(ball, player, bricks);

	slClose();
}
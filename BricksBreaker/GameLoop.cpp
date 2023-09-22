
#include "Entities.h"

#include <iostream>

#include "sl.h"


void SetEntities(Player& player, Ball ball, Brick bricks[])
{
	player.size = { 100.0f, 100.0f };
	player.textureSize = { player.size.x , -player.size.y };
	player.position = { screenWidth * 0.5f, -20.0f };
	player.points = 0;
	player.speed = { 0.0f, 0.0f };
	player.texture = slLoadTexture("../Assets/Images/Ship.png");


	ball.radius = 20.0f;
	ball.textureSize.x = ball.radius * 2;
	ball.textureSize.y = ball.radius * 2;
	ball.position = { screenWidth * 0.5f, 50.0f };
	ball.speed = { 250.0f, 250.0f };
	ball.maxSpeed = 800.0f;
	ball.texture = slLoadTexture("../Assets/Images/Enemy.png");


	int image1 = slLoadTexture("../Assets/Images/brick1.png");
	int image2 = slLoadTexture("../Assets/Images/brick2.png");
	int image3 = slLoadTexture("../Assets/Images/brick3.png");
	int image4 = slLoadTexture("../Assets/Images/brick4.png");
	int image5 = slLoadTexture("../Assets/Images/brick5.png");
	int image6 = slLoadTexture("../Assets/Images/brick6.png");


	Vector2 position = { 90.0f, screenHeight - 50.0f };
	int iterator = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			bricks[iterator].position = position;
			position.x += bricks[iterator].size.x;

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
		position.y -= bricks[iterator].size.y;
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

void StartUp()
{
	srand(NULL);

	slWindow(screenWidth, screenHeight, "Brick-Breaker", false);

	Player player = Player();
	Brick bricks[bricksQnty];
	Ball ball = Ball();

	SetEntities(player, ball, bricks);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		if (slGetKey(SL_KEY_TAB))
		{
			player.textureSize.y++;
		}

		player.GetInput();

		player.Move();
		ball.Move();

		colissionManager.CheckColission(player, ball, gameData);
		colissionManager.CheckLimitsColission(ball, gameData);


		slSetBackColor(0.1, 0.1, 0.1);
		player.Draw();
		ball.Draw();
		for (int i = 0; i < bricksQnty; i++)
		{
			bricks[i].Draw();
		}

		slRender();
	}

	slClose();
}
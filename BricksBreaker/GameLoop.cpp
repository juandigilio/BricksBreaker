#include "Entities.h"

#include <iostream>

#include "sl.h"

#include "GameFunctions.h"
#include "ColissionManager.h"



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

	InitGame(player, ball, bricks);

	Loop(ball, player, bricks);

	slClose();
}
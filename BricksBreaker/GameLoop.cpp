#include "Entities.h"

#include <iostream>

#include "sl.h"

#include "GameFunctions.h"
#include "ColissionManager.h"

using namespace std;
using namespace Assets;
using namespace Statics;


void GetInput(Player& player, Ball& ball, Brick bricks[], GameSceen& currentSceen)
{
	if (slGetKey(SL_KEY_LEFT))
	{
		player.speed.x = -500.0f;
	}
	else if (slGetKey(SL_KEY_RIGHT))
	{
		player.speed.x = 500.0f;
	}
	else if (slGetKey(SL_KEY_TAB))
	{
		player.textureSize.y++;
	}
	else if (slGetKey(SL_KEY_ESCAPE))
	{
		currentSceen = MENU;
	}
	else
	{
		player.speed.x = 0.0f;
	}

	if (!player.isAlive)
	{
		InitGame(player, ball, bricks);
		currentSceen = MENU;
	}
}

void MoveEntities(Player& player, Ball& ball)
{
	player.position.x += player.speed.x * slGetDeltaTime();
	player.position.y += player.speed.y * slGetDeltaTime();

	if (player.position.x < 0.0f + (player.size.x / 2))
	{
		player.position.x = 0.0f + (player.size.x / 2);
	}
	else if (player.position.x > screenWidth - (player.size.x / 2))
	{
		player.position.x = screenWidth - (player.size.x / 2);
	}

	ball.position.x += ball.speed.x * slGetDeltaTime();
	ball.position.y += ball.speed.y * slGetDeltaTime();
}

void Draw(Player& player, Ball& ball, Brick bricks[])
{
	slSprite(gameBackground, screenWidth / 2, screenHeight / 2, screenWidth * 1.8, screenHeight * 1.5f);

	for (int i = 0; i < bricksQnty; i++)
	{
		if (bricks[i].isAlive)
		{
			slSprite(bricks[i].texture, bricks[i].position.x, bricks[i].position.y, bricks[i].textureSize.x, bricks[i].textureSize.y);
		}
	}

	slSprite(ball.texture, ball.position.x, ball.position.y, ball.textureSize.x, ball.textureSize.y);
	slSprite(player.texture, player.position.x, player.position.y, player.textureSize.x, player.textureSize.y);
	slSprite(player.texture, player.position.x, player.position.y, player.textureSize.x, player.textureSize.y);
}

void Update(Player& player, Ball& ball, Brick bricks[])
{
	if (player.firstTime)
	{
		slSoundPlay(ballStart);
		player.firstTime = false;
	}

	CheckColissions(player, ball, bricks);

	MoveEntities(player, ball);
}

void GameLoop(Player& player, Ball& ball, Brick bricks[], GameSceen& currentSceen)
{	
	GetInput(player, ball, bricks, currentSceen);

	Update(player, ball, bricks);

	Draw(player, ball, bricks);	
}

void Play(Player& player, Ball& ball, Brick bricks[], GameSceen& currentSceen)
{
	if (player.firstTime)
	{
		InitGame(player, ball, bricks);
	}

	GameLoop(player, ball, bricks, currentSceen);
}
#include "GameFunctions.h"

#include <iostream>

#include"sl.h"

#include "GameData.h"
#include "Entities.h"

using namespace Assets;

void SetEntities(Player& player, Ball& ball, Brick bricks[])
{
	player.size = { 100.0f, 100.0f };
	player.textureSize = { player.size.x , -player.size.y };
	player.position = { screenWidth * 0.5f, 0.0f };
	player.availableLives = 3;
	player.points = 0;
	player.speed = { 0.0f, 0.0f };
	player.texture = Assets::player;
	player.isAlive = true;


	ball.radius = 8.0f;
	ball.textureSize.x = ball.radius * 2;
	ball.textureSize.y = ball.radius * 2;
	ball.position = { screenWidth /2, 80.0f };
	ball.speed = { 250.0f, 250.0f };
	ball.maxSpeed = 700.0f;
	ball.texture = Assets::ball;
	ball.isAlive = true;
	ball.isOut = false;


	Vector2 position = { 90.0f, screenHeight - 50.0f };
	int iterator = 0;
	float brickSizeX = 60;
	float brickSizeY = 17;
	int ran;

	srand(NULL);

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			bricks[iterator].size.x = brickSizeX;
			bricks[iterator].size.y = brickSizeY;
			bricks[iterator].textureSize.x = brickSizeX;
			bricks[iterator].textureSize.y = brickSizeY;
			bricks[iterator].position = position;
			bricks[iterator].isAlive = true;
			bricks[iterator].isAcid = false;
			bricks[iterator].isIce = false;
			bricks[iterator].isBig = false;
			bricks[iterator].isStone = false;

			position.x += bricks[iterator].size.x + 10.0f;

			ran = (rand() % 5) + 1;

			switch (ran)
			{
			case 1:
			{
				bricks[iterator].texture = brick1;
				break;
			}
			case 2:
			{
				bricks[iterator].texture = brick2;
				break;
			}
			case 3:
			{
				bricks[iterator].texture = brick3;
				break;
			}
			case 4:
			{
				bricks[iterator].texture = brick4;
				break;
			}
			case 5:
			{
				bricks[iterator].texture = brick5;
				break;
			}
			}

			iterator++;
		}

		position.x = 90.0f;
		position.y -= brickSizeY + 10.0f;
	}

	for (int i = 0; i < 3; i++)
	{
		do
		{
			ran = (rand() % bricksQnty);

		} while (bricks[ran].isAcid == true);

		bricks[ran].isAcid = true;
	}

	for (int i = 0; i < 2; i++)
	{
		do
		{
			ran = (rand() % bricksQnty);

		} while (bricks[ran].isAcid == true || bricks[ran].isIce == true);

		bricks[ran].isIce = true;
	}

	for (int i = 0; i < 2; i++)
	{
		do
		{
			ran = (rand() % bricksQnty);

		} while (bricks[ran].isAcid == true || bricks[ran].isIce == true || bricks[ran].isBig == true);

		bricks[ran].isBig = true;
	}
}

void LoadAssets()
{
	ballBrick = slLoadWAV("../Assets/Music/ballBrick.wav");
	ballStart = slLoadWAV("../Assets/Music/ballStart.wav");
	//ballWall = slLoadWAV("../Assets/Music/ballWall.wav");
	missBall = slLoadWAV("../Assets/Music/missBall.wav");
	//powerUp = slLoadWAV("../Assets/Music/powerUp.wav");
	rLaunch = slLoadWAV("../Assets/Music/rLaunch.wav");
	explosion = slLoadWAV("../Assets/Music/explosion.wav");
	
	gameBackground = slLoadTexture("../Assets/Images/gameBackground.png");
	player = slLoadTexture("../Assets/Images/Ship.png");
	ball = slLoadTexture("../Assets/Images/Enemy.png");

	brick1 = slLoadTexture("../Assets/Images/brick1.png");
	brick2 = slLoadTexture("../Assets/Images/brick2.png");
	brick3 = slLoadTexture("../Assets/Images/brick3.png");
	brick4 = slLoadTexture("../Assets/Images/brick4.png");
	brick5 = slLoadTexture("../Assets/Images/brick5.png");
}

void InitGame(Player& player, Ball& ball, Brick bricks[])
{
	LoadAssets();

	SetEntities(player, ball, bricks);
}
#include "GameFunctions.h"

#include <iostream>

#include"sl.h"

#include "GameData.h"


using namespace Assets;
using namespace Statics;

void SetEntities(Player& player, Ball& ball, Brick bricks[])
{
	player.size = { 100.0f, 100.0f };
	player.textureSize = { player.size.x , player.size.y };
	player.position = { screenWidth * 0.5f, -30.0f };
	player.availableLives = 3;
	player.points = 0;
	player.speed = { 0.0f, 0.0f };
	player.texture = Assets::player;
	player.isAlive = true;


	ball.radius = 8.0f;
	ball.textureSize.x = ball.radius * 2;
	ball.textureSize.y = ball.radius * 2;
	ball.position = { (float)screenWidth /2, 80.0f };
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

	srand(time(NULL));

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			bricks[activeBricks].size.x = brickSizeX;
			bricks[activeBricks].size.y = brickSizeY;
			bricks[activeBricks].textureSize.x = brickSizeX;
			bricks[activeBricks].textureSize.y = brickSizeY;
			bricks[activeBricks].position = position;
			bricks[activeBricks].isAlive = true;
			bricks[activeBricks].isAcid = false;
			bricks[activeBricks].isIce = false;
			bricks[activeBricks].isBig = false;
			bricks[activeBricks].isStone = false;

			position.x += bricks[activeBricks].size.x + 10.0f;

			ran = (rand() % 5) + 1;

			switch (ran)
			{
				case 1:
				{
					bricks[activeBricks].texture = brick1;
					break;
				}
				case 2:
				{
					bricks[activeBricks].texture = brick2;
					break;
				}
				case 3:
				{
					bricks[activeBricks].texture = brick3;
					break;
				}
				case 4:
				{
					bricks[activeBricks].texture = brick4;
					break;
				}
				case 5:
				{
					bricks[activeBricks].texture = brick5;
					break;
				}
			}

			activeBricks++;
		}

		position.x = 90.0f;
		position.y -= brickSizeY + 10.0f;
	}

	for (int i = 0; i < 2; i++)
	{
		do
		{
			ran = (rand() % bricksQnty);

		} while (bricks[ran].isAcid == true);

		bricks[ran].isAcid = true;
		bricks[ran].texture = acidBrick;
		activeBricks--;
	}

	for (int i = 0; i < 2; i++)
	{
		do
		{
			ran = (rand() % bricksQnty);

		} while (bricks[ran].isAcid == true || bricks[ran].isIce == true);

		bricks[ran].isIce = true;
		bricks[ran].texture = iceBrick;
		activeBricks--;
	}

	for (int i = 0; i < 2; i++)
	{
		do
		{
			ran = (rand() % bricksQnty);

		} while (bricks[ran].isAcid == true || bricks[ran].isIce == true || bricks[ran].isBig == true);

		bricks[ran].isBig = true;
		bricks[ran].texture = bigBrick;
		activeBricks--;
	}

	for (int i = 0; i < 8; i++)
	{
		do
		{
			ran = (rand() % bricksQnty);

		} while (bricks[ran].isAcid == true || bricks[ran].isIce == true || bricks[ran].isBig == true || bricks[ran].isStone == true);

		bricks[ran].isStone = true;
		bricks[ran].texture = stoneBrick;
		activeBricks--;
	}
}

void LoadAssets()
{
	ballBrick = slLoadWAV("../Assets/Music/ballBrick.wav");
	ballStart = slLoadWAV("../Assets/Music/ballStart.wav");
	ballWall = slLoadWAV("../Assets/Music/ballWall.wav");
	missBall = slLoadWAV("../Assets/Music/missBall.wav");
	iced = slLoadWAV("../Assets/Music/iced.wav");
	danger = slLoadWAV("../Assets/Music/danger.wav");
	bigPlayer = slLoadWAV("../Assets/Music/bigPlayer.wav");
	
	
	gameBackground = slLoadTexture("../Assets/Images/gameBackground.png");
	player = slLoadTexture("../Assets/Images/Ship.png");
	playerEnd = slLoadTexture("../Assets/Images/ShipEnd.png");
	ball = slLoadTexture("../Assets/Images/Enemy.png");

	brick1 = slLoadTexture("../Assets/Images/brick1.png");
	brick2 = slLoadTexture("../Assets/Images/brick2.png");
	brick3 = slLoadTexture("../Assets/Images/brick3.png");
	brick4 = slLoadTexture("../Assets/Images/brick4.png");
	brick5 = slLoadTexture("../Assets/Images/brick5.png");
	acidBrick = slLoadTexture("../Assets/Images/acid.png");
	iceBrick = slLoadTexture("../Assets/Images/ice.png");
	bigBrick = slLoadTexture("../Assets/Images/big.png");
	stoneBrick = slLoadTexture("../Assets/Images/stone.png");
}

void InitGame(Player& player, Ball& ball, Brick bricks[])
{
	LoadAssets();

	SetEntities(player, ball, bricks);
}
#pragma once


const int screenWidth = 1024;
const int screenHeight = 768;
const int bricksQnty = 156;

struct Vector2
{
	float x;
	float y;
};

enum GameSceen
{
	MENU,
	GAME,
	INSTRUCTIONS,
	CREDITS,
	EXIT,
};

namespace Colission
{
	extern int pointsQnty;
	extern float dyP1;
	extern float dxP1;
	extern float y;
	extern float x;
	extern float hickX;
	extern float hickY;
	extern float hypotenuse;
};

namespace Assets
{
	//sounds
	extern int ballBrick;
	extern int ballStart;
	extern int ballWall;
	extern int missBall;
	extern int powerUp;
	extern int rLaunch;
	extern int explosion;
	extern int danger;

	//textures
	extern int menuBackground;

	extern int gameBackground;
	extern int player;
	extern int ball;

	extern int brick1;
	extern int brick2;
	extern int brick3;
	extern int brick4;
	extern int brick5;
	extern int acidBrick;
	extern int iceBrick;
	extern int bigBrick;
	extern int stoneBrick;

	extern int acidBrick;
	extern int acidPosX;
	extern int acidPosY;
	extern int iceBrick;
	extern int icePosX;
	extern int icePosY;
	extern int bigBrick;
	extern int bigPosX;
	extern int bigPosY;
	extern int stoneBrick;
	extern int stonePosX;
	extern int stonePosY;

	extern int menuSizeX;
	extern int menuSizeY;

	//Fonts
	extern int menuFont;
}


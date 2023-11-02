#pragma once

const int bricksQnty = 80;
const int totalAcids = 10;


struct Vector2
{
	float x;
	float y;
};

enum class GameSceen
{
	MENU,
	GAME,
	INSTRUCTIONS,
	CREDITS,
	EXIT,
};

namespace Globals
{
	extern const int screenWidth;
	extern const int screenHeight;
	extern int activeBricks;
	extern int activeAcids;
	extern int droppedAcids;
	extern int acidLastDrop;
	extern int icedStartPoint;
	extern bool acidGame;
	extern bool icedGame;
}

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
	extern int iced;
	extern int danger;
	extern int bigPlayer;

	//textures
	extern int menuBackground;

	extern int gameBackground;
	extern int player;
	extern int playerEnd;
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

	extern int acidPosX;
	extern int acidPosY;
	extern int icePosX;
	extern int icePosY;
	extern int bigPosX;
	extern int bigPosY;
	extern int stonePosX;
	extern int stonePosY;

	extern int menuSizeX;
	extern int menuSizeY;

	//Fonts
	extern int menuFont;
};


#pragma once


const int screenWidth = 1024;
const int screenHeight = 768;
const int bricksQnty = 200;

struct Vector2
{
	float x;
	float y;
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
	extern int ballBoing;
	extern int missBall;
	extern int powerUp;
	extern int rLaunch;
	extern int explosion;
	extern int danger;

	extern int player;
	extern int ball;

	extern int brick1;
	extern int brick2;
	extern int brick3;
	extern int brick4;
	extern int brick5;
}


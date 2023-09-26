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


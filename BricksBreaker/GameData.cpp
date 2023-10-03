#include "GameData.h"

namespace Statics
{
	extern const int screenWidth = 1024;
	extern const int screenHeight = 768;
	extern int activeBricks = 0;
	extern int acidStartPoint = 0;
	extern int iceStartPoin = 0;
	extern bool acidGame = false;
	extern bool icedGame = false;
}

namespace Colission
{
	extern int pointsQnty{};
	extern float dyP1{};
	extern float dxP1{};
	extern float y{};
	extern float x{};
	extern float hickX{};
	extern float hickY{};
	extern float hypotenuse{};
};

namespace Assets
{
	//sounds
	extern int ballBrick{};
	extern int ballStart{};
	extern int ballWall{};
	extern int missBall{};
	extern int iced{};
	extern int danger{};
	extern int bigPlayer{};

	//Assets
	extern int menuBackground{};

	extern int gameBackground{};
	extern int player{};
	extern int ball{};

	extern int brick1{};
	extern int brick2{};
	extern int brick3{};
	extern int brick4{};
	extern int brick5{};
	extern int acidBrick{};
	extern int iceBrick{};
	extern int bigBrick{};
	extern int stoneBrick{};

	extern int acidPosX{};
	extern int acidPosY{};
	extern int icePosX{};
	extern int icePosY{};
	extern int bigPosX{};
	extern int bigPosY{};
	extern int stonePosX{};
	extern int stonePosY{};

	extern int menuSizeX{};
	extern int menuSizeY{};


	//Fonts
	extern int menuFont{};
};
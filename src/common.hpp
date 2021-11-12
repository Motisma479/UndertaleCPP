#pragma once
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <raylib.h>
#include <string>

namespace common{
	class LivingEntity
	{
	public:
		int HP;
		int ATK;
		int DEF;
	};
	
	class Player : public LivingEntity
	{
	public:
		int LV;
		int EXP;
		int ATK_Modifier;
		int DEF_Modifier;
		std::string name = "Chara";
	};

	

	struct dialogue
	{
		std::string text;
	};
	
	class introduction
	{
	public:
		int textureY =0; 
		int introStartFrame = 0;
	};	
	
	class Game
	{
	public:
		Player player;
		int gameState; // 0 Start Screen; 1 Intro; 2 OverWorld; 3 Fight;4 GameOver
		dialogue* storedDialogue;
		int showDebug;

		Texture2D Texture;
		
		int frameCounter;
		introduction intro;
	};
}
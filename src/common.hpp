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
		int introSlideStartFrame = 0;
		float alpha = 0.0;
		int dialogueToShow = 0;
	};
	class combat
	{
	public:
		Texture2D box;
		int isStart = 1;
		
	};	
	
	class Game
	{
	public:
		float deltaTime;
		int frameCounter;

		int gameState; // 0 Start Screen; 1 Intro; 2 OverWorld; 3 Fight;4 GameOver

		int showDebug;
		int debugBattle;

		Player player;

		int textFrame = 0;
		Font HBIT;
		dialogue* storedDialogue;
		int dialogueLine;

		Texture2D Texture;
		
		introduction intro;
		combat battle;
	};






}
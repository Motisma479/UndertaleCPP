#pragma once
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <raylib.h>

#include <string>

namespace common{
	class Game;
	class LivingEntity
	{
	public:
		int HP;
		int maxHP;
		int ATK;
		int DEF;
		bool isHitable = true;
		std::string name = "Default";
	};	
	class Player : public LivingEntity
	{
	public:
		int LV;
		int EXP;
		int ATK_Modifier;
		int DEF_Modifier;
		bool isInBattle = false;
		
		Texture2D Soul;
		Vector2 position{0,0};
		Rectangle   sizeOfInteraction;
    	Rectangle   sizeOfFrame;
	};
	class Monster : public LivingEntity
	{
	protected:
		bool Mercyable = false;
		int backGround = 1;//0=None 1=Standare 2=boss
	public:
		
		//void attack();
		
		virtual void animate(common::Game &game) = 0;
		virtual void drawSprite() = 0;
	};

	struct dialogue
	{
		std::string text;
	};
	
	struct bodyPart
	{
		Texture2D texture;
		Rectangle sizeofDraw;
		Rectangle sizeofPart;
		Vector2 origin = {0,0};
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

	class button
	{
	public:
		bool	 	playerIsOn = false;
		Texture2D	buttonTexture;
		Vector2 	position;
		Rectangle   sizeOfInteraction;
    	Rectangle   sizeOfFrame;
	};

	class combat
	{
	public:
		Rectangle 	Box =  { 32, 250, 575, 140 };
		int 		isStart = 1;
		button fight;
		button action;
		button item;
		button mercy;
	};	
	
	class Game
	{
	public:
		float 			deltaTime;
		int 			frameCounter;

		int 			gameState; // 0 Start Screen; 1 Intro; 2 OverWorld; 3 Fight;4 GameOver

		int 			showDebug;
		int 			debugBattle;

		Player 			player;
		int 			textFrame = 0;
		Font 			HBIT;
		dialogue* 		storedDialogue;
		int 			dialogueLine;
		Monster* monsters[3];
		Texture2D 		Texture;
		
		introduction 	intro;
		combat 			battle;
	};






}
#include "draw.hpp"

void drawEnter(common::Game &game);
void updateEnter(common::Game &game);

void drawIntro(common::Game &game);
void updateIntro(common::Game &game);

void drawStart(common::Game &game);
void drawOverWorld(common::Game &game);
void drawFight(common::Game &game);
void drawGOver(common::Game &game);


void draw::updateGame(common::Game &game){
    switch (game.gameState)
    {
    case 0:
        updateEnter(game);
        break;
    case 1:
        updateIntro(game);
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }
}

void draw::drawGame(common::Game &game){
    switch (game.gameState)
    {
    case 0:
        drawEnter(game);
        break;
    case 1:
        drawIntro(game);
        break;
    case 2:
        drawStart(game);
        
        break;
    case 3:
        drawOverWorld(game);
        
        break;
    case 4:
        drawFight(game);
        break;
    case 5:
        drawGOver(game);
        break;
    default:
        break;
    }
}

// Draw Enter Menu
void drawEnter(common::Game &game){
    BeginDrawing();
        ClearBackground(RED);
        DrawTextureEx(game.Texture,{0,0},0,2,WHITE);
        DrawText("[PRESS 2 OR ENTER]",  220, 350, 20, LIGHTGRAY);
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Player name: %s", game.player.name.data()), 10, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("Player ATK: %d", game.player.ATK), 10, 40, 20, LIGHTGRAY);
            DrawText(TextFormat("Player DEF: %d", game.player.DEF), 10, 70, 20, LIGHTGRAY);
            DrawText(TextFormat("Player EXP: %d", game.player.EXP), 10, 100, 20, LIGHTGRAY);
            DrawText(TextFormat("Player LOVE: %d", game.player.LV), 10, 130, 20, LIGHTGRAY);
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("deltaTime: %f", game.deltaTime), 10, 450, 20, LIGHTGRAY);
        }
    EndDrawing();
}
//Update Enter Menu
void updateEnter(common::Game &game){
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)){
        game.gameState = 1;
        UnloadTexture(game.Texture);
        game.Texture = LoadTexture("assets/intro.png");
    } 
}

// Draw Intro
void drawIntro(common::Game &game){
    
    BeginDrawing();
        ClearBackground(BLUE);
        DrawTextureEx(game.Texture,{0,(float)game.intro.textureY},0,2,WHITE);
        DrawRectangle(0,0,SCREEN_WIDTH,38*1.5-1,ColorAlpha(RED,0.5));
        DrawRectangle(0,38*1.5+219,SCREEN_WIDTH,SCREEN_HEIGHT-38*1.5-221,ColorAlpha(RED,0.5));
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("deltaTime: %f", game.deltaTime), 10, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("Frame Counter: %d", game.frameCounter), 10, 40, 20, LIGHTGRAY);
            DrawText(TextFormat("introStartFrame: %d", game.intro.introStartFrame), 10, 70, 20, LIGHTGRAY);
            //DrawText(TextFormat("introStartFrame with modifier: %d", (int)(game.intro.introStartFrame /(1*game.deltaTime))), 10, 100, 20, LIGHTGRAY);
        }
    EndDrawing();
}
void updateIntro(common::Game &game){
    if (game.intro.introStartFrame <= 0){
        game.intro.introStartFrame = game.frameCounter;
        printf("work\n");
    }
    
    if (game.intro.textureY >= -4320 )
    {
        if(game.frameCounter >= game.intro.introStartFrame+100){
            game.intro.textureY -= SCREEN_HEIGHT ;
            game.intro.introStartFrame = game.frameCounter;
            printf("krow\n");
        }
    }
    else if (game.intro.textureY < -4320 && game.intro.textureY >= -5260)
    {
        
        
        if(game.frameCounter == game.intro.introStartFrame+2){
            game.intro.textureY -= 2 ;
            game.intro.introStartFrame = game.frameCounter;
            printf("krow\n");
        }
    }
    
   
}

// Draw Start Menu
void drawStart(common::Game &game){
    BeginDrawing();

        ClearBackground(RED);

        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
        }

    EndDrawing();
}

// Draw OverWorld
void drawOverWorld(common::Game &game){
    BeginDrawing();

        ClearBackground(GREEN);

        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
        }

    EndDrawing();
}

// Draw Fight Menu
void drawFight(common::Game &game){
    BeginDrawing();

        ClearBackground(BLACK);

        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
        }

    EndDrawing();
}

// Draw Game Over
void drawGOver(common::Game &game){
    BeginDrawing();

        ClearBackground(RAYWHITE);

        
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
        }


        DrawText(TextFormat("%s", game.storedDialogue[3].text.c_str()), 10, 40, 20, LIGHTGRAY);

    EndDrawing();
}
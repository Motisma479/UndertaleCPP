#include "draw.hpp"
#include "utils.hpp"

void drawEnter(common::Game &game);
void updateEnter(common::Game &game);

void drawIntro(common::Game &game);
void updateIntro(common::Game &game);

void drawStart(common::Game &game);
void drawOverWorld(common::Game &game);
void drawFight(common::Game &game);
void drawGOver(common::Game &game);
void updateFight(common::Game &game);

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
        updateFight(game);
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
        DrawRectangle(0,0,SCREEN_WIDTH,38*1.5-1,ColorAlpha(BLACK,1));
        DrawRectangle(0,38*1.5+219,SCREEN_WIDTH,SCREEN_HEIGHT-38*1.5-219,ColorAlpha(BLACK,1));
        DrawRectangle(0,38*1.5-1,SCREEN_WIDTH,SCREEN_HEIGHT-38*1.5-203,ColorAlpha(BLACK,game.intro.alpha));
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("deltaTime: %f", game.deltaTime), 10, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("Frame Counter: %d", game.frameCounter), 10, 40, 20, LIGHTGRAY);
            DrawText(TextFormat("introStartFrame: %d", game.intro.introStartFrame), 10, 70, 20, LIGHTGRAY);
            //DrawText(TextFormat("introStartFrame with modifier: %d", (int)(game.intro.introStartFrame /(1*game.deltaTime))), 10, 100, 20, LIGHTGRAY);
            DrawText(TextFormat("slideStartFrame: %d", game.intro.introSlideStartFrame), 10, 450, 20, LIGHTGRAY);
        }
        switch (game.intro.dialogueToShow)
        {
        case 0:
        utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[0].text.c_str()), 0, game.textFrame/5) , (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
            //DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[0].text.c_str()), (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE);
            //DrawText(TextFormat("%s", game.storedDialogue[0].text.c_str()), 110, 300, 20, LIGHTGRAY);
            break;
        case 1:
        utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[1].text.c_str()), 0, game.textFrame/5) , (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
        
            //DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[1].text.c_str()), (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE);
            //DrawText(TextFormat("%s", game.storedDialogue[1].text.c_str()), 110, 300, 20, LIGHTGRAY);
            break;
        case 2:
        utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[2].text.c_str()), 0, game.textFrame/5) , (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
        
            //DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[2].text.c_str()), (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE);
            //DrawText(TextFormat("%s", game.storedDialogue[2].text.c_str()), 110, 300, 20, LIGHTGRAY);
            break;
        case 3:
        utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[3].text.c_str()), 0, game.textFrame/5) , (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
        
            //DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[3].text.c_str()), (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE);
            //DrawText(TextFormat("%s", game.storedDialogue[3].text.c_str()), 110, 300, 20, LIGHTGRAY);
            break;
        case 4:
        utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[4].text.c_str()), 0, game.textFrame/5) , (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
        
            //DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[4].text.c_str()), (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE);
            //DrawText(TextFormat("%s", game.storedDialogue[4].text.c_str()), 110, 300, 20, LIGHTGRAY);
            break;
        case 5:
        utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[5].text.c_str()), 0, game.textFrame/5) , (Vector2){ 250.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
        
            //DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[5].text.c_str()), (Vector2){ 250.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE);
            //DrawText(TextFormat("%s", game.storedDialogue[5].text.c_str()), 110, 300, 20, LIGHTGRAY);
            break;
        case 6:
        utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[6].text.c_str()), 0, game.textFrame/5) , (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
        
           // DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[6].text.c_str()), (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE);

            //DrawTextEx(game.HBIT, TextFormat("%s", game.storedDialogue[6].text.c_str()), (Vector2){ 120.0f, 00.0f }, (float)-game.HBIT.baseSize, 4, WHITE);
            
            //DrawText(TextFormat("%s", game.storedDialogue[6].text.c_str()), 110, 300, 20, LIGHTGRAY);
            break;
        
        default:
            DrawText(TextFormat(""), 110, 300, 20, LIGHTGRAY);
            break;
        }
    EndDrawing();
}
void updateIntro(common::Game &game){
    if (game.intro.introStartFrame <= 0){
        game.intro.introStartFrame = game.frameCounter;
        //printf("work\n");
    }
    
    if (game.intro.textureY >= -4320 )
    {
        if(game.frameCounter >= game.intro.introStartFrame+50 && game.intro.alpha > 0 && game.frameCounter <= game.intro.introStartFrame+450){
            game.intro.alpha -= 0.05;
        }
        if(game.frameCounter >= game.intro.introStartFrame+450 && game.intro.alpha < 1){
            game.intro.alpha += 0.05;
        }
        if(game.frameCounter >= game.intro.introStartFrame+500){
            game.intro.textureY -= SCREEN_HEIGHT ;
            game.intro.introStartFrame = game.frameCounter;
            game.intro.dialogueToShow +=1;
            game.textFrame=0;
            //printf("krow\n");
        } 
    }
    else if (game.intro.textureY <= -4740 && game.intro.textureY >= -5224)
    {
        if(game.frameCounter <= game.intro.introStartFrame+1){
            //game.intro.alpha = 0.0;
            game.intro.textureY = -5224 ;
        }
        if(game.frameCounter >= game.intro.introStartFrame+50 && game.intro.alpha > 0 && game.frameCounter <= game.intro.introStartFrame + 250){
            game.intro.alpha -= 0.05;
            //printf("claire\n");
        }
        if(game.frameCounter >= game.intro.introStartFrame+250){
        
            if(game.frameCounter >= game.intro.introSlideStartFrame+2 && game.intro.textureY != -4740){
                game.intro.textureY += 2 ;
                game.intro.introSlideStartFrame = game.frameCounter;
                //printf("krow\n");
            }
            if (game.frameCounter >= game.intro.introSlideStartFrame+50 && game.intro.alpha < 1)
            {
                game.intro.alpha += 0.05;
                //printf("sombre\n");
            }
            /* if(game.intro.alpha >= 1){
                game.intro.alpha=0;
                game.intro.introSlideStartFrame=0;
                game.intro.introStartFrame=0;
                game.intro.textureY=0;
                game.gameState = 2;
            } */
        }
    }
    if((game.intro.textureY == -4740 && game.frameCounter >= game.intro.introStartFrame+250 && game.frameCounter >= game.intro.introSlideStartFrame+50 && game.intro.alpha >= 1)||(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER))){
        game.intro.alpha=0;
        game.intro.introSlideStartFrame=0;
        game.intro.introStartFrame=0;
        game.intro.textureY=0;
        game.textFrame=0;
        game.intro.dialogueToShow=0;
        UnloadTexture(game.Texture);
        if(game.debugBattle == 1){game.gameState = 4;}else{game.gameState = 5;}
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
        DrawText(TextSubtext("message", 0, game.frameCounter/10), 210, 160, 20, MAROON);
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
        }
        //DrawTextureEx(game.battle.box,(Vector2){ 0.0f, 0.0f },0,2,WHITE);
        Rectangle Test =  { 16, 16, 246, 246 };
        //DrawTextureRec(game.battle.box,Test,(Vector2){ Test.x, Test.y },WHITE);
        
        NPatchInfo ninePatchInfo1 = { (Rectangle){ 0.0f, 0.0f, 16.0f, 16.0f }, 10, 10, 10, 10, NPATCH_NINE_PATCH };
    

        DrawTextureNPatch(game.battle.box, ninePatchInfo1, Test, (Vector2){ 0.0f, 0.0f }, 0.0f, WHITE);
        //DrawTexturePro(game.battle.box,SRC, Test,(Vector2){ 0, 0 },12,WHITE);
        //utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[10].text.c_str()), 0, game.textFrame/5) , (Vector2){ 0.0f, 0.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
        //utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[11].text.c_str()), 0, game.textFrame/5) , (Vector2){ 0.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
    
    EndDrawing();
}
void updateFight(common::Game &game){
    if (game.battle.isStart == 1)
    {
        game.battle.box = LoadTexture("assets/battle_box.png");
        game.battle.isStart=0;
    }
    if (IsKeyPressed(KEY_ENTER)) game.frameCounter = 0;
    
}
// Draw Game Over
void drawGOver(common::Game &game){
    BeginDrawing();

        ClearBackground(RAYWHITE);

        
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
        }

        DrawText(TextFormat("%s", game.storedDialogue[5].text.c_str()), 10, 40, 20, LIGHTGRAY);

    EndDrawing();
}
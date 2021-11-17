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
        DrawText(TextSubtext("Debug Battle", 0, game.frameCounter/15), 10, 10, 20, MAROON);
        DrawFPS(525,10);
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 490, 10, 20, LIGHTGRAY);
        }
        
        
        
        DrawRectangleLinesEx(game.battle.Box,5,WHITE);
        utils::printText(game.HBIT,TextFormat("%s", game.player.name.c_str()),(Vector2){ 32.0f, 397.0f },(float)game.HBIT.baseSize/1.2,3,WHITE,game);
        utils::printText(game.HBIT,TextFormat("lv %d", game.player.LV),(Vector2){ 45 + game.player.name.length()*12, 397.0f },(float)game.HBIT.baseSize/1.25,3,WHITE,game);
        utils::printText(game.HBIT,TextFormat("HP"),(Vector2){ 244, 399.0f },(float)game.HBIT.baseSize/1.75,3,WHITE,game);
        DrawRectangle(275,400,1.25*game.player.maxHP,21,RED);// draw the maxHp bar
        DrawRectangle(275,400,1.25*game.player.HP,21,YELLOW);// draw the Hp bar
        // define the space between the Hp bar and the Hp Counter
        int spaceHpAndBar = 295+(1.25*game.player.maxHP);
        if (game.player.HP > game.player.maxHP)
        {
            spaceHpAndBar = 295+(1.25*game.player.HP);
        }
        
        utils::printText(game.HBIT,TextFormat("%d/%d",game.player.HP,game.player.maxHP),(Vector2){ spaceHpAndBar, 397.0f },(float)game.HBIT.baseSize/1.25,3,WHITE,game); // hp / maxHP

        DrawTexturePro(game.battle.fight.buttonTexture,game.battle.fight.sizeOfFrame  ,game.battle.fight.sizeOfInteraction,(Vector2){0,0},0,WHITE);
        //DrawTextureTiled(game.battle.fight.buttonTexture,game.battle.act.sizeOfFrame  ,game.battle.act.sizeOfInteraction,(Vector2){0,0},0,1,WHITE);
        DrawTexturePro(game.battle.action.buttonTexture,game.battle.action.sizeOfFrame    ,game.battle.action.sizeOfInteraction  ,(Vector2){0,0},0,WHITE);
        DrawTexturePro(game.battle.item.buttonTexture,game.battle.item.sizeOfFrame,game.battle.item.sizeOfInteraction,(Vector2){0,0},0,WHITE);
        DrawTexturePro(game.battle.mercy.buttonTexture,game.battle.mercy.sizeOfFrame,game.battle.mercy.sizeOfInteraction,(Vector2){0,0},0,WHITE);

        DrawTexturePro(game.player.Soul,game.player.sizeOfFrame,game.player.sizeOfInteraction,(Vector2){0,0},0,WHITE);
        //DrawTexture(game.player.Soul,game.player.position.x,game.player.position.y,WHITE);
    
    EndDrawing();
}
void updateFight(common::Game &game){
    if (game.battle.isStart == 1)
    {
        game.battle.isStart=0;
        game.player.Soul = LoadTexture("assets/soul.png");

        game.battle.fight.buttonTexture =       LoadTexture("assets/ACT.png");
        game.battle.action.buttonTexture =       LoadTexture("assets/ACT.png");
        game.battle.item .buttonTexture =       LoadTexture("assets/ACT.png");
        game.battle.mercy.buttonTexture =       LoadTexture("assets/ACT.png");

        
        utils::initButton(game.battle.fight, 32, 432);
        utils::initButton(game.battle.action, 185, 432);
        utils::initButton(game.battle.item, 345, 432);
        utils::initButton(game.battle.mercy, 500, 432);

        utils::initSoul(game.player);
    }
    if (IsKeyPressed(KEY_ENTER)) {
        game.frameCounter = 0;
    }
    //pour tester le resize box
    if (IsKeyPressed(KEY_LEFT_CONTROL)) {
        if(game.player.isInBattle){
            game.player.isInBattle = false;
        }
        else{
            game.player.isInBattle=true;
        }
    }
    if (game.player.isInBattle)
    {
        utils::boxResize(game,240, 250, 140, 140);
        if (!(game.battle.Box.x == 240 && game.battle.Box.y == 250 && game.battle.Box.width == 140 && game.battle.Box.height ==140)) {
            game.player.position.x =                0;
            game.player.position.y =                0;
            game.player.sizeOfInteraction.x =       game.player.position.x;
            game.player.sizeOfInteraction.y =       game.player.position.y;
        }
        //utils::boxResize(game,200, 250, 220, 140);
        //utils::boxResize(game,200, 170, 220, 220);
    }else{
        utils::boxResize(game,32, 250, 575, 140);
        if (!(game.battle.Box.x == 32 && game.battle.Box.y == 250 && game.battle.Box.width == 575 && game.battle.Box.height ==140)) {
            game.player.position.x =                0;
            game.player.position.y =                0;
            game.player.sizeOfInteraction.x =       game.player.position.x;
            game.player.sizeOfInteraction.y =       game.player.position.y;
        }
        /* game.player.position.x = 0;
        game.player.position.y = 0; */
    }

    //met le joueur dans le menu apres le box resize:
    if ((game.battle.Box.x == 32 && game.battle.Box.y == 250 && game.battle.Box.width == 575 && game.battle.Box.height ==140)  && game.player.position.y!=446) {
        game.player.position.x =                40;
        game.player.position.y =                446;
        game.player.sizeOfInteraction.x =       game.player.position.x;
        game.player.sizeOfInteraction.y =       game.player.position.y;
    }
    
    //movement du joueur dans le menu
    if (!game.player.isInBattle && (game.battle.Box.x == 32 && game.battle.Box.y == 250 && game.battle.Box.width == 575 && game.battle.Box.height ==140)) {
        if (IsKeyPressed(KEY_RIGHT)) { 
            game.player.position.x+=30;
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
        if (IsKeyPressed(KEY_LEFT)) { 
            game.player.position.x-=30;
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
    }

    if (CheckCollisionRecs(game.player.sizeOfInteraction, game.battle.fight.sizeOfInteraction))
    {
        game.battle.fight.sizeOfFrame.y =              1*game.battle.fight.sizeOfFrame.height;
    }else
    {
        game.battle.fight.sizeOfFrame.y =              0*game.battle.fight.sizeOfFrame.height;
    }
    
    
    

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
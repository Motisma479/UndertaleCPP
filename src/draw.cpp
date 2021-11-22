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

        //draw background
        DrawTexture(game.battle.background,0,0,WHITE);

        DrawText(TextSubtext("Debug Battle", 0, game.frameCounter/15), 10, 10, 20, MAROON);
        DrawFPS(525,10);
        if (game.showDebug == 1)
        {
            DrawText(TextFormat("Game State: %d", game.gameState), 450, 260, 20, LIGHTGRAY);
            DrawText(TextFormat("Button Id: %d", game.battle.buttonId), 450, 340, 20, LIGHTGRAY);
            DrawText(TextFormat("Item Id: %d", game.battle.itemId), 450, 360, 20, LIGHTGRAY);
            DrawText(TextFormat("f counter: %d", game.frameCounter), 180, 360, 20, LIGHTGRAY);
        }
        
        

        //draw the Box
        DrawRectangleLinesEx(game.battle.Box,5,WHITE);

        //draw the player name
        utils::printText(game.HBIT,TextFormat("%s", game.player.name.c_str()),(Vector2){ 32.0f, 397.0f },(float)game.HBIT.baseSize/1.2,3,WHITE,game);

        //draw the player LV
        utils::printText(game.HBIT,TextFormat("lv %d", game.player.LV),(Vector2){ 45.0f + (float) game.player.name.length()*12, 397.0f },(float)game.HBIT.baseSize/1.25,3,WHITE,game);

        //draw HP at front of the HP Bar
        utils::printText(game.HBIT,TextFormat("HP"),(Vector2){ 244, 399.0f },(float)game.HBIT.baseSize/1.75,3,WHITE,game);

        // draw the maxHp bar
        DrawRectangle(275,400,1.25*game.player.maxHP,21,RED);

        // draw the Hp bar
        DrawRectangle(275,400,1.25*game.player.HP,21,YELLOW);

        // define the space between the Hp bar and the Hp Counter
        int spaceHpAndBar = 295+(1.25*game.player.maxHP);
        if (game.player.HP > game.player.maxHP)
        {
            spaceHpAndBar = 295+(1.25*game.player.HP);
        }  

        // hp / maxHP
        utils::printText(game.HBIT,TextFormat("%d/%d",game.player.HP,game.player.maxHP),(Vector2){ (float) spaceHpAndBar, 397.0f },(float)game.HBIT.baseSize/1.25,3,WHITE,game); 

        //draw the FIGHT, ACT, ITEM and MERCY buttons
        DrawTexturePro(game.battle.fight.buttonTexture,game.battle.fight.sizeOfFrame    ,game.battle.fight.sizeOfInteraction    ,(Vector2){0,0},0,WHITE);
        DrawTexturePro(game.battle.action.buttonTexture,game.battle.action.sizeOfFrame  ,game.battle.action.sizeOfInteraction   ,(Vector2){0,0},0,WHITE);
        DrawTexturePro(game.battle.item.buttonTexture,game.battle.item.sizeOfFrame      ,game.battle.item.sizeOfInteraction     ,(Vector2){0,0},0,WHITE);
        DrawTexturePro(game.battle.mercy.buttonTexture,game.battle.mercy.sizeOfFrame    ,game.battle.mercy.sizeOfInteraction    ,(Vector2){0,0},0,WHITE);

        //Draw the soul of the player
        DrawTexturePro(game.player.Soul,game.player.sizeOfFrame,game.player.sizeOfInteraction,(Vector2){0,0},0,WHITE);
        //DrawTexture(game.player.Soul,game.player.position.x,game.player.position.y,WHITE);

        //Draw the monsters
        for (int i = 0; i < 1; i++){
            game.monsters[i]->animate(game);
            game.monsters[i]->drawSprite();
        }
        //game.monsters[GetRandomValue(0, 2)];
        if ((game.battle.Box.x == 32 && game.battle.Box.y == 250 && game.battle.Box.width == 575 && game.battle.Box.height ==140)  &&!game.player.isInBattle)
        {
            if (game.battle.buttonMenu == 0) //print the menu message
            {
                game.monsters[0]->drawTextBox(game);
            }else if (game.battle.buttonMenu == 1)// print the monster name and his hp bar for the fight button
            {
                DrawTextEx(game.HBIT,TextFormat("* %s",game.monsters[0]->name.c_str()),(Vector2){ game.battle.Box.x+68, game.battle.Box.y+20},(float)game.HBIT.baseSize/1,3,WHITE);
            }else if (game.battle.buttonMenu == 2)// print the monster name for the Act button
            {
                DrawTextEx(game.HBIT,TextFormat("* %s",game.monsters[0]->name.c_str()),(Vector2){ game.battle.Box.x+68, game.battle.Box.y+20},(float)game.HBIT.baseSize/1,3,WHITE);
            }else if (game.battle.buttonMenu == 3)// print the inventory
            {
                int basey = 20;
                int basex = 68;
                if (game.battle.isFirstPageItem)
                {
                    for (int i = 0; i < 4 && game.player.item[i] != NULL; i++)
                    {
                        if (game.player.item[i]->isNull == true)
                        {
                            break;
                        }
                        DrawTextEx(game.HBIT,TextFormat("* %s",game.player.item[i]->name.c_str()),(Vector2){ game.battle.Box.x+basex, game.battle.Box.y+basey},(float)game.HBIT.baseSize/1,3,WHITE);
                        basex += 240;
                        if (basex > 325)
                        {
                            basex = 68;
                            basey+=32;
                        }
                        
                        
                    }
                    DrawTextEx(game.HBIT,TextFormat("Page 1"),(Vector2){ game.battle.Box.x+355, game.battle.Box.y+80},(float)game.HBIT.baseSize/1,3,WHITE);
                }else{
                    for (int i = 4; i < 8 && game.player.item[i] != NULL; i++)
                    {
                        if (game.player.item[i]->isNull == true)
                        {
                            break;
                        }
                        DrawTextEx(game.HBIT,TextFormat("* %s",game.player.item[i]->name.c_str()),(Vector2){ game.battle.Box.x+basex, game.battle.Box.y+basey},(float)game.HBIT.baseSize/1,3,WHITE);
                        basex += 240;
                        if (basex > 325)
                        {
                            basex = 68;
                            basey+=32;
                        }
                        
                    }
                    DrawTextEx(game.HBIT,TextFormat("Page 2"),(Vector2){ game.battle.Box.x+355, game.battle.Box.y+80},(float)game.HBIT.baseSize/1,3,WHITE);
                }
                
                
                //DrawTextEx(game.HBIT,TextFormat("* %s",game.player.item[0]->name.c_str()),(Vector2){ game.battle.Box.x+75, game.battle.Box.y+20},(float)game.HBIT.baseSize/1,3,WHITE);
                //DrawTextEx(game.HBIT,TextFormat("* %s",game.player.item[1]->name.c_str()),(Vector2){ game.battle.Box.x+75, game.battle.Box.y+50},(float)game.HBIT.baseSize/1,3,WHITE);
            }
            

        }
        
        
        
        
        
    EndDrawing();
}
void updateFight(common::Game &game){
    //execute when a fight is started
    if (game.battle.isStart)
    {
        game.battle.isStart=0;
        game.player.Soul = LoadTexture("assets/soul.png");

        game.battle.fight.buttonTexture =       LoadTexture("assets/FIGHT.png");
        game.battle.action.buttonTexture =       LoadTexture("assets/ACT.png");
        game.battle.item .buttonTexture =       LoadTexture("assets/ITEM.png");
        game.battle.mercy.buttonTexture =       LoadTexture("assets/MERCY.png");

        switch (game.monsters[0]->backGround)
        {
        case 1:
            game.battle.background = LoadTexture("assets/standar_background.png");
            break;
        case 2:
            game.battle.background = LoadTexture("assets/boss_background.png");
            break;
        default:
            break;
        }
        
        
        utils::initButton(game.battle.fight, 31, 431);
        utils::initButton(game.battle.action, 184, 431);
        utils::initButton(game.battle.item, 344, 431);
        utils::initButton(game.battle.mercy, 499, 431);

        utils::initSoul(game.player);
    }

    //When Enter is pressed
    if (IsKeyPressed(KEY_ENTER)) {
        /* game.frameCounter = 0;
        game.monsters[0]->neutralPicker = GetRandomValue(21, 25); */
        if(game.battle.buttonMenu == 0){
            if (game.battle.buttonId == 0)
            {
                game.battle.buttonMenu = 1;
            }else if (game.battle.buttonId == 1)
            {
                game.battle.buttonMenu = 2;
            }else if (game.battle.buttonId == 2)
            {
                game.battle.buttonMenu = 3;
            }else if (game.battle.buttonId == 3)
            {
                game.battle.buttonMenu = 4;
            }
        }else if (game.battle.buttonMenu == 3)
        {
            utils::onItemUse(game,game.battle.itemId);
        }
        
        
        
    }
    //When Enter is pressed
    if (IsKeyPressed(KEY_X)) {
        /* game.frameCounter = 0;
        game.monsters[0]->neutralPicker = GetRandomValue(21, 25); */
        if (game.battle.buttonMenu == 1 || game.battle.buttonMenu == 2 || game.battle.buttonMenu == 3 || game.battle.buttonMenu == 4)
        {
            game.battle.buttonMenu = 0;
            game.battle.isFirstPageItem = true;
            game.battle.itemId=0;
            game.textFrame=0;
        }
    }

    //for test the resize box
    if (IsKeyPressed(KEY_LEFT_CONTROL)) {
        if(game.player.isInBattle){
            game.player.isInBattle = false;
            game.battle.isFighting = false;
        }
        else{
            game.player.isInBattle=true;
        }

        game.battle.EncounterPhase=false;
    }
    
    //box resizer
    if (game.player.isInBattle)
    {
        utils::boxResize(game,240, 250, 140, 140);
        // utils::boxResize(game,32, 200, 575, 190);//Test for box resize in height
        if (!(game.battle.Box.x == 240 && game.battle.Box.y == 250 && game.battle.Box.width == 140 && game.battle.Box.height ==140)) {
            game.player.position.x =                0;
            game.player.position.y =                0;
            game.player.sizeOfInteraction.x =       game.player.position.x;
            game.player.sizeOfInteraction.y =       game.player.position.y;
        }
    }else{
        utils::boxResize(game,32, 250, 575, 140);
        if (!(game.battle.Box.x == 32 && game.battle.Box.y == 250 && game.battle.Box.width == 575 && game.battle.Box.height ==140)) {
            game.player.position.x =                0;
            game.player.position.y =                0;
            game.player.sizeOfInteraction.x =       game.player.position.x;
            game.player.sizeOfInteraction.y =       game.player.position.y;

            game.textFrame=0;
        }
    }

    //Put the Player in the menu after the box resize:
    if ((game.battle.Box.x == 32 && game.battle.Box.y == 250 && game.battle.Box.width == 575 && game.battle.Box.height ==140)  && game.player.position.y!=446 && game.battle.buttonMenu == 0) {
        switch (game.battle.buttonId)
        {
        case 0:
            game.player.position.x =                40;
            break;
        case 1:
            game.player.position.x =                193;
            break;
        case 2:
            game.player.position.x =                353;
            break;
        case 3:
            game.player.position.x =                508;
            break;
        
        default:
            game.player.position.x =                40;
            break;
        }
        game.player.position.y =                446;
        game.player.sizeOfInteraction.x =       game.player.position.x;
        game.player.sizeOfInteraction.y =       game.player.position.y;
    }
    //Put the Player in the box for interaction
    if (game.battle.buttonMenu != 0 && ( game.player.position.y!=game.battle.Box.y+28  &&  game.player.position.y!=game.battle.Box.y+60)) {
        game.player.position.x =                game.battle.Box.x+32;
        game.player.position.y =                game.battle.Box.y+28;
        game.player.sizeOfInteraction.x =       game.player.position.x;
        game.player.sizeOfInteraction.y =       game.player.position.y;
    }
    //Put the Player in the box for combat
    if ( (game.battle.Box.width == 140 && game.battle.Box.height ==140) && (game.player.position.x < game.battle.Box.x && game.player.position.y < game.battle.Box.y)) {
        game.player.position.x =                game.battle.Box.x+game.battle.Box.width/2-game.player.Soul.width/2;
        game.player.position.y =                game.battle.Box.y+game.battle.Box.height/2-game.player.Soul.height/2;

        game.player.sizeOfInteraction.x =       game.player.position.x;
        game.player.sizeOfInteraction.y =       game.player.position.y;
        game.battle.isFighting = true;
    }
    //movement of the Player in the menu
    if (!game.player.isInBattle && (game.battle.Box.x == 32 && game.battle.Box.y == 250 && game.battle.Box.width == 575 && game.battle.Box.height ==140)) {
        if (IsKeyPressed(KEY_RIGHT)) {
            int pos = game.player.position.x;
            if(game.battle.buttonMenu==0)//button FIGHT ect...
            {
                switch (pos)
                {
                case 40:
                    game.player.position.x+=153;
                    break;
                case 193:
                    game.player.position.x+=160;
                    break;
                case 353:
                    game.player.position.x+=155;
                    break;
                case 508:
                    game.player.position.x+=0;
                    break;
                default:
                    game.player.position.x=40;
                }
            }
            if(game.battle.buttonMenu==3)//Item
            {
                if ((game.player.item[4]!=NULL && game.player.item[4]->isNull == false) && game.player.position.x == 312 && game.player.position.y == 278)
                {
                    game.battle.isFirstPageItem = false;
                    game.battle.itemId = 5;
                }
                
                switch (pos)
                {
                case 64:
                    if ((game.battle.isFirstPageItem&&(game.player.item[1]!= NULL || game.player.item[3] != NULL))||(game.battle.isFirstPageItem == false&&(game.player.item[5]!= NULL || game.player.item[7] != NULL)))
                    {
                        if (game.player.position.y == 278 && ((game.battle.isFirstPageItem && game.player.item[1]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[5]->isNull == false)))
                        {
                            game.player.position.x+=248;
                            game.battle.itemId += 1;
                        }
                        if (game.player.position.y == 310 && ((game.battle.isFirstPageItem && game.player.item[3]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[7]->isNull == false)))
                        {
                            game.player.position.x+=248;
                            game.battle.itemId += 1;
                        }
                        
                        
                        
                    }
                    break;
                default:
                    game.player.position.x=64;
                    game.battle.itemId -= 1;
                    break;
                }
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
        if (IsKeyPressed(KEY_LEFT)) { 
            int pos = game.player.position.x;
            if(game.battle.buttonMenu==0)//button FIGHT ect...
            {
                switch (pos)
                {
                case 40:
                    game.player.position.x-=0;
                    break;
                case 193:
                    game.player.position.x-=153;
                    break;
                case 353:
                    game.player.position.x-=160;
                    break;
                case 508:
                    game.player.position.x-=155;
                    break;
                default:
                    game.player.position.x=40;
                }
            }
            if(game.battle.buttonMenu==3)//ITEM
            {
                if ((game.player.item[4]!=NULL && game.player.item[4]->isNull == false) && game.player.position.x == 64 && game.player.position.y == 278)
                {
                    game.battle.isFirstPageItem = true;
                    game.battle.itemId = 0;
                }
                    switch (pos)
                    {
                    case 312:
                        game.player.position.x-=248;
                        game.battle.itemId -= 1;
                        
                        break;
                    default:
                        if ((game.battle.isFirstPageItem&&(game.player.item[2]!= NULL || game.player.item[3] != NULL))||(game.battle.isFirstPageItem == false&&(game.player.item[6]!= NULL || game.player.item[7] != NULL)))
                        {
                            if (game.player.position.y == 278 && ((game.battle.isFirstPageItem && game.player.item[1]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[5]->isNull == false)))
                            {
                                game.player.position.x=312;
                                game.battle.itemId += 1;
                            }
                            if (game.player.position.y == 310 && ((game.battle.isFirstPageItem && game.player.item[3]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[7]->isNull == false)))
                            {
                                game.player.position.x=312;
                                game.battle.itemId += 1;
                            }
                        }
                        
                        break;
                    }  
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
        if(IsKeyPressed(KEY_UP)){
            int pos = game.player.position.y;
            if(game.battle.buttonMenu==3)//ITEM
            {
                switch (pos)
                {
                case 310:
                    game.player.position.y-=32;
                    game.battle.itemId -= 2;
                    break;
                default:
                    if ((game.battle.isFirstPageItem&&(game.player.item[2]!= NULL || game.player.item[3] != NULL))||(game.battle.isFirstPageItem == false&&(game.player.item[6]!= NULL || game.player.item[7] != NULL)))
                    {
                        
                        if (game.player.position.x == 64 && ((game.battle.isFirstPageItem && game.player.item[2]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[6]->isNull == false)))
                        {
                            game.player.position.y=310;
                            game.battle.itemId += 2;
                        }
                        if (game.player.position.x == 312 && ((game.battle.isFirstPageItem && game.player.item[3]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[7]->isNull == false)))
                        {
                            game.player.position.y=310;
                            game.battle.itemId += 2;
                        }
                    }
                }
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
        if(IsKeyPressed(KEY_DOWN)){
            int pos = game.player.position.y;
            if(game.battle.buttonMenu==3)//ITEM
            {
                switch (pos)
                {
                case 278:
                    if ((game.battle.isFirstPageItem&&(game.player.item[2]!= NULL || game.player.item[3] != NULL))||(game.battle.isFirstPageItem == false&&(game.player.item[6]!= NULL || game.player.item[7] != NULL)))
                    {
                        
                        if (game.player.position.x == 64 && ((game.battle.isFirstPageItem && game.player.item[2]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[6]->isNull == false)))
                        {
                            game.player.position.y+=32;
                            game.battle.itemId += 2;
                        }
                        if (game.player.position.x == 312 && ((game.battle.isFirstPageItem && game.player.item[3]->isNull == false)||(game.battle.isFirstPageItem== false && game.player.item[7]->isNull == false)))
                        {
                            game.player.position.y+=32;
                            game.battle.itemId += 2;
                        }
                    }
                    break;
                default:
                    game.player.position.y=278;
                    game.battle.itemId -= 2;
                }
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
    }

    

    //collission with fight
    if (CheckCollisionRecs(game.player.sizeOfInteraction, game.battle.fight.sizeOfInteraction))
    {
        game.battle.fight.sizeOfFrame.y =              1*game.battle.fight.sizeOfFrame.height;
        game.battle.buttonId = 0;
    }else
    {
        game.battle.fight.sizeOfFrame.y =              0*game.battle.fight.sizeOfFrame.height;
    }
    //collission with act
    if (CheckCollisionRecs(game.player.sizeOfInteraction, game.battle.action.sizeOfInteraction))
    {
        game.battle.action.sizeOfFrame.y =              1*game.battle.action.sizeOfFrame.height;
        game.battle.buttonId = 1;
    }else
    {
        game.battle.action.sizeOfFrame.y =              0*game.battle.action.sizeOfFrame.height;
    } 
    //collission with item
    if (CheckCollisionRecs(game.player.sizeOfInteraction, game.battle.item.sizeOfInteraction))
    {
        game.battle.item.sizeOfFrame.y =              1*game.battle.item.sizeOfFrame.height;
        game.battle.buttonId = 2;
    }else
    {
        game.battle.item.sizeOfFrame.y =              0*game.battle.item.sizeOfFrame.height;
    } 
    //collission with mercy
    if (CheckCollisionRecs(game.player.sizeOfInteraction, game.battle.mercy.sizeOfInteraction))
    {
        game.battle.mercy.sizeOfFrame.y =              1*game.battle.mercy.sizeOfFrame.height;
        game.battle.buttonId = 3;
    }else
    {
        game.battle.mercy.sizeOfFrame.y =              0*game.battle.mercy.sizeOfFrame.height;
    } 
    
    if (game.battle.isFighting )
    {
        game.monsters[0]->updateAttack(game);
        game.monsters[0]->attack(game);
        
        
        if (IsKeyDown(KEY_RIGHT))
        {
            if (CheckCollisionRecs((Rectangle){game.battle.MoveZone.x,game.battle.MoveZone.y,game.battle.MoveZone.width-game.player.sizeOfInteraction.width,game.battle.MoveZone.height},game.player.sizeOfInteraction))
            {
            game.player.position.x+=1;
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
        if (IsKeyDown(KEY_LEFT))
          {
            if (CheckCollisionRecs((Rectangle){game.battle.MoveZone.x+game.player.sizeOfInteraction.width,game.battle.MoveZone.y,game.battle.MoveZone.width,game.battle.MoveZone.height},game.player.sizeOfInteraction))
            {
            game.player.position.x-=1;
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
          }
         if (IsKeyDown(KEY_UP))
         {
            if (CheckCollisionRecs((Rectangle){game.battle.MoveZone.x,game.battle.MoveZone.y+game.player.sizeOfInteraction.height,game.battle.MoveZone.width,game.battle.MoveZone.height},game.player.sizeOfInteraction))
            {
            game.player.position.y-=1;
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            if (CheckCollisionRecs((Rectangle){game.battle.MoveZone.x,game.battle.MoveZone.y,game.battle.MoveZone.width,game.battle.MoveZone.height-game.player.sizeOfInteraction.height},game.player.sizeOfInteraction))
            {
            game.player.position.y+=1;
            }
            game.player.sizeOfInteraction.x =        game.player.position.x;
            game.player.sizeOfInteraction.y =        game.player.position.y;
        }
        
        
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
#include "common.hpp"
#include "draw.hpp"
#include "loader.hpp"
#include "utils.hpp"
#include "monster.hpp"
//#include "items.hpp"

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Undertale");
    common::Game game;
    game.frameCounter = 0;
    game.storedDialogue = new common::dialogue[1024]; //nombre de ligne de text a stocker

    game.gameState=0;
    game.Texture = LoadTexture("assets/title.png");
    fileManagement::readAllFile((const char*)"dialogue.txt",(const char*)"save.txt", game);
    utils::updateName(game);
    game.player.maxHP=16+(game.player.LV*4);
    //Rectangle window = {,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};

    game.HBIT = LoadFontEx("assets/8bitoperator_jve.ttf", 32, 0, 250);

    /***************Temporary***************/
    //enemy
    // game.monsters[0] = new Sans();
    game.monsters[0] = new SpiderMonkey();
    //item
    utils::initItem(game);
    /***************************************/


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        draw::updateGame(game);
        draw::drawGame(game);
        /* printf("UNF");
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing(); */
        game.frameCounter++;
        game.deltaTime = GetFrameTime();
    }

    /***************Temporary***************/
    //enemy
    //delete game.monsters[1];
    delete game.monsters[0];
    //item
    for (int i = 0; game.player.item[i] != NULL; i++)
    {
        delete game.player.item[i];
    }
    /***************************************/

    UnloadFont(game.HBIT);
    delete[] game.storedDialogue;
    CloseWindow();

    return 0;
}
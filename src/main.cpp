#include "common.hpp"
#include "draw.hpp"
#include "loader.hpp"

int main()
{   
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Undertale");
    common::Game game;
    game.storedDialogue = new common::dialogue[10];//nombre de ligne de text a stocker

    game.player.ATK=9;
    game.gameState=0;
    fileManagement::loadAllFile((const char*)"dialogue.txt",(const char*)"save.txt", game);

    //Rectangle window = {,SCREEN_HEIGHT/2,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        
        draw::drawGame(game);
    }
    CloseWindow();
    delete game.storedDialogue;
    return 0;
}
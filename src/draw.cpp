#include "draw.hpp"

void drawStart(common::Game &game);
void drawIntro(common::Game &game);
void drawOverWorld(common::Game &game);
void drawFight(common::Game &game);
void drawGOver(common::Game &game);


void draw::updateGame(common::Game &game){

}
void draw::drawGame(common::Game &game){
    switch (game.gameState)
    {
    case 0:
        drawStart(game);
        break;
    case 1:
        drawIntro(game);
        break;
    case 2:
        drawOverWorld(game);
        break;
    case 3:
        drawFight(game);
        break;
    case 4:
        drawGOver(game);
        break;
    
    default:
        break;
    }
}

// Draw Start Menu
void drawStart(common::Game &game){
    BeginDrawing();

        ClearBackground(RED);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawText(TextFormat("Player ATK: %03i", game.player.ATK), 10, 10, 20, LIGHTGRAY);

    EndDrawing();
}

// Draw Intro
void drawIntro(common::Game &game){
    BeginDrawing();

        ClearBackground(BLUE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawText(TextFormat("Player ATK: %03i", game.player.ATK), 10, 10, 20, LIGHTGRAY);

    EndDrawing();
}

// Draw OverWorld
void drawOverWorld(common::Game &game){
    BeginDrawing();

        ClearBackground(GREEN);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawText(TextFormat("Player ATK: %03i", game.player.ATK), 10, 10, 20, LIGHTGRAY);

    EndDrawing();
}

// Draw Fight Menu
void drawFight(common::Game &game){
    BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawText(TextFormat("Player ATK: %03i", game.player.ATK), 10, 10, 20, LIGHTGRAY);

    EndDrawing();
}

// Draw Game Over
void drawGOver(common::Game &game){
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawText(TextFormat("Player ATK: %03i", game.player.ATK), 10, 10, 20, LIGHTGRAY);
        DrawText(TextFormat("%s", game.storedDialogue[3].text.c_str()), 10, 40, 20, LIGHTGRAY);

    EndDrawing();
}
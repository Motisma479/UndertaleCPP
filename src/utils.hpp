#include "common.hpp"
namespace utils{
    void printText(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint, common::Game &game);
    void updateName(common::Game &game);
    void boxResize(common::Game &game, int x, int y, int width, int height);
    void initButton(common::button &button, int x, int y);
    void initSoul(common::Player &player);
}
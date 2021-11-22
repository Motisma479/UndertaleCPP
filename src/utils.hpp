#include "common.hpp"
namespace utils{
    void printText(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint, common::Game &game);
    void updateName(common::Game &game);
    std::string preLoadMonsterName(std::string text,std::string monsterName);
    void boxResize(common::Game &game, int x, int y, int width, int height);
    void initButton(common::button &button, int x, int y);
    void initSoul(common::Player &player);
    void initItem(common::Game &game);
    void onItemUse(common::Game &game, int itemPos);
}
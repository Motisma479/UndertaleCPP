#include "utils.hpp"
void utils::printText(Font font, const char *rawText, Vector2 position, float fontSize, float spacing, Color tint, common::Game &game){
    std::string modifiedText = rawText;
    // copy;
    int positionII= position.y;
    
    
    for (int i = 0; modifiedText[i] != '\0'; i++)
        {//text parameter
            if(modifiedText[i]=='<' && modifiedText[i+1]=='l' && modifiedText[i+2]=='n' && modifiedText[i+3]=='>'){
                std::string copy = modifiedText.c_str() + i+4;
                modifiedText.replace(i,modifiedText.length()-i," ");
                

                positionII+=35;
                printText(font, (const char *)copy.c_str(), (Vector2){position.x, positionII}, fontSize, spacing, tint, game);
                
                
            }
            
            if ((modifiedText[i]=='<'))
            {
                modifiedText.replace(i,4,"\0");
            }
            if ((modifiedText[i]=='\n'))
            {
                modifiedText.replace(i,1," ");
            }
    }
    DrawTextEx(font, (const char *)modifiedText.c_str(), position, fontSize, spacing, tint);
    game.textFrame++;
}

void utils::updateName(common::Game &game){
    for (int i = 0; i < 1024; i++)
    {
        std::string text = game.storedDialogue[i].text;
        for (int i = 0; text[i] != '\0'; i++)
        {
            if(text[i]=='<' && text[i+1]=='@' && text[i+2]=='>'){
                text.replace(i,3,game.player.name);
            }
        }
        game.storedDialogue[i].text = text;
    } 
}
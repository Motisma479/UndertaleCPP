#include "utils.hpp"
#include "items.hpp"
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
                printText(font, (const char *)copy.c_str(), (Vector2){position.x, (float)positionII}, fontSize, spacing, tint, game);
                
                
            }

            if ((modifiedText[i]=='<'))
            {
                modifiedText.replace(i,4,"\0");
            }
            if ((modifiedText[i]=='#'))
            {
                modifiedText.replace(i,modifiedText.length()-i," ");
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

std::string utils::preLoadMonsterName(std::string text,std::string monsterName){
    for (int i = 0; i < 1024; i++)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            if(text[i]=='<' && text[i+1]=='E' && text[i+2]=='>'){
                text.replace(i,3,monsterName);  
            }
        }
    }
    return text;
}

void utils::boxResize(common::Game &game, int x, int y, int width, int height){
    int speed = 16;
    //x
    if (game.battle.Box.x < x)
    {
        game.battle.Box.x+=speed/2.1;
        if(game.battle.Box.x > x){game.battle.Box.x = x;}
    }else if (game.battle.Box.x > x)
    {
        game.battle.Box.x-=speed/2.1;
        if(game.battle.Box.x < x){game.battle.Box.x = x;}
    }
    //y
    if (game.battle.Box.y < y)
    {
        game.battle.Box.y+=speed/2.1;
        if(game.battle.Box.y > y){game.battle.Box.y = y;}
    }else if (game.battle.Box.y > y)
    {
        game.battle.Box.y-=speed/2.1;
        if(game.battle.Box.y < y){game.battle.Box.y = y;}
    }
    //height
    if (game.battle.Box.height < height)
    {
        game.battle.Box.height+=speed;
        if(game.battle.Box.height > height){game.battle.Box.height = height;}
    }else if (game.battle.Box.height > height)
    {
        game.battle.Box.height-=speed;
        if(game.battle.Box.height < height){game.battle.Box.height = height;}
    }
    //width
    if (game.battle.Box.width < width)
    {
        game.battle.Box.width+=speed;
        if(game.battle.Box.width > width){game.battle.Box.width = width;}
    }else if (game.battle.Box.width > width)
    {
        game.battle.Box.width-=speed;
        if(game.battle.Box.width < width){game.battle.Box.width = width;}
    }
}

void utils::initButton(common::button &button, int x, int y){
        button.position.x =                 x;
        button.position.y =                 y;

        button.sizeOfFrame.height =         button.buttonTexture.height/2;
        button.sizeOfFrame.width =          button.buttonTexture.width;
        button.sizeOfFrame.x =              0;
        button.sizeOfFrame.y =              0*button.sizeOfFrame.height;

        button.sizeOfInteraction.x =        button.position.x;
        button.sizeOfInteraction.y =        button.position.y;
        button.sizeOfInteraction.height =   button.sizeOfFrame.height;
        button.sizeOfInteraction.width =    (float)button.buttonTexture.width;
}

void utils::initSoul(common::Player &player){

        player.sizeOfFrame.height =         player.Soul.height/2;
        player.sizeOfFrame.width =          player.Soul.width;
        player.sizeOfFrame.x =              0*player.sizeOfFrame.width;

        player.sizeOfInteraction.x =        player.position.x;
        player.sizeOfInteraction.y =        player.position.y;
        player.sizeOfInteraction.height =   player.sizeOfFrame.height;
        player.sizeOfInteraction.width =    (float)player.Soul.width;
}


void utils::initItem(common::Game &game){
    game.player.item[0] = new Sandwich();
    game.player.item[1] = new Sandwich();
    game.player.item[2] = new Sandwich();
    game.player.item[3] = new Sandwich();
    game.player.item[4] = new Dandelion();
    game.player.item[5] = new RealKnife();
    game.player.item[6] = new RealKnife();
    game.player.item[7] = new Dandelion();
}

void utils::onItemUse(common::Game &game, int itemPos){
    //0: unConsumables and unEquippable; 1: Consumables; 2: Equippable;
    if(game.player.item[itemPos]->type == 1){
        if (game.player.HP < game.player.maxHP)
        {
            game.player.HP += game.player.item[itemPos]->HP_regen;
            if (game.player.HP > game.player.maxHP)
            {
                game.player.HP=game.player.maxHP;
            }
            
        }
        
    }
    if (itemPos+1 == 8 || game.player.item[itemPos+1]==NULL || game.player.item[itemPos+1]->isNull)
    {
        delete game.player.item[itemPos];
        game.player.item[itemPos] = new null();
    }
    else{
        for (int i = itemPos; game.player.item[i]!=NULL; i++)
        {
            
            game.player.item[i]=game.player.item[i+1];
            if (game.player.item[i+1] == NULL)
            {
                delete game.player.item[i];
                game.player.item[i] = new null();
                break;
            }
            if (game.player.item[i+1] == NULL)
            {
                delete game.player.item[i];
                game.player.item[i] = new null();
                break;
            }
        }
        
    }
    
}
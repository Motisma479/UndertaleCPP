#include "loader.hpp"
#include <assert.h>

void fileManagement::readAllFile(const char* dialogue, const char* save, common::Game &game){

    //load file
    FILE* conv = fopen(dialogue, "r");
    if (conv == NULL)//cant't open the file
    {
        printf("Cannot dialogue.txt\n");
        assert(conv);
        
    }
    else{printf("dialogue file load sucess\n");}
    char line[1024];
    for (int id = 0; fgets(line, 1024, conv) != NULL; id++)
    {
        std::string cur = &line[0];
        char* next = &line[0];
        for (int i = 0; cur[i] != '\0'; i++)
        {
            if(cur[i]=='<' && cur[i+1]=='@' && cur[i+2]=='>'){
                cur.replace(i,3,game.player.name);
            }
        }
        game.storedDialogue[id].text = cur;
    }
    //unload file
    fclose(conv);
    //load file
    FILE* sav = fopen(save, "r");
    if (sav == NULL)//cant't open the file
    {
        printf("Cannot save.txt\n");
        assert(sav);
    }
    else{printf("save file load sucess\n");}
    char lineII[1024];
    for (int id = 0; fgets(lineII, 1024, sav) != NULL; id++)
    {
        char* value = &lineII[0];
        switch (id)
        {
        case 0:
            game.showDebug = atoi(value+10);
            break;
        case 2:
            game.player.name = value+6;
            break;
        case 3:
            game.player.HP = atoi(value+4);
            break;
        case 4:
            game.player.ATK = atoi(value+5);
            break;
        case 5:
            game.player.DEF = atoi(value+5);
            break;
        case 6:
            game.player.EXP = atoi(value+5);
            break;
        case 7:
            game.player.LV = atoi(value+6);
            break;
        }
    }
    //unload file
    fclose(sav);
}
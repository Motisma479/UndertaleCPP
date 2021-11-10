#include "loader.hpp"
#include <assert.h>

void fileManagement::loadAllFile(const char* dialogue, const char* save, common::Game &game){
    FILE* conv = fopen(dialogue, "r");
    if (conv == NULL)//cant't open the file
    {
        printf("Cannot dialogue.txt\n");
        assert(conv);
        
    }
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

    FILE* sav = fopen(save, "r");
    if (sav == NULL)//cant't open the file
    {
        printf("Cannot save.txt\n");
        assert(sav);
    }
}
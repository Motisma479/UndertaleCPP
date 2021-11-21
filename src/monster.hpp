#include "common.hpp"
//Sans
class Sans : public common::Monster
{
private:
    /* data */
    common::bodyPart head;
    common::bodyPart torso;
    common::bodyPart legs;
    Rectangle sizeOfEnemie;
public:
    Sans();
    ~Sans();
    void animate(common::Game &game) override;
    void drawSprite() override;
};

Sans::Sans() {
    

    head.texture = LoadTexture("assets/monster/sans/head.png");
    head.sizeofPart = {0,0,(float)head.texture.width,(float)head.texture.height};
   

    torso.texture = LoadTexture("assets/monster/sans/torso.png");
    torso.sizeofPart = {0,0,(float)torso.texture.width,(float)torso.texture.height};
    

    legs.texture = LoadTexture("assets/monster/sans/legs.png");
    legs.sizeofPart = {0,0,(float)legs.texture.width,(float)legs.texture.height};
    

    //sizeOfEnemie = {200,200, (float)torso.texture.width*2, (float)head.texture.height+torso.texture.height+legs.texture.height};
}

Sans::~Sans() {
    UnloadTexture(head.texture);
    UnloadTexture(torso.texture);
    UnloadTexture(legs.texture);
}

void Sans::animate(common::Game &game) {
    //frameIndex++;
    
    legs.sizeofDraw = {(float)((SCREEN_HEIGHT/2)+legs.texture.width/2+5),game.battle.Box.y-legs.texture.height*2-16,(float)legs.texture.width*2,(float)legs.texture.height*2};//the x and y is the pos of the texture in the window 
    torso.sizeofDraw = {(float)((SCREEN_HEIGHT/2)+16),legs.sizeofDraw.y-torso.texture.height*2,(float)torso.texture.width*2,(float)torso.texture.height*2};//the x and y is the pos of the texture in the window
    head.sizeofDraw = {(float)SCREEN_HEIGHT/2+6+head.texture.width,torso.sizeofDraw.y-head.texture.height-17,(float)head.texture.width*2,(float)head.texture.height*2};//the x and y is the pos of the texture in the window
    
}

void Sans::drawSprite() {
    //DrawRectangle(10,10,100,100,YELLOW);
    DrawTexturePro(legs.texture,legs.sizeofPart,legs.sizeofDraw,legs.origin,0,WHITE);
    DrawTexturePro(torso.texture,torso.sizeofPart,torso.sizeofDraw,torso.origin,0,WHITE);
    DrawTexturePro(head .texture,head .sizeofPart,head .sizeofDraw,head.origin,0,WHITE);

    //DrawTexture   (head.texture,                0,0,                          WHITE);
    //printf("%f,%f,%f,%f\n",sizeOfEnemie.x, sizeOfEnemie.y, sizeOfEnemie.width, sizeOfEnemie.height);
    
}

//SpiderMonkey
class SpiderMonkey : public common::Monster
{
private:
    common::bodyPart Monkhead;
    common::bodyPart Monktorso;
    common::bodyPart Monklegs;
    common::bodyPart MonkPogI;
    common::bodyPart MonkPogII;
    Rectangle sizeOfEnemie;
    unsigned int rgb;
    bool asDoneHisFristAnimation=false;
    bool torsoLeftToRight=true;
    bool headLeftToRight=false;
    bool legsLeftToRight=false;
public:
    SpiderMonkey();
    ~SpiderMonkey();
    void animate(common::Game &game) override;
    void drawTextBox(common::Game &game) override;
    void drawSprite() override;
};

SpiderMonkey::SpiderMonkey() {
    Monkhead.texture = LoadTexture("assets/monster/spiderMonkey/head.png");
    Monkhead.sizeofPart = {0,0,(float)Monkhead.texture.width,(float)Monkhead.texture.height};
   

    Monktorso.texture = LoadTexture("assets/monster/spiderMonkey/torso.png");
    Monktorso.sizeofPart = {0,0,(float)Monktorso.texture.width,(float)Monktorso.texture.height};
    

    Monklegs.texture = LoadTexture("assets/monster/spiderMonkey/legs.png");
    Monklegs.sizeofPart = {0,0,(float)Monklegs.texture.width,(float)Monklegs.texture.height};

    MonkPogI.texture = LoadTexture("assets/monster/spiderMonkey/pog_1.png");
    MonkPogI.sizeofPart = {0,0,(float)MonkPogI.texture.width,(float)MonkPogI.texture.height};

    MonkPogII.texture = LoadTexture("assets/monster/spiderMonkey/pog_2.png");
    MonkPogII.sizeofPart = {0,0,(float)MonkPogII.texture.width,(float)MonkPogII.texture.height};

    maxHP=100;
    HP=maxHP;
    name="SpiderMonkey";
    backGround=2;
    ATK=1;
	DEF=1;

    neutralPicker = GetRandomValue(21, 25);
    
}

SpiderMonkey::~SpiderMonkey() {
    UnloadTexture(Monkhead.texture);
    UnloadTexture(Monktorso.texture);
    UnloadTexture(Monklegs.texture);
    UnloadTexture(MonkPogI.texture);
    UnloadTexture(MonkPogII.texture);
}

void SpiderMonkey::animate(common::Game &game) {
    Monklegs.sizeofDraw = {(float)((SCREEN_HEIGHT/2)+Monklegs.texture.width/2+5),game.battle.Box.y-Monklegs.texture.height*2-16,(float)Monklegs.texture.width*2,(float)Monklegs.texture.height*2};//the x and y is the pos of the texture in the window 
    Monktorso.sizeofDraw = {(float)((SCREEN_HEIGHT/2)+16),Monklegs.sizeofDraw.y-Monktorso.texture.height*2,(float)Monktorso.texture.width*2,(float)Monktorso.texture.height*2};//the x and y is the pos of the texture in the window
    Monkhead.sizeofDraw = {(float)SCREEN_HEIGHT/2+6+Monkhead.texture.width,Monktorso.sizeofDraw.y-Monkhead.texture.height-17,(float)Monkhead.texture.width*2,(float)Monkhead.texture.height*2};//the x and y is the pos of the texture in the window
    MonkPogI.sizeofDraw = {(float)Monktorso.sizeofDraw.x-200,Monktorso.sizeofDraw.y-MonkPogI.texture.height-17,(float)MonkPogI.texture.width*6,(float)MonkPogI.texture.height*6};//the x and y is the pos of the texture in the window
    MonkPogII.sizeofDraw = {(float)Monktorso.sizeofDraw.x+200+MonkPogII.texture.width,Monktorso.sizeofDraw.y-MonkPogII.texture.height-17,(float)MonkPogII.texture.width*6,(float)MonkPogII.texture.height*6};//the x and y is the pos of the texture in the window
    
    if(!asDoneHisFristAnimation){
        Monkhead.origin.x+=3;
        Monklegs.origin.y-=3;
        Monktorso.origin.x-=3;
        if (Monkhead.origin.x==0 && Monklegs.origin.x==0 && Monktorso.origin.x==0)
        {
            asDoneHisFristAnimation = true;
        }
        

        // if (Monkhead.origin.x == 0)
        // {
        //     Monkhead.origin.x = -3;
        // }
        if (Monkhead.origin.x > 345)
        {
            Monkhead.origin.x = -345;
        }
        // if (Monklegs.origin.y == 0)
        // {
        //     Monklegs.origin.y = 3;
        // }
        if (Monklegs.origin.y < -345)
        {
            Monklegs.origin.y = 345;
        }
        // if (Monktorso.origin.x == 0)
        // {
        //     Monktorso.origin.x = 3;
        // }
        if (Monktorso.origin.x < -345)
        {
            Monktorso.origin.x = 345;
        }
    }
    else{
        if (torsoLeftToRight)
        {
            Monktorso.origin.x+=2;
            if (Monktorso.origin.x > 10)
            {
                torsoLeftToRight=false;
            }
        }else{
            Monktorso.origin.x-=2;
            if (Monktorso.origin.x < -10)
            {
                torsoLeftToRight=true;
            }
        }
        
        if (headLeftToRight)
        {
            Monkhead.origin.x+=2;
            if (Monkhead.origin.x > 5)
            {
                headLeftToRight=false;
            }
        }else{
            Monkhead.origin.x-=2;
            if (Monkhead.origin.x < -5)
            {
                headLeftToRight=true;
            }
        }

        if (legsLeftToRight)
        {
            Monklegs.origin.x+=0.1;
            if (Monklegs.origin.x > 2) 
            {
                legsLeftToRight=false;
            }
        }else{
            Monklegs.origin.x-=0.1;
            if (Monklegs.origin.x < -2)
            {
                legsLeftToRight=true;
            }
        }
        
    }
   
    if (MonkPogI.origin.x > 10)
    {
       MonkPogI.origin.y+=0.25;
    }else{
        MonkPogI.origin.y -=0.25;
    }
    if (MonkPogI.origin.y > 10)
    {
        MonkPogI.origin.x -=0.25;
    }
    else{
        MonkPogI.origin.x +=0.25;
    }

    if (MonkPogII.origin.x < 10)
    {
       MonkPogII.origin.y+=0.25;
    }else{
        MonkPogII.origin.y -=0.25;
    }
    if (MonkPogII.origin.y < 10)
    {
        MonkPogII.origin.x -=0.25;
    }
    else{
        MonkPogII.origin.x +=0.25;
    }

    rgb = ((rgb+10)%0xffff);
    
}

void SpiderMonkey::drawSprite() {
    // DrawTexture(frames,0,0,WHITE);
    // DrawRectangle(100,50,100,100,RED);
    DrawTexturePro(Monklegs.texture,Monklegs.sizeofPart,Monklegs.sizeofDraw,Monklegs.origin,0,ColorFromHSV(rgb,0.5,1.0));
    DrawTexturePro(Monktorso.texture,Monktorso.sizeofPart,Monktorso.sizeofDraw,Monktorso.origin,0,ColorFromHSV(rgb,0.5,1.0));
    DrawTexturePro(Monkhead .texture,Monkhead .sizeofPart,Monkhead .sizeofDraw,Monkhead.origin,0,ColorFromHSV(rgb,0.5,1.0));
    DrawTexturePro(MonkPogI .texture,MonkPogI .sizeofPart,MonkPogI .sizeofDraw,MonkPogI.origin,0,ColorFromHSV(rgb,0.5,1.0));
    DrawTexturePro(MonkPogII .texture,MonkPogII .sizeofPart,MonkPogII .sizeofDraw,MonkPogII.origin,0,ColorFromHSV(rgb,0.5,1.0));
    DrawText(TextFormat("%s", name.c_str()), 222, 10, 29, ColorFromHSV(rgb,0.5,1.0));
}

void SpiderMonkey::drawTextBox(common::Game &game) {
    std::string text;
    if (game.battle.EncounterPhase)
    {
        text = utils::preLoadMonsterName(game.storedDialogue[15].text, name);
         
        //utils::printText(game.HBIT, TextSubtext(TextFormat("%s", game.storedDialogue[0].text.c_str()), 0, game.textFrame/5) , (Vector2){ 120.0f, 320.0f }, (float)game.HBIT.baseSize, 4, WHITE, game);
    }else{
        text = utils::preLoadMonsterName(game.storedDialogue[neutralPicker].text, name);
    }
    DrawTextPro(game.HBIT,TextSubtext("*", 0, game.textFrame/5),(Vector2){ game.battle.Box.x+20, game.battle.Box.y+20 },(Vector2){ 0,0 },0,(float)game.HBIT.baseSize/1,3,WHITE);
    utils::printText(game.HBIT,TextSubtext(TextFormat("%s", text.c_str()), 0, game.textFrame/5),(Vector2){ game.battle.Box.x+50, game.battle.Box.y+20 },(float)game.HBIT.baseSize/1,3,WHITE,game);
}

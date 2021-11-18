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
    Rectangle sizeOfEnemie;
    unsigned int rgb;
public:
    SpiderMonkey();
    ~SpiderMonkey();
    void animate(common::Game &game) override;
    void drawSprite() override;
};

SpiderMonkey::SpiderMonkey() {
    Monkhead.texture = LoadTexture("assets/monster/sans/head.png");
    Monkhead.sizeofPart = {0,0,(float)Monkhead.texture.width,(float)Monkhead.texture.height};
   

    Monktorso.texture = LoadTexture("assets/monster/sans/torso.png");
    Monktorso.sizeofPart = {0,0,(float)Monktorso.texture.width,(float)Monktorso.texture.height};
    

    Monklegs.texture = LoadTexture("assets/monster/sans/legs.png");
    Monklegs.sizeofPart = {0,0,(float)Monklegs.texture.width,(float)Monklegs.texture.height};
    
}

SpiderMonkey::~SpiderMonkey() {
    UnloadTexture(Monkhead.texture);
    UnloadTexture(Monktorso.texture);
    UnloadTexture(Monklegs.texture);
}

void SpiderMonkey::animate(common::Game &game) {
    Monklegs.sizeofDraw = {(float)((SCREEN_HEIGHT/2)+Monklegs.texture.width/2+5),game.battle.Box.y-Monklegs.texture.height*2-16,(float)Monklegs.texture.width*2,(float)Monklegs.texture.height*2};//the x and y is the pos of the texture in the window 
    Monktorso.sizeofDraw = {(float)((SCREEN_HEIGHT/2)+16),Monklegs.sizeofDraw.y-Monktorso.texture.height*2,(float)Monktorso.texture.width*2,(float)Monktorso.texture.height*2};//the x and y is the pos of the texture in the window
    Monkhead.sizeofDraw = {(float)SCREEN_HEIGHT/2+6+Monkhead.texture.width,Monktorso.sizeofDraw.y-Monkhead.texture.height-17,(float)Monkhead.texture.width*2,(float)Monkhead.texture.height*2};//the x and y is the pos of the texture in the window
    
   Monkhead.origin.x+=3;
    if (Monkhead.origin.x == 0)
    {
        Monkhead.origin.x = -3;
    }
    if (Monkhead.origin.x > 345)
    {
        Monkhead.origin.x = -345;
    }
    
    Monklegs.origin.y-=3;
        if (Monklegs.origin.y == 0)
        {
            Monklegs.origin.y = 3;
        }
        if (Monklegs.origin.y < -345)
        {
            Monklegs.origin.y = 345;
        }
    
    Monktorso.origin.x-=3;
        if (Monktorso.origin.x == 0)
        {
            Monktorso.origin.x = 3;
        }
        if (Monktorso.origin.x < -345)
        {
            Monktorso.origin.x = 345;
        }
    rgb = ((rgb+10)%0xffff);
    
}

void SpiderMonkey::drawSprite() {
    // DrawTexture(frames,0,0,WHITE);
    // DrawRectangle(100,50,100,100,RED);
    DrawTexturePro(Monklegs.texture,Monklegs.sizeofPart,Monklegs.sizeofDraw,Monklegs.origin,0,ColorFromHSV(rgb,0.5,1.0));
    DrawTexturePro(Monktorso.texture,Monktorso.sizeofPart,Monktorso.sizeofDraw,Monktorso.origin,0,ColorFromHSV(rgb,0.5,1.0));
    DrawTexturePro(Monkhead .texture,Monkhead .sizeofPart,Monkhead .sizeofDraw,Monkhead.origin,0,ColorFromHSV(rgb,0.5,1.0));
}

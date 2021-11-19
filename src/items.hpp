#include "common.hpp"
//RealKnife
class RealKnife : public common::Item
{
public:
    RealKnife();
};
RealKnife::RealKnife() {
    name = "Real Knife";
	ATK_Modifier = 99;
	type = 2;
	isAWeapon = true;
}

//Sandwich
class Sandwich : public common::Item
{
public:
    Sandwich();
};
Sandwich::Sandwich() {
    name = "Sandwich";
	HP_regen = 20;
	type = 1;
}
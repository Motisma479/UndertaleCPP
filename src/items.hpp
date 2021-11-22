#include "common.hpp"
//null
class null : public common::Item
{
public:
    null();
};
null::null() {
    name = "0";
	type = 0;
	isNull = true;
}

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

//Dandelion
class Dandelion : public common::Item
{
public:
    Dandelion();
};
Dandelion::Dandelion() {
    name = "Dandelion";
	HP_regen = 3;
	type = 1;
}
// Monster.cpp
// copyright junhyeok

#include "Monster.h"

Monster::Monster() : attackPower(5) {}

int Monster::GetDamage() const {
    return this->attackPower;
}

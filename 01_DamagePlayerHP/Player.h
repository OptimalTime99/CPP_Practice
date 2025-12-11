// Player.h
// copyright junhyeok

#pragma once
#include "Player.h"

class Player {
 private:
    int currentHP;

 public:
    Player();

    int PreviewDamage(int damage) const;

    void LoseHP_ByPointer(int* pDamage);

    void LoseHP_ByReference(int& damage);

    int getHP() const;

    void setHP(int hp);
};

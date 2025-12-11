// copyright junhyeok

#include "Player.h"

Player::Player() : currentHP(100) {}

int Player::PreviewDamage(int damage) const {
    return this->currentHP - damage;
}

void Player::LoseHP_ByPointer(int* pDamage) {
    if (this->currentHP - *pDamage > 0) {
        this->currentHP -= *pDamage;
    } else {
        this->currentHP = 0;
    }
}

void Player::LoseHP_ByReference(int& damage) {
    if (this->currentHP - damage > 0) {
        this->currentHP -= damage;
    } else {
        this->currentHP = 0;
    }
}

int Player::getHP() const {
    return this->currentHP;
}

void Player::setHP(int hp) {
    if (hp > 100) hp = 100;
    if (hp < 0) hp = 1;
    this->currentHP = hp;
}

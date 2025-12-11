// copyright junhyeok

#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "ConsoleUI.h"

int main() {
    Player player1;
    Monster monster1;
    ConsoleUI consoleUI;

    int currentHP = player1.getHP();
    int damage = monster1.GetDamage();
    int previewHP = player1.PreviewDamage(damage);

    consoleUI.ShowTitle("==== CallByValue Test ====");
    consoleUI.ShowPlayerHP(currentHP);
    consoleUI.ShowPreviewResult(currentHP, damage, previewHP);
    consoleUI.ShowPlayerHP(player1.getHP());



    consoleUI.ShowTitle("==== CallByPointer Test ====");
    player1.setHP(100);
    consoleUI.ShowPlayerHP(player1.getHP());
    player1.LoseHP_ByPointer(&damage);
    consoleUI.ShowPlayerHP(player1.getHP());



    consoleUI.ShowTitle("==== CallByReference Test ====");
    player1.setHP(100);
    consoleUI.ShowPlayerHP(player1.getHP());
    player1.LoseHP_ByReference(damage);
    consoleUI.ShowPlayerHP(player1.getHP());

    return 0;
}

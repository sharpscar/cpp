// main.cpp
#include "./family.h"
#include "./family.cpp"


int main() {
    Character jon("Jon", "Snow", "Watcher", SWORD,
                  "Stark", "Direwolf", "Winter is Coming", "Winterfell");

    jon.introduce();
    return 0;
}

#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include"hashtable.h"
#include <ctime>


int main() {
    Catch::Session().run();

    std::srand(std::time(nullptr));

    HashTable hashTable(1000,0.6,2);
    for(int i = 0; i < 200; ++i){
        int randomValue = 1000 + std::rand() % 501;
        hashTable.insert(randomValue);
    }

    std::cout << "Anzahl der Kollisionen: " << hashTable.getCollisionCount() << std::endl;

    system("pause");
    return 0;
}
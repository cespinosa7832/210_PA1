#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << "Let the games begin" << std::endl;
    std::unique_ptr<List<Player>> game1 = makeList<Player>();
    std::unique_ptr<List<Player>> game2 = makeList<Player>();
    game2->addFront(new Player(7, "Bill"));
    game2->addFront(new Player(29, "Shane"));
    game2->addAnywhere(1, new Player(12, "Linda"));
    game1->addFront(new Player(1, "Bob"));
    game1->addFront(new Player(2, "Sierra"));
    game1->addFront(new Player(3, "Selena"));
    game1->print();
    game1->addAnywhere(2, new Player(4, "Jorge"));
    game1->print();
    game1->reverse();
    game1->print();
    game1->deleteAnywhere(1);
    game1->concat(game2.get());
    game1->print();


    return 0;
}

#include "AlienType.hpp"

int main() {
    Alien* baseAlien = new AlienType("Mars", "Green");
    baseAlien->setMissing("Zorg", "Invisibility");

    Alien* clone1 = baseAlien->clone();
    clone1->setMissing("Blorg", "Fire Blast");

    Alien* clone2 = baseAlien->clone();
    clone2->setMissing("Xen", "Teleportation");

    baseAlien->print();
    clone1->print();
    clone2->print();

    delete baseAlien;
    delete clone1;
    delete clone2;

    return 0;
}

#include "Skat.cpp"
#include "Skat.hpp"
#include "KoalaBot.cpp"
#include "KoalaBot.hpp"
#include "Parts.cpp"
#include "Parts.hpp"
#include "KreogCom.cpp"
#include "KreogCom.hpp"
#include "Phaser.cpp"
#include "Phaser.hpp"
#include "Sounds.hpp"

const std::string Sounds::Regular = "Pew Pew!";
const std::string Sounds::Plasma = "Bzzzzzap!";
const std::string Sounds::Rocket = "Boom!";

int main()
{
    Skat s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();

    KoalaBot kb;
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();

    KreogCom k(42, 42, 101010);
    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k.locateSquad();
    k.removeCom();
    k.removeCom();

    Phaser p(5, Phaser::PLASMA);
    p.fire();
    p.reload();
    std::cout << "Firing all ammunition" << std::endl;
    while (p.getCurrentAmmos() > 0)
        p.fire();

    std::cout << __cplusplus << std::endl;

    return 0;
}
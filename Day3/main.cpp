#include "Skat.hpp"
#include "KoalaBot.hpp"
#include "Parts.hpp"
#include "KreogCom.hpp"
#include "Phaser.hpp"
#include "Sounds.hpp"
#include "Squad.hpp"

int main()
{
    Squad s(0, 0, Phaser::REGULAR);
    s.fire();
    return 0;
}
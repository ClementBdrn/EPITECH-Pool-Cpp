#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <vector>
#include "Skat.hpp"

class Squad
{
private:
    std::vector<Skat *> _squad;

public:
    // Constructor
    Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size = 5);

    // Destructor
    ~Squad();

    // Methods
    void fire();
    void localisation();
    std::vector<Skat *> skats() const;
    Skat *at(int idx) const;
    int size() const;

    void foreach (int beginIdx, void(Skat::*actionPtr)());
};

#endif
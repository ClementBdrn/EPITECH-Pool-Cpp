#include <iostream>
#include "Squad.hpp"
#include "Skat.hpp"

// Constructor
Squad::Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int x = posXBegin + (i * 10);
        int y = posYBegin + (i * 15);
        _squad.push_back(new Skat("Skat_" + std::to_string(i), 15, i, x, y, ammoType));
    }
}

// Destructor
Squad::~Squad()
{
    for (Skat *skat : _squad)
    {
        delete skat;
    }
}

// Fire with all the squad
void Squad::fire()
{
    foreach (0, &Skat::fire)
        ;
}

// Locate all the squad
void Squad::localisation()
{
    foreach (0, &Skat::locate)
        ;
}

// Return all the squad members
std::vector<Skat *> Squad::skats() const
{
    return _squad;
}

// Return the Skat at the given index
Skat *Squad::at(int idx) const
{
    if (idx < 0 || idx >= _squad.size())
    {
        return nullptr;
    }
    return _squad[idx];
}

// Return the size of the squad
int Squad::size() const
{
    return _squad.size();
}

// foreach function implementation
void Squad::foreach (int beginIdx, void(Skat::*actionPtr)())
{
    // Check if the start  index is valid
    if (beginIdx < 0 || beginIdx >= _squad.size())
    {
        std::cerr << "Invalid start index." << std::endl;
        return;
    }

    // Loop over the Skats starting from beginIdx and apply the function pointer
    for (int i = beginIdx; i < _squad.size(); ++i)
    {
        Skat *currentSkat = _squad[i];
        if (currentSkat)
        {
            (currentSkat->*actionPtr)();
        }
    }
}

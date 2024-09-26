#ifndef PHASER_HPP
#define PHASER_HPP
#include <iostream>
#include <vector>
#include "Sounds.hpp"

class Phaser
{
private:
    // Setup variables
    static const int Empty;
    int _maxAmmo;
    int _currentAmmo;

public:
    // Enum ammo types
    enum AmmoType
    {
        REGULAR,
        PLASMA,
        ROCKET
    };

    // Constructor
    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);

    // Destructor
    ~Phaser();

    // Fire
    void fire();

    // Clear the magazine and set to 0 amount of ammo
    void ejectClip();

    // Change the type of ammo used
    void changeType(AmmoType newType);

    // Reload with REGULAR bullets
    void reload();

    // Add ammo of the type selected
    void addAmmo(AmmoType type);

    // Return the amount of ammo
    int getCurrentAmmos() const;

private:
    // Current Ammo type
    AmmoType currentType;
    std::vector<AmmoType> magazine;
};

#endif
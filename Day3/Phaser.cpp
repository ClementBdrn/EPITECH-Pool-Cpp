#include "Phaser.hpp"
#include "Sounds.hpp"

const int Phaser::Empty = 0;

// Constructor
Phaser::Phaser(int maxAmmo, AmmoType type) : _maxAmmo(maxAmmo), _currentAmmo(maxAmmo), currentType(type)
{
    for (int i = 0; i < maxAmmo; i++)
    {
        magazine.push_back(REGULAR);
    }
}

// Destructor
Phaser::~Phaser() {}

// FIIIIIRE
void Phaser::fire()
{
    if (_currentAmmo > Empty && !magazine.empty())
    {
        switch (currentType)
        {
        case REGULAR:
            std::cout << Sounds::Regular << std::endl;
            break;
        case PLASMA:
            std::cout << Sounds::Plasma << std::endl;
            break;
        case ROCKET:
            std::cout << Sounds::Rocket << std::endl;
            break;
        default:
            break;
        }
        magazine.pop_back();
        _currentAmmo--;
    }
    else
    {
        std::cout << "Clip empty, please reload" << std::endl;
    }
}

// Clear the magazine and set to 0 the amount of current ammo
void Phaser::ejectClip()
{
    magazine.clear();
    _currentAmmo = Empty;
    std::cout << "Clip ejected." << std::endl;
}

// Change the type of ammo
void Phaser::changeType(AmmoType newType)
{
    currentType = newType;
    std::cout << "Ammo type changed." << std::endl;
}

// Reload with REGULAR bullets
void Phaser::reload()
{
    if (_currentAmmo < _maxAmmo)
    {
        int toReload = _maxAmmo - _currentAmmo;
        for (int i = 0; i < toReload; ++i)
        {
            magazine.push_back(REGULAR);
        }
        _currentAmmo = _maxAmmo;
        std::cout << "Phaser reloaded." << std::endl;
    }
}

// Add ammo of the type selected
void Phaser::addAmmo(AmmoType type)
{
    if (_currentAmmo < _maxAmmo)
    {
        magazine.push_back(type);
        _currentAmmo++;
        std::cout << "Ammo added." << std::endl;
    }
    else
    {
        std::cout << "Magazine is full." << std::endl;
    }
}

// Return the amount of ammo
int Phaser::getCurrentAmmos() const
{
    return _currentAmmo;
}
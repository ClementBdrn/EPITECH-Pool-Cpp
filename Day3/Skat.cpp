#include "Skat.hpp"

// Constructor
Skat::Skat(const std::string &name, int stimPaks, int serial, int x, int y, Phaser::AmmoType type) : _name(name), _stimPaks(stimPaks), _phaser(20, type), _kreogCom(x, y, serial) {}

// Destructor
Skat::~Skat() {}

// Return number of stimPaks
int Skat::getStimPaks()
{
    return _stimPaks;
}

// Set the number of stimPaks
void Skat::setStimPaks(int stims)
{
    _stimPaks = stims;
}

// Return the name of the Skat
const std::string &Skat::name() const
{
    return _name;
}

// Share your stimPaks with someone else
void Skat::shareStimPaks(int number, int &stock)
{
    if (number <= _stimPaks)
    {
        stock += number;
        _stimPaks - +number;
        std::cout << "Keep the change." << std::endl;
    }
    else
    {
        std::cout << "Don't be greedy." << std::endl;
    }
}

// Add new stimpaks to your stock
void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
    {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    }
    else
    {
        _stimPaks += number;
    }
}

// Use 1 of your stimPaks
void Skat::useStimPaks()
{
    if (_stimPaks == 0)
    {
        std::cout << "Mediiiiiic" << std::endl;
    }
    else
    {
        _stimPaks--;
        std::cout << "Time to kick some ass and chew bublle gum." << std::endl;
    }
}

// Print the number of stimpaks remaining
void Skat::status() const
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}

void Skat::fire()
{
    _phaser.fire();
}

void Skat::locate()
{
    _kreogCom.locateSquad();
}

void Skat::reload()
{
    _phaser.reload();
}

KreogCom &Skat::com()
{
    return _kreogCom;
}
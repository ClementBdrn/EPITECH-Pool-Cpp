#include "Droid.hpp"

// Constructor
Droid::Droid(std::string serial) : _serial(serial), _Energy(50), _Attack(25), _Toughness(15) {}

// Copy constructor (replication)
Droid::Droid(Droid &droid) : _serial(droid.getSerial()), _Energy(droid.getEnergy()), _Attack(droid.getAttack()), _Toughness(droid.getToughness()), _Status(droid.getStatus()) {}

// Assignment operator (replacement)
/*Droid::&operator=(const Droid &other)
{
}*/

// Getters / Setters
std::string Droid::getSerial()
{
    return _serial;
}

void Droid::setSerial(std::string serial)
{
    _serial = serial;
}

size_t Droid::getEnergy()
{
    return _Energy;
}

void Droid::setEnergy(size_t Energy)
{
    _Energy = Energy;
}

size_t Droid::getAttack()
{
    return _Attack;
}

size_t Droid::getToughness()
{
    return _Toughness;
}

std::string *Droid::getStatus()
{
    return _Status;
}
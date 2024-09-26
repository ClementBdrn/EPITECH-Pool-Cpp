#include "KoalaBot.hpp"

// Constructor
KoalaBot::KoalaBot(const std::string &serial) : _serial(serial), _arm(), _leg(), _head() {}

// Destructor
KoalaBot::~KoalaBot() {}

// Set parts
void KoalaBot::setParts(const Arms &arm)
{
    _arm = arm;
}

void KoalaBot::setParts(const Legs &leg)
{
    _leg = leg;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

// Swap parts
void KoalaBot::swapParts(const Arms &arm)
{
    _arm = arm;
}

void KoalaBot::swapParts(const Legs &leg)
{
    _leg = leg;
}

void KoalaBot::swapParts(const Head &head)
{
    _head = head;
}

// Print informations about the KoalaBot
void KoalaBot::informations()
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arm.informations();
    _leg.informations();
    _head.informations();
}

// Return if all the parts of the KoalaBot are running
bool KoalaBot::status()
{
    return _arm.isFunctional() && _leg.isFunctional() && _head.isFunctional();
}
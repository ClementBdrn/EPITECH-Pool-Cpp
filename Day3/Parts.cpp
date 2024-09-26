#include "Parts.hpp"

// Constructor
Arms::Arms(const std::string &serial, bool functional) : _serial(serial), _functional(functional) {}

// Return if this part is functional
bool Arms::isFunctional() const
{
    return _functional;
}

// Return the serial of the part
std::string Arms::serial() const
{
    return _serial;
}

// Print informations about the part
void Arms::informations()
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}

// Constructor
Legs::Legs(const std::string &serial, bool functional) : _serial(serial), _functional(functional) {}

// Return if this part is functional
bool Legs::isFunctional() const
{
    return _functional;
}

// Return the serial of the part
std::string Legs::serial() const
{
    return _serial;
}

// Print informations about the part
void Legs::informations()
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}

// Constructor
Head::Head(const std::string &serial, bool functional) : _serial(serial), _functional(functional) {}

// Return if this part is functional
bool Head::isFunctional() const
{
    return _functional;
}

// Return the serial of the part
std::string Head::serial() const
{
    return _serial;
}

// Print informations about the part
void Head::informations()
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}
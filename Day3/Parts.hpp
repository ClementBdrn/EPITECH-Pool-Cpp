#ifndef PARTS_HPP
#define PARTS_HPP

#include <string>
#include <iostream>

class Arms
{
private:
    // Setup variables
    std::string _serial;
    bool _functional;

public:
    // Constructor
    Arms(const std::string &serial = "A-01", bool functional = true);

    // Return if the part is functional
    bool isFunctional() const;

    // Return the serial name of the part
    std::string serial() const;

    // Print informations about the part
    void informations();
};

class Legs
{
private:
    // Setup variables
    std::string _serial;
    bool _functional;

public:
    // Constructor
    Legs(const std::string &serial = "L-01", bool functional = true);

    // Return if the part is functional
    bool isFunctional() const;

    // Return the serial name of the part
    std::string serial() const;

    // Print informations about the part
    void informations();
};

class Head
{
private:
    // Setup variables
    std::string _serial;
    bool _functional;

public:
    // Constructor
    Head(const std::string &serial = "H-01", bool functional = true);

    // Return if the part is functional
    bool isFunctional() const;

    // Return the serial name of the part
    std::string serial() const;

    // Print informations about the part
    void informations();
};

#endif
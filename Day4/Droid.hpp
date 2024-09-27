#ifndef DROID_HPP
#define DROID_HPP
#include <iostream>

class Droid
{
private:
    // Setup variables
    std::string _serial;
    std::string _Id;
    size_t _Energy;
    const size_t _Attack;
    const size_t _Toughness;
    std::string *_Status;

public:
    // Constructor
    Droid(std::string serial = "");

    // Copy constructor (replication)
    Droid(Droid &d);

    // Assignment operator (replacement)
    Droid &operator=(const Droid &other);

    // Destructor
    ~Droid();

    // Getters / Setters
    std::string getSerial();
    void setSerial(std::string serial);

    size_t getEnergy();
    void setEnergy(size_t Energy);

    size_t getAttack();

    size_t getToughness();

    std::string *getStatus();
};

#endif
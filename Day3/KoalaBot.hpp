#ifndef KOALABOT_HPP
#define KOALABOT_HPP

#include "Parts.hpp"

class KoalaBot
{
private:
    // Setup variables
    std::string _serial;
    Arms _arm;
    Legs _leg;
    Head _head;

public:
    // Constructor
    KoalaBot(const std::string &_serial = "Bob-01");

    // Destructor
    ~KoalaBot();

    // Set each parts of the KoalaBot
    void setParts(const Arms &arm);
    void setParts(const Legs &leg);
    void setParts(const Head &head);

    // Swap each parts of the KoalaBot
    void swapParts(const Arms &arm);
    void swapParts(const Legs &leg);
    void swapParts(const Head &head);

    // Print the informations about the KoalaBot
    void informations();

    // Return if all the parts are running
    bool status();
};

#endif
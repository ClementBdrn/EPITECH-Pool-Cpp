#ifndef SKAT_HPP
#define SKAT_HPP

#include "Phaser.hpp"
#include "KreogCom.hpp"
#include <iostream>

class Skat
{
private:
    // Setup variables
    std::string _name;
    int _stimPaks;
    Phaser _phaser;
    KreogCom _kreogCom;

public:
    // Constructor
    Skat(const std::string &name, int stimPaks, int seria, int x, int y, Phaser::AmmoType type);

    // Destructor
    ~Skat();

    // Return number of stimPaks
    int getStimPaks();

    // Set the number of stimPaks
    void setStimPaks(int stims);

    // Return the name of the Skat
    const std::string &name() const;

    // Share your stimPaks with someone else
    void shareStimPaks(int number, int &stock);

    // Add new stimpaks to your stock
    void addStimPaks(unsigned int number);

    // Use 1 of your stimPaks
    void useStimPaks();

    // Print the number of stimpaks remaining
    void status() const;

    // Phaser & KreogCom methods
    void fire();
    void locate();
    void reload();
    KreogCom &com();
};

#endif
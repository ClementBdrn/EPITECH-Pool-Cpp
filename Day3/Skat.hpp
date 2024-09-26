#ifndef SKAT_HPP
#define SKAT_HPP

#include <iostream>

class Skat
{
private:
    // Setup variables
    std::string _name;
    int _stimPaks;

public:
    // Constructor
    Skat(const std::string &name = "bob", int stimPaks = 15);

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
};

#endif
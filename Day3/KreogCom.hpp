#ifndef KREOGCOM_HPP
#define KREOGCOM_HPP
#include <iostream>

class KreogCom
{
private:
    // Setup variable
    const int m_serial;
    int m_x;
    int m_y;
    KreogCom *m_nextCom;

public:
    // Constructor
    KreogCom(int x, int y, int serial);

    // Destructor
    ~KreogCom();

    // Creates a new KreogCom
    void addCom(int x, int y, int serial);
    void removeCom();

    // Return the ptr of the KreogCom
    KreogCom *getCom();

    // Print locations
    void ping();
    void locateSquad();
};

#endif
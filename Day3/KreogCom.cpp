#include "KreogCom.hpp"
#include <string>

// Constructor
KreogCom::KreogCom(int x, int y, int serial) : m_x(x), m_y(y), m_serial(serial), m_nextCom(nullptr) {}

// Destructor
KreogCom::~KreogCom()
{
    if (m_nextCom != nullptr)
    {
        delete m_nextCom;
    }
}

// Add a new KreogCom
void KreogCom::addCom(KreogCom *com)
{
    com->m_nextCom = m_nextCom;
    m_nextCom = com;
}

// Remove a KreogCom
void KreogCom::removeCom()
{
    if (m_nextCom != nullptr)
    {
        KreogCom *temp = m_nextCom;
        m_nextCom = m_nextCom->m_nextCom;
        delete temp;
    }
}

// Return the ptr of the next_Com
KreogCom *KreogCom::getCom()
{
    return m_nextCom;
}

// Print the actual location of the KreogCom
void KreogCom::ping()
{
    std::cout << "KreogCom " << m_serial << " currently at " << m_x << " " << m_y << "." << std::endl;
}

// Print le location of the entire squad
void KreogCom::locateSquad()
{
    const KreogCom *current = this;
    while (current != nullptr)
    {
        std::cout << "KreogCom " << current->m_serial << " currently at " << current->m_x << " " << current->m_y << std::endl;
        current = current->m_nextCom;
    }
}
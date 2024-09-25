#include <iostream>
#include "Destination.hpp"

namespace WarpSystem
{
    class QuantumReactor
    {
    private:
        // Setup variable
        bool _stability = true;

    public:
        // Constructor
        QuantumReactor()
        {
        }

        // Return the state of _stability
        bool isStable() const
        {
            return _stability;
        }

        // Set the value of _stability (true / false)
        void setStability(bool value)
        {
            _stability = value;
        }
    };

    class Core
    {
    private:
        // Setup variable
        QuantumReactor *_coreReactor;

    public:
        // Constructor
        Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor)
        {
        }

        // Return the pointer of _coreReactor
        QuantumReactor *checkReactor() const
        {
            return _coreReactor;
        }
    };
}

namespace Borg
{
    class BorgQueen {
    public:
        // Constructor
        BorgQueen() {
            // Setup pointers
            movePtr = &Borg::Ship::move;
            firePtr = &Borg::Ship::fire;
            destroyPtr = &Borg::Ship::fire;
        }

        // Function pointers
        bool (Borg::Ship::*movePtr)(Destination);
        void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship*);
        void (Borg::Ship::*destroyPtr)(Federation::Ship*);

        // Move method
        bool move(Borg::Ship* ship, Destination dest) {
            std::cout << "Borg Queen orders the ship to move." << std::endl;
            return (ship->*movePtr)(dest);
        }

        // Fire method
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target) {
            std::cout << "Borg Queen orders the ship to fire on a Starfleet vessel." << std::endl;
            (ship->*firePtr)(target);
        }

        // Destroy method
        void destroy(Borg::Ship *ship, Federation::Ship *target) {
            std::cout << "Borg Queen orders the ship to destroy a Federation vessel." << std::endl;
            (ship->*destroyPtr)(target);
        }
    };

    class Ship
    {
    private:
        // Setup variables
        int _side = 300;
        short _maxWrap = 9;
        WarpSystem::Core *_coreReactor = nullptr;
        Destination _location;
        Destination _home;
        int _shield = 100;
        int _weaponFrequency;
        short _repair;

    public:
        // Constructor
        Ship(int weaponFrequency = 50, short repair = 5) : _weaponFrequency(weaponFrequency), _repair(repair) ,_location(UNICOMPLEX), _home(UNICOMPLEX)
        {
            std::cout << "We are the Borgs . Lower your shields and surrender yourselves unconditionally. \nYour biological characteristics and technologies will be assimilated. \nResistance is futile." << std::endl;
        }

        // Getters / Setters
        int getShield(){
            return _shield;
        }

        void setShield(int shield){
            _shield = shield;
        }

        int getWeaponFrequency(){
            return _weaponFrequency;
        }

        void setWeaponFrequency(int frequency){
            _weaponFrequency = frequency;
        }

        short getRepair(){
            return _repair;
        }

        void setRepair(short repair){
            _repair = repair;
        }

        // Setup the value of the core
        void setupCore(WarpSystem::Core *core)
        {
            _coreReactor = core;
        }

        // Print the state of _stability
        void checkCore() const
        {
            if (_coreReactor != nullptr)
            {
                bool stability = _coreReactor->checkReactor()->isStable();
                std::cout << "Everything is in order." << std::endl;
            }
            else
            {
                std::cout << "Critical failure iminent." << std::endl;
            }
        }

        // Move Ship
        bool move(int warp, Destination d){
            if (warp <= _maxWrap && d != _location && _coreReactor->checkReactor()->isStable() == true){
                _location = d;
                return true;
            }
            return false;
        }

        bool move(int warp){
            if (warp <= _maxWrap && _coreReactor->checkReactor()->isStable() == true){
                _location = _home;
                return true;
            }
            return false;
        }

        bool move(Destination d){
            if (d != _location && _coreReactor->checkReactor()->isStable() == true){
                _location = d;
                return true;
            }
            return false;
        }

        bool move(){
            if (_coreReactor->checkReactor()->isStable() == true){
                _location = _home;
                return true;
            }
            return false;
        }

        // Shoot on Starfleet's Ships
        void fire(Federation::Starfleet::Ship *target){
            target->setShield(target->getShield() - _weaponFrequency);

            std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
        }

        // Shoot on Federation's Ships
        void fire(Federation::Ship *target){
            target->getCore()->checkReactor()->setStability(false);

            std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
        }

        // Repair the vessels
        void repair(){
            if (_repair > 0){
                _shield = 100;
                _repair--;

                std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
            }

            std::cout << "Energy cells depleted, shield weakening." << std::endl;
        }
    };
}

namespace Federation
{
    namespace Starfleet
    {
        class Admiral{
        private:
            // Setup variable
            std::string _name;
        public:
            // Constructor
            Admiral(std::string name) : _name(name){
                std::cout << "Admiral " << name << " ready for action." << std::endl;
            }

            // Function pointers
            bool (Federation::Starfleet::Ship::*movePtr)(Destination);
            void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship*);

            // Call the ship's fire metod
            void fire(Federation::Starfleet::Ship* ship, Borg::Ship* target) {
                std::cout << "On order from Admiral " << _name << std::endl;

                (ship->*firePtr)(target);
            }

            // Call the ship's move method
            bool move(Federation::Starfleet::Ship* ship, Destination dest) {
                return (ship->*movePtr)(dest);
            }
        };

        class Captain
        {
        private:
            // Setup variable
            std::string _name;
            int _age;

        public:
            // Constructor
            Captain(std::string name) : _name(name)
            {
            }

            // Return the name of the captain
            std::string getName()
            {
                return _name;
            }

            // Return the age of the captain
            int getAge()
            {
                return _age;
            }

            // Set the age of the captain
            void setAge(int age)
            {
                _age = age;
            }
        };

        class Ensign
        {
        private:
            // Setup variable
            std::string _name;

        public:
            // Constructor
            Ensign(std::string name) : _name(name)
            {
                std::cout << "Ensign " << _name << ", awaiting for orders." << std::endl;
            }
        };

        class Ship
        {
        private:
            // Setup variables
            int _length;
            int _width;
            std::string _name;
            short _maxWrap;
            WarpSystem::Core *_coreReactor = nullptr;
            Captain *_captain = nullptr;
            Destination _location;
            Destination _home;
            int _shield = 100;
            int _photonTorpedo = 0;

        public:
            // Constructor
            Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWrap = 6, int torpedo = 0) : _length(length), _width(width), _name(name), _maxWrap(maxWrap), _photonTorpedo(torpedo), _location(EARTH), _home(EARTH)
            {
                std::cout << "The ship USS " << name << " has been finished. \nIt is " << length << " m in length and " << width << " m in width. \nIt can go to Warp " << maxWrap << " !" << std::endl;
                if (torpedo > 0){
                    std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
                }
            }

            // Getters / Setters
            int getShield(){
                return _shield;
            }

            void setShield(int shield){
                _shield = shield;
            }

            int getTorpedo(){
                return _photonTorpedo;
            }

            void setTorpedo(int torpedo){
                _photonTorpedo = torpedo;
            }

            // Setup the value of the core
            void setupCore(WarpSystem::Core *core)
            {
                _coreReactor = core;
                std::cout << "USS " << _name << " : The core is set." << std::endl;
            }

            // Print the state of _stability
            void checkCore() const
            {
                if (_coreReactor != nullptr)
                {
                    bool stability = _coreReactor->checkReactor()->isStable();
                    std::cout << "USS " << _name << " : The core is " << (stability ? "stable" : "unstable") << " at the time." << std::endl;
                }
                else
                {
                    std::cout << "USS " << _name << " : No core found!" << std::endl;
                }
            }

            // Promote a new captain of the ship
            void promote(Captain *captain)
            {
                _captain = captain;
                std::cout << _captain->getName() << " : I'm glad to be the captain of the USS " << _name << "." << std::endl;
            }

            // Move Ship
            bool move(int warp, Destination d){
                if (warp <= _maxWrap && d != _location && _coreReactor->checkReactor()->isStable() == true){
                    _location = d;
                    return true;
                }
                return false;
            }

            bool move(int warp){
                if (warp <= _maxWrap && _coreReactor->checkReactor()->isStable() == true){
                    _location = _home;
                    return true;
                }
                return false;
            }

            bool move(Destination d){
                if (d != _location && _coreReactor->checkReactor()->isStable() == true){
                    _location = d;
                    return true;
                }
                return false;
            }

            bool move(){
                if (_coreReactor->checkReactor()->isStable() == true){
                    _location = _home;
                    return true;
                }
                return false;
            }

            // Shoot 1 torpedo
            void fire(Borg::Ship *target){
                if (_photonTorpedo > 0) {
                    _photonTorpedo--;

                    target->setShield(target->getShield() - 50);

                    std::cout << _name << " : Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
                }
                else{
                    std::cout << _name << " : No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
                }
            }

            // Shoot torpedoes
            void fire(int torpedoes, Borg::Ship *target){
                if (_photonTorpedo -torpedoes > 0) {
                    _photonTorpedo-=torpedoes;

                    target->setShield(target->getShield() - (50*torpedoes));

                    std::cout << _name << " : Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
                }
                else{
                    std::cout << _name << " : Not enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
                }
            }
        };
    }

    class Ship
    {
    private:
        // Setup variables
        int _length;
        int _width;
        std::string _name;
        short _maxWrap = 1;
        WarpSystem::Core *_coreReactor = nullptr;
        Destination _location;
        Destination _home;

    public:
        // Constructor
        Ship(int length, int width, std::string name) : _length(length), _width(width), _name(name), _location(VULCAN), _home(VULCAN)
        {
            std::cout << "The independant ship " << name << " just finished his construction. \nIt is " << length << " m in length and " << width << std::endl;
        }

        // Setup the value of the core
        void setupCore(WarpSystem::Core *core)
        {
            _coreReactor = core;
            std::cout << "Independant ship " << _name << " : The core is set." << std::endl;
        }

        // Print the state of _stability
        void checkCore() const
        {
            if (_coreReactor != nullptr)
            {
                bool stability = _coreReactor->checkReactor()->isStable();
                std::cout << "Independent ship " << _name << " : The core is " << (stability ? "stable" : "unstable") << " at the time." << std::endl;
            }
            else
            {
                std::cout << "Independent ship " << _name << " : No core found!" << std::endl;
            }
        }

        // Move Ship
        bool move(int warp, Destination d){
            if (warp <= _maxWrap && d != _location && _coreReactor->checkReactor()->isStable() == true){
                _location = d;
                return true;
            }
            return false;
        }

        bool move(int warp){
            if (warp <= _maxWrap && _coreReactor->checkReactor()->isStable() == true){
                _location = _home;
                return true;
            }
            return false;
        }

        bool move(Destination d){
            if (d != _location && _coreReactor->checkReactor()->isStable() == true){
                _location = d;
                return true;
            }
            return false;
        }

        bool move(){
            if (_coreReactor->checkReactor()->isStable() == true){
                _location = _home;
                return true;
            }
            return false;
        }

        // Get the ptr of the core
        WarpSystem::Core *getCore(){
            return _coreReactor;
        }
    };
}

int main()
{
    /*Federation ::Starfleet ::Ship UssJanissary(289, 132, " Janissary ", 6);
    Federation ::Starfleet ::Captain James(" James T. Kirk ");
    Federation ::Starfleet ::Ensign Ensign(" Pavel Chekov ");
    WarpSystem ::QuantumReactor QR;
    WarpSystem ::QuantumReactor QR2;
    WarpSystem ::Core core(&QR);
    WarpSystem ::Core core2(&QR2);
    UssJanissary.setupCore(&core);
    UssJanissary.checkCore();
    UssJanissary.promote(&James);
    Borg ::Ship Cube;
    Cube.setupCore(&core2);
    Cube.checkCore();

    Federation :: Starfleet :: Ship UssJanissary (289 , 132 , " Janissary ", 6) ;
    Federation :: Starfleet :: Ship BiggerShip (345 , 219 , " Pathfinder ", 6 , 5) ;
    Federation :: Starfleet :: Ship DefaultShip ;

    Borg :: Ship Cube ;
    Borg :: Ship AnotherCube (20 , 3) ;
    */
    return 0;
}

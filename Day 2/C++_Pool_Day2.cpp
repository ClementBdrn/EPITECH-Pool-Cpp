#include <iostream>

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

namespace Federation
{
    namespace Starfleet
    {
        class Ship
        {
        private:
            // Setup variables
            int _length;
            int _width;
            std::string _name;
            short _maxWrap;
            WarpSystem::Core *_coreReactor = nullptr;

        public:
            // Constructor
            Ship(int length, int width, std::string name, short maxWrap) : _length(length), _width(width), _name(name), _maxWrap(maxWrap)
            {
                std::cout << "The ship USS " << name << " has been finished. \nIt is " << length << " m in length and " << width << " m in width. \nIt can go to Warp " << maxWrap << " !" << std::endl;
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

    public:
        // Constructor
        Ship(int length, int width, std::string name) : _length(length), _width(width), _name(name)
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
    };
}

int main()
{
    // Exercice_0
    Federation ::Starfleet ::Ship UssJanissary(289, 132, " Janissary ", 6);
    Federation ::Ship Independent(150, 230, " Nomad ");
    WarpSystem ::QuantumReactor QR;
    WarpSystem ::QuantumReactor QR2;
    WarpSystem ::Core core(&QR);
    WarpSystem ::Core core2(&QR2);
    UssJanissary.setupCore(&core);
    UssJanissary.checkCore();
    Independent.setupCore(&core2);
    Independent.checkCore();
    QR.setStability(false);
    QR2.setStability(false);
    UssJanissary.checkCore();
    Independent.checkCore();
    return 0;
}

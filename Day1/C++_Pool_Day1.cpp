#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

/// @brief Read every line of a file
/// @param path
/// @return
int Exercice_1(const std::string &path)
{
    // Open the file in read mode
    std::ifstream file(path);

    // Check if the file is open
    if (!file.is_open())
    {
        std::cerr << "Error ! Impossible to run this file. " << path << std::endl;
        return 84;
    }

    std::string line;

    // Read each line of the file and print it
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
}

/// @brief Convert celsius temperature in fahrenheit and vice versa
/// @param temp
/// @param measure
/// @return
int Exercice_2(float temp, std::string measure)
{

    // If the measure is Fahrenheit
    if (measure == "Fahrenheit")
    {
        // Convert to Celsius
        temp = (temp - 32) * 5 / 9;
        measure = "Celsius";
    }
    // If the measure is Celsius
    else if (measure == "Celsius")
    {
        // Convert to Fahrenheit
        temp = (temp * 9 / 5) + 32;
        measure = "Fahrenheit";
    }
    else
    {
        std::cerr << "The measure is not 'Celsius' or 'Fahrenheit' !" << std::endl;
    }

    // Set the precision to 1000th
    std::cout << std::fixed << std::setprecision(3);
    std::cout << temp << " " << measure << "\n";

    return temp;
}

class Student
{
private:
    // Setup variables
    std::string name;
    int energy = 100;

    // Send a message when adding a new student
    void welcome()
    {
        std::cout << "Student " << name << " : I'm ready to learn C++" << std::endl;
    }

public:
    // Constructor
    Student(std::string n) : name(n)
    {
        welcome();
    }

    // Destructor
    ~Student()
    {
        std::cout << "Student " << name << " : Wow, much learning today, very smart, such C++." << std::endl;
    }

    std::string getName()
    {
        return name;
    }

    // Print a text
    bool learn(std::string text)
    {
        if (energy >= 42)
        {
            // Print the parameter text without modifications
            std::cout << "Student " << name << " : " << text << std::endl;
            energy -= 42;

            return true;
        }
        else
        {
            // Print the parameter text and change all the 'C++' in 'shit'
            std::string newText = "";
            int pos = 0;
            while (text.find("C++") != std::string::npos)
            {
                newText += text.substr(pos, text.find("C++")) + "shit";
                text = text.substr(text.find("C++") + 3, text.length() - 1);
            }
            newText += text.substr(pos, text.length());

            std::cout << "Student " << name << " : " << newText << std::endl;

            return false;
        }
    }

    // Add energy points to the student
    void drink(const std::string &drinkName)
    {
        // Check which drink is in parameter
        if (drinkName == "Red Bull")
        {
            std::cout << "Student " << name << " : Red Bull gives you wings!" << std::endl;
            if (energy + 32 > 100)
            {
                energy = 100;
            }
            else
            {
                energy += 32;
            }
        }
        else if (drinkName == "Monster")
        {
            std::cout << "Student " << name << " : Unleash The Beast!" << std::endl;
            if (energy + 64 > 100)
            {
                energy = 100;
            }
            else
            {
                energy += 64;
            }
        }
        else
        {
            std::cout << "Student " << name << " : ah yes...enslaved moisture." << std::endl;
            if (energy < 100)
            {
                energy += 1;
            }
        }
    }
};

class Assistant
{
private:
    // Setup variables
    int ID;
    bool isWorking;

    // Print when creating a new Assistant
    void welcome()
    {
        std::cout << "Assistant " << ID << " : 'morning everyone *sip coffee*" << std::endl;
    }

public:
    // Constructor
    Assistant(int i) : ID(i), isWorking(false)
    {
        welcome();
    }

    // Destructor
    ~Assistant()
    {
        std::cout << "Assistant " << ID << " : see you tomorrow at 9.00 *sip coffee" << std::endl;
    }

    // Give a drink to a student to restore his energy
    void giveDrink(Student &student, const std::string &drinkName)
    {
        std::cout << "Assistant " << ID << " : drink this, " << student.getName() << " *sip coffee*" << std::endl;

        // Student restores his energy
        student.drink(drinkName);
    }

    // Create a file with a drink name and after that remove this file
    std::string readDrink(std::string &studentName)
    {
        // Setup a file name
        std::string fileName = studentName + ".drink";

        // Create a file and write inside the name of a drink
        std::ofstream file(fileName);
        if (file.is_open())
        {
            file << "Monster";
        }
        file.close();

        std::cout << "Assistant " << ID << " : " << studentName << " needs a Monster *sip coffee*" << std::endl;

        // Remove the file
        remove(fileName.c_str());

        return "Monster";
    }

    // Give a drink to a student
    void helpStudent(Student &student)
    {
        std::string name = student.getName();
        std::string drink = readDrink(name);

        // If the readDrink method return a name of a drink, then give it to a student
        if (drink.length() > 0)
        {
            giveDrink(student, drink);
        }

        std::cout << "Assistant " << ID << " : " << name << " seems fine *sip coffee*" << std::endl;
    }

    // Check the time of work
    void timeCheck()
    {
        // If the assistant isnt working, set isWorking to true
        if (!isWorking)
        {
            std::cout << "Assistant " << ID << " : Time to teach some serious buisness *sip coffee*" << std::endl;
            isWorking = true;
        }
        // Else set isWorking to false and stop working
        else
        {
            std::cout << "Assistant " << ID << " : Enough teaching for today *sip coffee*" << std::endl;
            isWorking = false;
        }
    }
};

class Dean
{
private:
    // Setup variables
    std::string name;
    std::vector<std::string> drinks = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
    bool isWorking;

    // Print when a Dean is created
    void welcome()
    {
        std::cout << "Dean " << name << " : I'm Dean " << name << "! How do you do fellow kids ?" << std::endl;
    }

    // Write inside a text file a drink for a student
    void writeReport(Student &student)
    {
        std::string drink = drinks[rand() % 5];
        std::string fileName = student.getName() + ".drink";
        std::ofstream file(fileName);

        if (file.is_open())
        {
            file << drink;
            file.close();
        }
    }

public:
    // Constructor
    Dean(std::string n) : name(n), isWorking(false)
    {
        welcome();
    }

    // Destructor
    ~Dean()
    {
        std::cout << "Dean " << name << " : Time to go home" << std::endl;
    }

    // Teach to a student a lesson
    void teachStudent(Student &student, std::string lesson)
    {
        // Check if the student has enough energy
        bool val = student.learn(lesson);
        if (!val)
        {
            // Print if the student can't learn
            std::cout << "Dean " << name << " : All work and no play makes " << student.getName() << " a dull student." << std::endl;
            writeReport(student);
        }
    }

    // Check the time of work
    void timeCheck()
    {
        // If the assistant isnt working, set isWorking to true
        if (!isWorking)
        {
            std::cout << "Dean " << name << " : Where is everyone ?" << std::endl;
            isWorking = true;
        }
        // Else set isWorking to false and stop working
        else
        {
            std::cout << "Dean " << name << " : Don't forget to close the windows when you leave" << std::endl;
            isWorking = false;
        }
    }
};

int main()
{
    std::string filePath = "test.txt";
    // Exercice_1(filePath);

    std::string measure = "Celsius";
    int temp = 34;
    // Exercice_2(temp, measure);

    measure = "Fahrenheit";
    temp = -26;
    // Exercice_2(temp, measure);

    // Exercice_3
    Student stud1("Clément");
    for (int i = 0; i < 3; i++)
    {
        stud1.learn("Ceci est un test en C++ !");
    }
    stud1.drink("Monster");
    stud1.learn("Ceci est un test en C++ !");
    stud1.drink("Miaou");

    // Exercice_4
    Assistant assist1(22);
    Student stud2("Clément");
    stud2.learn("I'm learning C++ !");

    assist1.timeCheck();
    assist1.giveDrink(stud2, "Red Bull");
    assist1.helpStudent(stud2);
    std::string name = stud2.getName();
    assist1.readDrink(name);
    assist1.timeCheck();

    // Exercice_5
    srand(static_cast<unsigned>(time(0)));
    Dean dean1("Thierry");
    Student stud3("Clément");
    dean1.timeCheck();
    dean1.teachStudent(stud3, "Ceci est un test en C++ !");
    dean1.teachStudent(stud3, "Ceci est un test en C++ !");
    dean1.teachStudent(stud3, "Ceci est un test en C++ !");
    dean1.timeCheck();

    return 0;
}
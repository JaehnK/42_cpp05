#include "Bureaucrat.hpp"

void    printLine(void)
{
    std::cout << "\n";
    for (int i = 0; i < 80; i++)
        std::cout << "-";
    std::cout << "\n" <<std::endl;
}

int main(void)
{
    try 
    {
        Bureaucrat b1("Jean", 30);
        Bureaucrat b2("Pierre", 50);

        std::cout << b1;
        std::cout << b2;

        Bureaucrat b3("Kylian", 151);
        std::cout << b3;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLine();

    try
    {
        Bureaucrat b1("Giroud", 149);
        std::cout << b1;
        b1.incrementGrade();
        std::cout << b1;
        b1.incrementGrade();
        std::cout << b1;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLine();

    try
    {
        Bureaucrat b1("Gerome", 2);
        std::cout << b1;
        b1.decrementGrade();
        std::cout << b1;
        b1.decrementGrade();
        std::cout << b1;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
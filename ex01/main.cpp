#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        Bureaucrat  b1("Jean", 30);
        Bureaucrat  b2("Pierre", 50);

        Form        f1("Paper", 40);

        std::cout << f1;
        b1.signForm(f1);
        b2.signForm(f1);

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLine();

    try
    {
        Form f1("Paper", 160);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form f1("Paper", 0);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLine();


    try
    {
        Form f1("Papier", 50);
        Bureaucrat b1("Jean", 51);

        b1.incrementGrade();
        b1.incrementGrade();
        std::cout << b1;
        b1.signForm(f1);
        b1.signForm(f1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
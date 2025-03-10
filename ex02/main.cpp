#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void    printLine(void)
{
    std::cout << "\n";
    for (int i = 0; i < 80; i++)
        std::cout << "-";
    std::cout << "\n" <<std::endl;
}

int main(void)
{
    Bureaucrat              b1("Jean", 30);
    Bureaucrat              b2("Pierre", 50);

    AForm*                  form = new ShrubberyCreationForm();
    AForm*                  form2 = new RobotomyRequestForm();

    try 
    {
		std::cout << form << std::endl;
		
		b2.signForm(*form);
		b2.executeForm(*form);

		delete form;
    }
    catch (const std::exception& e)
    {
        delete form;
        std::cerr << e.what() << std::endl;
    }

    printLine();

    try
    {
        b1.signForm(*form2);
        b1.executeForm(*form2);

		delete form2;
    }
    catch (const std::exception& e)
    {
        delete form2;
        std::cerr << e.what() << std::endl;
    }


    return (0);
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
    Bureaucrat              b3("Arthur", 26);
    Bureaucrat              b4("Jacque", 5);

    AForm*                  form = new ShrubberyCreationForm();
    AForm*                  form2 = new RobotomyRequestForm();
    AForm*                  form3 = new PresidentialPardonForm();

    try 
    {
		std::cout << *form << std::endl;
		
		b2.signForm(*form);
		std::cout << *form << std::endl;
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

    printLine();

    try
    {
        b3.incrementGrade();
        b3.signForm(*form3);

        b4.executeForm(*form3);
        delete form3;
    }
    catch (const std::exception& e)
    {
        delete form3;
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
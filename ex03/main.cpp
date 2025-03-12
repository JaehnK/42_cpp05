#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void    printLine(void)
{
    std::cout << "\n";
    for (int i = 0; i < 80; i++)
        std::cout << "-";
    std::cout << "\n" <<std::endl;
}

int main(void)
{
    Bureaucrat              b1("Benoit", 1);
    Intern                  poorIntern;
    AForm*                  form;
    AForm*                  form2;
    AForm*                  form3;

    printLine();
    try 
    {
        form = poorIntern.makeForm("PresidentialPardon", "Benoit");
        
        std::cout << *form << std::endl;
		b1.signForm(*form);
        b1.executeForm(*form);
        
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    printLine();
    try 
    {
        form = poorIntern.makeForm("ShrubberyCreation", "Park");
        
        std::cout << *form << std::endl;
		b1.signForm(*form);
        b1.executeForm(*form);
        
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    printLine();
    try 
    {
        form2 = poorIntern.makeForm("RobotomyRequest", "Lee");
        
        std::cout << *form << std::endl;
		b1.signForm(*form);
        b1.executeForm(*form);
        
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    printLine();
    try 
    {
        // form3 = poorIntern.makeForm("Super Cool Form", "Kim");
        form3 = poorIntern.makeForm("RobotomyRequestdfdfd", "asdf");
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
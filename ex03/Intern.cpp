#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::Intern(Intern &rhs)
{
    *this = rhs;
}

Intern &Intern::operator=(Intern &rhs)
{
    if (this != &rhs)
    {
        std::cout << "Copy Operator Called" << std::endl;
    }
    return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string formName, std::string targetName)
{
    std::string formNames[3] = {
                    "RobotomyRequest",
                    "ShrubberyCreation", 
                    "PresidentialPardon"
                    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            switch (i)
            {
                case (0):
                    return (new RobotomyRequestForm(targetName));
                
                case (1):
                    return (new ShrubberyCreationForm(targetName));
                
                case (2):
                    return (new PresidentialPardonForm(targetName));
            }
        }
    }
    throw InvalidFormNameException();
    return (NULL);
}

const char*  Intern::InvalidFormNameException::what(void) const throw()
{
	return "Intern: Invalid Form Name";
}
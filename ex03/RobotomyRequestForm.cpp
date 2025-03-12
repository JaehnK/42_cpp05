#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45)
{
    this->_signed = false;
	this->_targetName = "None";
}

RobotomyRequestForm::RobotomyRequestForm(std::string targetName)
	: AForm("RobotomyRequestForm", 72, 45)
{
	this->_signed = false;
	this->_targetName = targetName;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rhs)
    : AForm("RobotomyRequestForm", 72, 45)
{
    *this = rhs;   
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
    if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->_signed == false)
	{
		throw NotSignedFormException();
		return ;
	}
	if (this->_gradeExec < executor.getGrade())
	{

		throw GradeTooLowException();
		return ;
	}

    srand(static_cast<unsigned int>(clock()));

    std::cout << "Drrrrrr..." << std::endl;
    if (rand() % 2)
        std::cout << executor.getName() << " has been robotomized successfully." << std::endl;
    else
        throw FailedRobotomizedException();
}

const char*  RobotomyRequestForm:: FailedRobotomizedException::what(void) const throw()
{
	return "RobotomyRequestForm: Failed to Robotomized Target";
}


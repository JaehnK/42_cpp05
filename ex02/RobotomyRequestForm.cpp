#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72),
      _gradeExec(45)
{
    this->_signed = false;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rhs)
    : AForm("RobotomyRequestForm", 72),
      _gradeExec(45)
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
		throw NotSignedForm();
		return ;
	}
	if (this->_gradeExec < executor.getGrade())
	{

		throw GradeTooLowException();
		return ;
	}

    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "Drrrrrr..." << std::endl;
    if (rand() % 2)
        std::cout << executor.getName() << "has been robotomized successfully." << std::endl;
    else
        throw FailedRobotomized();
}

const char*  RobotomyRequestForm::NotSignedForm::what(void) const throw()
{
	return "RobotomyRequestForm: Not Signed Form";
}

const char*  RobotomyRequestForm::FailedRobotomized::what(void) const throw()
{
	return "RobotomyRequestForm: Failed to Robotomized Target";
}


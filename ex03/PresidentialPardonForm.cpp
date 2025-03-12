#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5)
{
    this->_signed = false;
	this->_targetName = "None";
}

PresidentialPardonForm::PresidentialPardonForm(std::string targetName)
	: AForm("PresidentialPardonForm", 25, 5)
{
	this->_signed = false;
	this->_targetName = targetName;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &rhs)
    : AForm("PresidentialPardonForm", 25, 5)
{
    *this = rhs;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
    if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
		this->_targetName = rhs.getTargetName();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{    
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
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
	std::cout << "= = = =" << std::endl;
    std::cout << executor.getName() <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << "= = = =" << std::endl;
}
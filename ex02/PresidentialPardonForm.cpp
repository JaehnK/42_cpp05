#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5)
{
    this->_signed = false;
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
		throw NotSignedForm();
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
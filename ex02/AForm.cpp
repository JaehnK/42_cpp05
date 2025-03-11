#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("form"), _grade(1), _gradeExec(1)
{}

void    AForm::validateGrade(void)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(std::string name, unsigned int grade, unsigned int gradeExec)
    : _name(name),
      _grade(grade),
      _gradeExec(gradeExec)
{
    validateGrade();
    this->_signed = false;
}

AForm::AForm(const AForm &rhs)
    : _name(rhs.getName()),
      _grade(rhs.getGrade()), 
      _gradeExec(rhs.getGradeExec())
{
    *this = rhs;
}

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
    {
        this->_signed = getSigned();
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm(" << getName() << ") Has Destructed" << std::endl;
}

std::string     AForm::getName(void) const
{
    return (this->_name);
}

unsigned int    AForm::getGrade(void) const
{
    return (this->_grade);
}

unsigned int    AForm::getGradeExec(void) const
{
    return (this->_gradeExec);
}

bool            AForm::getSigned(void) const
{
    return (this->_signed);
}

void            AForm::beSigned(const Bureaucrat &bu)
{
    if (this->_grade >= bu.getGrade())
    {
        if (this->_signed == true)
        {
            std::cout << bu.getName() << " couldn't sign " << this->_name << " because bureaucrat tried already signed form." << std::endl;
            throw AleardySignedForm();
            return ;
        }

        this->_signed = true;
        std::cout << bu.getName() << " signed " << this->_name << "." << std::endl;
        return ;
    }
    else
    {
        std::cout << bu.getName() << " couldn't sign " << this->_name << " because Bureaucrat has low grade" << std::endl;
        throw GradeTooLowException();
        return ;
    }
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form: Grade Too High";
};

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form: Grade Too Low";
};

const char* AForm::AleardySignedForm::what() const throw()
{
    return "Form: Already Signed";
}

const char*  AForm::NotSignedForm::what(void) const throw()
{
	return "Form: Not Signed Form";
}

std::ostream	&operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", Form grade " << f.getGrade() << ", Form execGrade " << f.getGradeExec() \
        << ", Form signed " << std::boolalpha << f.getSigned();
    return (os);
}
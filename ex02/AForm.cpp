#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("form"), _grade(1)
{}

void    AForm::validateGrade(void)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(std::string name, unsigned int grade)
    : _name(name),
      _grade(grade)   
{
    validateGrade();
    this->_signed = false;
}

AForm::AForm(const AForm &rhs): _name(rhs.getName()), _grade(rhs.getGrade())
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
    return "AForm: Grade Too High";
};

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade Too Low";
};

const char* AForm::AleardySignedForm::what() const throw()
{
    return "AForm: Already Signed";
}

std::ostream	&operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", Form grade " << f.getGrade() << ", Form signed " << std::boolalpha << f.getSigned() << std::endl;
    return (os);
}
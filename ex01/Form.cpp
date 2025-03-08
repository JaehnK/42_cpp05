#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("form"), _grade(1)
{}

void    Form::validateGrade(void)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Form::Form(std::string name, unsigned int grade)
    : _name(name),
      _grade(grade)   
{
    validateGrade();
    this->_signed = false;
}

Form::Form(const Form &rhs): _name(rhs.getName()), _grade(rhs.getGrade())
{
    *this = rhs;
}

Form &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {
        this->_signed = getSigned();
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form(" << getName() << ") Has Destructed" << std::endl;
}

std::string     Form::getName(void) const
{
    return (this->_name);
}

unsigned int    Form::getGrade(void) const
{
    return (this->_grade);
}

bool            Form::getSigned(void) const
{
    return (this->_signed);
}

void            Form::beSigned(const Bureaucrat &bu)
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

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade Too High";
};

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade Too Low";
};

const char* Form::AleardySignedForm::what() const throw()
{
    return "Form: Already Signed";
}

std::ostream	&operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ", Form grade " << f.getGrade() << ", Form signed " << std::boolalpha << f.getSigned() << std::endl;
    return (os);
}
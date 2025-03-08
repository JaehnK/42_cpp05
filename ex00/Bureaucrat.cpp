#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    :_name(name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
    *this = rhs;
}

Bureaucrat      &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
        // this->_name = rhs.getName();
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat(" << getName() <<") Destructed" << std::endl;
}

void    Bureaucrat::setGrade(unsigned int grade)
{

    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();

    this->_grade = grade;
}

std::string		Bureaucrat::getName(void) const
{
    return (this->_name);
}

unsigned int     Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade(void)
{
    setGrade(this->_grade - 1);
}

void    Bureaucrat::decrementGrade(void)
{
    setGrade(this->_grade + 1);
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Error: Grade Too High";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Error: Grade Too Low";
}

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& bu)
{
    os << bu.getName() << ", bureaucrat grade " << bu.getGrade() << "." << std::endl;
    return (os);
}
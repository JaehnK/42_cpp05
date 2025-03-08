#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;
class Form
{
    private:
        
        const std::string   _name;
        const unsigned int  _grade;
        bool                _signed;

        Form();
        void            validateGrade(void);
    
    public:
        Form(std::string name, unsigned int grade);
        Form(const Form &rhs);
        Form    &operator=(const Form &rhs);
        ~Form();
        
        // getter
        std::string     getName(void) const;
        unsigned int    getGrade(void) const;
        bool             getSigned(void) const;

        // funcs
        void            beSigned(const Bureaucrat &bu);

        // exceptions
        class           AleardySignedForm: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class           GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class           GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };

};
std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
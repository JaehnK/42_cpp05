#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;
class AForm
{
    private:
        AForm();
        void            validateGrade(void);

    protected:
        const std::string   _name;
        const unsigned int  _grade;
        bool                _signed;
    
    public:
        AForm(std::string name, unsigned int grade);
        AForm(const AForm &rhs);
        AForm    &operator=(const AForm &rhs);
        virtual ~AForm();
        
        // getter
        std::string     getName(void) const;
        unsigned int    getGrade(void) const;
        bool            getSigned(void) const;

        // funcs
        void            beSigned(const Bureaucrat &bu);
        virtual void    execute(Bureaucrat const& executor) const = 0;

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
std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
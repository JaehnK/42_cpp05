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
        std::string         _targetName;
        const unsigned int  _grade;
        const unsigned int  _gradeExec;
        bool                _signed;
        
        AForm(std::string name, unsigned int grade, unsigned int gradeExec);
        AForm(const AForm &rhs);
    
    public:
        AForm    &operator=(const AForm &rhs);
        virtual ~AForm();
        
        // getter
        std::string     getName(void) const;
        std::string     getTargetName(void) const;
        unsigned int    getGrade(void) const;
        unsigned int    getGradeExec(void) const;
        bool            getSigned(void) const;

        // funcs
        void            beSigned(const Bureaucrat &bu);
        virtual void    execute(Bureaucrat const& executor) const = 0;

        // exceptions
        class           AleardySignedFormException: public std::exception
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
        class           NotSignedFormException: public std::exception
        {
            public:
                const char* what() const throw();
        };

};
std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
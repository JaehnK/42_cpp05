#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        const unsigned int _gradeExec;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm &rhs);
        RobotomyRequestForm &operator=(RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();

        virtual void    execute(Bureaucrat const& executor) const;

        class           NotSignedForm: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class           FailedRobotomized: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif

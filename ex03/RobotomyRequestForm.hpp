#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string targetName);
        RobotomyRequestForm(RobotomyRequestForm &rhs);
        RobotomyRequestForm &operator=(RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();

        virtual void    execute(Bureaucrat const& executor) const;

        class           FailedRobotomizedException: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif

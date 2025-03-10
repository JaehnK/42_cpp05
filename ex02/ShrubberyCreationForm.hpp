#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        const unsigned int _gradeExec;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &rhs);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();

        virtual void    execute(Bureaucrat const& executor) const;

        class           NotSignedForm: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif
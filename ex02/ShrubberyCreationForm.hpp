#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &rhs);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();

        virtual void    execute(Bureaucrat const& executor) const;
};

#endif
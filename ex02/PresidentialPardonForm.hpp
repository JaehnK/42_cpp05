#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm &rhs);
        PresidentialPardonForm &operator=(PresidentialPardonForm &rhs);
        ~PresidentialPardonForm();

        virtual void    execute(Bureaucrat const& executor) const;
};

#endif

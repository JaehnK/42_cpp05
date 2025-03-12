#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern
{
    private:
    
    public:
        Intern();
        Intern(Intern &rhs);
        Intern &operator=(Intern &rhs);
        ~Intern();

        AForm   *makeForm(std::string formName, std::string targetName);
        
        class InvalidFormNameException: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif 
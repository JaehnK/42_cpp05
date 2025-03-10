#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	 : AForm("ShrubberyCreationForm", 145),
	  _gradeExec(137)
{
	this->_signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &rhs)
	: AForm("ShrubberyCreationForm", 145),
	  _gradeExec(137)
{
	*this = rhs;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	int 				i;
	int					size;
	std::ofstream		outFile;
	std::string			fileName;
	
	std::cout << "Check Excutable Form" << std::endl;
	if (this->_signed == false)
	{
		throw NotSignedForm();
		return ;
	}
	if (this->_gradeExec < executor.getGrade())
	{

		throw GradeTooLowException();
		return ;
	}
	
	fileName = executor.getName() + "_shrubbery";
	outFile.open(fileName.c_str());
	 std::string asciiTree[] = {
        "                                                 .",
        "                                      .         ;  ",
        "         .              .              ;%     ;;   ",
        "           ,           ,                :;%  %;   ",
        "            :         ;                   :;%;'     .,   ",
        "   ,.        %;     %;            ;        %;'    ,;",
        "     ;       ;%;  %%;        ,     %;    ;%;    ,%'",
        "      %;       %;%;      ,  ;       %;  ;%;   ,%;' ",
        "       ;%;      %;        ;%;        % ;%;  ,%;'",
        "        `%;.     ;%;     %;'         `;%%;.%;'",
        "         `:;%.    ;%%. %@;        %; ;@%;%'",
        "            `:%;.  :;bd%;          %;@%;'",
        "              `@%:.  :;%.         ;@@%;'   ",
        "                `@%.  `;@%.      ;@@%;         ",
        "                  `@%%. `@%%    ;@@%;        ",
        "                    ;@%. :@%%  %@@%;       ",
        "                      %@bd%%%bd%%:;     ",
        "                        #@%%%%%:;;",
        "                        %@@%%%::;",
        "                        %@@@%(o);  . '         ",
        "                        %@@@o%;:(.,'         ",
        "                    `.. %@@@o%::;         ",
        "                       `)@@@o%::;         ",
        "                        %@@(o)::;        ",
        "                       .%@@@@%::;         ",
        "                       ;%@@@@%::;.          ",
        "                      ;%@@@@%%:;;;. ",
        "                  ...;%@@@@@%%:;;;;,.."
    };

	size = sizeof(asciiTree) / sizeof(asciiTree[0]);
    i = 0;
    while (i < size) {
        outFile << asciiTree[i] << std::endl;
        i++;
    }
	outFile.close();
	return ;
}

const char*  ShrubberyCreationForm::NotSignedForm::what(void) const throw()
{
	return "ShrubberyCreationForm: Not Signed Form";
}

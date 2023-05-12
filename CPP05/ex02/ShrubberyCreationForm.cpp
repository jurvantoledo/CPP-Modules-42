#include "./include/ShrubberyCreationForm.hpp"
#include "./include/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), \
                                                                        _target(target)
{
    std::cout << "Default constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor is called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    std::ofstream out;
    std::string outfileName = this->_target + "_shrubbery";
    out.open(outfileName.c_str());
    if (!out)
    {
        std::cout << "Cannot create outfile" << std::endl;
        return ;
    }
    std::string			shrubbery =	"               ,@@@@@@@,\n"
							   						"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
							   						"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
							   						"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
							   						"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
							   						"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
							   						"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
							   						"       |o|        | |         | |\n"
							   						"       |.|        | |         | |\n"
							   						"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
    if (executor.getGrade() <= this->getExecutedGrade())
    {
        out << shrubbery;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}
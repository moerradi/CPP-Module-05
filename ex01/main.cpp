#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("simo", 120);
		Form ab1("laysam7", 10, 5);
		Form ab2("gg ez", 130, 5);
		std::cout << ab1 << std::endl;
		std::cout << ab2 << std::endl;
		b.signForm(ab1);
		b.signForm(ab2);
		std::cout << ab1 << std::endl;
		std::cout << ab2 << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
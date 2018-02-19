#include <iostream>
#include <string>

#include "../include/ExtremeInteger.hpp"

int main()
{
	XInt n1( "131" );
	XInt n2( "32" );

	std::cout << n1 - n2 << std::endl;

	return 0;
}

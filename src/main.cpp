#include <iostream>
#include <string>

#include "../include/ExtremeInteger.hpp"

int main()
{
	XInt n1( "1" );
	XInt n2( "10000" );

	for( int i = 1; i < 10000; ++i ) {
		n1 = n1 * n2;
		--n2;
	}

	std::cout << n1 << std::endl;

	return 0;
}

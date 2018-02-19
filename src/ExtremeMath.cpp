#include <string>
#include <vector>

#include "../include/ExtremeInteger.hpp"

std::vector< uint8_t > XInt::Add( const std::vector< uint8_t > & num1, const std::vector< uint8_t > & num2 )
{
	auto first = num1.size() >= num2.size() ? num1 : num2;
	auto second = num1.size() < num2.size() ? num1 : num2;

	std::vector< uint8_t > res;

	uint8_t carry = 0;

	for( int i = 0; i < second.size(); ++i ) {
		res.push_back( first[ i ] + second[ i ] + carry );

		carry = res[ i ] / 10;
		res[ i ] %= 10;
	}
	for( int i = second.size(); i < first.size(); ++i ) {
		res.push_back( first[ i ] + carry );

		carry = res[ i ] / 10;
		res[ i ] %= 10;
	}

	while( carry > 0 ) {
		res.push_back( carry % 10 );
		carry /= 10;
	}

	return res;
}

std::vector< uint8_t > XInt::Subtract( const std::vector< uint8_t > & num1, const std::vector< uint8_t > & num2 )
{
	auto first = num1.size() >= num2.size() ? num1 : num2;
	auto second = num1.size() < num2.size() ? num1 : num2;

	std::vector< uint8_t > res;

	bool borrow = false;
	uint8_t tosub;
	int8_t temp;

	for( int i = 0; i < first.size(); ++i ) {
		tosub = i >= second.size() ? 0 : second[ i ];
		temp = first[ i ] - tosub - ( uint8_t )borrow;

		if( temp < 0 ) {
			borrow = true;
			res.push_back( temp + 10 );
		}
		else {
			borrow = false;
			res.push_back( temp );
		}
	}

	if( borrow == true ) {
		res.clear();
		res.push_back( 0 );
	}
	else {
		for( auto it = res.rbegin(); it != res.rend(); ) {
			if( * it != 0 )
				break;
			std::advance( it, 1 );
			res.erase( it.base() );
		}
	}

	return res;
}

std::vector< uint8_t > XInt::Increment( const std::vector< uint8_t > & num )
{
	return Add( num, { 1 } );
}

std::vector< uint8_t > XInt::Decrement( const std::vector< uint8_t > & num )
{
	return Subtract( num, { 1 } );
}
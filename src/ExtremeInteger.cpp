#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../include/ExtremeInteger.hpp"

//////////////////////////////////////////////////////////////////////////
////////////////////////////// PRIVATE ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////

////////////////////////// NUMBER VALIDATION /////////////////////////////

bool XInt::IsValidNumber( const std::string & num )
{
	for( auto n : num ) {
		if( n < '0' || n > '9' )
			throw std::invalid_argument( "Invalid number entered!" );
	}

	return true;
}

bool XInt::IsValidNumber( const std::vector< uint8_t > & num )
{
	for( auto n : num ) {
		if( n < 0 || n > 9 )
			throw std::invalid_argument( "Invalid number entered!" );
	}

	return true;
}

//////////////////////// STRING/VECTOR REVERSAL //////////////////////////

std::vector< uint8_t > XInt::ToReverseVector( const std::string & num )
{
	std::vector< uint8_t > temp;
	for( auto n = num.rbegin(); n != num.rend(); ++n )
		temp.push_back( ( * n ) - '0' );

	return temp;
}

std::string XInt::ToReverseString( const std::vector< uint8_t > & num )
{
	std::string temp;

	for( auto n = num.rbegin(); n != num.rend(); ++n )
		temp += '0' + ( * n );

	return temp;
}

//////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////

////////////////////////// CONSTRUCTORS //////////////////////////////////

XInt::XInt()
{
	this->number.push_back( 0 );
}

XInt::XInt( const XInt & num ) : number( num.number )
{}

XInt::XInt( const std::string & num )
{
	if( num.size() < 1 ) {
		this->number.push_back( 0 );
	}
	else {
		XInt::IsValidNumber( num );
		this->number = ToReverseVector( num );
	}
}

XInt::XInt( const std::vector< uint8_t > & digits )
{
	if( digits.empty() ) {
		this->number.push_back( 0 );
	}
	else {
		IsValidNumber( digits );
		this->number = digits;
	}
}

//////////////////////// BASIC OPERATORS /////////////////////////////////

XInt XInt::operator +( const XInt & num2 )
{
	return Add( this->number, num2.number );
}

XInt XInt::operator -( const XInt & num2 )
{
	return Subtract( this->number, num2.number );
}

XInt XInt::operator *( const XInt & num2 )
{
	return Multiply( this->number, num2.number );
}

//////////////////////// INCREMENT/DECREMENT OPERATORS ///////////////////

XInt & XInt::operator ++()
{
	* this = XInt::Increment( this->number );
	return * this;
}

XInt XInt::operator ++( int )
{
	XInt temp = * this;

	* this = XInt::Increment( this->number );

	return temp;
}

XInt & XInt::operator --()
{
	* this = XInt::Decrement( this->number );
	return * this;
}

XInt XInt::operator --( int )
{
	XInt temp = * this;

	* this = XInt::Decrement( this->number );

	return temp;
}

////////////////////// I/O OPERATOR OVERLOADS ////////////////////////////

std::ostream & operator <<( std::ostream & os, const XInt & exint )
{
	os << XInt::ToReverseString( exint.number );
	return os;
}

std::istream & operator >>( std::istream & is, XInt & exint )
{
	std::string temp;
	is >> temp;

	XInt::IsValidNumber( temp );

	exint.number = XInt::ToReverseVector( temp );

	return is;
}

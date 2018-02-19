#ifndef EXTREMEINTEGER_HPP
#define EXTREMEINTEGER_HPP

#include <iostream>
#include <string>
#include <vector>

class XInt
{
	// Stored as reverse array.
	std::vector< uint8_t > number;

	static bool IsValidNumber( const std::string & num );
	static bool IsValidNumber( const std::vector< uint8_t > & num );

	static std::vector< uint8_t > ToReverseVector( const std::string & num );
	static std::string ToReverseString( const std::vector< uint8_t > & num );

	// Extreme Mathematics, all vectors are reverse.
	static std::vector< uint8_t > Add( const std::vector< uint8_t > & num1, const std::vector< uint8_t > & num2 );
	static std::vector< uint8_t > Subtract( const std::vector< uint8_t > & num1, const std::vector< uint8_t > & num2 );
	static std::vector< uint8_t > Multiply( const std::vector< uint8_t > & num1, const std::vector< uint8_t > & num2 );

	static std::vector< uint8_t > Increment( const std::vector< uint8_t > & num );
	static std::vector< uint8_t > Decrement( const std::vector< uint8_t > & num );

public:

	XInt();

	XInt( const XInt & num );
	XInt( const std::string & num );
	XInt( const int & num );
	XInt( const std::vector< uint8_t > & digits );

	XInt operator +( const XInt & num2 );
	XInt operator -( const XInt & num2 );
	XInt operator *( const XInt & num2 );

	XInt & operator ++();
	XInt operator ++( int );
	XInt & operator --();
	XInt operator --( int );

	friend std::ostream & operator <<( std::ostream & os, const XInt & exint );
	friend std::istream & operator >>( std::istream & is, XInt & exint );

};

#endif // EXTREMEINTEGER_HPP
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
	this->fp_value = raw;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw)
{
	//
	std::cout << "Float constructor called" << std:endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp_value = fixed.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fp_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float	toFloat(void) const
{

}

int	toInt(void) const
{

}
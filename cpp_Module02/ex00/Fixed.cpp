#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	this->fp_value = fixed.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
		this->fp_value = fixed.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
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

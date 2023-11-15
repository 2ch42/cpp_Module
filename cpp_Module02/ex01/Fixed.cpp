#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
	this->fp_value = (raw << this->frac_bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw)
{
	this->fp_value = roundf(raw * (1 << this->frac_bits));
	std::cout << "Float constructor called" << std::endl;
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

float	Fixed::toFloat(void) const
{
	return ((float)(this->fp_value) / (1 << this->frac_bits));
}

int	Fixed::toInt(void) const
{
	return (this->fp_value >> this->frac_bits);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
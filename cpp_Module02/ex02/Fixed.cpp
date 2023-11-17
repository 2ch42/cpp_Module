#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
	this->fp_value = raw << this->frac_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw)
{
	this->fp_value = std::roundf(raw * (1 << frac_bits));
	std::cout << "Float constructor called" << std::endl;
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

float	Fixed::toFloat(void) const
{
	return ((float)this->fp_value / (1 << this->frac_bits));
}

int	Fixed::toInt(void) const
{
	return (this->fp_value >> this->frac_bits);
}

// comparison operators

bool Fixed::operator>(const Fixed& fixed)
{
	int pre_value = this->getRawBits();
	int	post_value = fixed.getRawBits();
	return (pre_value > post_value);
}

bool Fixed::operator<(const Fixed& fixed)
{
	int	pre_value = this->getRawBits();
	int	post_value = fixed.getRawBits();
	return (pre_value < post_value);
}

bool Fixed::operator>=(const Fixed& fixed)
{
	int	pre_value = this->getRawBits();
	int	post_value = fixed.getRawBits();
	return (pre_value >= post_value);
}

bool Fixed::operator<=(const Fixed& fixed)
{
	int	pre_value = this->getRawBits();
	int	post_value = fixed.getRawBits();
	return (pre_value <= post_value);
}

bool Fixed::operator==(const Fixed& fixed)
{
	int	pre_value = this->getRawBits();
	int	post_value = fixed.getRawBits();
	return (pre_value == post_value);
}

bool Fixed::operator!=(const Fixed& fixed)
{
	int	pre_value = this->getRawBits();
	int	post_value = fixed.getRawBits();
	return (pre_value == post_value);
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed& fixed)
{
	Fixed	temp;
	temp.setRawBits(this->fp_value + fixed.fp_value);
	return (temp);
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	Fixed	temp;
	temp.setRawBits(this->fp_value - fixed.fp_value);
	return (temp);
}

Fixed Fixed::operator*(const Fixed& fixed)
{
	Fixed	temp(this->toFloat() * fixed.toFloat());
	return (temp);
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	Fixed temp(this->toFloat() / fixed.toFloat());
	return (temp);
}

// increment & decrement operators

Fixed& Fixed::operator++()
{
	int fp_value = this->getRawBits();
	this->setRawBits(fp_value + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	int fp_value = this->getRawBits();
	this->setRawBits(fp_value + 1);
	return (temp);
}

Fixed& Fixed::operator--()
{
	int fp_value = this->getRawBits();
	this->setRawBits(fp_value - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	int fp_value = this->getRawBits();
	this->setRawBits(fp_value - 1);
	return (temp);
}

// additional member function

Fixed&	Fixed::min(Fixed& pre, Fixed& post)
{
	if (pre >= post)
		return (post);
	else
		return (pre);
}

const Fixed& Fixed::min(const Fixed& pre, const Fixed& post)
{
	int	pre_value = pre.getRawBits();
	int	post_value = post.getRawBits();
	if (pre_value >= post_value)
		return (post);
	else
		return (pre);
}

Fixed&	Fixed::max(Fixed& pre, Fixed& post)
{
	if (pre >= post)
		return (pre);
	else
		return (post);
}

const Fixed& Fixed::max(const Fixed& pre, const Fixed& post)
{
	int	pre_value = pre.getRawBits();
	int	post_value = post.getRawBits();
	if (pre_value >= post_value)
		return (pre);
	else
		return (post);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
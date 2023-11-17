#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	fp_value;
		static const int	frac_bits = 8;
	public:
		Fixed();
		Fixed(const int raw); //added
		Fixed(const float raw); //added
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const; //added
		int	toInt(void) const; //added
		
		bool operator>(const Fixed& fixed); // comparision operators
		bool operator<(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);

		Fixed	operator+(const Fixed& fixed); // arithmetic operators
		Fixed	operator-(const Fixed& fixed);
		Fixed	operator*(const Fixed& fixed);
		Fixed	operator/(const Fixed& fixed);

		Fixed&	operator++(); // increment & decrement operators
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed& pre, Fixed& post); // additional member function
		static const Fixed&	min(const Fixed& pre, const Fixed& post);
		static Fixed&	max(Fixed& pre, Fixed& post);
		static const Fixed&	max(const Fixed& pre, const Fixed& post);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

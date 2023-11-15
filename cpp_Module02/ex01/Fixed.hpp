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
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

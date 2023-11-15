#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	fp_value;
		static const int	frac_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif

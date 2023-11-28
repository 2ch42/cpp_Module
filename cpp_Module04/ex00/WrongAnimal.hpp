#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& Wronganimal);
		WrongAnimal& operator=(const WrongAnimal& wronganimal);
		~WrongAnimal();
		void	makeSound() const;
		std::string	getType() const;
};

#endif

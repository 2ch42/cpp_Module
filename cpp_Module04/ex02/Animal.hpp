#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal // with pure virtual function
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& animal);
		Animal& operator=(const Animal& animal);
		virtual ~Animal();
		virtual void	makeSound() const = 0; // pure virual function
		std::string	getType() const;
};

#endif

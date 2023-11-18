#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int	hit_points;
		int	energy_points;
		int	attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap& operator=(const ClapTrap& claptrap);
		~ClapTrap();
		std::string	get_name(void) const;
		void	set_name(std::string name);
		int		get_hp(void) const;
		void	set_hp(int hit_points);
		int		get_ep(void) const;
		void	set_ep(int energy_points);
		int		get_ad(void) const;
		void	set_ad(int attack_damage);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRapired(unsigned int amount);
};

#endif

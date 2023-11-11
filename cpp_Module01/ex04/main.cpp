#include <iostream>
#include <fstream>
#include <string>

int	get_text(int argc, char *argv[], std::string& s)
{
	std::ifstream in(argv[1]);
	if (in.is_open())
		std::getline(in, s, '\0');
	else
	{
		std::cout << "File open error!" << std::endl;
		return (0);
	}
	return (1);
}

void	w_file(std::string& s, std::string new_file)
{
	std::ofstream out(new_file);
	if (out.is_open())
		out << s;
	else
		std::cout << "New file open error!" << std::endl;
}

int arg_err(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	return (0);
}

void	man_text(int argc, char *argv[], std::string& s)
{
	std::string pre_str(argv[2]);
	std::string post_str(argv[3]);
	int idx = s.find(pre_str);
	int	len;
	int	check;
	while (idx >= 0)
	{
		s.erase(idx, pre_str.size());
		s.insert(idx, post_str);
		len = (s.substr(0, idx + post_str.size())).size();
		check = (s.substr(idx + post_str.size(), s.size() - len)).find(pre_str);
		if (check < 0)
			break;
		idx = len + check;
	}
}

int main(int argc, char *argv[])
{
	if (arg_err(argc, argv))
	{
		std::cout << "Argc Error!" << std::endl;
		return (0);
	}

	std::string new_file = argv[1];
	new_file +=	 ".replace";

	std::string s;

	if (!(get_text(argc, argv, s)))
		return (0);
	man_text(argc, argv, s);
	w_file(s, new_file);
	return (0);
}

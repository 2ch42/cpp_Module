#include <iostream>
#include <fstream>
#include <string>

int arg_err(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	return (0);
}

int	get_text(int argc, char *argv[], std::string& s)
{
	std::ifstream in(argv[1]);
	if (in.is_open())
	{
		in.seekg(0, std::ios::end);
		int size = in.tellg();
		s.resize(size);
		in.seekg(0, std::ios::beg);
		in.read(&s[0], size);
	}
	else
	{
		std::cout << "File open error!" << std::endl;
		return (1);
	}
	return (0);
}

void	w_file(std::string& s, std::string new_file)
{
	std::ofstream out(new_file);
	if (out.is_open())
		out << s;
	else
		std::cout << "New file open error!" << std::endl;
}

void	man_text(int argc, char *argv[], std::string& s)
{
	std::string pre_str(argv[2]);
	std::string post_str(argv[3]);
	int idx = s.find(pre_str);
	while (idx >= 0)
	{
		s.replace(idx, pre_str.size(), post_str);
		idx = s.find(pre_str);
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

	if (get_text(argc, argv, s))
		return (0);
	man_text(argc, argv, s);
	w_file(s, new_file);
	return (0);
}

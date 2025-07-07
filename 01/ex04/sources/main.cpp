# include <iostream>
# include <fstream>

std::string	ftReplace(std::string line, char *str1, char *str2)
{
	std::string	s1;
	std::string	s2;
	std::string	ret;
	size_t		pos;

	s1 = str1;
	s2 = str2;
	pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.size());
		line.insert(pos, s2);
		pos++;
	}
	return (line);
}

int	ftSed(char **av)
{
	std::ifstream	fd1; //ifstream pour ouvrir en lecture seule
	std::ofstream	fd2;
	std::string		f2;
	std::string		line;
	// std::fstream	fd1(av[1]); //declare et ouvre en meme temps

	fd1.open(av[1]);
	if (fd1.is_open() == false)
	{
		std::cout << "Error while opening " << av[1] << std::endl;
		return (1);
	}
	f2 = std::string(av[1]) + ".replace";
	fd2.open(f2.c_str(), std::ios::out);
	if (fd2.is_open() == false)
	{
		std::cout << "Error while creating " << f2 << std::endl;
		return (1);
	}

	// std::getline(fd1, line);
	while (std::getline(fd1, line) && !line.empty())
		fd2 << ftReplace(line, av[2], av[3]) << std::endl;
	//fermer le fd
	fd1.close();
	fd2.close();
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "3 arguments needed: a filename and two string" << std::endl;
		return (1);
	}
	if (ftSed(av) == 1)
		return (1);
	return (0);
}

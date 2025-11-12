#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	text;

	if (argc == 4)
	{
		std::string search = argv[2];
		std::fstream inputFile(argv[1]);
		std::ofstream outputFile(((std::string)argv[1] + ".replace").c_str());
		std::size_t searchSize = search.size();
		if (!searchSize || !inputFile)
		{
			std::cout << "Problem with string search size or reading from input file" << std::endl;
			return (0);
		}
		while (getline(inputFile, text))
		{
			std::string temp;
			std::size_t	found = text.find(search);
			while (found != std::string::npos)
			{
				temp = text.substr(0, found);
				temp.append(argv[3]);
				temp.append(text, found + searchSize);
				text = temp;
				found = text.find(argv[2]);
			}
			outputFile << text << std::endl;
		}
	}
	else
		std::cout << "You must input a filename and two strings" << std::endl;
	return (0);
}

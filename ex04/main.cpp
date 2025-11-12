#include <fstream>
#include <iostream>

int	main(int argc, char **argv)
{
	std::string	text;
	std::string inPath;
	std::string outPath;

	if (argc == 4)
	{
		std::ofstream	outputFile;
		std::ifstream	inputFile;
		std::string sub = argv[3];
		std::string search = argv[2];
		std::size_t searchSize = search.size();
		inPath = argv[1];
		outPath = inPath + ".replace";
		inputFile.open(inPath.c_str());
		outputFile.open(outPath.c_str());

		while (getline(inputFile, text))
		{
			std::string temp;

			std::size_t	found = text.find(argv[2]);
			while (found != std::string::npos)
			{
				temp = text.substr(0, found);
				temp.append(sub);
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

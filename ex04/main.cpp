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
		// std::size_t textSize = 0;
		std::string sub = argv[3];
		std::string search = argv[2];
		std::size_t subSize = sub.size();
		std::size_t searchSize = search.size();
		inPath = argv[1];
		outPath = inPath + ".replace";
		inputFile.open(inPath.c_str());
		outputFile.open(outPath.c_str());

		while (getline(inputFile, text))
		{
			std::size_t	count = 0;
			std::string temp = text;

			std::size_t	found = temp.find(argv[2]);
			while (found != std::string::npos)
			{
				std::size_t textSize = temp.size();

				// if (count < textSize)
				// {
				temp = text.substr(0, found);
				count += found;
				if (count < textSize)
				{
					temp.append(sub);
					temp.append(text, count + searchSize);
				}
				// }
				found = temp.find(argv[2]);
				if (found != std::string::npos)
					count += subSize;
				// textSize = temp.size();
			}
			// temp.append(text, searchSize + 1);
			outputFile << temp << std::endl;
		}
	}
	else
		std::cout << "You must input a filename and two strings" << std::endl;

	return (0);
}

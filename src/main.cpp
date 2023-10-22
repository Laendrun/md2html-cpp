#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Tokenizer.hpp"
#include "Parser.hpp"
#include "Generator.hpp"
#include "structs.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		std::cerr << "./convert <input.md>." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string in_content;
	{
		std::stringstream content_stream;
		std::fstream input(av[1], std::ios::in);
		content_stream << input.rdbuf();
		in_content = content_stream.str();
	}

	Tokenizer tokenizer(in_content);
	std::vector<Token> tokens = tokenizer.tokenize();

	Parser parser(tokens);
	std::vector<Node> nodes = parser.parse();

	Generator generator(nodes);
	{
		std::fstream output("output.html", std::ios::out);
		output << generator.generate();
	}

	exit(EXIT_SUCCESS);
}
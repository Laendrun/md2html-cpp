#ifndef GENERATOR_HPP
# define GENERATOR_HPP
# include "structs.hpp"
# include <iostream>
# include <sstream>
# include <vector>
# include <optional>
# include <string>
# include <variant>

class Generator
{
	public:
		Generator(std::vector<Node> nodes);
		~Generator();
		std::string	generate(void);
	private:
		const std::vector<Node>	m_nodes;
		std::stringstream		m_output;

		void	gen_node(Node node);
		void	gen_title(NodeTitle node);
};

#endif
#ifndef PARSER_HPP
# define PARSER_HPP
# include "structs.hpp"
# include <iostream>
# include <vector>
# include <optional>
# include <string>

class Parser
{
	public:
		Parser(std::vector<Token> tokens);
		~Parser();
		std::vector<Node>	parse(void);
	private:
		const std::vector<Token>	m_tokens;
		size_t						m_index = 0;
		std::optional<Token>		peek(int offset = 0) const;
		Token						consume(void);
};

#endif
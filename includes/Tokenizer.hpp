#ifndef TOKENIZER_HPP
# define TOKENIZER_HPP
# include "structs.hpp"
# include <iostream>
# include <vector>
# include <optional>
# include <string>

class Tokenizer
{
	public:
		Tokenizer(std::string &source);
		~Tokenizer();
		std::vector<Token>	tokenize(void);
	private:
		const std::string	m_source;
		size_t				m_index = 0;
		std::optional<char>	peek(int offset = 0) const;
		char				consume(void);
};

#endif
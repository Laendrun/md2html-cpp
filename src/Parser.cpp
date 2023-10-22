#include "Parser.hpp"

Parser::Parser(std::vector<Token> tokens): m_tokens(tokens) {}

Parser::~Parser() {}

std::vector<Node>	Parser::parse(void)
{
	std::vector<Node>	nodes;
	while (peek().has_value())
	{
		if (peek().value().type == TokenType::title)
		{
			Token title = consume();
			assert(peek().value().type == TokenType::text && "Title must have a text.");
			Token text = consume();
			nodes.push_back({ .value = NodeTitle { .title = title, .text = text } });
		}
		else if (peek().value().type == TokenType::text)
		{
			Token text = consume();
			nodes.push_back({ .value = NodeText { .text = text } });
		}
		else if (peek().value().type == TokenType::nl)
		{
			consume();
		}
		else
		{
			assert(false && "Not implemented.");
		}
	}
	m_index = 0;
	return nodes;
}

std::optional<Token>	Parser::peek(int offset) const
{
	if (m_index + offset >= m_tokens.size())
		return std::nullopt;
	return m_tokens[m_index + offset];
}

Token	Parser::consume(void)
{
	return m_tokens[m_index++];
}
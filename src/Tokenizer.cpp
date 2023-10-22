#include "Tokenizer.hpp"

const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

Tokenizer::Tokenizer(std::string &source): m_source(source) {}

Tokenizer::~Tokenizer() {}

std::vector<Token>	Tokenizer::tokenize(void)
{

	std::vector<Token>	tokens;
	std::string			buf;
	while (peek().has_value())
	{
		if (peek().value() == '#')
		{
			// TokenType::title
			buf.push_back(consume());
			while (peek().has_value() && peek().value() == '#')
				buf.push_back(consume());
			assert(peek().value() == ' ' && "Title must be followed by a space.");
			consume();
			tokens.push_back({ .type = TokenType::title, .value = trim(buf) });
			buf.clear();
		}
		else if (std::isprint(peek().value()))
		{
			// TokenType::text
			while (peek().has_value() && std::isprint(peek().value()) && peek().value() != '\n')
				buf.push_back(consume());
			tokens.push_back({ .type = TokenType::text, .value = trim(buf) });
			buf.clear();
		}
		else if (peek().value() == '\n')
		{
			// TokenType::newline
			consume();
			tokens.push_back({ .type = TokenType::nl, .value = "" });
		}
		else
		{
			assert(false && "Not implemented.");
		}
	}
	m_index = 0;
	return tokens;
}

std::optional<char>	Tokenizer::peek(int offset) const
{
	if (m_index + offset >= m_source.length()) {
		return {};
	}
	else {
		return m_source.at(m_index + offset);
	}
}

char	Tokenizer::consume(void)
{
	return m_source.at(m_index++);
}
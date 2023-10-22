#ifndef STRUCTS_HPP
# define STRUCTS_HPP
# include <optional>
# include <variant>
# include <string>

enum class TokenType
{
	title, // #, ##, ###, ####, #####, ######
	text, // any printable character
	nl, // \n
	chevron, // >
	underscore, // _
	star, // *
	tilde, // ~
	pipe, // |
	dash, // -
	backtick // `
};

struct Token
{
	TokenType	type;
	std::optional<std::string>	value;
};

struct NodeTitle
{
	Token	title;
	Token	text;
};

struct Node
{
	std::variant<NodeTitle>	value;
};


#endif
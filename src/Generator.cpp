#include "Generator.hpp"

Generator::Generator(std::vector<Node> nodes) : m_nodes(nodes) {}

Generator::~Generator() {}

std::string	Generator::generate(void)
{
	m_output << "<!DOCTYPE html>\n";
	for (auto node : m_nodes)
	{
		gen_node(node);
	}

	return m_output.str();
}

void	Generator::gen_node(Node node)
{
	struct NodeVisitor {
		Generator& gen;
		void operator()(const NodeTitle& node) const 
		{
			gen.gen_title(node);
		}
	};

	NodeVisitor visitor { .gen = *this };
	std::visit(visitor, node.value);
}

void	Generator::gen_title(NodeTitle node)
{
	const int level = node.title.value.value().length();
	m_output << "<h" << level << ">" << node.text.value.value() << "</h" << level << ">\n";
}
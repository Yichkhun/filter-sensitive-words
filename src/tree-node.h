#ifndef __TREE_NODE__
#define __TREE_NODE__

#include <string>
#include <unordered_map>

class CTreeNode
{
public:
	CTreeNode();
	CTreeNode(bool aend);
	~CTreeNode();

public:
	//insert tire tree node 
	CTreeNode * insert_tree_node(std::string anode_val, bool aend);
	//find tire node by tire tree
	CTreeNode * find_tree_node(std::string anode_val);	
	
public:
	bool													m_end;
	std::unordered_map<std::string, CTreeNode*>				m_tree;
};

#endif //__TREE_NODE__
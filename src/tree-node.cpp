#include "stdafx.h"
#include "tree-node.h"

CTreeNode::CTreeNode()
	:m_end(false)
{
}

CTreeNode::CTreeNode(bool aend)
{
	m_end = aend;
}

CTreeNode::~CTreeNode()
{
}

CTreeNode* CTreeNode::insert_tree_node(std::string anode_val, bool aend)
{
	m_end = aend;
	m_tree[anode_val] = this;
	return this;
}

CTreeNode* CTreeNode::find_tree_node(std::string anode_val)
{
	auto iter = m_tree.find(anode_val);
	if(iter == m_tree.end())
	{
		return NULL;
	}
	return iter->second;
}



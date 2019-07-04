#ifndef	__TIRE_TREE__
#define __TIRE_TREE__

#include <string>
#include "tree-node.h"

class CTireTree
{
public:
	CTireTree();
	~CTireTree();

public:
	//insert data	
	CTreeNode * insert_word(const std::string & awords);
	//find sensitive words imp
	CTreeNode * filter_sensitive_words(const std::string & awords, unsigned int & alength);
	//replace sensitive words to ***
	bool replace_sensitive_words(std::string & awords);

private:
	//insert words to tire tree
	CTreeNode * insert_word_to_tire(CTreeNode * aparent, const std::string & awords);
	//create new node
	CTreeNode * create_tire_tree_node(CTreeNode * aparent, const std::string & awords, bool aend = false);
	//find sensitive words
	CTreeNode * filter_sensitive_words(CTreeNode * aparent, const std::string & awords, unsigned int & alength);

private:
	//tire tree root is empty
	CTreeNode												m_root;
};

#endif //__TIRE_TREE__
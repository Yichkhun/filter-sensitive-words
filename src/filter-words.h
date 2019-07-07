#ifndef	__FILTER_WORDS_H__
#define __FILTER_WORDS_H__

#include <vector>
#include "tire-tree.h"

class CFilter
{
public:
	CFilter();
	~CFilter();

public:
	//create tire tree for store keywords
	void create_tire_tree();
	//replace sensitive words to ***
	bool adjust_sensitive_words(std::string & adealstr);
	//load sensitive words from file
	bool load_keywords(const char * afilepath);

private:
	std::vector<std::string>					m_words_vec;	//cache sensitive words
	bool								m_res;		//make tire tree res
	CTireTree							m_tree;		//tire tree
};

#endif //__FILTER_WORDS_H__

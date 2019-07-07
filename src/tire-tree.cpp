#include "stdafx.h"
#include "tire-tree.h"
#include "common.h"
#include "tree-node.h"

CTireTree::CTireTree()
{
}

CTireTree::~CTireTree()
{
}

CTreeNode * CTireTree::insert_word(const std::string & awords)
{
	return insert_word_to_tire(&m_root, awords);
}

CTreeNode * CTireTree::filter_sensitive_words(const std::string & awords, unsigned int & alength)
{
	return filter_sensitive_words(&m_root, awords, alength);
}

bool CTireTree::replace_sensitive_words(std::string & awords)
{
	bool _relpace = false;
	int _length = awords.size();
	int i = 0;
	
	while(i < _length){
		unsigned int _len = 0;
		std::string _newStr = awords.substr(i, _length - i);
		
		if( filter_sensitive_words(_newStr, _len) != NULL ) {
			_relpace = true;
			awords.replace(i, _len, "***");
			_length = awords.size();
			i += 3;
		} else {
			i += _len;	
		}
	}

	return _relpace;
}

CTreeNode * CTireTree::insert_word_to_tire(CTreeNode * aparent, const std::string & awords)
{
	if(awords.size() == 0){
		return NULL;
	}

	std::vector<std::string>	_vec;
	CTreeNode * _parent = aparent;
	msgop::split_utf8(awords, _vec);

	for(auto i = 0; i < _vec.size(); i++){
		std::string & _word = _vec[i];
		CTreeNode * _node = _parent->find_tree_node(_word);
		
		if(_node){
			if(i == _vec.size() - 1){
				_node->m_end = true;
			}
			_parent = _node;
			continue;
		}
		
		bool _end = false;
		if(i == _vec.size() - 1){	
			_end = true;
		}	
		_parent = create_tire_tree_node(_parent, _word, _end);		
	}
	
	return _parent;
}

CTreeNode * CTireTree::create_tire_tree_node(CTreeNode * aparent, const std::string & awords, bool aend)
{
	return aparent->insert_tree_node(awords, aend);
}

CTreeNode * CTireTree::filter_sensitive_words(CTreeNode * aparent, const std::string & awords, unsigned int & alength)
{
	std::vector<std::string>	_vec;
	msgop::split_utf8(awords, _vec);
	alength = 0;
	unsigned int _last_len	 = 0;
	CTreeNode	 *_last_node = NULL;	
	CTreeNode	 *_parent	 = aparent;

	for (int i = 0; i < _vec.size(); ++i){
		alength += _vec[i].size();
		CTreeNode * _node = _parent->find_tree_node(_vec[i]);

		if (!_node) {
			if (_last_len){
				alength = _last_len;
				return _last_node;
			}
			if (alength - _vec[i].size() != 0){
				alength = _vec[0].size();
			}
			return NULL;
		}

		_parent = _node;
		if (_node->m_tree.empty()){
			return _node;	
		}

		if (_node->m_end){
			_last_len = alength;
			_last_node = _node;
		}
	}

	if (_last_len){
		alength = _last_len;
		return _last_node;
	}

	alength = _vec[0].size();
	return NULL;
}






















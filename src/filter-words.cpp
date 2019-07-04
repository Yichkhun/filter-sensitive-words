#include "stdafx.h"
#include "filter-words.h"
#include "common.h"

CFilter::CFilter()
	:m_res(false)
{
}

CFilter::~CFilter()
{
}

void CFilter::create_tire_tree()
{
	auto pfn = [&](std::vector<std::string>::reference onepair){
		m_tree.insert_word(onepair);
	};
	std::for_each(m_words_vec.begin(), m_words_vec.end(), pfn);
	m_res = true;
}

bool CFilter::adjust_sensitive_words(std::string & adealstr)
{
	if (false == m_res){
		std::cout<<"be sure to create tire tree"<<std::endl;
		return  false;
	}

	return m_tree.replace_sensitive_words(adealstr);
}

bool CFilter::load_keywords(const char * afilepath)
{
	std::ifstream in(afilepath);

	if (in.fail()){
		std::cout<<"load file error"<<std::endl;
		return false;
	}

	std::string _file_context;
	while (getline(in, _file_context)){
		std::string _fin_context;
		msgop::string_trim(_file_context, _fin_context);
		m_words_vec.push_back(_fin_context);
	}

	return true;
}




#include "stdafx.h"
#include "common.h"

void msgop::string_trim(std::string & aparam_in, std::string & aparam_out)
{
	char * p = (char *)aparam_in.c_str();
	char _buffer[256] = { 0 };
	char * q = _buffer;
	int _size = static_cast<int>(aparam_in.size());

	for(auto i = 0; i < _size; i ++){
		if(*p == '\n' || *p == '\t' || *p == '\r' || *p == '\f' || *p == '\v'){
			p++;
		}else{
			*q++ = *p++;
		}
	}
	aparam_out = _buffer;
}

void msgop::split_utf8(std::string aword, std::vector<std::string>& avec)
{
	int _size = static_cast<int>(aword.size());
	int i = 0;
	
	while(i < _size){
		int _len = 1;
		if(aword[i] & 0x80){
			unsigned char _char = aword[i];
			_char <<= 1;
			do{
				_char <<= 1;
				++_len;
			}while(_char & 0x80);
		}
		std::string _sub_word;
		_sub_word = aword.substr(i, _len);
		if(_sub_word.size() > 0){
			avec.push_back(_sub_word);
			i += _len;
		}
	}
}

#include "01_constructor.h"

Constructor::Constructor(){
        _s_copy = NULL;
	_sId = 0;
	_sLength = 16;

}

Constructor::Constructor(char sId, int sLength){
	_s_copy= NULL;
	_sId = sId;
	_sLength = sLength;
        _s_copy = new char[_sLength];
}

Constructor::Constructor(const char* str){
	_s_copy=NULL;
	_sId = 0;
	_sLength = 16;
	if(str != NULL){
        	_s_copy = new char[_sLength];
	        //strcpy(_s_copy, str);
		std::memcpy( _s_copy, str, _sLength);
	}
}

Constructor::Constructor(const char* str, int sLength){
	_s_copy=NULL;
	_sId = 0;
	_sLength = sLength;
	if(str != NULL){
	        _s_copy = new char[_sLength];
        	//strcpy(_s_copy, str);
	        std::memcpy( _s_copy, str, _sLength);
	}
}

Constructor::Constructor(const Constructor& str){
        this->_s_copy= NULL;
	_sId= str.getId();
	_sLength= str.getLength();
        if(str._s_copy != NULL){
                _s_copy= new char [_sLength]; //Dynamic memory alocation
                strcpy(_s_copy, str._s_copy);
        }
}

Constructor& Constructor::operator=(const Constructor& str){
        if(this == &str){
                return *this;
        }
        else{
		_sId= str.getId();
		_sLength= str.getLength();
                char* tmp_s_copy = new char[_sLength];
                delete []_s_copy;
                _s_copy= tmp_s_copy;
                strcpy(_s_copy,str._s_copy);

        }
        return *this;
}

Constructor::~Constructor(){
        if(_s_copy != NULL){
                delete []_s_copy;
        }

}

char* Constructor::getString() const{
	return _s_copy;
}

char Constructor::getId() const{
	return _sId;


}
int Constructor::getLength() const{
	return _sLength;

}

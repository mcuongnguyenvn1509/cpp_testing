#include "01_constructor.h"

Constructor::Constructor(){
        _s_copy = NULL;

}

Constructor::Constructor(const char* str){
	_s_copy=NULL;
        _s_copy = new char[16];
        strcpy(_s_copy, str);
}

Constructor::Constructor(const Constructor& str){
        this->_s_copy= NULL;
        if(str._s_copy != NULL){
                _s_copy= new char [16]; //Dynamic memory alocation
                strcpy(_s_copy, str._s_copy);
        }


}

Constructor& Constructor::operator=(const Constructor& str){
        if(this == &str){
                return *this;
        }
        else{
                char* tmp_s_copy = new char[16];
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

#include "bitio.hh"
#include <iostream>
#include <cassert>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////////////

BitIO::BitIO(std::ostream* os, std::istream* is){ 
    
    assert(!((os && is)||!(os || is)));

    if(os!=nullptr){
        os_ = os;
        is_ = nullptr;
    }
    else{
        is_ = is;
        os_ = nullptr;
    }

    index_ = 0;
    byte_ = 0;
}

//////////////////////////////////////////////////////////////////////////////////////

BitIO::~BitIO(){
    if(os_!=nullptr){
        while(index_ != 0){
            output_bit(false);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////

bool
BitIO::input_bit(){
    //char mask = 0b10000000;
    bool result;

    if(index_ == 0){
        is_ -> get(byte_);
    }

    if((0b10000000 & byte_) == 0b10000000){
        result = true;
    }

    else{
        result = false;
    }

    byte_ <<= 1;
    index_ = (index_+1)%8;

    return result;
}

//////////////////////////////////////////////////////////////////////////////////////

void
BitIO::output_bit(bool bit){

    if(bit){
        byte_ <<= 1;
        byte_ |= 1;
        index_ += 1;
    }

    else{
        byte_ <<= 1;
        index_ += 1;
    }
    
    if(index_ == 8){
        os_ -> put(byte_);
        byte_ = 0;
        index_ = 0;
    }
}

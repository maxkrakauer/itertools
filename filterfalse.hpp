
#pragma once
#include "range.hpp"
#include "accumulate.hpp"
#include <vector>
#include <iostream>
using namespace std;




template<typename OP, typename T>

class Filterfalse{
	public:
	T _first;
	OP _op;

	Filterfalse(OP op, const T& first ):_first(first),_op(op){}

	struct iterator{
		decltype(_first.begin()) firstIterator;
		OP _op;
		
		
		auto operator*(){
			//return *firstIterator;
			while(!_op(*firstIterator)){
                ++firstIterator;
            }
            return *firstIterator;
		}

		iterator& operator++(){
			++firstIterator;
            return *this;
		}

		iterator& operator++(int){
			iterator tmp=*this;
			operator++();
			return tmp;
		}

		bool operator==(const iterator& other){
			return firstIterator==other.firstIterator;
		}

		bool operator!=(const iterator& other){
			return !(operator==(other));
		}

	};

		iterator begin() const{
			return iterator{_first.begin(), _op};
		}

		iterator end() const{
			return iterator{_first.end(),  _op};
		}

		iterator begin() {
			return iterator{_first.begin(),  _op};
		}

		iterator end() {
			return iterator{_first.end(), _op};
		}




    size_t size(){
        return _first.size();
    }





	};




namespace itertools{

template<typename OP,typename S>
Filterfalse <OP,S> filterfalse(OP op, S s){
	Filterfalse<OP,S>r(op,s);
	return r;
}



};




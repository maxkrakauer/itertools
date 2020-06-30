
#pragma once
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include <vector>
#include <iostream>
using namespace std;




template<typename T, typename S>

class Compress{
	public:
	T _first;
	S _second;

	Compress(const T& first, const S& second):_first(first),_second(second){}

	struct iterator{
		decltype(_first.begin()) firstIterator;
        decltype(_second.begin()) secondIterator;
	
		
		
		auto operator*(){
			//return *firstIterator;
			while(!*secondIterator){
                ++firstIterator;
                ++secondIterator;
            }
            return *firstIterator;
		}

		iterator& operator++(){
			++firstIterator;
            ++secondIterator;
            return *this;
		}

		iterator& operator++(int){
			iterator tmp=*this;
			operator++();
			return tmp;
		}

		bool operator==(const iterator& other){
			return firstIterator==other.firstIterator && 
            secondIterator==other.secondIterator;
		}

		bool operator!=(const iterator& other){
			return !(operator==(other));
		}

	};

		iterator begin() const{
			return iterator{_first.begin(), _second.begin()};
		}

		iterator end() const{
			return iterator{_first.end(), _second.end()};
		}

		iterator begin() {
			return iterator{_first.begin(), _second.begin()};
		}

		iterator end() {
			return iterator{_first.end(), _second.end()};
		}




    size_t size(){
        return _first.size();
    }





	};




namespace itertools{

template<typename T,typename S>
Compress <T,S> compress(T t, S s){
	Compress<T,S>r(t,s);
	return r;
}



};




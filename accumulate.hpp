
#pragma once
#include "range.hpp"
#include <vector>
#include <iostream>
using namespace std;


template<typename T>

class Accumulate{
	public:
	T _first;
	Accumulate(const T& first):_first(first){}

	struct iterator{
		decltype(_first.begin()) firstIterator;
	    T _f;
		size_t _index;
		
		
		auto operator*(){
			//return *firstIterator;
			//decltype(_first.begin()) firstsum;
			auto sum=*_f.begin();
			int index=0;
			for(auto i: _f){
				if(index>_index)
				break;
				if(index>0)
				sum+=i;
				index++;
			}
			return sum;
		}

		iterator& operator++(){
			//++firstIterator;
			++_index;
			return *this;
		}

		iterator& operator++(int){
			iterator tmp=*this;
			operator++();
			_index++;
			return tmp;
		}

		bool operator==(const iterator& other){
			return _index==other._index;
		}

		bool operator!=(const iterator& other){
			return !(operator==(other));
		}

	};

		iterator begin() const{
			return iterator{_first.begin(), _first.end(), _first, 0};
		}

		iterator end() const{
			return iterator{_first.end(), _first.end(), _first, 0};
		}

		iterator begin() {
			return iterator{_first.begin(), _first, 0};
		}

		iterator end() {
			return iterator{_first.end(), _first, _first.size()};
		}




    size_t size(){
        return _first.size();
    }





	};








template<typename T, typename OP>

class AccFunc{
	public:
	T _first;
	OP _op;

	AccFunc(const T& first, OP op):_first(first),_op(op){}

	struct iterator{
		decltype(_first.begin()) firstIterator;
	    T _f;
		size_t _index;
		OP _op;
		
		
		auto operator*(){
			//return *firstIterator;
			//decltype(_first.begin()) firstsum;
			auto sum=*_f.begin();
			int index=0;
			for(auto i: _f){
				if(index>_index)
				break;
				if(index>0)
				//sum+=i;
				sum=_op(sum,i);
				index++;
			}
			return sum;
		}

		iterator& operator++(){
			//++firstIterator;
			++_index;
			return *this;
		}

		iterator& operator++(int){
			iterator tmp=*this;
			operator++();
			_index++;
			return tmp;
		}

		bool operator==(const iterator& other){
			return _index==other._index;
		}

		bool operator!=(const iterator& other){
			return !(operator==(other));
		}

	};

		iterator begin() const{
			return iterator{_first.begin(), _first.end(), _first, 0, _op};
		}

		iterator end() const{
			return iterator{_first.end(), _first.end(), _first, 0, _op};
		}

		iterator begin() {
			return iterator{_first.begin(), _first, 0, _op};
		}

		iterator end() {
			return iterator{_first.end(), _first, _first.size(), _op};
		}




    size_t size(){
        return _first.size();
    }





	};








	
namespace itertools{

template <typename S>
Accumulate <S> accumulate(S a){
	Accumulate<S>r(a);
    return r;
}

template<typename S,typename OP>
AccFunc <S,OP> accumulate(S a, OP op){
	AccFunc<S,OP>r(a,op);
	return r;
}



};




/*
 * A template stack class.
 * Implemented as a linked list.
 * 
 * AUTHOR: Ofir Pele
 * SINCE : 2017
 */
#pragma once
#include <iostream>
using namespace std;
template<typename S>
class Range {

    public:

    S _first, _last;

public:

	Range(S a, S b){
        _first=a;
        _last=b;
	}

	~Range() {
		
	}

	
	
public:

	// Avoid copying
	/*
	Range (const Range& rhs);
	Range& operator=(const Range& rhs);
*/
	

	
	
public:	

	//-------------------------------------------------------------------
	// iterator related code:
	// inner class and methods that return instances of it)
	//-------------------------------------------------------------------
	struct iterator {

      int _current;

	public:
/*
		iterator(S c){
            _current=c;
            cout<<"current is "<<_current<<endl;
		}
*/
		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		S operator*() const  {
			//return *pointer_to_current_node;
            //cout<<"int operator*()"<<endl;
			return _current;
		}

		S operator->()  {
            //cout<<"int operator->()"<<endl;
			return _current;
		}

		// ++i;
		iterator& operator++() {
			//++pointer_to_current_node;
            //cout<<"iterator& operator++() "<<endl;
            _current++;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
            //cout<<"onst iterator operator++(int) "<<endl;
            iterator tmp= *this;
            _current++;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
            //cout<<"bool operator==(const iterator& rhs) const"<<endl;
			return _current == rhs._current;
		}

		bool operator!=(const iterator& rhs) const {
            //cout<<"bool operator!=(const iterator& rhs) const"<<endl;
			return _current != rhs._current;
		}
	};  // END OF CLASS ITERATOR



	class const_iterator {

	  S _f;
      S _l;
      S _current;

	public:

		const_iterator(S f, S l){
            _current=f;
            _l=l;
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		const int& operator*() const {
			return _current;
		}

		const int* operator->() const {
			return &_current;
		}

		// ++i;
		const_iterator& operator++() {
            _current++;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const const_iterator operator++(int) {
			const_iterator tmp= *this;
            _current++;
			return tmp;
		}

		bool operator==(const const_iterator& rhs) const {
			return _current == rhs._current;
		}

		bool operator!=(const const_iterator& rhs) const {
			return _current != rhs._current;
		}
	};  // END OF CLASS const_iterator



	iterator begin() {
        //cout<<"iterator begin()"<<endl;
		return iterator{_first};
	}
	
	iterator end() {
        //cout<<"iterator end()"<<endl;
		return iterator{_last};
	}

	const_iterator cbegin() const {
		return const_iterator{_first,_last};
	}
	
	const_iterator cend() const {
		return const_iterator{_first,_last};
	}

	//-------------------------------------------------------------------

/*
	class reverse_iterator {
		...
	};
	reverse_iterator rbegin() {
	};
	reverse_iterator rend() {
	};
*/


	//-------------------------------------------------------------------
	// generic constructor:
	// template constructor inside a template class!
	//-------------------------------------------------------------------
	template<typename IT>
	Range(IT begin, IT end): Range(_first, _last) {
        cout<<"start of Range(IT begin, IT end): Range(_first, _last) "<<endl;
		for (; begin!=end; ++begin) {
			push(*begin);
		}
	}
	//-------------------------------------------------------------------
	

    size_t size(){
        return _last-_first;
    }

}; 


namespace itertools{


Range<int> range(int a, int b){ 
	Range <int>r(a,b);
    return r;
}

};
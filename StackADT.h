#ifndef STACKADT_H
#define STACKADT_H

// @author Derek Avery
// Written for CS 300 -
// Bellevue College - Assignment 3
// Due Nov 4, 2018

template <class T>
class StackADT {
	public:
		virtual void push(const T&)=0;	// push element to the top of Stack
		virtual void pop()=0;		    // remove & return top element of Stack
		virtual bool isEmpty()=0;	    // returns true if there are 0 elements in the Stack
		virtual bool isFull()=0;	    // returns true if Stack cannot handle any more elements
		virtual T top()=0;		        // examines (but does not remove) top element of Stack
};

#endif /*StackADT_H*/

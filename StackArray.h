// @author Derek Avery
// Written for CS 300 -
// Bellevue College - Assignment 3
// Due Nov 4, 2018


#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "StackADT.h"
#include "InvalidOperationException.h"

/*
 * This class is an implementation of the StackADT abstract
 * class, which implements all basic Stack (Last in, first out)
 * functionality. This is a template class which accepts all
 * class types.
 */
template <class T>
class StackArray : public StackADT<T> {
    protected:
        int size;	//< size of T array to hold StackArray elements
        T* data;	//< pointer to the array of T elements
        int count;	//< running count of the number of elements in the StackArray
        int sTop;	//< index of the 'top' element of the StackArray
    
    public:
        /*
         * Default constructor for the StackArray class.
         * This constructor will initialize a new T array
         * of default size 100 (or whatever @param _size
         * is passed) and initialize all other fields to 0
         * to instantiate a new, empty StackArray
         */
        StackArray(int _size=100) { //constructor
            size = _size;
            data = new T[size];
            sTop = -1;
            count = 0;
        }

        /*
         * @returns true if the StackArray is empty (i.e. contains no elements)
         * or false otherwise
         */
        bool isEmpty() {
            return count == 0;
        }

        /*
         * Returns true if the StackArray is full (i.e. cannot
         * handle any additional elements) or false otherwise
         */
        bool isFull() {
            return count == size;
        }

        /*
         * This function returns a copy of the element located at
         * the 'top' of the StackArray, which is by definition the last
         * T object pushed to the StackArray. The top() function does
         * not act destructively; that is, the StackArray is not affected.
         */
        T top() {
            
            // throw exception if there is an attempt to check
            // the 'top' of an empty StackArray
            if(isEmpty())
                throw InvalidOperationException("The stack is empty");
            
            // return the top element
            return data[sTop];
        }

        /*
         * This function removes the top element of the StackArray, which
         * is equivalent to the 'top' of the StackArray. Unlike the top() function,
         * the pop() function will affect the state of the StackArray, and actually
         * remove the top element upon execution. It will not, however,
         * actually return the top element. To both remove and return the top
         * element, a client should execute the top() and pop() operations in sequence.
         */
        void pop() {
            
            // throw an exception if there is an attempt
            // to pop an element from an empty StackArray
            if(isEmpty())
                throw InvalidOperationException("The stack is empty");
            
            // decrement count and top to effectively 'remove' the top
            // element. The element itself will not actually deleted
            sTop--;
            count--;
        }

        /*
         * This function will create a copy of the parameter item and
         * put it on the top of the StackArray, assuming the StackArray is not
         * yet full. The original element will not be affected by this operation.
         */
        void push(const T& item) {
            
            // throw an exception if an attempt is made to
            // push an element onto a full StackArray
            if(isFull())
                throw InvalidOperationException("The stack is full");
            
            // increment top and count, and set the top StackArray
            // element equal to item
            count++;
            sTop++;
            data[sTop] = item;
        }
    /*
     * Returns the number of elements currently in
     * the Stack, including in the case of an empty Stack
     */
    int getCount() {
        return count;
    }
    
    /*
     * Inserts all elements of the stack into the implicit
     * output stream @param os and returns the reference to os
     */
    friend std::ostream& operator<<(std::ostream& os, StackArray<T>& stack) {
        if(stack.isEmpty()) { //edge case; empty stack --> return empty brackets
            os << "<>";
            return os;
        } else {
            //insert first enclosing bracket in @param out
            os << "<";

            // insert comma-separated elements into @param out from top-to-bottom
            for(int i = stack.sTop; i > 0; i--) {
                os << stack.data[i] << ", ";
            }
            // insert bottom element and closing brace in @param out
            os << stack.data[0] << ">";
        }
        return os;
    }
};


#endif /* STACKARRAY_H */

/*
 * Code created by: 
 * Derek Avery
 * for CS 300 - Bellevue College
 * Assignment 3 - Due Nov 4, 2018
 */
#ifndef INVALIDOPERATIONEXCEPTION_H
#define INVALIDOPERATIONEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

/*
 * This exception class represents a logical error during
 * code execution in which an operation of a class is called
 * which does not satisfy pre-conditions of the class member 
 * function, or some other logical principle or function constraint
 * is violated by attempting to execute the function
 * 
 * Example: Attempting to read the first element in a List 
 * which does not contain any elements could throw this exception, 
 * because such an operation cannot logically be performed on an
 * empty list.
 */
class InvalidOperationException : public exception {
	const char* description;	// description of the cause of the exception

    public:
        /*
         * Primary constructor for the InvalidOperationException
         * class, which takes as an argument a string (char[]) which
         * describes the
         */
        InvalidOperationException(const char* _description) {
            description = _description;
        }

        /*
         * Return a copy of the string which explains the error
         * when this exception was thrown
         */
        const char* what() const throw() {
            return description;
        }
}; 


#endif /* INVALIDOPERATIONEXCEPTION_H */

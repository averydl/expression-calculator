#include "StackArray.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <exception>

// @author Derek Avery
// Written for CS 300 -
// Bellevue College - Assignment 3
// Due Nov 4, 2018


// FUNCTIONS //

std::vector<std::string>* getInput();
void processToken(std::string);
bool validDigit(std::string);

// FIELDS //

StackArray<int>* stack = new StackArray<int>(); //< StackArray of user-entered numbers
bool running = true; //< flag to indicate if program should continue execution
int result; //< result of each operation performed on stack elements

std::string insufficientelements =
        "missing operands";  // error message if not enough elements exist for an operation
std::string invalidinput =
        "invalid input";    //error message if input is not defined

int main() {
    while(running) {
        // prompt for and store user input
        std::vector<std::string>* input = getInput();
        int size = input -> size();

        //process each token of user input
        for(int i = 0; i < size; i++) {
            std::string curToken = input -> at(i);  //< current token for processing
            
            //terminate program if user enters '\'
            if(curToken == "\\") {
                running = false;
                break;
            } else {
                // process the current token of input
                processToken(curToken);
            }
        }
    }
    std::cout << "Result: " << result << std::endl;
}

/*
 * This method provides the main functionality of
 * the program, performing appropriate operations
 * for each of the defined operations for the program
 * consists of the operators +, -, *, and / as well as
 * operations to print the stack (using <<), pop/print
 * the top element (using ^), or to terminate the program
 * (using \). If the argument provided is not one of the
 * above supported operations, or an operator is not provided
 * with sufficient operands, an error message is displayed
 */
void processToken(std::string str) {
    // push all numbers to @param stack
    if(validDigit(str)) {
        int curNumber = stoi(str);
        stack->push(curNumber);
        
    } else if(str == "+") { // push result of addition operation of the stack's top two elements
        //  if stack does not have enough operands, display error message
        if(stack -> getCount() < 2) {
            std::cout << insufficientelements << std::endl;
        } else {
            //  if stack has >=2 operands, pop the top two,
            //  perform the operation, and push/store the result
            int operand2 = stack -> top();
            stack -> pop();
            int operand1 = stack -> top();
            stack -> pop();
            result = operand1 + operand2;
            stack -> push(result);
        }
    } else if(str == "-") { // push result of subtraction operation of the stack's top two element
        //  if stack does not have enough operands, display error message
        if(stack -> getCount() < 2) {
            std::cout << insufficientelements << std::endl;
        } else {
            //  if stack has >=2 operands, pop the top two,
            //  perform the operation, and push the result
            int operand2 = stack -> top();
            stack -> pop();
            int operand1 = stack -> top();
            stack -> pop();
            
            result = operand1 - operand2;
            stack -> push(result);
        }
        
    } else if(str == "*") { // push result of multiplication operation of the stack's top two elements
        //  if stack does not have enough operands, display error message
        if(stack -> getCount() < 2) {
            std::cout << insufficientelements << std::endl;
        } else {
            //  if stack has >=2 operands, pop the top two,
            //  perform the operation, and push the result
            int operand2 = stack -> top();
            stack -> pop();
            int operand1 = stack -> top();
            stack -> pop();
            
            result = operand1 * operand2;
            stack -> push(result);
        }
        
    } else if(str == "/") { // push result of division operation of the stack's top two elements
        //  if stack does not have enough operands, display error message
        if(stack -> getCount() < 2) {
            std::cout << insufficientelements << std::endl;
        } else {
            //  if stack has >=2 operands, pop the top two,
            //  perform the operation, and push the result
            int operand2 = stack -> top();
            stack -> pop();
            int operand1 = stack -> top();
            stack -> pop();
            
            try {
                result = operand1 / operand2;
                stack -> push(result);
            } catch (exception e) {
                std::cout << "Expression error: " << e.what() << std::endl;
            }
        }
        
    } else if(str == "<<") { // print the current contents of the stack
        std::cout << *stack << std::endl;
        
    } else if (str == "^") { // pop and print the top element of the stack
        
        // print error if stack does not have an element to pop
        if(stack -> getCount() < 1) {
            std::cout << insufficientelements << std::endl;
        } else {
            int topElement = stack -> top();
            stack -> pop();
            std::cout << topElement << std::endl;
        }
        
    } else {
        std::cout << invalidinput << std::endl;
    }
}


/*
 * When invoked, this function prompts for user input
 * and stores all tokens in a vector, which is then
 * returned
 */
std::vector<std::string>* getInput() {
    std::string input;  //< string to hold user input
    std::string token;  //< string to hold tokens from @param input
    
    std::vector<std::string>* tokens =
        new std::vector<std::string>();     //< vector to hold all tokens from user input

    std::cout << "Enter the expression: ";
    // prompt for and store user input in @param input string
    std::getline(std::cin, input);
    std::istringstream stream(input);  //< input string stream to parse tokens in @param input
    
    // tokenize user input
    while(stream >> token)
        tokens -> push_back(token);
    return tokens;
}

/*
 * This program returns true if a string can be interpreted
 * as a number, or false if it cannot. For example, the string
 * "12345" can be interpreted as a number, but "pac12" can not
 */
bool validDigit(std::string str) {
    // test each character of @param str to
    // see if it is valid as a digit. If any
    // are not, return false
    for(int i = 0; i < str.size(); i++) {
        //remove leading '-' sign if it exists
        if((char)str[0] == '-')
            i++;
        // if char casted to int exceeds 57, it is not a
        // valid digit in ASCII --> return false
        if((int)str[i] > 57 || (int)str[i] < 48)
            return false;
    }
    return true;
}




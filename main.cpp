#include <iostream>
#include "DSAJourney/Stack/ValidParentheses.h"

int main() {    
    std::string input = "({[]})";
    std::cout << "Parentheses are: " << isValidParentheses(input) << std::endl;
    return 0;
}
#include <stack>
#include <string>
using namespace std;

bool isValidParentheses(string input) {
    stack<char> stack;

    for (char c: input) {
        // If opening bracket → Push
        if (c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
        }
        else
        {
            if (stack.empty())
            {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
            {
                return false;
            }
            
        }
        
    }
    return stack.empty();
}
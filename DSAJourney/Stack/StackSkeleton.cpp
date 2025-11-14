/* The celebrity problem
*/
#include <iostream>
#include <vector>
#include <stack>

int celebrity(std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    std::cout << "Matrix size is: " << n << std::endl;
    std::stack<int> myStack;

    for (int i = 0; i < n; i++)
        myStack.push(i);
        
    while (myStack.size() > 1)
    {
        int a = myStack.top();
        std::cout << "top a element is: " << a << std::endl;
        myStack.pop();

        int b = myStack.top();
        std::cout << "top b element is: " << b << std::endl;
        myStack.pop();
        std::cout << "mat[a][b] value is: " << mat[a][b] << std::endl;
        if (mat[a][b])
        {
            myStack.push(b);
        }
        else
        {
            myStack.push(a);
        }            
    }

    // potential candidate of celebrity
    int c = myStack.top();
    std::cout << "top c element is: " << c << std::endl;
    myStack.pop();

    // Check if c is actully a celebrity or not
    for (int i = 0; i < n; i++)
    {
        if (i == c) continue;

        if (mat[c][i] || !mat[i][c])
        {
            return -1;
        }
        
    }
    return c;
}
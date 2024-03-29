/**
 * You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
 * Evaluate the expression. Return an integer that represents the value of the expression.
 *
 * Note that:
 *      The valid operators are '+', '-', '*', and '/'.
 *      Each operand may be an integer or another expression
 *      The division between two integers always truncates toward zero.
 *      There will not be any division by zero.
 *      The input represents a valid arithmetic expression in a reverse polish notation.
 *      The answer and all the intermediate calculations can be represented in a 32-bit integer.
 *
 * Constraints:
 *      1 <= tokens.length <= 10^4
 *      tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>
#include <stack>
#include <cctype>

class Solution
{
public:
    int evalRPN(const std::vector<std::string> &tokens)
    {
        std::stack<int> numbers;

        for (const std::string &token : tokens)
        {
            // Check for number
            if (std::isdigit(token[0]) || token[0] == '-' && token.size() > 1)
            {
                numbers.push(std::stoi(token));
                continue;
            }

            // Get values
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();

            // Perform operations
            switch (token[0])
            {
            case '+':
                numbers.push(a + b);
                break;
            case '-':
                numbers.push(a - b);
                break;
            case '*':
                numbers.push(a * b);
                break;
            case '/':
                numbers.push(a / b);
                break;
            }
        }

        return numbers.top();
    }
};
#endif
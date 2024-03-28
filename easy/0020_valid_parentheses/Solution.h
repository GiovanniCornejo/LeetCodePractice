/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *      Open brackets must be closed by the same type of brackets.
 *      Open brackets must be closed in the correct order.
 *      Every close bracket has a corresponding open bracket of the same type.
 *
 * Constraints:
 *      1 <= s.length <= 10^4
 *      s consists of parentheses only '()[]{}'.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        // Use a stack to keep track of brackets
        std::stack<char> brackets;

        for (const char &c : s)
        {
            switch (c)
            {
            // Open brackets found
            case '(':
            case '[':
            case '{':
                brackets.push(c);
                break;
                // Closing brackets found
            case ')':
                if (brackets.empty() || brackets.top() != '(')
                    return false;
                brackets.pop();
                break;
            case ']':
                if (brackets.empty() || brackets.top() != '[')
                    return false;
                brackets.pop();
                break;
            case '}':
                if (brackets.empty() || brackets.top() != '{')
                    return false;
                brackets.pop();
                break;
            }
        }

        // Invalid if brackets still remain
        return brackets.empty();
    }
};
#endif
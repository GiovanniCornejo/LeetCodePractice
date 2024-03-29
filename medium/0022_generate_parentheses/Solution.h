/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * Constraints:
 *      1 <= n <= 8
 *
 * Example 1:
 *      Input: n = 1
 *      Output: [ () ]
 *
 * Example 2:
 *      Input: n = 2
 *      OUtput: [ (()) , ()() ]
 *
 * Example 3:
 *      Input: n = 3
 *      Output: [ ((())) , (()()) , (())() , ()(()) , ()()() ]
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> results;
        backtrack(results, "", 0, 0, n);
        return results;
    }

private:
    void backtrack(std::vector<std::string> &results, std::string &&combination, int numOpen, int numClose, const int n)
    {
        // Base Case: Combination found
        if (numOpen == n && numClose == n)
        {
            results.push_back(combination);
            return;
        }

        // Add opening parentheses then backtrack
        if (numOpen < n)
            backtrack(results, combination + '(', numOpen + 1, numClose, n);

        // Add closing parentheses then backtrack
        if (numClose < numOpen)
            backtrack(results, combination + ')', numOpen, numClose + 1, n);
    }
};
#endif
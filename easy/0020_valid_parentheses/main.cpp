#include <iostream>
#include <vector>
#include "Solution.h"

struct Test
{
    std::string input;
    bool expected;
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define test cases
    std::vector<Test> tests = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([)]", false},
        {"{[]}", true},
    };

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (const Test &test : tests)
    {
        bool result = solution.isValid(test.input);
        results += (result == test.expected) ? "." : "F";

        std::cout << "Input: " << test.input << std::endl;
        std::cout << "\tExpected: " << (test.expected ? "true" : "false") << std::endl;
        std::cout << "\tResult:   " << (result ? "true" : "false") << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    // Summary
    if (results.find('F') == std::string::npos)
    {
        std::cout << "All tests passed." << std::endl;
    }
    else
    {
        std::cout << results << std::endl;
        std::cout << "Tests failed." << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include "Solution.h"

struct Test
{
    std::vector<std::string> input;
    int expected;
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define test cases
    std::vector<Test> tests = {
        {{"2", "1", "+", "3", "*"}, 9},
        {{"4", "13", "5", "/", "+"}, 6},
        {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (const Test &test : tests)
    {
        int result = solution.evalRPN(test.input);
        results += (result == test.expected) ? "." : "F";

        std::cout << "Input: [" << '"' << test.input[0] << '"';
        for (int i = 1; i < test.input.size(); ++i)
            std::cout << ", \"" << test.input[i] << '"';
        std::cout << "]\n";

        std::cout << "\tExpected: " << test.expected << std::endl;
        std::cout << "\tResult:   " << result << std::endl;
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
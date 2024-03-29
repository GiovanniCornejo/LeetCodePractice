#include <iostream>
#include <vector>
#include "Solution.h"

struct Test
{
    std::vector<int> input;
    int expected;
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define test cases
    std::vector<Test> tests = {
        {{1, 1, 0, 1, 1, 1}, 3},
        {{1, 0, 1, 1, 0, 1}, 2}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (Test &test : tests)
    {
        int result = solution.findMaxConsecutiveOnes(test.input);
        results += (result == test.expected) ? "." : "F";

        std::cout << "Input: [" << test.input[0];
        for (int i = 0; i < test.input.size(); ++i)
            std::cout << ", " << test.input[i];
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
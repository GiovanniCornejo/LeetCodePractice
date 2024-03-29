#include <iostream>
#include <vector>
#include "Solution.h"

struct Test
{
    std::vector<int> input;
    std::vector<int> expected;
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define test cases
    std::vector<Test> tests = {
        {{-4, -1, 0, 3, 10}, {0, 1, 9, 16, 100}},
        {{-7, -3, 2, 3, 11}, {4, 9, 9, 49, 121}}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (Test &test : tests)
    {
        std::vector<int> result = solution.sortedSquares(test.input);
        bool passed = true; // Flag to track if the test case passed or failed
        if (test.expected.size() != result.size())
            passed = false;
        else
        {
            for (int i = 0; i < test.expected.size(); ++i)
            {
                if (result[i] != test.expected[i])
                {
                    passed = false;
                    break;
                }
            }
        }
        results += (passed) ? "." : "F";

        std::cout << "Input: [" << test.input[0];
        for (int i = 1; i < test.expected.size(); ++i)
            std::cout << ", " << test.expected[i];
        std::cout << "]\n";
        std::cout << "\tExpected: [" << test.expected[0];
        for (int i = 1; i < test.expected.size(); ++i)
            std::cout << ", " << test.expected[i];
        std::cout << "]\n";
        std::cout << "\tResult:   [" << result[0];
        for (int i = 1; i < result.size(); ++i)
            std::cout << ", " << result[i];
        std::cout << "]\n";
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
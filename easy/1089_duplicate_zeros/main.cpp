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
        {{1, 0, 2, 3, 0, 4, 5, 0}, {1, 0, 0, 2, 3, 0, 0, 4}},
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 3, 4, 0, 1, 0, 2, 3, 4}, {1, 2, 3, 4, 0, 0, 1, 0, 0, 2}}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (Test &test : tests)
    {
        std::cout << "Input: [" << test.input[0];
        for (int i = 1; i < test.expected.size(); ++i)
            std::cout << ", " << test.input[i];
        std::cout << "]\n";

        solution.duplicateZeros(test.input);
        bool passed = true; // Flag to track if the test case passed or failed
        if (test.input.size() != test.expected.size())
            passed = false;
        else
        {
            for (int i = 0; i < test.input.size(); ++i)
            {
                if (test.input[i] != test.expected[i])
                {
                    passed = false;
                    break;
                }
            }
        }
        results += (passed) ? "." : "F";

        std::cout << "\tExpected: [" << test.expected[0];
        for (int i = 1; i < test.expected.size(); ++i)
            std::cout << ", " << test.expected[i];
        std::cout << "]\n";
        std::cout << "\tResult:   [" << test.input[0];
        for (int i = 1; i < test.input.size(); ++i)
            std::cout << ", " << test.input[i];
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
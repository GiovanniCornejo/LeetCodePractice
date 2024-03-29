#include <iostream>
#include <vector>
#include <string>
#include "MinStack.h"

struct Test
{
    std::vector<std::string> operations;
    std::vector<std::vector<int>> values;
    std::vector<int> expected;
};
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [ [], [-2], [0], [-3], [], [], [], [] ]
// [null,null,null,null,-3,null,0,-2]

int main()
{
    // Create an instance of the Solution class
    MinStack minstack;

    // Define test cases
    std::vector<Test> tests = {
        // Test 1
        {
            {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"},
            {{}, {-2}, {0}, {-3}, {}, {}, {}, {}},
            {0, 0, 0, 0, -3, 0, 0, -2}},
        // Test 2
        {
            {"MinStack", "push", "push", "push", "getMin", "pop", "getMin"},
            {{}, {0}, {1}, {0}, {}, {}, {}, {}},
            {0, 0, 0, 0, 0, 0, 0, 0}},
        // Test 3
        {
            {"MinStack", "push", "push", "push", "pop", "getMin", "pop", "getMin"},
            {{}, {3}, {2}, {1}, {}, {}, {}, {}},
            {0, 0, 0, 0, 0, 2, 0, 3}}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (const Test &test : tests)
    {
        MinStack minStack;
        bool passed = true; // Flag to track if the test case passed or failed

        for (size_t i = 0; i < test.operations.size(); ++i)
        {
            std::cout << "Input: ";
            const std::string &operation = test.operations[i];
            const std::vector<int> &values = test.values[i];

            if (operation == "MinStack")
            {
                std::cout << operation << "()";
                minStack = MinStack(); // Initialize MinStack for the test case
            }
            else if (operation == "push")
            {
                std::cout << "push(" << values[0] << ")";
                minStack.push(values[0]);
            }
            else if (operation == "pop")
            {
                std::cout << "pop()";
                minStack.pop();
            }
            else if (operation == "top")
            {
                std::cout << "top()";
                int result = minStack.top();
                if (result != test.expected[i])
                {
                    passed = false;
                }
                std::cout << "\n\tExpected: " << test.expected[i] << "\n\tResult:   " << result;
            }
            else if (operation == "getMin")
            {
                std::cout << "getMin()";
                int result = minStack.getMin();
                if (result != test.expected[i])
                {
                    passed = false;
                }
                std::cout << "\n\tExpected: " << test.expected[i] << "\n\tResult:   " << result;
            }

            if (i < test.operations.size() - 1)
            {
                std::cout << "," << std::endl;
            }
        }

        if (passed)
        {
            results += ".";
        }
        else
        {
            results += "F";
        }

        std::cout << std::endl;
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
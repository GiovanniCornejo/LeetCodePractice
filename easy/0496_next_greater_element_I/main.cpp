#include <iostream>
#include <vector>
#include "Solution.h"

struct Test
{
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> expected;
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define test cases
    std::vector<Test> tests = {
        {{4, 1, 2}, {1, 3, 4, 2}, {-1, 3, -1}},
        {{2, 4}, {1, 2, 3, 4}, {3, -1}}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (Test &test : tests)
    {
        std::vector<int> result = solution.nextGreaterElement(test.nums1, test.nums2);
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

        std::cout << "Input:" << std::endl;
        std::cout << "nums1: [" << test.nums1[0];
        for (int i = 0; i < test.nums1.size(); ++i)
            std::cout << ", " << test.nums1[i];
        std::cout << "]\n";
        std::cout << "nums2: [" << test.nums2[0];
        for (int i = 0; i < test.nums2.size(); ++i)
            std::cout << ", " << test.nums2[i];
        std::cout << "]\n";

        std::cout << "\tExpected: [" << test.expected[0];
        for (int i = 0; i < test.expected.size(); ++i)
            std::cout << ", " << test.expected[i];
        std::cout << "]\n";
        std::cout << "\tResult:   [" << result[0];
        for (int i = 0; i < result.size(); ++i)
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
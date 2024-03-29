#include <iostream>
#include <vector>
#include "Solution.h"

struct Test
{
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    std::vector<int> expected;
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define test cases
    std::vector<Test> tests = {
        {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
        {{1}, 1, {}, 0, {1}},
        {{0}, 0, {1}, 1, {1}}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (Test &test : tests)
    {
        std::cout << "Input:" << std::endl;

        std::cout << "nums1: [" << test.nums1[0];
        for (int i = 1; i < test.nums1.size(); ++i)
            std::cout << ", " << test.nums1[i];
        std::cout << "]\n";
        std::cout << "m: " << test.m << std::endl;

        if (test.nums2.size() > 0)
            std::cout << "nums2: [" << test.nums2[0];
        else
            std::cout << "nums2: [";
        for (int i = 1; i < test.nums2.size(); ++i)
            std::cout << ", " << test.nums2[i];
        std::cout << "]\n";
        std::cout << "n: " << test.n << std::endl;

        solution.merge(test.nums1, test.m, test.nums2, test.n);
        bool passed = true; // Flag to track if the test case passed or failed
        if (test.nums1.size() != test.expected.size())
            passed = false;
        else
        {
            for (int i = 0; i < test.nums1.size(); ++i)
            {
                if (test.nums1[i] != test.expected[i])
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
        std::cout << "\tResult:   [" << test.nums1[0];
        for (int i = 1; i < test.nums1.size(); ++i)
            std::cout << ", " << test.nums1[i];
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
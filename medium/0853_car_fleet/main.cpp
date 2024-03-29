#include <iostream>
#include <vector>
#include "Solution.h"

struct Test
{
    int target;

    std::vector<int> position;
    std::vector<int> speed;
    int expected;
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define test cases
    std::vector<Test> tests = {
        {12, {10, 8, 0, 5, 3}, {2, 4, 1, 1, 3}, 3},
        {10, {3}, {3}, 1},
        {100, {0, 2, 4}, {4, 2, 1}, 1},
        {10, {0, 4, 2}, {2, 1, 3}, 1}};

    // Check if solution passed
    std::string results;

    // Loop over test cases
    for (Test &test : tests)
    {
        int result = solution.carFleet(test.target, test.position, test.speed);
        results += (result == test.expected) ? "." : "F";

        std::cout << "Input:" << std::endl;
        std::cout << "Target:    " << test.target << std::endl;
        std::cout << "Positions: " << test.position[0];
        for (int i = 1; i < test.position.size(); ++i)
            std::cout << ", " << test.position[i];
        std::cout << "]\n";
        std::cout << "Speed:     " << test.speed[0];
        for (int i = 1; i < test.speed.size(); ++i)
            std::cout << ", " << test.speed[i];
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
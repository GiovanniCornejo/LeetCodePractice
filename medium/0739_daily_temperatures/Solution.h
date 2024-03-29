/**
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the ith day to get a warmer temperature.
 * If there is no future day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Constraints:
 *      1 <= temperatures.length <= 10^5
 *      30 <= temperatures[i] <= 100
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> dailyTemperatures(const std::vector<int> &temperatures)
    {
        // Initialize number of days to 0
        // All temps that do not see a larger temperature are automatically 0
        std::vector<int> days(temperatures.size(), 0);

        std::stack<int> s;

        for (int i = 0; i < days.size(); ++i)
        {
            // All smaller temperatures have the current temp as their highest
            // and can be added to the output and popped off the stack
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                // Number of days is difference in indices
                days[s.top()] = i - s.top();
                s.pop();
            }

            s.push(i);
        }

        return days;
    }
};
#endif
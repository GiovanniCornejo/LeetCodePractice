/**
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
 * return the area of the largest rectangle in the histogram.
 *
 * Constraints:
 *      1 <= heights.length <= 10^5
        0 <= heights[i] <= 10^4
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <stack>
#include <utility>

class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        int maxArea = 0;

        // Keep track of index to calculate widths
        // and heights for stack popping
        std::stack<std::pair<int, int>> pairs;

        for (int i = 0; i < heights.size(); ++i)
        {
            int startIndex = i;

            // Pop elements until a smaller height is found
            while (!pairs.empty() && pairs.top().second > heights[i])
            {
                // Get current largest height
                int currHeight = pairs.top().second;

                // Calculate the width which is the difference between the current index
                // and the largest height's index
                int width = i - pairs.top().first;

                maxArea = std::max(maxArea, width * currHeight);

                // Update start index to a further back index
                startIndex = pairs.top().first;
                pairs.pop();
            }

            pairs.push(std::pair<int, int>{startIndex, heights[i]});
        }

        // Calculate remaining areas (areas extended to end of histogram)
        while (!pairs.empty())
        {
            int currHeight = pairs.top().second;
            int width = heights.size() - pairs.top().first;

            maxArea = std::max(maxArea, width * currHeight);
            pairs.pop();
        }

        return maxArea;
    }
};
#endif
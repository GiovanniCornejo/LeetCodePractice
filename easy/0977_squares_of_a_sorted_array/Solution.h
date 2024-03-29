/**
 * Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 *
 * Constraints:
 *      1 <= nums.length <= 10^4
 *      -10^4 <= nums[i] <= 10^4
 *      nums is sorted in non-decreasing order.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        std::vector<int> sorted(nums.size());

        // Keep track of values on left and right of pivot (0)
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;

        // Iterate in reverse order (largest squares get added first)
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            // Compare absolute values
            int absRight = abs(nums[rightIndex]);
            int absLeft = abs(nums[leftIndex]);

            // Add from right
            if (absRight > absLeft)
            {
                sorted[i] = absRight * absRight;
                --rightIndex;
            }
            // Add from left
            else
            {
                sorted[i] = absLeft * absLeft;
                ++leftIndex;
            }
        }

        return sorted;
    }
};
#endif
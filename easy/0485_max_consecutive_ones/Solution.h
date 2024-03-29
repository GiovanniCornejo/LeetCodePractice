/**
 * Given a binary array nums, return the maximum number of consecutive 1's in the array.
 *
 * Constraints:
 *      1 <= nums.length <= 10^5
 *      nums[i] is either 0 or 1.
 */

#include <vector>

#ifndef SOLUTION_H
#define SOLUTION_H

class Solution
{
public:
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int maxConsecutive = 0;
        int count = 0; // Keep track of current consecutive amount
        for (int num : nums)
        {
            // Reset count and check max when 0 is found
            if (num == 0)
            {
                maxConsecutive = std::max(maxConsecutive, count);
                count = 0;
            }
            else
            {
                ++count;
            }
        }

        return std::max(maxConsecutive, count);
    }
};
#endif
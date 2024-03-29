/**
 * Given an array nums of integers, return how many of them contain an even number of digits.
 *
 * Constraints:
 * 1 <= nums.length <= 500
 * 1 <= nums[i] <= 10^5
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution
{
public:
    int findNumbers(std::vector<int> &nums)
    {
        int numEven = 0;
        for (int num : nums)
        {
            // Count number of digits (no need to check if num is already 0)
            int numDigits = 0;
            while (num != 0)
            {
                num /= 10;
                numDigits++;
            }

            // Number is even if numDigits is divisible by 2
            if (numDigits % 2 == 0)
                ++numEven;
        }

        return numEven;
    }
};
#endif
/**
 * Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place and do not return anything.
 *
 * Constraints:
 *      1 <= arr.length <= 104
 *      0 <= arr[i] <= 9
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution
{
public:
    void duplicateZeros(std::vector<int> &arr)
    {
        // Count the number of zeros
        int numZeros = 0;
        for (int num : arr)
        {
            if (num == 0)
                ++numZeros;
        }

        // Move elements over by numZero (number of zeros inserted before the element)
        for (int i = arr.size() - 1; i >= 0 && numZeros != 0; --i)
        {
            // If zero found, duplicate it
            if (arr[i] == 0)
            {
                // If room to duplicate zero
                if (i + numZeros < arr.size())
                    arr[i + numZeros] = 0;
                numZeros--;
            }

            // Shift all elements by numZeros spaces
            if (i + numZeros < arr.size())
            {
                arr[i + numZeros] = arr[i];
            }
        }
    }
};
#endif
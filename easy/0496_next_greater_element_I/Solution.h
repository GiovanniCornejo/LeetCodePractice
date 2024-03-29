/**
 * The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
 *
 * You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
 * For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
 * If there is no next greater element, then the answer for this query is -1.
 * Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
 *
 * Constraints:
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * All integers in nums1 and nums2 are unique.
 * All the integers of nums1 also appear in nums2.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <stack>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> ans(nums1.size(), -1);

        // Keep nums1 values in a hashmap with key as value to store indices
        std::unordered_map<int, int> nums1Mapping;
        for (int i = 0; i < nums1.size(); ++i)
            nums1Mapping[nums1[i]] = i;

        // Use monotonically decreasing stack
        std::stack<int> nextGreater;

        // Calculate next greater elements in nums2
        for (int i = 0; i < nums2.size(); ++i)
        {
            // Pop elements until a smaller value is found
            while (!nextGreater.empty() && nums2[i] > nextGreater.top())
            {
                int idx = nums1Mapping[nextGreater.top()];
                ans[idx] = nums2[i];
                nextGreater.pop();
            }

            // Only add values found in nums1 to the stack
            if (nums1Mapping.count(nums2[i]) > 0)
                nextGreater.push(nums2[i]);
        }

        return ans;
    }
};
#endif
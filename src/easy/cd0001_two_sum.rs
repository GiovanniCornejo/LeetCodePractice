use super::Solution;

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut diffs = HashMap::with_capacity(nums.len());

        for (i, num) in nums.iter().enumerate() {
            match diffs.get(num) {
                Some(diff) => return vec![*diff, i as i32],
                None => diffs.insert(target - num, i as i32),
            };
        }

        vec![]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_two_sum() {
        // Example 1:
        let nums = vec![2, 7, 11, 15];
        let target = 9;
        let output = vec![0, 1];
        assert_eq!(Solution::two_sum(nums, target), output);

        // Example 2:
        let nums = vec![3, 2, 4];
        let target = 6;
        let output = vec![1, 2];
        assert_eq!(Solution::two_sum(nums, target), output);

        // Example 3:
        let nums = vec![3, 3];
        let target = 6;
        let output = vec![0, 1];
        assert_eq!(Solution::two_sum(nums, target), output);
    }
}

use super::Solution;

use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        // Convert to set
        let mut sequences = HashSet::new();
        for &num in &nums {
            sequences.insert(num);
        }

        let mut longest = 0;
        for &num in &nums {
            // Skip if current number is not the start of a sequence
            if sequences.contains(&(num - 1)) {
                continue;
            }

            // Get length of sequence
            let mut length = 1;
            while sequences.contains(&(num + length)) {
                length += 1;
            }

            // Update longest sequence
            longest = longest.max(length);
        }

        longest
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_longest_consecutive() {
        let nums = vec![100, 4, 200, 1, 3, 2];
        assert_eq!(Solution::longest_consecutive(nums), 4);

        let nums = vec![0, 3, 7, 2, 5, 8, 4, 6, 0, 1];
        assert_eq!(Solution::longest_consecutive(nums), 9);
    }
}

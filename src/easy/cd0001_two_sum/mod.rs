pub struct Solution;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let nums = vec![];

        return nums;
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

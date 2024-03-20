use super::Solution;
impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut products = vec![1; nums.len()];
        let mut pre = 1;
        let mut post = 1;

        // Calculate prefix and postfix simultaneously
        for i in 0..nums.len() {
            let j = nums.len() - i - 1;
            products[i] *= pre;
            products[j] *= post;
            pre *= nums[i];
            post *= nums[j];
        }

        products
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_product_except_self() {
        let nums = vec![1, 2, 3, 4];
        let output = vec![24, 12, 8, 6];
        assert_eq!(Solution::product_except_self(nums), output);

        let nums = vec![-1, 1, 0, -3, 3];
        let output = vec![0, 0, 9, 0, 0];
        assert_eq!(Solution::product_except_self(nums), output);
    }
}

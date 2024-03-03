use super::Solution;
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut area = 0;
        let mut left = 0;
        let mut right = height.len() - 1;

        while left < right {
            // Calculate area with minimum of pointer heights
            let curr = height[left].min(height[right]) * (right - left) as i32;
            area = area.max(curr);

            // Move smaller height pointer
            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }

        area
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    pub fn test_max_area() {
        let height = vec![1, 8, 6, 2, 5, 4, 8, 3, 7];
        assert_eq!(Solution::max_area(height), 49);

        let height = vec![1, 1];
        assert_eq!(Solution::max_area(height), 1);
    }
}

use super::Solution;

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        // Calculate number of digits
        let mut digits = 0;
        let mut x = x;
        let mut y = x;
        while y != 0 {
            y /= 10;
            digits += 1;
        }

        // Check first half with second half
        for i in 0..digits / 2 {
            let left = (x / (10 as i32).pow(digits - i - 1)) % 10;
            let right = x % 10;
            if left != right {
                return false;
            }
            x /= 10;
            digits -= 1;
        }

        true
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    pub fn test_is_palindrome() {
        assert_eq!(Solution::is_palindrome(0), true);
        assert_eq!(Solution::is_palindrome(121), true);
        assert_eq!(Solution::is_palindrome(-121), false);
        assert_eq!(Solution::is_palindrome(10), false);
        assert_eq!(Solution::is_palindrome(1221), true);
        assert_eq!(Solution::is_palindrome(123456), false);
        assert_eq!(Solution::is_palindrome(12344321), true);
        assert_eq!(Solution::is_palindrome(1234321), true);
    }
}

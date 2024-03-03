use super::Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let negative = x < 0;
        let Some(mut x) = x.checked_abs() else {
            return 0;
        };
        let mut reverse: i32 = 0;

        while x >= 10 {
            let digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }

        if let Some(v) = reverse.checked_mul(10).and_then(|r| r.checked_add(x % 10)) {
            reverse = v;
        } else {
            return 0;
        }

        if negative {
            if let Some(v) = reverse.checked_mul(-1) {
                v
            } else {
                0
            }
        } else {
            reverse
        }
    }
}

#[cfg(test)]

mod tests {
    use super::*;

    #[test]
    pub fn test_reverse() {
        assert_eq!(Solution::reverse(123), 321);
        assert_eq!(Solution::reverse(-123), -321);
        assert_eq!(Solution::reverse(120), 21);
        assert_eq!(Solution::reverse(2147483642), 0);
        assert_eq!(Solution::reverse(-2147483648), 0);
    }
}

use super::Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let chars = s.as_bytes();
        let mut i = 0;

        // 1. Read in and ignore leading whitespace
        while i < chars.len() && chars[i] == b' ' {
            i += 1;
        }
        if i == chars.len() {
            return 0;
        }

        // 2. Check if the next character is '-' or '+'
        let mut negative = false;
        if chars[i] == b'-' {
            negative = true;
            i += 1;
        } else if chars[i] == b'+' {
            i += 1;
        }

        // 3. Read in characters until non-digit character or end of the input is reached
        let mut result: i64 = 0;
        while i < chars.len() && chars[i].is_ascii_digit() && result < core::i32::MAX as i64 {
            result = result * 10 + chars[i] as i64 - 0x30;
            i += 1;
        }

        // 4. Change the sign as necessary
        if negative {
            result = -result;
        }

        // 5. If the integer is out of 32-bit signed range, clamp to range
        result.clamp(core::i32::MIN as i64, core::i32::MAX as i64) as i32
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    pub fn test_my_atoi() {
        assert_eq!(Solution::my_atoi("42".to_string()), 42);
        assert_eq!(Solution::my_atoi("         -42".to_string()), -42);
        assert_eq!(Solution::my_atoi("4193 with words".to_string()), 4193);
        assert_eq!(
            Solution::my_atoi("9223372036854775808".to_string()),
            core::i32::MAX
        );
        assert_eq!(
            Solution::my_atoi("     -9223372036854775808 wow".to_string()),
            core::i32::MIN
        );
    }
}

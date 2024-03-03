use super::Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut num = 0;
        let mut prev = 0;

        for c in s.chars() {
            let value = match c {
                'I' => 1,
                'V' => 5,
                'X' => 10,
                'L' => 50,
                'C' => 100,
                'D' => 500,
                'M' => 1000,
                _ => return -1,
            };

            // Check for incorrect additions (e.g. IV, XL)
            if value > prev {
                num += value - 2 * prev;
            } else {
                num += value;
            }

            prev = value;
        }

        num
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    pub fn test_roman_to_int() {
        assert_eq!(Solution::roman_to_int("III".to_string()), 3);
        assert_eq!(Solution::roman_to_int("LVIII".to_string()), 58);
        assert_eq!(Solution::roman_to_int("MCMXCIV".to_string()), 1994);
    }
}

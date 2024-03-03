use super::Solution;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;
        let conversions = vec![
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ];
        let mut roman = String::new();

        for convert in conversions {
            while convert.0 <= num {
                roman += convert.1;
                num -= convert.0;
            }
        }

        roman
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    pub fn test_int_to_roman() {
        assert_eq!(Solution::int_to_roman(3), "III");
        assert_eq!(Solution::int_to_roman(58), "LVIII");
        assert_eq!(Solution::int_to_roman(1994), "MCMXCIV");
    }
}

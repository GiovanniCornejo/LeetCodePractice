use super::Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if s.len() as i32 <= num_rows || num_rows == 1 {
            return s;
        }

        let mut result = String::with_capacity(s.len());
        let chars = s.as_bytes();
        let length = chars.len() as i32;
        let jump = (num_rows - 1) * 2;

        for i in 0..num_rows {
            let mut j = i;
            while j < length {
                result.push(chars[j as usize] as char);
                j += jump;
                if i > 0 && i < num_rows - 1 && j - (2 * i) < length {
                    result.push(chars[(j - (2 * i)) as usize] as char);
                }
            }
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_convert() {
        let s = String::from("A");
        let num_rows = 1;
        assert_eq!(Solution::convert(s.clone(), num_rows), "A");

        let s = String::from("PAYPALISHIRING");
        let num_rows = 2;
        assert_eq!(Solution::convert(s.clone(), num_rows), "PYAIHRNAPLSIIG");

        let num_rows = 3;
        assert_eq!(Solution::convert(s.clone(), num_rows), "PAHNAPLSIIGYIR");

        let num_rows = 4;
        assert_eq!(Solution::convert(s, num_rows), "PINALSIGYAHRPI");
    }
}

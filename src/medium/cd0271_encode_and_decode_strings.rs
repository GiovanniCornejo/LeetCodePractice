use super::Solution;
impl Solution {
    fn encode(strs: Vec<String>) -> String {
        let mut encoder = String::new();

        // Use length of each string in encoding
        for s in &strs {
            encoder.push_str(&s.len().to_string());
            encoder.push(':'); // Delimiter to separate length
            encoder.push_str(s);
        }

        encoder
    }

    fn decode(str: String) -> Vec<String> {
        let mut decoder = vec![];
        let mut start = 0;

        while let Some(delimiter) = str[start..].find(':') {
            // Extract length of string
            let delimiter_index = start + delimiter;
            let length = str[start..delimiter_index].parse::<usize>().unwrap();

            // Extract string
            let string_start = delimiter_index + 1;
            let string_end = string_start + length;
            let s = str[string_start..string_end].to_owned();
            decoder.push(s);
            start = string_end;
        }

        decoder
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_encode_and_decode() {
        let strs = vec![
            "leet".to_string(),
            "code".to_string(),
            "love".to_string(),
            "you".to_string(),
        ];
        let encode = Solution::encode(strs.clone());
        assert_eq!(Solution::decode(encode), strs);

        let strs = vec![
            "we".to_string(),
            "say".to_string(),
            ":".to_string(),
            "yes".to_string(),
        ];
        let encode = Solution::encode(strs.clone());
        assert_eq!(Solution::decode(encode), strs);
    }
}

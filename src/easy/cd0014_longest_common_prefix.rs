use super::Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut prefix = String::new();

        'outer: for i in 0..strs[0].len() {
            let curr = strs[0].get(i..i + 1).expect("Checked length already");
            for s in &strs {
                match s.get(i..i + 1) {
                    Some(c) if c == curr => continue,
                    _ => break 'outer,
                }
            }
            prefix += curr;
        }

        prefix
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    pub fn test_longest_common_prefix() {
        let strs = vec![
            String::from("flower"),
            String::from("flow"),
            String::from("flight"),
        ];
        assert_eq!(Solution::longest_common_prefix(strs), String::from("fl"));

        let strs = vec![
            String::from("dog"),
            String::from("racecar"),
            String::from("car"),
        ];
        assert_eq!(Solution::longest_common_prefix(strs), String::from(""));

        let strs = vec![
            String::from(""),
            String::from("racecar"),
            String::from("car"),
        ];
        assert_eq!(Solution::longest_common_prefix(strs), String::from(""));
    }
}

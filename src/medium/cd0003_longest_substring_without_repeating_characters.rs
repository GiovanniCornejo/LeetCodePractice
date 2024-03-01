use std::collections::HashMap;

use super::Solution;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut head = 0;
        let mut tail = 0;
        let mut longest = 0;
        let mut repeats = HashMap::new();

        for (i, c) in s.chars().enumerate() {
            if let Some(&pos) = repeats.get(&c) {
                longest = longest.max(tail - head);
                head = head.max(pos + 1);
            }

            repeats.insert(c, i);
            tail += 1;
        }

        longest.max(tail - head) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_length_of_longest_substring() {
        let s = String::from("abcabcbb");
        assert_eq!(Solution::length_of_longest_substring(s), 3);

        let s = String::from("bbbbb");
        assert_eq!(Solution::length_of_longest_substring(s), 1);

        let s = String::from("pwwkew");
        assert_eq!(Solution::length_of_longest_substring(s), 3);
    }
}

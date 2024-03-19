use super::Solution;

use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut set = HashMap::new();

        // Rust handles Unicode characters ('char' type is a Unicode Scalar Value)
        for c in s.chars() {
            set.entry(c).and_modify(|count| *count += 1).or_insert(1);
        }

        for c in t.chars() {
            match set.get_mut(&c) {
                Some(count) => {
                    *count -= 1;
                    if *count < 0 {
                        return false;
                    }
                }
                None => return false,
            }
        }

        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_is_anagram() {
        let s = String::from("anagram");
        let t = String::from("nagaram");
        assert_eq!(Solution::is_anagram(s, t), true);

        let s = String::from("rat");
        let t = String::from("car");
        assert_eq!(Solution::is_anagram(s, t), false);
    }
}

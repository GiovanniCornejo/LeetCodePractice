use super::Solution;

use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        // Use frequency array as keys and values as vector of matching strings
        let mut groups = HashMap::new();

        for s in strs {
            // Calculate frequency of characters
            let mut frequency = [0u8; 26];
            for c in s.bytes() {
                frequency[(c - b'a') as usize] += 1;
            }

            // Add frequency to map and push current string
            groups.entry(frequency).or_insert(Vec::new()).push(s);
        }

        groups.into_values().collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_group_anagrams() {
        let strs = vec![
            "eat".to_string(),
            "tea".to_string(),
            "tan".to_string(),
            "ate".to_string(),
            "nat".to_string(),
            "bat".to_string(),
        ];
        let output = vec![
            vec!["ate".to_string(), "eat".to_string(), "tea".to_string()],
            vec!["bat".to_string()],
            vec!["nat".to_string(), "tan".to_string()],
        ];

        // Sort entire vector to prevent random comparisons and match output
        let mut result = Solution::group_anagrams(strs);
        result.iter_mut().for_each(|group| group.sort());
        result.sort();
        assert_eq!(result, output);

        let strs = vec!["".to_string()];
        let output = vec![vec!["".to_string()]];
        assert_eq!(Solution::group_anagrams(strs), output);

        let strs = vec!["a".to_string()];
        let output = vec![vec!["a".to_string()]];
        assert_eq!(Solution::group_anagrams(strs), output);
    }
}

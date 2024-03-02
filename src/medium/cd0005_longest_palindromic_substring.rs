use super::Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        // Helper function to find the longest palindrome centered at the given left and right indices
        fn longest_substring(s: &[u8], mut left: isize, mut right: isize) -> &[u8] {
            while left >= 0 && right < s.len() as isize && s[left as usize] == s[right as usize] {
                left -= 1;
                right += 1;
            }

            &s[(left + 1) as usize..right as usize]
        }

        let chars = s.as_bytes();
        let mut longest: &[u8] = &[0];
        let mut max_length = 0;

        for i in 0..s.len() {
            let odd_palindrome = longest_substring(chars, i as isize, i as isize);
            let even_palindrome = longest_substring(chars, i as isize, (i + 1) as isize);

            if odd_palindrome.len() > max_length {
                longest = odd_palindrome;
                max_length = odd_palindrome.len()
            }
            if even_palindrome.len() > max_length {
                longest = even_palindrome;
                max_length = even_palindrome.len()
            }
        }

        std::str::from_utf8(longest).unwrap().to_string()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_longest_palindrome() {
        let s = String::from("babad"); // "aba" is also a valid answer
        assert_eq!(Solution::longest_palindrome(s), "bab".to_string());

        let s = String::from("cbbd");
        assert_eq!(Solution::longest_palindrome(s), "bb".to_string());

        let s = String::from("abacdfgdcaba");
        assert_eq!(Solution::longest_palindrome(s), "aba".to_string());

        let s = String::from("xyz");
        assert_eq!(Solution::longest_palindrome(s), "x".to_string());

        let s = String::from("eabcb");
        assert_eq!(Solution::longest_palindrome(s), "bcb".to_string());

        let s = std::iter::repeat('a').take(1000).collect::<String>();
        assert_eq!(Solution::longest_palindrome(s.clone()), s);
    }
}

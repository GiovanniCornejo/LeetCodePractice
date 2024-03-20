use super::Solution;

use std::collections::{BinaryHeap, HashMap};

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        // Use number as key and frequency as value
        let mut frequencies = HashMap::new();
        for num in nums {
            *frequencies.entry(num).or_insert(0) += 1;
        }

        // Sort frequency of each number via a max-heap
        let mut freq_heap = BinaryHeap::new();
        for (num, freq) in frequencies {
            freq_heap.push((freq, num));
        }

        // Extract top k elements from the heap
        let mut top_k = Vec::new();
        for _ in 0..k {
            match freq_heap.pop() {
                Some((_, num)) => top_k.push(num),
                None => break,
            }
        }

        top_k
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_top_k_frequent() {
        let mut result = Solution::top_k_frequent(vec![1, 1, 1, 2, 2, 3], 2);
        result.sort();
        assert_eq!(result, vec![1, 2]);
        assert_eq!(Solution::top_k_frequent(vec![1], 1), vec![1]);
    }
}

use std::i32::{MAX, MIN};

use super::Solution;
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        // Perform binary search on smaller array
        let (nums1, nums2) = if nums2.len() > nums1.len() {
            (nums1, nums2)
        } else {
            (nums2, nums1)
        };

        let total = nums1.len() + nums2.len();
        let mid_index = total / 2;
        let even = total % 2 == 0;

        let (mut lo, mut hi) = (0, nums1.len());
        loop {
            // Calculate middle position of both arrays
            let mid1 = (lo + hi) / 2;
            let mid2 = mid_index - mid1;

            // Get end of left partition and beginning of right partition for each
            // treat out of bounds as min and max values
            let nums1_left = if mid1 > 0 { nums1[mid1 - 1] } else { MIN };
            let nums1_right = if mid1 < nums1.len() { nums1[mid1] } else { MAX };
            let nums2_left = if mid2 > 0 { nums2[mid2 - 1] } else { MIN };
            let nums2_right = if mid2 < nums2.len() { nums2[mid2] } else { MAX };

            // Check for correct partitions in both arrays
            if nums1_left <= nums2_right && nums2_left <= nums1_right {
                if even {
                    return (nums1_left.max(nums2_left) + nums1_right.min(nums2_right)) as f64
                        / 2.0;
                }
                return nums1_right.min(nums2_right) as f64;
            }

            // Compare partitions to determine direction of correction
            if nums1_left > nums2_right {
                hi = mid1 - 1;
            } else {
                lo = mid1 + 1;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_find_median_sorted_arrays() {
        // let nums1 = vec![1, 3];
        // let nums2 = vec![2];
        // assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 2.00000);

        let nums1 = vec![1, 2];
        let nums2 = vec![3, 4];
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 2.50000);

        let nums1 = vec![0, 0, 0, 0, 0];
        let nums2 = vec![-1, 0, 0, 0, 0, 0, 1];
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 0.00000);

        let nums1 = vec![3];
        let nums2 = vec![1, 2];
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 2.00000);

        let nums1 = vec![1, 2];
        let nums2 = vec![3];
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 2.00000);

        let nums1 = vec![1, 2];
        let nums2 = vec![1, 2, 3];
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 2.00000);

        let nums1 = vec![2, 2, 4, 4];
        let nums2 = vec![2, 2, 4, 4];
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 3.00000);

        let nums1 = vec![1];
        let nums2 = vec![2, 3, 4, 5];
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), 3.00000);
    }
}

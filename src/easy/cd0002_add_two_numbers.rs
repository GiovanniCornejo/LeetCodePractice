// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

use super::Solution;
impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        return None;
    }
}

/// Helper function to generate a linked list from an array of values
fn generate_linked_list(values: &[i32]) -> Option<Box<ListNode>> {
    let mut head = None;
    let mut current = &mut head;

    for &val in values {
        *current = Some(Box::new(ListNode::new(val)));
        current = &mut current.as_mut().unwrap().next;
    }

    head
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_add_two_numbers() {
        // Example 1:
        let l1 = generate_linked_list(&[2, 4, 3]);
        let l2 = generate_linked_list(&[5, 6, 4]);
        let output = generate_linked_list(&[7, 0, 8]);

        assert_eq!(Solution::add_two_numbers(l1, l2), output);

        // Example 2:
        let l1 = generate_linked_list(&[0]);
        let l2 = generate_linked_list(&[0]);
        let output = generate_linked_list(&[0]);

        assert_eq!(Solution::add_two_numbers(l1, l2), output);

        // Example 3:
        let l1 = generate_linked_list(&[9, 9, 9, 9, 9, 9, 9]);
        let l2 = generate_linked_list(&[9, 9, 9, 9]);
        let output = generate_linked_list(&[8, 9, 9, 9, 0, 0, 0, 1]);

        assert_eq!(Solution::add_two_numbers(l1, l2), output);
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        // We can shift elements to the left by 1 and remove last node.
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
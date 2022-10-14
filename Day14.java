
public class Solution {

    // approach - 1 - Runtime 9 ms
    public ListNode deleteMiddle_1(ListNode head) {

        if(head.next==null) return null;

        // temp node to traverse the linked-list and get length of linked-list.
        ListNode temp = head;
        int listNodeSize = 0;

        while(temp!=null){
            temp = temp.next;
            listNodeSize++;
        }

        // to move among the current nodes of linked-list.
        ListNode currentNode = head;
        for(int i=0;i<(listNodeSize/2)-1;i++) {
            currentNode = currentNode.next;
        }

        currentNode.next = currentNode.next.next;
        return head;
    }

    // approach - 2 - sentinel node - Runtime - 4 ms

    public ListNode deleteMiddle_2(ListNode head) {

        if(head.next==null) return null;

        ListNode fast = head;
        ListNode slow = new ListNode(0, head);

        while(fast!=null && fast.next!=null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        slow.next= slow.next.next;
        return head;
    }

    // approach - 3 - Runtime 8 ms

  public ListNode deleteMiddle(ListNode head) {

        if (head.next == null) return null;

        ListNode fast = head;
        ListNode slow = head;

        while(fast!=null && fast.next!=null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        ListNode curr = head;
        while(curr.next!=slow) {
            curr = curr.next;
        }

        curr.next = slow.next;
        return  head;

}
}

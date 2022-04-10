class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) return head;
        ListNode res = head, evenFirst = head.next;
        ListNode odd = head, even = head.next;//odd奇数，even偶数
        boolean f = true;//true为奇数，false偶数
        head = head.next.next;
        while (head != null) {
            if (f) {
                //奇数
                odd.next = head;
                odd = head;
            } else {
                //偶数
                even.next = head;
                even = head;
            }
            f = !f;
            head = head.next;
        }
        //合并
        odd.next = evenFirst;
        even.next = null;
        return res;
    }
}

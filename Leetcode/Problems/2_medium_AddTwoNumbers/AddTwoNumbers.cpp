/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

        ListNode* res = new ListNode();
        ListNode* cur = res;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {

            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            int left = sum % 10;

            ListNode* nextNode = new ListNode();
            nextNode->val = left;

            cur->next = nextNode;

            cur = nextNode;
        }

        if (carry > 0) {

            ListNode* LastNode = new ListNode(1);

            cur->next = LastNode;
        }

        return res->next;
    }
};
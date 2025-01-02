#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* solve(ListNode* prev, ListNode* curr) {
        if (curr == nullptr) {
            return prev;
        }
        ListNode* forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
        return solve(prev, curr);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        return solve(prev, curr);
    }
};

int main() {
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    ListNode* current = reversedHead;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    return 0;
}

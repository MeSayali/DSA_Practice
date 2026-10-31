#include <vector>
#include <algorithm> // For sort()

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        std::vector<int> arr;

        // Collect all values from both lists
        while (list1 != nullptr) {
            arr.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            arr.push_back(list2->val);
            list2 = list2->next;
        }
        
        std::sort(arr.begin(), arr.end());
        ListNode* newnode = new ListNode(); 
        ListNode* current = newnode;

        for (int i = 0; i < arr.size(); i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return newnode->next;
    }
};

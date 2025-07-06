#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    cout << "[";
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << "]" << endl;
}

// Function to create intersection between two lists
ListNode* createIntersection(ListNode* list1, ListNode* list2, int intersectionValue) {
    // Find the end of list1
    ListNode* current1 = list1;
    while (current1->next != nullptr) {
        current1 = current1->next;
    }

    // Find the end of list2
    ListNode* current2 = list2;
    while (current2->next != nullptr) {
        current2 = current2->next;
    }

    // Create intersection node
    ListNode* intersection = new ListNode(intersectionValue);

    // Link both lists to the intersection
    current1->next = intersection;
    current2->next = intersection;

    return intersection;
}

// Function to free memory safely (handles shared nodes)
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to free lists with intersection safely
void freeListsWithIntersection(ListNode* list1, ListNode* list2) {
    // First, find where the intersection starts
    ListNode* current1 = list1;
    ListNode* current2 = list2;

    // Get lengths
    int len1 = 0, len2 = 0;
    while (current1 != nullptr) {
        len1++;
        current1 = current1->next;
    }
    while (current2 != nullptr) {
        len2++;
        current2 = current2->next;
    }

    // Reset pointers
    current1 = list1;
    current2 = list2;

    // Align pointers
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            current1 = current1->next;
        }
    } else if (len2 > len1) {
        for (int i = 0; i < len2 - len1; i++) {
            current2 = current2->next;
        }
    }

    // Find intersection point
    ListNode* intersection = nullptr;
    while (current1 != nullptr && current2 != nullptr) {
        if (current1 == current2) {
            intersection = current1;
            break;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    // Free list1 up to intersection
    current1 = list1;
    while (current1 != intersection) {
        ListNode* temp = current1;
        current1 = current1->next;
        delete temp;
    }

    // Free list2 up to intersection
    current2 = list2;
    while (current2 != intersection) {
        ListNode* temp = current2;
        current2 = current2->next;
        delete temp;
    }

    // Free the shared part (intersection onwards)
    if (intersection != nullptr) {
        freeList(intersection);
    }
}
    //check if list is empty, return nullptr
    //count separately the length of both lists
    //reset the pointers
    //move the pointer of the longer list forward by difference
    //traverse through until the pointers are equal
    //if there is no intersection - return nullptr
    ListNode* GetIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0, lenB = 0;
        while (tempA != nullptr) {
          lenA++;
          tempA = tempA->next;
        }
        while (tempB != nullptr) {
          lenB++;
          tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if (lenA > lenB) {
          for (int i = 0; i < lenA - lenB; i++) {
            tempA = tempA->next;
          }
        } else if (lenB > lenA) {
          for (int i = 0; i < lenB - lenA;i++) {
            tempB = tempB->next;
          }
        }

        while (tempA != nullptr && tempB != nullptr) {
          if (tempA == tempB) {
            return tempA;
          }
          tempA = tempA->next;
          tempB = tempB->next;
        }
        return nullptr;
    }


int main() {
    cout << "=== Linked Lists with Intersection Test ===" << endl;

    // Test Case 1: Simple intersection
    cout << "\n--- Test Case 1 ---" << endl;
    int list1_arr[] = {4, 1, 8, 4, 5};
    int list2_arr[] = {5, 6, 1, 8, 4, 5};

    ListNode* list1 = createList(list1_arr, 3); // [4, 1, 8]
    ListNode* list2 = createList(list2_arr, 3); // [5, 6, 1]

    // Create intersection at value 8
    ListNode* intersection = createIntersection(list1, list2, 8);
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);

    ListNode* result = GetIntersectionNode(list1,list2);
    if (result != nullptr) {
        cout << "Found intersection at value: " << result->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }
    cout << "Expected intersection value: 8" << endl;

    // Test Case 2: Intersection at the end
    cout << "\n--- Test Case 2 ---" << endl;
    int list3_arr[] = {1, 9, 1, 2, 4};
    int list4_arr[] = {3, 2, 4};

    ListNode* list3 = createList(list3_arr, 4); // [1, 9, 1, 2]
    ListNode* list4 = createList(list4_arr, 2); // [3, 2]

    // Create intersection at value 4
    ListNode* intersection2 = createIntersection(list3, list4, 4);

    ListNode* result2 = GetIntersectionNode(list3,list4);
    if (result2 != nullptr) {
        cout << "Found intersection at value: " << result2->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }
    cout << "Expected intersection value: 4" << endl;

    // Test Case 3: No intersection
    cout << "\n--- Test Case 3 ---" << endl;
    int list5_arr[] = {2, 6, 4};
    int list6_arr[] = {1, 5};

    ListNode* list5 = createList(list5_arr, 3);
    ListNode* list6 = createList(list6_arr, 2);

    ListNode* result3 = GetIntersectionNode(list5,list6);
    if (result3 != nullptr) {
        cout << "Found intersection at value: " << result3->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }
    cout << "Expected intersection  - nullptr(no intersection)" << endl;

    // Test Case 4: Same length lists
    cout << "\n--- Test Case 4 ---" << endl;
    int list7_arr[] = {1, 2, 3, 4, 5};
    int list8_arr[] = {6, 7, 3, 4, 5};

    ListNode* list7 = createList(list7_arr, 2); // [1, 2]
    ListNode* list8 = createList(list8_arr, 2); // [6, 7]

    // Create intersection at value 3
    ListNode* intersection3 = createIntersection(list7, list8, 3);
    intersection3->next = new ListNode(4);
    intersection3->next->next = new ListNode(5);

    ListNode* result4 = GetIntersectionNode(list7,list8);
    if (result4 != nullptr) {
        cout << "Found intersection at value: " << result4->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }
    cout << "Expected intersection value: 3" << endl;


    // Clean up memory safely
    freeListsWithIntersection(list1, list2);
    freeListsWithIntersection(list3, list4);
    freeList(list5);
    freeList(list6);
    freeListsWithIntersection(list7, list8);

    return 0;
}
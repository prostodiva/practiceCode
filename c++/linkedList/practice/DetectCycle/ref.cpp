//Detect a cycle in a Singly Linked List
//HasCycle:
//    - create two pointers(slow, fast)
//    - assign with a head
//    - traverce the List until fast != nullptr or fast->next != nullptr
//    - move forward both pointers
//    - if the pointers meet - return true, otherwise false

#include <string>
#include <iomanip>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {};
};

bool HasCycle(Node*& head) {
  Node* slow = head;
  Node* fast = head;
  while(fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
  }
  return false;
}

int main() {

  return 0;
}
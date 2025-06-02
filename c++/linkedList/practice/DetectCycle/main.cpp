#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {};
};

bool DetectCycle(Node*& head) {
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
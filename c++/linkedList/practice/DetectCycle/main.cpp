#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {};
};


bool HasCycle(Node* head) {
  if (head == nullptr) return false;
  Node* slow = head;
  Node* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    return false;
  }
}

int main() {
  Node* singlyLL = nullptr;
  return 0;
}
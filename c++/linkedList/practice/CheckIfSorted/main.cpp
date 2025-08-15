//check if list is sorted
// we need to check for false statement
// start to compare with -32768

#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {};
};

void PushAtFront(Node*& head, int value) {
  Node* newNode = new Node(value);
  newNode->next = head;
  head = newNode;
}

bool CheckIfSorted(Node* head) {
  if (head == nullptr) return true;

  Node* temp = head;
  int x = -32768;
  while (temp != nullptr) {
    if (temp->data < x) {
      return false;
    }
    x = temp->data;
    temp = temp->next;
  }
  return true;
}

void PrintList(Node*& head) {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "nullptr"<<endl;
}


int main() {
  Node* singlyLL = nullptr;
  PushAtFront(singlyLL, 50);
  PushAtFront(singlyLL, 40);
  PushAtFront(singlyLL, 30);
  PushAtFront(singlyLL, 20);
  PushAtFront(singlyLL, 10);
  PrintList(singlyLL);          //10 20 30 40 50

  bool result = CheckIfSorted(singlyLL);
  cout << result;

  return 0;
}
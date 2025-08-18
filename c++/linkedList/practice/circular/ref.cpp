#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {}
};

//create a newNode
//if it is the first node:
//     - make it point to itself
//     - head is a newNode
//else - create temp pointer
//     - traverse until temp hits the head(find the last node and insert after)
//     - insert neNode at the end:
//      newNode's next point to the head
//      the last node's next point to newNode
// return head
Node* CreateList(Node*& head, int value) {
  Node* newNode = new Node(value);
  if (head == nullptr) {
    newNode->next = newNode;  //first node points to itself
    head = newNode;
  } else {
    Node* temp = head;
    while(temp->next != head) { //find the last node and insert after
      temp = temp->next;
    }
    newNode->next = head;      //the new node poits to the first node
    temp->next = newNode;      //the last node points to the new node
  }
  return head;
}

void PrintList(Node* head) {
  Node* temp = head;
  do {
    cout << temp->data <<"->";
    temp = temp->next;
  } while (temp != head);
}

//insert before head and after the last is the same procedure.
//pseudocode:
//insert before head(pos == 0):
//  - create a node
//if the list is empty:
//   - make the first node point to itself
//if not:
//  - create temp, traverse it until temp->next != head (find the end)
//  - make a newNode->next point to head, temp->next to newNode
//insert at position the procedure is the same as in linear linked list
void Insert(Node*& head, int position, int value) {
  Node* newNode = new Node(value);
  Node* temp = head;
  if (position == 0) {
      if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
      }
      while (temp->next != head) {
        temp = temp->next;
      }
      newNode->next = head;
      temp->next = newNode;
      head = newNode;    //optional
  } else {
    for (int i = 0; i < position - 1; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

// check if the list is empty
// create temp; assign with head->next
// traverse until head
// create last pointer; assign with temp
// move temp; delete last
// delete head
// assign head with nullptr
void DeleteList(Node*& head) {
  if (head == nullptr) return;

  Node* temp = head->next;
  while (temp != head) {
    Node* last = temp;
    temp = temp->next;
    delete last;
  }
  delete head;
  head = nullptr;
}

int main() {
  Node* circularList = nullptr;

  CreateList(circularList, 10);
  CreateList(circularList, 20);
  CreateList(circularList, 30);

  PrintList(circularList);
  Insert(circularList, 0, 5);
  Insert(circularList, 2, 15);
  PrintList(circularList);
  DeleteList(circularList);

  return 0;
}

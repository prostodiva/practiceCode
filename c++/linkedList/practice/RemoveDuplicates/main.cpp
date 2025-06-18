//remove duplicates from sorted list
//compare two values if move pointers forward if not matching (prev and temp)
// if match - delete the second node
// delete the pointer
// reassign temp with prev->next

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

void RemoveDuplicates(Node*& head) {
  Node* prev = head;
  Node* temp = head->next;
  while(temp != nullptr) {
    if (prev->data != temp->data) {
      prev = temp;
      temp = temp->next;
    } else {
      prev->next = temp->next;
      delete temp;
      temp = prev->next;
    }
  }
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
    PushAtFront(singlyLL, 40);
    PushAtFront(singlyLL, 40);
    PushAtFront(singlyLL, 30);
    PushAtFront(singlyLL, 10);
    PushAtFront(singlyLL, 10);
    PrintList(singlyLL);          //10 10 30 40 40

    RemoveDuplicates(singlyLL);
    PrintList(singlyLL);

    return 0;
}
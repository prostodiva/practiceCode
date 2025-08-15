#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {};
};

template<typename T>
void PushAtFront(Node<T>*& head, T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void PrintList(Node<T>* head) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr"<<endl;
}

template<typename T>
void SearchKeyAndMove(Node<T>*& head, T key) {
  if (head == nullptr) return;
  Node<T>* prev = nullptr;
  Node<T>* temp = head;
  while (temp != nullptr) {
    if (temp->data == key) {
      prev->next = temp->next;
      temp->next = head;
      head = temp;
    }
    prev = temp;
    temp = temp->next;
  }
}



//5, 30, 20, 10
//search for 30 and move at front:
// 30 5 20 10
int main() {
    Node<int>* singlyLL = nullptr;
    PushAtFront(singlyLL, 10);
    PushAtFront(singlyLL, 20);
    PushAtFront(singlyLL, 30);
    PushAtFront(singlyLL, 5);
    PrintList(singlyLL);

    SearchKeyAndMove(singlyLL, 30);
    PrintList(singlyLL);

    return 0;
}

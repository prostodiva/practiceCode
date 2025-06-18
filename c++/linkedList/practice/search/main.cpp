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


//move the key to the head
//prev follows temp
template<typename T>
Node<T>* SearchKeyAndMove(Node<T>*& head, int key) {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    while(temp != nullptr) {
      if (key == temp->data) {
        prev->next = temp->next;
        temp->next = head;
        head = temp;
      }
      prev = temp;
      temp = temp->next;
    }
    return (head);
}


//5, 30, 20, 10
int main() {
    Node<int>* singlyLL = nullptr;
    PushAtFront(singlyLL, 10);
    PushAtFront(singlyLL, 20);
    PushAtFront(singlyLL, 30);
    PushAtFront(singlyLL, 5);
    PrintList(singlyLL);


    Node<int>* result = SearchKeyAndMove(singlyLL, 30);
    cout << result->data << endl;
    PrintList(singlyLL);

    return 0;
}

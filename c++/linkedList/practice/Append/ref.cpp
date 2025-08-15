//append two lists

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
Node<T>* Append(Node<T>*& firstHead, Node<T>*& secondHead) {
    Node<T>* temp = firstHead;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = secondHead;
    secondHead = nullptr;
    return firstHead;
}


template<typename T>
void PrintList(Node<T>*& head) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr"<<endl;
}

int main() {
    Node<int>* firstList = nullptr;
    PushAtFront(firstList, 30);
    PushAtFront(firstList, 20);
    PushAtFront(firstList, 10);
    PrintList(firstList);            //10, 20 30

    Node<int>* secondList = nullptr;
    PushAtFront(secondList, 60);
    PushAtFront(secondList, 50);
    PushAtFront(secondList, 40);
    PrintList(secondList);           //40 50 60

    Node<int>* newList = Append(firstList, secondList);
    PrintList(newList);            // 10 20 30 40 50 60

    return 0;
}
//Merge two lists. Don't need to create the third list. Time - O(m+n)
//check the smallest first value in the lists(compare)
//assign two pointers(temp and last) to the smallerst value
// relink the head to next node
// last->next = nullptr
// else - the dame thing for the second list
// compare again two lists, relink this node to the node from the second list
// make ladt next to null
// continue the steps


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
Node<T>* Merge(Node<T>*& firstHead, Node<T>*& secondHead) {

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
    PushAtFront(secondList, 35);
    PushAtFront(secondList, 25);
    PushAtFront(secondList, 15);
    PrintList(secondList);           //15 25 35



    return 0;
}
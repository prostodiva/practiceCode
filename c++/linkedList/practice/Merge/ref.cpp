//Merge two lists. Don't need to create the third list. Time - O(m+n)
//devide the code in four parts


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
Node<T>* Merge(Node<T>*& first, Node<T>*& second) {
      //handle if the first node if nullptr
    if (first == nullptr) return second;
    if (second == nullptr) return first;
      //part 1:
      //    - create two pointers
      //    - compare the first two nodes from the lists. handle cases if value are equal
      //    - move both pointers to the smallers node
      //    - move head to the next node
      //    - make the last node point to nullptr
    Node<T>* last = nullptr;
    Node<T>* temp = nullptr;
    if (first->data <= second->data) {
        temp = last = first;
        first = first->next;
        last->next = nullptr;
    } else if (second->data <= first->data) {
      last = temp = second;
      second = second->next;
      last->next = nullptr;
    }


      //Part 2:
      //    - traverse until one of the list is not nullptr
      //    - compare data
      //    - move last->next on the smallest
      //    - move last on the head
      //    - move head forward
    while (first != nullptr && second != nullptr) {
      if (first->data <= second->data) {
        last->next = first;
        last = first;
        first = first->next;
      } else if (second->data <= first->data) {
        last->next = second;
        last = second;
        second = second->next;
      }
    }


        //Part 3:
        //    - if there are remaining nodes - point to the node
        //    - check for != nullptr
    if (first != nullptr) {
      last->next = first;
    } else {
      last->next = second;
    }
    return temp;
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

template<typename T>
void DeleteList(Node<T>*& head) {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
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

    Node<int>* mergedList = Merge(firstList, secondList);
    PrintList(mergedList);

    // Clean up memory
    DeleteList(mergedList);
    firstList = nullptr;  // Already merged, so firstList is now part of mergedList
    secondList = nullptr; // Already merged, so secondList is now part of mergedList

    return 0;
}
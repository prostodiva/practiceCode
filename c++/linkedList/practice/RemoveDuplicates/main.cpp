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

//remove dups from sorted list
//check if list is empty
//create two pointers(prev starts from head)
//traverse until temp != nullptr
//compare the data and move pointers forward if not equal
//if equal - delete the second node(relink prev->next to temp->next)
//delete temp
//reasign temp
//return head
Node* RemoveDuplicates(Node*& head) {
    if (head == nullptr) return nullptr;
    Node* prev = head;
    Node* temp = head->next;
    while (temp != nullptr) {
      if (prev->data != temp->data) {
        prev = temp;
        temp = temp->next;
      } else {
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
      }
    }

    return head;
}

//"check if list is empty" → if (head == nullptr) return nullptr;
//"create outer pointer(start with head) and traverse" → Node* outer = head; while (outer != nullptr)
//    "inside the previous loop: create inner pointer(start from outer)" → Node* inner = outer;
//"traverse inner until inner->next != nullptr" → while (inner->next != nullptr)
//    "compare the data (check for true)" → if (outer->data == inner->next->data)
//        "create temp to store node to delete" → Node* temp = inner->next;
//"relink inner->next(skip the duplicate)" → inner->next = inner->next->next;
//"delete temp" → delete temp;
//"move inner" → inner = inner->next; (in else block)
//"move outer" → outer = outer->next;
//"return head" → return head;
Node* RemoveDupsFromUnSorted(Node*& head) {
        if (head == nullptr) return nullptr;

        Node* outer = head;
        while (outer != nullptr) {
            Node* inner = outer;
            while (inner->next != nullptr) {
                if (outer->data == inner->next->data) {
                    Node* temp = inner->next;
                    inner->next = inner->next->next;
                    delete temp;
                } else {
                    inner = inner->next;
                }
            }
            outer = outer->next;
        }
        return head;
    }

void PrintList(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr"<<endl;
}

void DeleteList(Node*& head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  head = nullptr;
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
    PrintList(singlyLL);    //10->30->40->nullptr

    PushAtFront(singlyLL, 10);
    PushAtFront(singlyLL, 30);
    PrintList(singlyLL);    // 30->10->10->30->40->nullptr
    RemoveDupsFromUnSorted(singlyLL);
    PrintList(singlyLL);     // 30->10->40->nullptr

    DeleteList(singlyLL);

    return 0;
}
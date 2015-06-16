#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){};
};

class LinkedList{
public:
    void removeElement(int value);
    void addElements(int value);
    bool empty();
    void printLinkedList();
    LinkedList();
    ~LinkedList();

private:
    ListNode* _head;
};

LinkedList::LinkedList():_head(NULL){
}

void LinkedList::addElements(int value) {
    ListNode* node = new ListNode(value);
    if(_head == NULL){
        _head = node;
    }else{
        node->next = _head;
        _head = node;
    }
}
bool LinkedList::empty() {
    return _head == NULL;
}

void LinkedList::removeElement(int value) {
    ListNode* p = _head;
    ListNode* prev = NULL;
    while(p){
        if(p->val == value){
            if(p == _head){
                ListNode* q = p->next;
                delete p;
                p = q;
                _head = q;
            }else{
                ListNode* q = p->next;
                prev->next = q;
                delete p;
                p = q;
            }
            continue;
        }
        prev = p;
        p = p->next;
    }
}
void LinkedList::printLinkedList() {
    ListNode* p = _head;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
}
LinkedList::~LinkedList() {
    ListNode* p = _head;
    while(p){
        ListNode* q = p->next;
        delete p;
        p = q;
    }
}
int main() {
    LinkedList list;
    list.addElements(6);
    list.addElements(5);
    list.addElements(4);
    list.addElements(3);
    list.addElements(2);
    list.addElements(1);

    list.printLinkedList();
    list.removeElement(4);

    list.printLinkedList();
    list.removeElement(1);
    list.printLinkedList();
    return 0;
}

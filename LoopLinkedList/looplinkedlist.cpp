#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename type>
type randUniform() {
    return rand() % ((type)100);
}

template <typename type>
struct LinkedList {
    type value;
    LinkedList* next;
    LinkedList() {
        value = randUniform<type>();
        next = NULL;
    }
};

template <typename type>
void createLoopLinkedList(LinkedList<type>* head, int count) {
    LinkedList<type>* x = head;
    for (size_t i = 1; i < count; i++) {
        LinkedList<type>* newNode = new LinkedList<type>();
        x->next = newNode;
        x = newNode;
    }
    x->next = head; // connect tail to head
}

template <typename type>
void retrieveLoopLinkedList(LinkedList<type>* head) {
    cout << head->value << ", ";
    LinkedList<type>* x = head->next;
    for (; x != head; x = x->next) {
        cout << x->value << ", ";
    }
    cout << endl;
}

template <typename type>
bool isLooped(LinkedList<type>* head) {
    bool looped;
    LinkedList<type>* x = head->next;
    for (;;) {
        if (x == head) {
            looped = true; 
            break;
        }
        if (x->next == NULL) {
            looped = false; 
            break;
        }
        else x = x->next;
    }
    return looped;
}

template <typename type>
int count(LinkedList<type>* head, LinkedList<type>* x) {
    if (x->next == head) return 1;
    return 1 + count(head, x->next);
}

int main(int argc, char** argv) {
    int N = atoi(argv[1]);
    LinkedList<int>* head = new LinkedList<int>();
    
    createLoopLinkedList(head, N);
    cout << endl;
    retrieveLoopLinkedList(head);
    
    if (isLooped(head)) {
        cout << "it's a looped linked list." << endl;
    }
    else cout << "it's not a looped linked list." << endl;
    
    LinkedList<int>* x = head;
    cout << count(head, x) << endl;
    
    
    return 0;
}
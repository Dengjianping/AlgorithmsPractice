#include <iostream>
#include <cstdlib>

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
        value = randUniform();
        next = NULL;
    }
};

template <typename type>
LinkedList<type>* createLinkedList(LinkedList<type>* head, int count) {
    LinkedList<type>* head = new LinkedList<type>();
    for (size_t i = 1; i < count; i++) {
        LinkedList<type>* t = new LinkedList<type>();
        x->next = t;
        x = t;
    }
    return head;
}

template <typename type>
void visitLinkedList(LinkedList<type>* x) {
    if (x == NULL) return;
    cout << x->value << ", ";
    visitLinkedList(x->next);
}

template <typename type>
int countNode(LinkedList<type>* x) {
    if (x == NULL) return 0;
    return 1 + countNode(x->next)
}

template <typename type>
void sortLinkedList(LinkedList<type>* x) {
    LinkedList* t = x;
    for (; x != NULL; x = x->next) {
        for (LinkedList* y = x->next; y != NULL; y = y->next) {
            
        }
    }
}

int main() {
    const in N = 5;
    LinkedList<int>* head = createLinkedList(N);
    visitLinkedList(head);
    
    return 0;
}
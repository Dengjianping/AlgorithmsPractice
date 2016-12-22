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
        value = randUniform<type>();
        next = NULL;
    }
};

template <typename type>
LinkedList<type>* createNode() {
    LinkedList<type>* node = new LinkedList<type>();
    return node;
}

template <typename type>
void recursiveCreateLinkedList(LinkedList<type>* x, const int N) {
    static int count = 0;
    if (count == N) return;
    count++;
    x->next = createNode<type>();
    recursiveCreateLinkedList(x->next, N);
}

template <typename type>
LinkedList<type>* createLinkedList(const int count) {
    LinkedList<type>* head = new LinkedList<type>();
    LinkedList<type>* x = head;
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
    return 1 + countNode(x->next);
}

template <typename type>
void sortLinkedList(LinkedList<type>* x) {
    LinkedList<type>* t = x;
    for (; x != NULL; x = x->next) {
        for (LinkedList<type>* y = x->next; y != NULL; y = y->next) {
            if (x->value > y->value) {
                int t = x->value;
                x->value = y->value;
                y->value = t;
            }
        }
    }
}

int main() {
    const int N = 10;
    // LinkedList<int>* head = createLinkedList<int>(N);
    LinkedList<int>* head = createNode<int>();
    recursiveCreateLinkedList(head, N);
    visitLinkedList(head);
    cout << endl;
    sortLinkedList(head);
    visitLinkedList(head);
    
    cout << endl << "count nodes: " << countNode(head) << endl;
    
    return 0;
}
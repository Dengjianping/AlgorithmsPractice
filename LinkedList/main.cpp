#include "header.h"
#include "singlelinkedlist.h"
#include "doublelinkedlist.h"


int main()
{
    const int N = 10;
    int range = 100;

    srand((unsigned)time(NULL));

    LinkedList<int>* head = new LinkedList<int>(randNumber(range));
    LinkedList<int>* x = head;
    for (size_t i = 0; i < N-1; i++)
    {
        LinkedList<int>* node = new LinkedList<int>(randNumber(range));
        x->next = node;
        x = node;
    }
   
    x = head;
    visitLinkedList(head);

    cout << endl << "count: " << count(head) << endl;
    cout << "max node: " << maxNode(head)->value << endl;
    cout << "min node: " << minNode(head)->value << endl;

    system("pause");
    delete head;
    return 0;
}
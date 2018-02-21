#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode
{
    int m_value;
    ListNode * m_next;
    
    ListNode(int v) : m_value(v), m_next(NULL) {};
};

void print(ListNode * head)
{
    while (head != NULL)
    {
        cout << head->m_value << " ";
        head = head->m_next;
    }
    cout << endl;
}

ListNode * reverse(ListNode * head)
{
    ListNode * newHead = NULL;
    ListNode * cur = head;
    while (cur != NULL)
    {
        ListNode * tmp = cur->m_next;
        cur->m_next = newHead;
        newHead = cur;
        cur = tmp;
    }
    
    return newHead;
}

ListNode * createList()
{
    ListNode * head = new ListNode(20);
    ListNode * n1 = new ListNode(-10);
    head->m_next = n1;
    
    return head;
}

int main(int argc, char** argv) {

    ListNode * head = createList();
    print(head);
    head = reverse(head);
    print(head);
    
    return 0;
}


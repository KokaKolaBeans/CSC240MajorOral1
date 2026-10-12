#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void removeDuplicates(Node *&head) // Node* passes copy of ptr address; Node*& copies the ptr variable itself
{

    if (head == nullptr || head->next = head)
    {
        return;
    }

    Node *outer = head;
    while (outer != nullptr)
    {
        Node *inner = outer;

        while (inner->next != nullptr)
        {
            if (inner->next->val == outer->val)
            {
                Node *temp = inner->next;
                inner->next = inner->next->next;

                delete temp;
            }
            inner = inner->next;
        }
        outer =
    }

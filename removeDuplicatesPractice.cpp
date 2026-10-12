#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void removeDuplicates(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *outer = head;

    while (outer != nullptr)
    {
        Node *inner = outer;

        // Look ahead at inner->next so we can easily unhook duplicates
        while (inner->next != nullptr)
        {
            if (inner->next->val == outer->val)
            {
                // Duplicate found! Unhook and delete
                Node *temp = inner->next;
                inner->next = inner->next->next;
                delete temp;
            }
            else
            {
                // Move inner forward only if we didn't delete
                inner = inner->next;
            }
        }
        outer = outer->next;
    }
}

int main()
{
    return 0;
}

// Input : head->[3]->[1]->[3]->[2]->[1]->nullptr

//    Expected Output List : head->[3] ->[1] ->[2] ->nullptr
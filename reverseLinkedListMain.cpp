#include <iostream>

struct Node
{
    int val;
    Node *next;
};

// Iterative In-Place Reversal: O(n) time, O(1) space
void reverseList(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *nextNode = nullptr;
 
    while (curr != nullptr)
    {
        nextNode = curr->next; // Save the rest of the list
        curr->next = prev;     // Reverse current node's pointer
        prev = curr;           // Step prev forward
        curr = nextNode;       // Step curr forward
    }

    head = prev; // Update head to point to the new front node
}

// Helper to print list
void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << "[" << head->val << "] -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

int main()
{
    // Construct test list: [10] -> [20] -> [30] -> [40] -> nullptr
    Node *head = new Node{10, new Node{20, new Node{30, new Node{40, nullptr}}}};

    std::cout << "Original: ";
    printList(head);

    reverseList(head);

    std::cout << "Reversed: ";
    printList(head);

    return 0;
}
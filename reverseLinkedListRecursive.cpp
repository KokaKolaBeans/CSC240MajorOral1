// Recursive Reversal: O(n) time, O(n) stack space

struct Node
{
    int val;
    Node *next;
};

Node *reverseListRecursive(Node *head)
{
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Reverse the sub-list starting from the second node
    Node *newHead = reverseListRecursive(head->next);

    // Rewire pointers on the unwind
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
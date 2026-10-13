#include <iostream>
using namespace std;

// INCLUDES

struct Node
{
    int val;
    Node *next;
};

// LAB 4:

void ShiftRight(int info[], int len)
{
    if (len <= 1)
    {
        return;
    }

    int lastItem = info[len - 1];

    for (int k = len - 1; k > 0; --k)
    {
        info[k] = info[k - 1];
    }
    info[0] = lastItem;
    return;
}

void SplitLists(int info[], int len, int tar, int hi[], int lo[])

{
    for (int k = 0; k < len; ++k)

    {
        if (info[k] >= tar)
        {
        }
    }
}

#include <iostream>
using namespace std;

void deleteItemAndCompact(int array[], int &length, int target);

int main()

{
    int len = 6;
    int tar = 4;

    int *arr = new int[len]{4, 1, 4, 4, 3, 2};

    cout << "Original Array:" << endl;

    for (int n = 0; n < len; ++n)
    {
        cout << arr[n] << endl;
    }

    deleteItemAndCompact(arr, len, 4);

    cout << "Compacted Array:" << endl;

    for (int n = 0; n < len; ++n)
    {
        cout << arr[n] << endl;
    }

    delete[] arr;

    return 0;
}

void deleteItemAndCompact(int array[], int &length, int target)
{
    int write = 0;
    for (int read; read < length; read++)
    {
        if (array[read] != target)
        {
            array[write] = array[read];
            write++;
        }
    }
    length = write;
}

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

// ============================================================================
// EXERCISE 1: Singly Linked List - Remove Duplicates (Nested Pointers)
// Prompt: Write a function 'removeDuplicates' that modifies a singly linked
// list in-place so that only the first occurrence of each value is kept.
// Do not use standard containers or extra data structures.
// ============================================================================

struct Node
{
    int val;
    Node *next;
};

void removeDuplicates(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
        return;

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
            else
            {
                inner = inner->next;
            }
        }
        outer = outer->next;
    }
}

// ============================================================================
// EXERCISE 2: Array-Based List - Compact and Remove Item
// Prompt: Write a function 'deleteItemAndCompact' that searches an array
// for all occurrences of 'target', removes them by shifting remaining elements
// in-place, and updates 'length'.
// ============================================================================

void deleteItemAndCompact(int arr[], int &length, int target)
{
    int write = 0;
    for (int read = 0; read < length; read++)
    {
        if (arr[read] != target)
        {
            arr[write] = arr[read];
            write++;
        }
    }
    length = write;
}

// ============================================================================
// EXERCISE 3: Recursive Linked List - Remove Odd Nodes
// Prompt: Write a RECURSIVE function 'countAndRemoveOdd' that unlinks and
// deletes all nodes containing odd integer values from a linked list and
// returns the total count of deleted nodes.
// ============================================================================

int countAndRemoveOdd(Node *&head)
{
    if (head == nullptr)
        return 0;

    int countFromRest = countAndRemoveOdd(head->next);

    if (head->val % 2 != 0)
    {
        Node *temp = head;
        head = head->next; // Updates original pointer via reference
        delete temp;
        return 1 + countFromRest;
    }

    return countFromRest;
}

// ============================================================================
// EXERCISE 4: Singly Linked List - Reverse In-Place (Iterative)
// Prompt: Write a function 'reverseList' that reverses a singly linked list
// in-place using three pointers (prev, curr, next).
// ============================================================================

void reverseList(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *nextNode = nullptr;

    while (curr != nullptr)
    {
        nextNode = curr->next; // Save next node
        curr->next = prev;     // Reverse pointer
        prev = curr;           // Advance prev
        curr = nextNode;       // Advance curr
    }

    head = prev; // Update head pointer
}

// ============================================================================
// EXERCISE 5: Array-Based Queue - Insert at Position (Shift Right)
// Prompt: Write a function 'insertAt' that inserts 'value' at index 'pos' in
// an array-based list, shifting elements to the right. Increment 'length'.
// If 'pos' is out of bounds (pos < 0 or pos > length), return false.
// ============================================================================

bool insertAt(int arr[], int &length, int capacity, int pos, int value)
{
    if (pos < 0 || pos > length || length >= capacity)
    {
        return false;
    }

    // Shift elements right starting from the end
    for (int i = length; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    length++;
    return true;
}

// ============================================================================
// MAIN FUNCTION (Demonstration & Output Verification)
// ============================================================================

void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << "[" << head->val << "] -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

// REVERSE LINKED LIST RECURSIVE

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

// int main()
// {
//     std::cout << "--- 1. Remove Duplicates ---\n";
//     Node *list1 = new Node{3, new Node{1, new Node{3, new Node{2, new Node{1, nullptr}}}}};
//     removeDuplicates(list1);
//     printList(list1);

//     std::cout << "\n--- 2. Delete and Compact ---\n";
//     int arr2[] = {4, 1, 4, 4, 3, 2};
//     int len2 = 6;
//     deleteItemAndCompact(arr2, len2, 4);
//     for (int i = 0; i < len2; i++)
//         std::cout << arr2[i] << " ";
//     std::cout << "\n";

//     std::cout << "\n--- 3. Count & Remove Odd (Recursive) ---\n";
//     Node *list3 = new Node{4, new Node{7, new Node{1, new Node{8, new Node{3, nullptr}}}}};
//     int removed = countAndRemoveOdd(list3);
//     std::cout << "Removed: " << removed << " nodes\nRemaining: ";
//     printList(list3);

//     std::cout << "\n--- 4. Reverse List ---\n";
//     Node *list4 = new Node{10, new Node{20, new Node{30, nullptr}}};
//     reverseList(list4);
//     printList(list4);

//     std::cout << "\n--- 5. Insert At Position ---\n";
//     int arr5[10] = {10, 20, 40, 50};
//     int len5 = 4;
//     insertAt(arr5, len5, 10, 2, 30); // Insert 30 at index 2
//     for (int i = 0; i < len5; i++)
//         std::cout << arr5[i] << " ";
//     std::cout << "\n";

//     return 0;
// }
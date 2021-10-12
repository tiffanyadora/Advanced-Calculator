#include<iostream>
using namespace std;

// Linked list node
class Node{
public:
    string data;
    Node* next;
};

// Give a new node in front of the list
void push(Node** headRef, string newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) =newNode;
}

void deleteNode(Node **headRef, int position)
{
    // Store the head node as tempNode
    Node* tempNode = *headRef;

    // If linked list is empty/null
    if (*headRef == NULL){
        return;
    }

    // If we need to remove the head
    if (position == 1)
    {
        // Change head with next node
        *headRef = tempNode->next;

        free(tempNode); // Free old head
        return;
    }

    // Find previous node of the node that is going to be deleted
    for(int i = 1; i < position - 1; i++){
        // If the tempNode is not empty
        if (tempNode != NULL){
            tempNode = tempNode->next;
        }
    }

    // If position is more than number of nodes
    if (tempNode == NULL || tempNode->next == NULL){
        return;
    }

    // Store pointer to the next of tempNode->next (the node to be deleted)
    Node *next = tempNode->next->next;

    free(tempNode->next); // Free the memory

    // Unlink the deleted node from list
    tempNode->next = next;
}

// This function to prints the content
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data;

        // Conditional operator
		// if next node is true (not empty), print arrow
		// if false (empty), print new line
		cout << (node->next ? " | ": "\n");

        node = node->next;
    }
}

// main function
int main()
{
    int n; // n as input position

    cout << "======= Delete Function ======\n" << endl;

    // Start with the empty list
    Node* head = NULL;

    // Add elements in history linked list
    push(&head, "2 x 99-10^2");
    push(&head, "3+sin(23)");
    push(&head, "log 100");
    push(&head, "cos(180) : 5");
    push(&head, "2+3");

    // User prompt
    puts("Original History list: ");
    printList(head);

    cout << "\nInput position: ";
    cin >> n;

    deleteNode(&head, n); // Deleting element at n position
    cout << "\nHistory list after Deletion at position " << n << ": \n";

    printList(head);

    return 0;
}

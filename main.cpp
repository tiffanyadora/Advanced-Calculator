#include <iostream>
using namespace std;

/* Link list node */
class Node{
    public:
        string data;
        struct Node* next;

        Node(string x){
            data = x;
            next = NULL;
        }
};

/* Class for functions of History Manager */
class CalculatorTrial {
    public:
        void DisplayHistory();
        void DeleteHistory();
        void ClearHistory();
};

/* Function to append new data into the history list */
void append(struct Node** head_ref, struct Node **tail_ref, string new_data){
    struct Node* new_node = new Node(new_data);
    if(*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Removing the elements in history list at specific position k */
struct Node* deleteNode(struct Node *head, int k) {

    // Store the head as tempNode
    Node* tempNode = head;

    // If linked list is empty/null and the input position is invalid
    if (head == NULL && k <= 0){
        return head;
    }

    // If we need to remove the head
    else if (k == 1)
    {
        // Change head with next node
        head = tempNode->next;

        return head;
    }

    else {
        // Find previous node of the node that is going to be deleted
        for(int i = 1; i < k - 1; i++){
            // If the tempNode is not empty
            if (tempNode != NULL){
                tempNode = tempNode->next;
            }
        }

        // If position is more than number of nodes
        if (tempNode == NULL || tempNode->next == NULL){
            return head;
        }

        // Store pointer to the next of tempNode->next (the node to be deleted)
        Node *next = tempNode->next->next;

        free(tempNode->next); // Free the memory

        // Unlink the deleted node from list
        tempNode->next = next;

        return head;
    }

}

/* Function to print the linked list for the history */
void printList(Node *head){
    while (head != NULL){

        cout << head->data;

        // Conditional operator
		    // if next node is true (not empty), print |
		    // if false (empty), print new line
		    cout << (head->next ? " | ": "\n");

        head = head->next;
    }
    cout << "\n";
}

/* Function to display the current history list */
void DisplayHistory(Node *head){

    cout << "Displaying current history of Calculator..." << endl;

    // If the list is empty
    if (head == NULL){
        cout << "Nothing here." << endl;
    }
    // If it is not empty, print the contents
    else
        printList(head);

}

/* Function to delete specific elements in history list*/
void DeleteHistory(Node **head_ref){
    int position;
	
    // Prompt
    cout << "Enter position to delete: ";
    cin >> position;

    // Update the list after node removal
    *head_ref = deleteNode(*head_ref, position);

    cout << "History of Calculator after deletion: " << endl;
    printList(*head_ref); // Print the update
}

/* Function to clear the entire history list */
void ClearHistory(Node** head_ref)
{

    // Deref head_ref to get the real head
    Node* currNode = *head_ref;
    Node* next = NULL;

    while (currNode != NULL)
    {
        next = currNode->next; // Storing the address of next node
        free(currNode);        // Deallocates the memory
        currNode = next;       // Current Node goes to the next node
    }

    // Deref head_ref to affect the real head back in the caller
    *head_ref = NULL;

    cout << "Calculator History is cleared." << endl;
}

/* Main function */
int main(){
    int userChoice;

    // Initialize head node and tail node as NULL
    struct Node *head = NULL, *tail = NULL;

    // Try adding some input to the history list
    // (Will be adjusted later for program implementation)
    append(&head, &tail, "123+456");
    append(&head, &tail, "cos(360)");
    append(&head, &tail, "99xlog(1000)");

    cout << "============= Calculator History =============\n";

    // User guide (Option 1-4)
    cout<<"1) Display history list"<<endl;
    cout<<"2) Delete an element from history list"<<endl;
    cout<<"3) Clear history list"<<endl;
    cout<<"4) Exit"<<endl;

    // > Main Loop
    do {
        // Prompt
        cout << "\nEnter your choice : " << endl;
        cin >> userChoice;

        switch (userChoice) {
            case 1: DisplayHistory(head);   // If user enter 1 -> display history
                break;
            case 2: DeleteHistory(&head);   // If user enter 2 -> delete history at specific pos
                break;
            case 3: ClearHistory(&head);    // If user enter 3 -> clear history
                break;
            case 4: cout<<"Calculator History Manager ended."<<endl; // If 4, program terminated
                break;
            default: cout<<"Invalid choice"<<endl; // Other input will considered as invalid
        }
   } while(userChoice!=4);

    return 0;
}

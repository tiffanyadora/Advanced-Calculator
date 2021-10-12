#include <iostream>
using namespace std;

// Link list node
class Node{
    public:
        string data;
        struct Node* next;

        Node(string x){
            data = x;
            next = NULL;
        }
};

class CalculatorTrial {
    // Public access classifier
    public:
        void DisplayHistory();
        void DeleteHistory();
        //void ClearHistory(); ... soon to be added
};

void append(struct Node** head_ref, struct Node **tail_ref, string new_data){
    struct Node* new_node = new Node(new_data);
    if(*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

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

void DisplayHistory(Node *head){
    cout << "Displaying current history of Calculator..." << endl;
    printList(head);
}

void DeleteHistory(Node **head){
    int position;
    cout << "Enter position to delete: ";
    cin >> position;

    cout << "History of Calculator after deletion: " << endl;
    *head = deleteNode(*head, position);

    printList(*head);
}

/** 
void ClearHistory(){
}
**/

// Main function
int main(){
    int userChoice;

    struct Node *head = NULL, *tail = NULL;

    append(&head, &tail, "123+456");
    append(&head, &tail, "cos(360)");
    append(&head, &tail, "99xlog(1000)");

    cout << "============= Calculator History =============\n";

    cout<<"1) Display history list"<<endl;
    cout<<"2) Delete an element from history list"<<endl;
    //cout<<"3) Clear history list"<<endl; ... soon to be added
    cout<<"3) Exit"<<endl; // supposed to be 4 but make it 3 first

    do {
      cout<<"\nEnter your choice : "<<endl;
      cin>>userChoice;

      switch (userChoice) {
         case 1: DisplayHistory(head);
         break;
         case 2: DeleteHistory(&head);
         break;
         //case 3: ClearHistory(); ... soon to be added
         //break;
         case 3: cout<<"Calculator Program ended."<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(userChoice!=3);

    return 0;
}


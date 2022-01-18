#include <iostream>
using namespace std;

//Framework of a node datatype. 
//Automatically intializes with a value of 0 or 'a' and a pointer to adress 0x00.
//!User will not have access to Node structure!

template <typename T>
class Node {
private:
    Node* next_ptr;
    template <typename U> friend class SLList;
    Node() { 
        if (typeid(T) == typeid(char)) {
            value = '0';
        } else {
            value = 0;
        }
        next_ptr = NULL;
    }
public:
    T value;
};

//Class where the user will interact with. All class-related functions are here.

template <typename T>
class SLList {
private:
    Node<T>* head_ptr;
public:
    SLList(T user_value = T()) {
        head_ptr = new Node<T>();

        //If user inputs a value, it will change it to this value.
        if (user_value != T()) {
            head_ptr->value = user_value;
        }
    }

    void Print() {
        //Special case :: Trying to print a Listless List.
        if (head_ptr == NULL) {
            cout << "Error :: Trying to Print a Listless List (err.3)." << endl;
            return;
        }

        //Creates temp pointer that starts at the head of our Linked List.
        Node<T>* follow_ptr;
        follow_ptr = head_ptr;

        //Iterates through every node on our linked list.
        while(follow_ptr->next_ptr != NULL) {
            cout << follow_ptr->value << " -> ";
            follow_ptr = follow_ptr->next_ptr;
        }

        cout << follow_ptr->value << endl;
    }

    void PrintatIndex(int index) {

        //Special case :: Trying to print a Listless List.
        if (head_ptr == NULL) {
            cout << "Error :: Trying to Print a Listless List (err.1)." << endl;
            return;
        }

        //Creates a follow pointer, and a counter that keeps track of the index.
        Node<T>* follow_ptr;
        follow_ptr = head_ptr;
        int count = 0;

        bool Found_index = false;

        //Will iterate through the list until either it reaches the end or it arrives to the index.
        while (follow_ptr != NULL) {
            if (count == index) {
                Found_index = true;
                cout << follow_ptr->value << endl;
                break;
            }
            count += 1;
            follow_ptr = follow_ptr->next_ptr;
        }

        //If while-loop ends and count < index, it will send an error message to the user.
        if (!Found_index) {
            cout << "ERROR :: Index out of Bounds (err.2)." << endl;
        }
    }

    int Size() {
        //creates a size counter and a pointer that will follow the entire list.
        int size = 0;
        Node<T>* follow_ptr;
        follow_ptr = head_ptr;

        while (follow_ptr != NULL) {
            size += 1;
            follow_ptr = follow_ptr->next_ptr;
        }

        return size;
    }

    void Append(T user_value) {

        Node<T>* follow_ptr;
        follow_ptr = head_ptr;
        
        //Initializing new node and setting its pointer to NULL and its value to the user_inputed value.
        Node<T>* new_Node;
        new_Node = new Node<T>();
        new_Node->next_ptr = NULL;
        new_Node->value = user_value;
    
        //Special case :: inserting a new node on a listless list.
        if (head_ptr == NULL) {
            head_ptr = new_Node;
            return;
        }
    
        while(follow_ptr->next_ptr != NULL) {
            follow_ptr = follow_ptr->next_ptr;
        }
        
        //making the follow_ptr(the last pointer) point to the new node.
        follow_ptr->next_ptr = new_Node;
    }

    void Pop() {
        Node<T>* follow_ptr;
        follow_ptr = head_ptr;

        //Special case :: trying to delete a listless list.
        if (head_ptr == NULL) {
            cout << "Error :: Trying to Delete a Listless List (err.3)." << endl;
            return;
        }

        //Special case :: trying to delete the head itself.
        if (head_ptr -> next_ptr == NULL) {
            delete head_ptr;
            head_ptr = NULL;
            return;
        }

        while(follow_ptr->next_ptr->next_ptr != NULL) {
            follow_ptr = follow_ptr->next_ptr;
        }

        delete follow_ptr->next_ptr;
        follow_ptr->next_ptr = NULL;
    }

    void Detatch() {
        //Special case :: trying to delete a listless list.
        if (head_ptr == NULL) {
            cout << "Error :: Trying to Delete a Listless List (err.3)." << endl;
            return;
        }

        Node<T>* temp_ptr;
        temp_ptr = head_ptr->next_ptr;

        delete head_ptr;

        head_ptr = temp_ptr;
    }

    void Push(T user_value) {
        //Placeholder for this new pointer.
        Node<T>* tmp_ptr = head_ptr;

        //Creating new Node
        Node<T>* new_Node;
        new_Node = new Node<T>();
        new_Node->next_ptr = NULL;
        
        //Making head_ptr point to the new node.
        head_ptr = new_Node;
        //Making the pointer in the new Node point to the rest of the list.
        head_ptr->next_ptr = tmp_ptr;
        head_ptr->value = user_value;


    }

    void ClearList() {

        while (head_ptr != NULL) {
            Detatch();
        }
        delete head_ptr;
    }

    void InserteAtIndex(T user_value, int index){
        
        int size = Size();

        //Special Case :: Inserting Node at index 0 (head);
        if (index == 0) {
            Push(user_value);
            return;
        }

        //Special Case :: Inserting Node at last index (size - 1);
        if (index == size) {
            Append(user_value);
            return;
        }

        //Special Case :: Inserting Node out of Index (>size - 1);
        if (index >= size) {
            cout << "Error :: Attempting to Insert a Node That is Out of Bounds (err.4)." << endl;
            return;
        }

        //Creating new Node.4
        Node<T>* new_Node;
        new_Node = new Node<T>();

        //Initializing temporary pointers.
        Node<T>* temp = head_ptr;

        for(int i = 1; i < index; i++) {
            if(temp->next_ptr != NULL) {
                temp = temp->next_ptr;
            }
        }

        new_Node->next_ptr = temp->next_ptr;
        temp->next_ptr = new_Node;
        new_Node->value = user_value;

    }

    void RemoveAtIndex(int index) {

        int size = Size();

        //Special Case :: Inserting Node at index 0 (head);
        if (index == 0) {
            Detatch();
            return;
        }

        //Special Case :: Inserting Node at last index (size - 1);
        if (index == size - 1) {
            Pop();
            return;
        }

        //Special Case :: Inserting Node out of Index (>size - 1);
        if (index >= size - 1) {
            cout << "Error :: Attempting to Remove a Node That is Out of Bounds (err.5)." << endl;
            return;
        }

        //Creating new pointer.
        Node<T>* next_Node;

        //Initializing temporary pointers.
        Node<T>* temp = head_ptr;

        for(int i = 1; i < index; i++) {
            if(temp->next_ptr != NULL) {
                temp = temp->next_ptr;
            }
        }

        next_Node = temp->next_ptr->next_ptr;
        delete temp->next_ptr;

        temp->next_ptr = next_Node;

    }
    
    void ChangeValueAtIndex(T user_value, int index) {
        RemoveAtIndex(index);
        InserteAtIndex(user_value, index);
    }

};

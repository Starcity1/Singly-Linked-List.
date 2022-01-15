NAME :: SLList (Singly Linked List)

AUTHOR :: David Rodriguez Sanchez

VERSION :: 1.0.0

DESC :: This is my take on how to create a new Singledly Linked List. 
The code contains the basic structure of a Linked List in addition to some function methods
that will allow the user to insert/delete items in their list, as well as printing the values
of each node (or an specific node), and other functions described below.


USAGE :: 

- SLList<data_type> name_of_list(user_value) :: Initializes linked list with a default node of value 0.

- name_of_list.Print() :: Prints all values on the linked list.

- name_of_list.PrintatIndex(index) :: Prints the list's value at the index specified by the user.
!Similar to arrays, the first index for any list is 0.

-name_of_list.Size() :: returns how many notes are on the list.

-name_of_list.Append(user_value) :: Inserts a new node with a new value at the end of the list.

-name_of_list.Pop() :: Deletes the last node from your list. 
Sends error if user tries to delete a listless list.

-name_of_list.Push(user_value) :: Inserts a new node with a new value at the start of the list.

-name_of_list.ClearList() :: Entirely clears and frees all the memory created by the list.

-name_of_list.InsertNodeatIndex(user_value, <int>index) :: Inserts a value in front of the index
given by the user. It will return an error if user tries to insert a Node on an out-of-bounds index.

-name_of_list.RemoveNodeatIndeX(<int>index) :: Removes and deletes memory from the node at the index specified by user.
It will return an error if user tries to remoce a Node on an out-of-bounds index.

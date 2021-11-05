// Author: Will Torres
#include <stdio.h>
#include <stdlib.h>

struct node {
        // data field
        int data;
        // nextNode field
        struct node* nextNode;
};

/*
  struct node  myNode;
  printf("%d", myNode.data);
  printf("%p", myNode.nextNode);
*/


// FUNCTION      - allocate and create a new Node
// Precondition  - data exists
// Postcondition - Node allocated,  and ptr returned
struct node* createNode(int newData) {
        // must allocate memory for each node
        // because each nodes lifetime is longer than this function
        // *note must manually deallocate (free) each node when program is complete
        // memory for these nodes
        // must outlive this function call
        // myObj() => malloc()
        // ~myObj() => free()
        struct node* np = malloc(sizeof(struct node));
        // set the fields
        (*np).data = newData;
        (*np).nextNode = NULL;

        // return the pointer to this new Node
        return np;
}

// FUNCTION      - insert new Node into our linked List
//                 New Node inserted ahead of larger nodes
// Precondition  - ptr to list containing 0 or more nodes
// Postcondition - after insertion list is always sorted
struct node* insertNode(struct node* list, int data) {
        // defining our reference data
        // new node to be inserted
        struct node* np;
        // previous node
        struct node* prev = NULL;
        // current beginning of LL
        struct node* head = list;
        // current node
        struct node* lp = list;


        // create a new Node
        np = createNode(data);

        //check if this is our first node
        if(list == NULL) {
                //start the list with this node since it's empty
                head = np;
                lp = np;

                //return new head pointer, since list was empty now head is np
                return head;
        }


        // MOVE TO WHILE LOOP
        // while list pointer isn't at the end
        while( lp != NULL ) {
                // if our current node data is larger than the new node data
                // insert into list before current node
                if( (*lp).data > (*np).data) {
                        // insert new node into list by setting it's next node to current node
                        (*np).nextNode = lp;
                        // check if this is NOT the beginning of the list
                        if(lp != head) {
                                // it's not, so remember to set last node to point to new node
                                (*prev).nextNode = np;
                        } else {
                                // it is! cool, set head to new node
                                head = np;
                        }
                        // send back the beginning of the list
                        return head;
                }
                // what's the case for this 'else'?
                // our current node data is smaller than the new node data
                else {
                        // current node was smaller than new node
                        // lets check if we're at the end yet
                        if((*lp).nextNode == NULL ) {
                                // add new node to end of the list
                                (*lp).nextNode = np;
                                // head didn't change, but return it anyway because we're done here
                                return head;
                        }
                        // move the loop along because we aren't at the end of the list yet
                        prev = lp;
                        lp = (*lp).nextNode;
                }
        }
        // list ended for some reason...
        // probably shouldn't ever reach this code...
        // if we inserted the new node into the list, we would have returned head already...
        // hmm...
        fprintf(stderr, "ERROR: WE DIDN'T INSERT OUR NEW NODE FOR SOME REASON...");
        return head;
}

// FUNCTION      - call free on every node in our list from back to front
// Precondition  - ptr to list containing 0 or more nodes
// Postcondition - return 0 on all nodes mem freed
// FREE EACH POINTER FROM END OF LIST TO FRONT
int freeListMemory(struct node* list) {
        // Omer helped with this

        // Call the node stack
        struct node* lp = list;
        struct node* temp = NULL;
        
        // loop through each node, frees each node in the list
        while(list) {
                temp = lp;
                free(lp);
                free(temp);
        }

        //on success
        return 0;
}

//
// COMPLETE
// DO NOT EDIT
//
int main() {
        // insert create 7 data points
        int data1 = 6;
        int data2 = 4;
        int data3 = 3;
        int data4 = 1;
        int data5 = 5;
        int data6 = 7;
        int data7 = 2;

        // create POINTER to front of list
        struct node *ptrHead;
        ptrHead = NULL;

        // insert each data point into the list
        ptrHead = insertNode(ptrHead, data1);
        ptrHead = insertNode(ptrHead, data2);
        ptrHead = insertNode(ptrHead, data3);
        ptrHead = insertNode(ptrHead, data4);
        ptrHead = insertNode(ptrHead, data5);
        ptrHead = insertNode(ptrHead, data6);
        ptrHead = insertNode(ptrHead, data7);



        // create list pointer for our loop
        struct node *lp = ptrHead;

        // Here we ASSUME list is non-empty
        while( lp != NULL) {
                // print out the data for this node
                printf("%d\n", (*lp).data);

                // set the list pointer to the next node in the list
                lp = (*lp).nextNode;

        }


        // FREE EACH POINTER FROM END OF LIST TO FRONT (reverse order)
        int freed = freeListMemory(ptrHead);

        return freed;
}
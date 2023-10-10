#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

struct Node{
    char *data;
    struct Node *next;
};

struct Linkedlist {
    struct Node *head;
};

void insertAtBeginning(struct Linkedlist* LL, char ele[]);
void insertAtTheEnd(struct Linkedlist* LL, char ele[]);
void deleteNode(struct Linkedlist* LL, char ele[]);
int findNode(struct Linkedlist LL, char ele[]);
void displayLinkedList(struct Linkedlist LL);

int main(int argc, char *argv[]) {
    int i;
    struct Linkedlist LL;
    LL.head = NULL;

    if (argc == 1) {
        printf("ERROR: The program must read at least an argument.\n");
        return 0;
    }

    for (i = 1; i<argc; i++) {
        if (findNode(LL, argv[i])) {
            deleteNode(&LL, argv[i]);
        }
        else if (isupper(argv[i][0])) {
            insertAtBeginning(&LL, argv[i]);
        }
        else {

            insertAtTheEnd(&LL, argv[i]);
        }
    }

    displayLinkedList(LL);

    // Free the whole Linkedlist
    // Free each data and then free each node
    //Please consider how to write this part to get some extra bonus points.

    return 1;
}

void insertAtBeginning(struct Linkedlist* LL, char ele[]){
    /*
     * Takes a pointer to the struct, and a string
     * Allocates a node using malloc or calloc()
     * Inserts string at the beginning of the LL
     *  For data, get size using strlen(), allocate the string, and then copy the string to it using strcpy()
     */

    if(LL -> head != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode -> next = NULL;
        newNode -> data = calloc(1, strlen(ele));
        strcpy(newNode -> data, ele);

        newNode -> next = LL->head;
        LL->head = newNode;
    }
    else{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode -> next = NULL;
        newNode -> data = ele;
        LL->head = newNode;
    }
};
void insertAtTheEnd(struct Linkedlist* LL, char ele[]){
    /*
     * Takes a pointer to the struct, and a string
     * Allocates a node using malloc or calloc()
     * Inserts string at the end of the LL
     *  For data, get size using strlen(), allocate the string, and then copy the string to it using strcpy()
     */
    if(LL -> head != NULL) {
        struct Node* indexPtr = (struct Node*)malloc(sizeof(struct Node));
        indexPtr -> next = LL -> head;
        while (indexPtr -> next->next != NULL) {
            indexPtr -> next = indexPtr -> next->next;
        }

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode -> next = NULL;
        newNode -> data = calloc(1, strlen(ele));
        strcpy(newNode -> data, ele);

        indexPtr -> next->next = newNode;
    }
    else{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode -> next = NULL;
        newNode -> data = ele;
        LL->head = newNode;
    }
};

void deleteNode(struct Linkedlist* LL, char ele[]){
    /*
     * Takes a pointer to struct and a string
     * Removes the node with the string in its data from the LL and frees its space
     * Free the string's space too?
     */

    struct Node* indexPtr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
    indexPtr -> next = LL -> head;

    //Check Head
    char *temp = LL -> head -> data;
    if(!strcmp(temp, ele)){
        tempNode -> next = LL -> head ->next;
        free(LL -> head);
        LL -> head = tempNode;
    } //Head is not ele
    else{
        while (indexPtr -> next->next->data != NULL) {
            char* temp2 = indexPtr -> next->next->data;
            if (!strcmp(temp2, ele)) {

                tempNode -> next = indexPtr -> next->next->next;

                free(indexPtr -> next->next);

                indexPtr -> next->next = tempNode -> next;

                break;
            }
            indexPtr -> next = indexPtr -> next->next;
        }
    }
};

int findNode(struct Linkedlist LL, char ele[]){
    /*
     * Takes a structure LL and a string
     * Return 1 if ele exists, otherwise return 0
     */
    if(LL.head != NULL) {
        struct Node* indexPtr = (struct Node*)malloc(sizeof(struct Node));
        indexPtr->data = LL.head->data;
        indexPtr->next = LL.head->next;

        while (indexPtr->next != NULL) {
            char *temp = indexPtr -> data;
            if (!strcmp(temp, ele)) {
                return 1;
            } else {
                indexPtr->data = indexPtr->next->data;
                indexPtr->next = indexPtr->next->next;
            }
        }
        //Check last/One item
        char *temp = indexPtr -> data;
        if(temp == ele){
            return 1;
        } else {
            return 0;
        }

    }
    else{
        return 0;
    }
};

void displayLinkedList(struct Linkedlist LL){
    /*
     * Takes a struct LL and prints all the nodes data seperated by commas
     */

    struct Node* indexPtr = (struct Node*)malloc(sizeof(struct Node));
    indexPtr->data = LL.head -> data;
    indexPtr->next = LL.head -> next;

    while(indexPtr->next -> next != NULL) {
        printf("%s, ", indexPtr->data);

        indexPtr->data = indexPtr->next->data;
        indexPtr->next = indexPtr->next->next;
    }

    printf("%s, %s", indexPtr -> data, indexPtr->next -> data);
};
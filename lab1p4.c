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

};
void insertAtTheEnd(struct Linkedlist* LL, char ele[]){

};
void deleteNode(struct Linkedlist* LL, char ele[]){

};
int findNode(struct Linkedlist LL, char ele[]){

};
void displayLinkedList(struct Linkedlist LL){

};
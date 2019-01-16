#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct NODE
{
 struct NODE *link;
 int value;
 int valid;
}NODE;

typedef struct NODE Node;

#include "newLLfunctions.c"

int main()
{
 Node *HeadPtr = NULL;
 Node *pointer = NULL;
 
 int j;
 insertFirst(&HeadPtr, 5 );
 insertFirst(&HeadPtr, 12 );
 insertFirst(&HeadPtr, 7 );
 insertFirst(&HeadPtr, 18 );
 insertFirst(&HeadPtr, 2 );
 insertFirst(&HeadPtr, 9 );

 
 printf("\nList printed in order of insert: \n");
 traverseAll(HeadPtr); printf(" \n");
 
 printf("\nNumber of valid nodes: %d\n", countNodes(HeadPtr));
 
 printf("\nTest of delete first:\t");
 deleteFirst(HeadPtr); /* should delete 9 */
 deleteFirst(HeadPtr);
 
 traverse(HeadPtr); printf(" \n");
 
 printf("\nNumber of valid nodes: %d\n", countNodes(HeadPtr));
 
 printf("\nTest of delete Last:\t");
 deleteLast(HeadPtr); /* should delete 5 */
 
 traverse(HeadPtr); printf(" \n");
 
 printf("\nNumber of valid nodes: %d\n", countNodes(HeadPtr));
 
 printf("\nTest of delete value:\t");
 deleteValue(HeadPtr, 2);
 
 traverse(HeadPtr); printf(" \n");
 
 printf("\nNumber of valid nodes: %d\n", countNodes(HeadPtr));
 
 traverseAll(HeadPtr);
 
 restoreValue(HeadPtr, 2);
 
 traverseAll(HeadPtr);
 
 compact(HeadPtr, &pointer);
 
 traverseAll(pointer);
 
 
 /* frees all nodes of the list */
 freeList(HeadPtr);
}

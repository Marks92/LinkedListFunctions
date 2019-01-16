/* CS 153 PROGRAM ASSIGNMENT #11

Program that creates 10 functions for a
linked list that holds two values, one is
a normal int value, the other being an int 
valid which declares whether the node is "valid"
when set to 1 or "not valid" when set to 0. Some
functions will "delete" valid nodes by setting int valid
to 0 and other functions will differentiate between valid 
and not valid nodes.

Mark Schuberth 
 
12/8/2018 */


/* inserts a node to the front of the list */
int insertFirst(Node **ptrToHeadPtr, int val)
{
  Node *node = (Node *)malloc( sizeof(Node));
  node->value = val;
  /* initially sets each node valid = 1 */
  node->valid = 1;
  node->link = *ptrToHeadPtr;
  *ptrToHeadPtr = node;
  
  return 1;
}

/* traverse only valid nodes */
void traverse(Node *ptrToFirst)
{
 Node* temp = ptrToFirst;
 
  //Node* ptrToFirst = ptrToFirst;
  while(temp != NULL)
  {
   if(temp->valid == 1)
   {
    /* print each valid node */
    printf(" %d ", temp->value);
   }
   /* continue looping whether valid or not */
   temp = temp->link;
  }
}

/* traverse all nodes valid or not */
void traverseAll(Node *ptrToFirst)
{
 while(ptrToFirst != NULL)
 {
  if(ptrToFirst->valid == 1)
  {
   printf(" %d ", ptrToFirst->value);
  }
  else
  {
   printf(" *%d, ", ptrToFirst->value);
  }
  ptrToFirst = ptrToFirst->link;
 }
}

/* "deletes" node by changing valid to 0 */
int deleteFirst(Node *ptrToFirst)
{
 if(ptrToFirst == NULL)
 {
  return 0;
 }
 
 /* traverses list */
 while(ptrToFirst != NULL)
 {
  /* if we find a valid node */
  if(ptrToFirst->valid = 1)
  {
   /* flag node as invalid */
   ptrToFirst->valid = 0;
   return 1;
  }
  else
  {
   /* otherwise continue to traverse list */
   ptrToFirst = ptrToFirst->link;
  }
 }

 return 0;
}

/* count all valid nodes */
int countNodes(Node *ptrToFirst)
{
 int count = 0;
 while(ptrToFirst != NULL)
 {
  /* counts valid nodes in the list */
  if(ptrToFirst->valid == 1) count++;
  ptrToFirst = ptrToFirst->link;
 }
 /* return count */
 return count;
}

/* make last valid node invalid */
int deleteLast(Node *ptrToFirst)
{
 if(ptrToFirst == NULL)
 {
  return 0;
 }
 /* make temporary values to traverse list */
  Node *temp = ptrToFirst;
  Node *t = NULL;
 while(temp != NULL)
 {
  if(temp->valid == 1)
  {
   t = temp;
  }
  /* keep traversing list for valid nodes */
  temp = temp->link;
 }
 /* if there are no valid nodes return 0 */
 if(t == NULL)
 {
  return 0;
 }
 else
 {
  /* last valid node is now logically deleted */
  t->valid = 0;
  return 1;
 }

 return 0;
}

/* delete the value of the target valid node */
int deleteValue(Node *ptrToFirst, int val)
{
 if(ptrToFirst == NULL)
 {
  return 0;
 }
 
 while(ptrToFirst != NULL)
 {
  /* if the node is valid and makes value */
  if(ptrToFirst->valid == 1 && ptrToFirst->value == val)
  {
   /* logically delete valid node */
   ptrToFirst->valid = 0;
   return 1;
  }
  ptrToFirst = ptrToFirst->link;
 }
 
 return 0;
}

/* undelete value by making node valid */
int restoreValue(Node *start, int val)
{
 if(start == NULL)
 {
  return 0;
 }
 
 while(start != NULL)
 {
  /* if the node is not valid and target value matches */
  if(start->valid == 0 && start->value == val)
  {
   /* make the node valid again */
   start->valid = 1;
   return 1;
  }
  start = start->link;
 }
 
 return 0;
}

/* make a new list of just valid nodes */
int compact(Node *old, Node **ptrToNewHeadPtr)
{
 if(old == NULL)
 {
  return 0;
 }
 
 Node *temp = old;
 while(temp != NULL)
 {
  /* insert all valid nodes into a new list */
  if(temp->valid == 1)
  {
   /* use insertFirst again to find valid nodes */
   insertFirst(ptrToNewHeadPtr, temp->value);
  }
  temp = temp->link;
 }
 
 return 0;
}

/* free memory */
void freeList(Node *ptrToNewHeadPtr)
{
 Node *temp;
 while(ptrToNewHeadPtr != NULL)
 {
  temp = ptrToNewHeadPtr;
  ptrToNewHeadPtr = ptrToNewHeadPtr->link;
  free(temp);
 }
}


/**
 * @file: doubleLinkedList.c
 * @authors Paul Murphy 21334889, Luke Griffin 21334528, Michael Cronin 21329001, Patrick Crotty 21336113, Taha Al-Salihi 21302227
 * Implementation of DoubleLinked List and Its Functions
 *
 * @date: 29 Nov 2022
 */
 
// UPDATED BY TAHA ON 2/12/2022 READ EVERYTHING IN COMMENTS FOR REF.

#include "doubleLinkedList.h"

/**
 * @brief creates an empty linked list, head points to tail
 * which is implemented as NULL
 *
 * @return pointer to list if success
 * pointer to NULL on failure
 */
llist *createDoubleLinkedList()
{
  llist *list;
  list = (llist *) malloc(sizeof(llist));
  // check for allocation success
  if (list != NULL) {
    // attempt to allocate memory for head and tail
    list->head = (llnode *) malloc(sizeof(llnode));
    list->tail = (llnode *) malloc(sizeof(llnode));
    if ((list->head != NULL)&&(list->tail !=NULL)) {
      // allocation successfull, satisfy condition
      // that head points to tail (which is doesn't have a value associated with it,NULL) and current is head
      list->head->next=list->tail;
      list->current = list->head;
   
    }
    else {
      free(list);
      list = NULL;
    }
  }
  return list;
  }

/**
 * @brief deletes the entire list of which
 * head is head-node
 *
 * @param list pointer to valid list
 */
void deleteDoubleLinkedList(llist *list)
{
      llnode *temp;
  // delete all nodes until list is empty
  // start at beginning of list
  list->current = list->head;
  // iterate through all nodes in list and delete them
  while (list->current->next != list->tail) {//(list->head->next != list->tail) {
    temp = list->current->next;
    list->current->next = list->current->next->next;
    free(temp);
    temp = NULL;
  }
  free(list->head); // deletes head
  free(list->tail); // deletes tail
  free(list);       // deletes list
}

/**
 * @brief returns data of current nod
 * @param list list to be accessed
 *
 * @return NULL if @ head or Tail else
 * return data
 */
data *getData(llist *list)
{
  // is current head or tail?
  if (list->current != list->head && list->current != NULL) {
    // no, return data
    return &(list->current->d);
  } else {
    // yes, return NULL
    return NULL;
  }
}

/**
 * @brief sets current node of list to its successor
 * @param list lsit to be moved along
 *
 * @return result and whether its 'ok' or 'Illegal'
 */
llError gotoNextNode(llist *list)
{
  llError result = ok;
 
  // is  current tail?
  if (list->current!=list->tail) {
    // no -> move forward
    list->current=list->current->next;
   
  } else {
    // reached end of list, cannot move any further
    result = illegalNode;
  }
  return result;
}

/**
 * @brief sets current node of list to its presuccessor
 * @param list lsit to be moved along
 *
 * @return result and whether its 'ok' or 'Illegal'
 */
llError gotoPreviousNode(llist *list)
{
  llError result = ok;
 //is current node head?
  if (list->current!=list->head ) {
      //if not ->move backwards
    list->current=list->current->prev;
  } else {
    // reached end of list, cannot move any further
   result = illegalNode;
  }
  return result;
}

/**
 * @brief sets current node of list to head
 *
 * @param list list to be set to head
 */
void gotoHead(llist *list)
{
  // set current node to head
  list->current = list->head;
}

/**
 * @brief sets current node of list to Tail
 *
 * @param list list to be set to Tail
 */
void gotoTail(llist *list)
{
    //set the node to tail
    list->current = list->tail;
}

/**
 * @brief reates a new node newnode, associates data d with
 * newnode and inserts newnode in linse as successor of
 * current node
 *
 * @param d data to be associated with newnode
 * @param list list into which to insert
 * @return ok if insertion successful or
 * noMemory if no memory available to create newnode
 */
llError insertAfter(data *d, llist *list)
{
  llError returnvalue = ok;
  llnode *newnode;
  // create new node
  newnode = (llnode *) malloc(sizeof(llnode));
  // allocation successful?
  if (newnode == NULL) {
    // allocation un successful and is failure
    returnvalue = noMemory;
  }
  else if (list->current==list->tail){
    returnvalue=illegalNode;
  }
  else {
    // allocation successful
    // associate data d with newnode
    newnode->d = *d;
    // link newnode into linked list
    // 1. set next of newnode to current nodes's next
    newnode->next = list->current->next;
    //2.set prev of newnode to current node
    newnode->prev=list->current;
    //set current next to newnode
    list->current->next=newnode;
    //navigate to original next of current node and set prev to newnode
    gotoNextNode(list);
    gotoNextNode(list);
    list->current->prev=newnode;
    //returing to current node
    gotoPreviousNode(list);
    gotoPreviousNode(list);
  }
  return returnvalue;
}

/**
 * @brief reates a new node newnode, associates data d with
 * newnode and inserts newnode in linse as presuccessor of
 * current node
 *
 * @param d data to be associated with newnode
 * @param list list into which to insert
 * @return ok if insertion successful or
 * noMemory if no memory available to create newnode
 */
llError insertBefore(data *d, llist *list)
{
  llError returnvalue = ok;
  llnode *newnode;
  // create new node
  newnode = (llnode *) malloc(sizeof(llnode));
  // allocation successful?
  if (newnode == NULL) {
    // allocation failure
    returnvalue = noMemory;
  }
  else if (list->current==list->head){
      returnvalue=illegalNode;
  }
  else {
    // allocation successful
    // associate data d with newnode
    newnode->d = *d;
    // link newnode into linked list
    //1.set newnode prev to current prev
    newnode->prev = list->current->prev;
    //2.set newnode next to current node
    newnode->next=list->current;
    //set current's prev to newnode
   list->current->prev = newnode;
   //Navigate to original prev and set next to newnode
    gotoPreviousNode(list);
    gotoPreviousNode(list);
    list->current->next=newnode;
    //return to original current node
    gotoNextNode(list);
    gotoNextNode(list);
  }
  return returnvalue;
}

/**
 * @brief deletes values in current node when list called
 *
 * @param list for node to be deleted
 * @return result and whether its 'ok' or 'Illegal'
 */
llError deleteCurrent(llist *list)
{
  llError result = ok;
  llnode *todelete;
  if ((list->current== list->tail)||(list->current == list-> head)) {
    // cannot delete head or tail
    result = illegalNode;
  } else {
    //  keep pointer to node to be deleted
    todelete = list->current;
    // set current to prev of node to be deleted
    list->current=list->current->prev;//setting current node to prev
    // set current next to node after node to be deleted
    list->current->next = todelete->next;
    //  delete node from memory
    free(todelete);
  }
  return result;
}

 
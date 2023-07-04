/**
 * @file: doubleLinkedList.h
 * @authors Paul Murphy 21334889, Luke Griffin 21334528, Michael Cronin 21329001, Patrick Crotty 21336113, Taha Al-Salihi 21302227
 * header file for DoubleLinked List
 * 
 * @date: 29 Nov 2022
 */
 

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * define error codes for linked list
 */
typedef enum {
    ok, ///< No error
    illegalNode, ///< attempt to access an illegal node
    noMemory ///< system cannot allocate &rarr; out of memory

} llError;

/**
 * define return values associated with set 
 * 
 */
typedef enum {
	NUMBER_ALREADY_IN_SET, ///< Element already in set 
	NUMBER_NOT_IN_SET, ///< Element not in set 
	NUMBER_ADDED, ///< Element has been added to the set 
	NUMBER_REMOVED, ///< Element has been removed from set 
	ALLOCATION_ERROR ///< Error from dynamic data structure preventing insertion of new element 
	
} setError;

/**
 * define structure for set to be stored in ordered int sets
 */
typedef struct {
   
    int *members; // Pointer of elements in set 
    int len;      //Lenght of the set 
   
} Set;

/**
 * define structure for data to be stored in linked
 * list
 */
typedef struct {
  Set *members;
} data;

/**
 * define structure for a node of a linked list
 */
typedef struct n {
  data d; ///< store some data in node
  struct n *next; /**< store successor(next) of node
               as typedef is not yet completed
               name llnode cannot be used*/
  struct n *prev;/**< store presuccessor(prev) of node*/
} llnode;

/**
 * define type for linked list
 */
typedef struct {
  llnode *head; ///< pointer to head of list
  llnode *current; ///< current node of list
  llnode *tail;///<pointer to tail of list
} llist;



/*
 * function declarations
 */
llist *createDoubleLinkedList();
void deleteDoubleLinkedList(llist *list);
data *getData(llist *list);
llError gotoNextNode(llist *list);
llError gotoPreviousNode(llist *list);
void gotoHead(llist *list);
void gotoTail(llist *list);
llError insertAfter(data *d, llist *list);
llError insertBefore(data *d, llist *list);
llError deleteCurrent(llist *list);


Set* createOrderedSet();
void deleteOrderedSet(Set *set);
setError addElements(Set *set, int elem);
setError removeElement(Set* set,int elem);
Set *setUnion(Set *s1, Set *s2);
Set *setIntersection(Set * s1, Set * s2);
Set *setDifference(Set * s1, Set * s2);
void sortSet(Set * set);
void printset(Set *set);

#endif
/**
 * @file: orderedIntSet.c
 * @authors Paul Murphy 21334889, Luke Griffin 21334528, Michael Cronin 21329001, Patrick Crotty 21336113, Taha Al-Salihi 21302227
 * file with main() to test double Linked List and its Functions
 * 
 * @date: 29 Nov 2022
 */
#include "doubleLinkedList.h"


/**
 * @brief Creates an empty ordered set which contains no elements
 * 
 * @return newSet Pointer of the newly created empty set 
 */
 Set* createOrderedSet()
 {
     Set *newSet = malloc(sizeof(Set));     // Create the set   
     newSet->len = 0;                       // Make number of elements in set to zero
     newSet->members = malloc(sizeof(int)); // Allocate memory for the members of the set 
     
     
     return newSet;
 }
 
 /**
  * @brief Deletes the oredered set from memory 
  * 
  * @param set Pointer to the memeory adress of the set 
  */
 void deleteOrderedSet(Set *set)
 {
         if(set != NULL)                            // if the set is not null
         {
             free(set);                             // De-allocate the memory associated with set
             printf("Set has been deleted!\n");
         }
         
 }
 
 /**
  * @brief Adds new elements into the correct location of oredered set. 
  * Only adds elements which are not already in the set.
  * 
  * @param set Pointer to the memory address of the set  
  * @param elem Integer to be added to set 
  * @return status NUMBER_ADDED if element has been added or NUMBER_ALREADY_IN_SET if element was already present 
  */
 setError addElements(Set *set, int elem)
 {
     setError status = NUMBER_NOT_IN_SET; 
     
     for(int i = 0; i < set->len; i++)          // for i less than the number of elements in set 
     {
         if(set->members[i] == elem)            // if elem being added is already in set 
         {
             status = NUMBER_ALREADY_IN_SET;    // return enum NUMBER_ALREADY_IN_SET
         }
       
     }
     
     if(status == NUMBER_NOT_IN_SET)            // If the elem being added is not already if set   
     {
         set->members = realloc(set->members, sizeof(int) * (set->len + 1));    // Change the memory size of set to allow for new elem
         set->members[set->len] = elem;         // Assign the elem a place in the memory set 
         set->len = set->len + 1;               // Increase the lenght of the set by 1
         
     }
     
     sortSet(set);                           // Re-arrange the set in ascending order  
     
     
     return status;                             // return the status 
 }          
 
 /**
  * @brief Removes the number element from the set 
  * @param set Pointer to the memory address of the set 
  * @param elem Integer to be removed from the set 
  * @return status NUMBER_REMOVED if elem has been in set or NUMBER_NOT_IN_SET if not
  */
 setError removeElement(Set *set, int elem)
 {
     
      setError status = NUMBER_NOT_IN_SET;
      int i,j, pos;                                     // Create local variables for loop
     for(i = 0; i < set->len; i++)                      // for i from 0 to the lenght of the set
     {
         if(elem == set->members[i])                    // if elem is already in set
         {
             pos = i;                                   // Assign i to the pos
            status = NUMBER_ALREADY_IN_SET;             

         }
         
         //If the element being passed is in the set remove it 
          if(status == NUMBER_ALREADY_IN_SET)          
          {   
              // Iterate through the set to find the match    
              for(j = pos; j < set->len - 1 ; j++)       
              {                                         
                  set->members[j] = set->members[j+1];  // swaps the numbers in the sets with a different location and exludes the elem that needs to be removed
                  status = NUMBER_REMOVED;              
              }
               
          }
     }
     
      set->members = realloc(set->members, sizeof(int) * (set->len - 1)); // Remove the memory of the extra memory address  
      set->len = set->len -1;                           // Reduce the lenght of the set by 1 

     if(status == NUMBER_NOT_IN_SET)                    // if the elem is not in the set 
     {
         printf("Number is not in this set.");          // Inform the user 
     }
     
     return status;                                     // return status 
 }
 
 /**
  * @brief Creates new set which contains all elements in set s1 or s2
  * 
  * @param s1 Pointer of set to be combined in newSet 
  * @param s2 Pointer of set to be combined in newset 
  * 
  * @return newSet Containing all elements in s1 or s2
  */
 Set *setUnion(Set *s1, Set *s2)
 {
     Set *newSet = createOrderedSet();          // Create the newSet using createOrderedSet() function 
     
     for(int i = 0; i < s1->len; i++)           // for i from 0 to the lenght of set s1
     {
         addElements(newSet, s1->members[i]);   // Add the elements in s1 to the newSet
     }
     
     for(int i = 0; i < s1->len; i++)           // for i from 0 to the lenght of set s2
     {
         addElements(newSet,s2->members[i]);    // Add the elements in s2 to the newSet
     }
     
     return newSet;                             // return the newSet     
 }

/**
 * @brief Creates a new set of elements which are in s1 and s2
 * 
 * @param s1 Pointer of set to be checked for the same elements as s2
 * @param s2 Pointer of set to be checked for the same elements as s1
 * 
 * @return newSet Containing elements that are in s1 and s2
 */
Set *setIntersection(Set * s1, Set * s2)
{
    Set * newSet = createOrderedSet();                  // Create the newSet using createOrderedSet() function 
   
    for(int i = 0; i < s1->len; i++)                    // for i from 0 to the lenght of set s1
    {
        for( int j = 0; j < s2->len; j++)               // for j from 0 to the lenght of set s2
        {
            if(s1->members[i] == s2->members[j])        // if the elements in the s1 and s2 are the same 
            {
                addElements(newSet, s1->members[i]);    // Add the elements to the newSet 
            }
           
        }
    }
   
    return newSet;                                      // return the newSet 
}

/***
 * @brief Creates a new set with elements that are in s1 but not in s2
 * 
 * @param s1 Pointer of set to be checked if it has any of the same alements as s2
 * @param s2 Pointer of set to be compared to S1
 * 
 * @return newSet Contains all elements that are in s1 but not in s2
 */
Set *setDifference(Set * s1, Set * s2)
{
    Set * newSet = createOrderedSet();              // Create the newSet using createOrderedSet() function
   
   
    for(int i = 0; i < s1->len; i++)                // for i from 0 to the lenght of set s1
    {
        bool in_s2 = false;                         // Create bool to check in s1 are equal to elements in s2 and initialise false 
       
        for(int j = 0; j < s2->len; j++)            // for j from 0 to the lenght of set s1
        {
            if(s1->members[i] == s2->members[j])    // if elements of s1 and s2 are equal set in_s2 to true
            {
                in_s2 = true;
            }
           
           
        }
       
            if(!in_s2)                              // in_s2 is false (elements in s1 but not in s2)                              
            {
                addElements(newSet, s1->members[i]);// Add the elements to the newSet
            }
    }
   
    return newSet;                                  // return the newSet
}

/**
 * @brief Selection Sort to re-arrange the set in ascending order 
 * @param set Pointer to the memory address of the set 
 */
void sortSet(Set * set)
{
    for(int i = 0; i < set->len - 1;i++)                // for i from 0 to the lenght of set s-1
    {
           
         int min = i;                                   // Index of smallest element
         
         for(int j = i + 1; j< set->len;j++)            // Search for the smallest element
         {
             if(set->members[min] > set->members[j])
             {
                 min = j;
             }
         }
            // Swap smallest and i-th elements 
            int temp = set->members[i];                 
            set->members[i] = set->members[min];
            set->members[min] = temp;
     }
     
}

/**
 * @brief Prints the elements in a given set 
 * @param set Pointer to the memory address of the set 
 */
void printset(Set *set)
{
     printf("{%d", set->members[0]);       // Print tout the first element of the set 
     for(int i = 1; i < set->len; i++)      // for i from 1 to the lenght of the set, increment i
     {
         printf(" %d", set->members[i]);   // print out the element at position i of the set 
     }
     printf("}\n");                         
 }
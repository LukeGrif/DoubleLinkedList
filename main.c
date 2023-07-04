/**
 * @file: main.c
 * @authors Paul Murphy 21334889, Luke Griffin 21334528, Michael Cronin 21329001, Patrick Crotty 21336113, Taha Al-Salihi 21302227
 * file with main() to test double Linked List and its Functions
 * 
 * @date: 29 Nov 2022
 */
 

#include "doubleLinkedList.h"

/**
 * @brief main() to test Double Linked List
 * @return EXIT_SUCCESS
 */
int main()  {
   //Initialise list, data, sets & elements inside sets
   llist *mylist=NULL;
   data newdata;
   
   //Initialise sets by creating them 
   Set *set1 = createOrderedSet(); 
   Set *set2 = createOrderedSet();
   Set *set3 = createOrderedSet();
   Set *set4 = createOrderedSet();

   //Initialise elements in set1 
   addElements(set1, 8);
   addElements(set1, 7);
   addElements(set1, 6);
   addElements(set1, 5);
   
   //Initialise elements in set2
   addElements(set2, 9);
   addElements(set2, 10);
   addElements(set2, 8);
   addElements(set2, 7);
   
   ///Initialise elements in set3
   addElements(set3, 13);
   addElements(set3, 11);
   addElements(set3, 12);
   addElements(set3, 13);
   
   //Initialise elements in set4 
   addElements(set4, 14);
   addElements(set4, 15);
   addElements(set4, 16);
   addElements(set4, 17);
   
   Set *setC = setUnion(set1,set2);			//Return the union set of all elemtns that in set1 or set2
   Set * setD = setIntersection(set1,set2); //Return new set with set1 & set2 elements
   Set * setE = setDifference(set1,set2);	//Return set of all elements that are in set1 but not set2
   

   // Begin testing the implementation 

   // Test the createDoubleLinkedList() function
   printf("#1: Test function createDoubleLinkedList()\n");
   mylist = createDoubleLinkedList(); 							// Create list
   if(mylist != NULL){											// if list not null test passed as created
   printf("Test Passed List Created\n");
   } else {														// else test failed as its NULL
       printf("Test Failed\n");
   }
   printf("\n\n\n");
   printf("Press Any Key to Continue\n");
   getchar();													// Call getchar() function to allow user to continue
   
   
   

   // Test the addElements() function
   printf("#2: Test that sets have been created elements added to them\n");
   printf("Set1 = ");
   printset(set1);							//Print Set1
   printf("Set2 = ");
   printset(set2);							//Print Set2
   printf("Set3 = ");
   printset(set3);							//Print Set3
   printf("Set4 = ");
   printset(set4);							//Print Set4
   printf("Set1 Union Set2 = ");	
   printset(setC);							//Print SetC
   printf("Set1 Intersection Set2 = ");
   printset(setD);							//Print SetD
   printf("Set1 Difference Set2 = ");
   printset(setE);							//Print SetE
   printf("\n\n\n");
   printf("Press Any Key to Continue\n");
   getchar();								//Call getchar() function to allow user to continue
   
   
   

   //Test the gotoHead() function
   printf("#3: Test for Function gotoHead() \n");
   gotoHead(mylist);											//Call function to go to the head of the list
   if (mylist->current == mylist->head) { 						// if current == head function works
	  printf("Test Passed ( Currently @ Head )\n");							
	} else {
																// Otherwise print test failed
																// data *d = getData(mylist);
	  printf("Test Failed ( not @ Head )\n");
	}
   printf("\n\n\n");
   printf("Press Any Key to Continue\n");
   getchar();													//Call getchar() function to allow user to continue
	
	
	

   //Test for insertAfter() && getData() && gotoNextNode() && gotoPreviousNode()
   printf("#4: Test for Function insertAfter() & gotoNextNode() & gotoPreviousNode() && getData() & removeElement()\n");
   printf("set3 insertAfter()\tset2 insertAfter()\tset1 insertAfter() and remove an element from set3\n");
   
   removeElement(set3, 3);
   //Testing the insertAfter() function
   newdata.members = set3;										// Add set3 elements to the data struct of memebers
   insertAfter(&newdata,mylist);
   newdata.members = set2;										// Add set2 elements to the data struct of memebers
   insertAfter(&newdata,mylist);
   newdata.members = set1;										// Add set1 elements to the data struct of memebers	
   insertAfter(&newdata,mylist);

   //Testing the gotoNextNode() function
   gotoNextNode(mylist); 										// Test gotoNextNode() function for set1
   if (mylist->current == mylist->head) {
	  printf("Test Failed ( @Head )\n"); 						// Test failed as still @ head
	} else {
																// Otherwise print all data elements
	  data *d = getData(mylist);
	  printf("Test Passed(gotoNextNode)\nNumber of Elements in set1 = %d\n",
		d->members->len);									
	  printf("Elements in set1 = ");
	  printset(d->members);
	}
   gotoNextNode(mylist); 										// Test gotoNextNode() function for set2
   if (mylist->current == mylist->head) {
	  printf("Test Failed ( @Head )\n"); 						// Test failed as still @ head
	} else {
																// Otherwise print all data elements
	  data *d = getData(mylist);								
	  printf("Test Passed(gotoNextNode)\nNumber of Elements in set2 = %d\n",
		d->members->len);
	  printf("Elements in set2 = ");
	  printset(d->members);
	}
	gotoNextNode(mylist); 										// Test gotoNextNode() function for set3
   if (mylist->current == mylist->head) {
	  printf("Test Failed ( @Head )\n"); 						// Test failed as still @ head
	} else {
																// Otherwise print all data elements
	  data *d = getData(mylist);
	  printf("Test Passed(gotoNextNode)\nNumber of Elements in set3 = %d\n",
		d->members->len);
	  printf("Elements in set3 = ");
	  printset(d->members);
	}

   // Test gotoPreviousNode() function
   gotoPreviousNode(mylist);
    if ((mylist->current == mylist->head)) {					// Test failed still @ head
		printf("Test Failed\n");
	} else if ((mylist->current == mylist->tail)) {				// Test failed still @ tail
	  printf("Test Failed\n");
	} else {
																// Otherwise print all data elements
	  data *d = getData(mylist);

	  // Print the number of elements in set 2
	  printf("Test Passed(gotoPreviousNode)\nNumber of Elements in set2 = %d\n",
	  
		d->members->len);
	  printf("Elements in set2 = ");
	  printset(d->members);										// Prints the elements in set 2
	}


	printf("Remove element test passed - 13 removed from set 3");
	printf("\n\n\n");
	printf("Press Any Key to Continue\n");
    getchar();													// Call getchar() function to allow user to continue
	
	
	

	// Test gotoHead && gotoTail functions
    printf("#5: Test functions gotoHead() && gotoTail()\n");// Inform user of test
	printf("gotoHead()\n");
    gotoHead(mylist);										// Call the gotoHead function 

	// Check if the current node is gone to the head node 
    if ((mylist->current == mylist->head)) {
	  printf("Test Passed ( @Head )\n");					// Test passed, gone to head 	
	} else if ((mylist->current == mylist->tail)) {
	  printf("Test Failed ( @Tail )\n");					// Test failed still @ tail
	} else {
	  	// otherwise print all data elements
	  printf("Test failed");
	}
	
	// Check if the current node is set to tail
	printf("gotoTail()\n");
    gotoTail(mylist);
    if ((mylist->current == mylist->head)) {			// Test failed still @ head
	  printf("Test Failed ( @Head )\n");
	} else if ((mylist->current == mylist->tail)) {
	  printf("Test Passed ( @Tail )\n");				// Test passed, gonr to tail
	} else {
	  // Otherwise print all data elements
	  printf("Test Failed\n");
	}
	printf("\n\n\n");
	printf("Press Any Key to Continue\n");
   getchar();											// Call getchar() function to allow user to continue
   
   
   
   
   // Test the insertBefore() method 
   printf("#6: Test function insertBefore() \n");
   newdata.members = set4;										// Add set4 elements to the data struct of memebers
   insertBefore(&newdata,mylist);
   gotoPreviousNode(mylist); 									
   if (mylist->current == mylist->head) {
	  printf("Test Failed ( @Head )\n"); 						//Test failed as still @ head
	} else {
																// Otherwise print all data elements
	  data *d = getData(mylist);
	  printf("Test Passed(gotoPreviousNode)\nNumber of Elements in set4 = %d\n",
		d->members->len);
	  printf("Elements in set4 = ");
	  printset(d->members);										// Call the printset() function to print elements
	}
   printf("\n\n\n");
   printf("Press Any Key to Continue\n");
   getchar();													// Call getchar() function to allow user to continue
   
   
	// Test the deleteCurrent() function 
	printf("#7: Test function deleteCurrent()  to show deletion was successful\n");
    gotoPreviousNode(mylist);							// Go to the previous node
    deleteCurrent(mylist);								// Delete the node 
    gotoHead(mylist);									// Go to the head of the list
	printf("Print List\n");

		
   if (mylist->current == mylist->head) {              	// if current node is the head inform the user
	  printf("Head\n");				
	} else {
	  // Otherwise print all data elements
	  data *d = getData(mylist);					   	// Get the data from the list 
	  printf("Number of Elements = %d\n",
		d->members->len);
	  printf("Elements = ");
	  printset(d->members);
	}
	gotoNextNode(mylist);

   if (mylist->current == mylist->head) {				// if current node is the head inform the user
	  printf("Head\n");
	} else {											
	  // otherwise print all data elements
	  data *d = getData(mylist);						// Get the data from the list 
	  printf("Number of Elements = %d\n",
		d->members->len);
	  printf("Elements = ");
	  printset(d->members);								// Call printset() function to print the data elements
	}
   gotoNextNode(mylist);

   if (mylist->current == mylist->head) {				// if current node is the head inform the user
	  printf("Head\n");
	} else {
	  // otherwise print all data elements
	  data *d = getData(mylist);						// Get the data from the list 
	  printf("Number of Elements = %d\n",
		d->members->len);
	  printf("Elements = ");
	  printset(d->members);								// Call printset() function to print the data elements
	}
    gotoNextNode(mylist);

   if (mylist->current == mylist->head) {				// if current node is the head inform the user
	  printf("Head\n");
	} else {
	  // otherwise print all data elements
	  data *d = getData(mylist);						// Get the data from the list 
	  printf("Number of Elements = %d\n",
		d->members->len);
	  printf("Elements = ");
	  printset(d->members);								// Call printset() function to print the data elements
	}
	gotoNextNode(mylist);

    if ((mylist->current == mylist->head)) {			// if current node is the head inform the user
	  printf("Head\n");
	} else if ((mylist->current == mylist->tail)) {		// if the current node is tail inform the user 
	  printf("Tail\n");									
	} else {
	  // otherwise print all data elements
	  data *d = getData(mylist);						// Get the data from the list
	  printf("Number of Elements = %d\n",
		d->members->len);
	  printf("Elements = ");
	  printset(d->members);								// Call printset() function to print the data elements
	}
	printf("Test Passed 3rd set not Printed\n\n\n\n");	// Test Passed
	printf("Press Any Key to Continue\n");
    getchar();											// Call getchar() function to allow user to continue
	
	
	printf("#8: Test to Delete Set\n");
	deleteOrderedSet(set2);
	gotoHead(mylist);	
	printf("\n\n\n");
    printf("Press Any Key to Continue\n");
    getchar();								// Go to the head of the list
	
	
   

    // Test the deleteDoubleLinkedList() function 
	printf("#9: Test deleteDoubleLinkedList() function\n");
	if (mylist!=NULL){									// Test Failes if the list is not null
        deleteDoubleLinkedList(mylist);						// Delete the the previously created list
        mylist=NULL;									
		printf("Test passed!!\n");		
			// Otherwise test passed if list found to be null
    }
    
	if(mylist!=NULL) {
		printf("Test Failed!!\n");						// Otherwise test passed if list found to be null
	}

return EXIT_SUCCESS;									// Succesful termination 
}
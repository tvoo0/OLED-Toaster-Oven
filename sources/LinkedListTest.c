// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CMPE13 Support Library
#include "BOARD.h"


// User libraries:
#include "LinkedList.h"

int main() {
    // Initializing the board
    BOARD_Init();
    
    // first list
    char* firstData = "First item.";
    ListItem* listHead1 = LinkedListNew(firstData);

    char* secondData = "Second item.";
    ListItem* newItem1 = LinkedListCreateAfter(listHead1, secondData);

    // second list
    char* thirdData = "Third item.";
    ListItem* listHead2 = LinkedListNew(thirdData);

    char* fourthData = "Fourth item.";
    ListItem* newItem2_1 = LinkedListCreateAfter(listHead2, fourthData);

    char* fifthData = "Fifth item.";
    ListItem* newItem2_2 = LinkedListCreateAfter(newItem2_1, fifthData);
    

    // Test for LinkedListPrint
    printf("\nDemonstrating LinkedListPrint():\n");
    int printResult1 = LinkedListPrint(listHead1);
    int printResult2 = LinkedListPrint(listHead2);

    if ((printResult1 == EXIT_SUCCESS) && (printResult2 == EXIT_SUCCESS)) {
        printf("PASSED (%d/%d): LinkedListPrint()\n", 2, 2);
    } else if ((printResult1 == EXIT_SUCCESS) ^ (printResult2 == EXIT_SUCCESS)) {
        printf("FAILED (%d/%d): LinkedListPrint()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListPrint()\n", 0, 2);
    }


    // Test for LinkedListNew
    if ((listHead1 != NULL) && (listHead2 != NULL)) {
        printf("PASSED (%d/%d): LinkedListNew()\n", 2, 2);
    } else if ((listHead1 != NULL) ^ (listHead2 != NULL)) {
        printf("FAILED (%d/%d): LinkedListNew()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListNew()\n", 0, 2);
    }


    // Test for LinkedListCreateAfter
    if ((newItem1 != NULL) && (newItem2_1 != NULL)) {
        printf("PASSED (%d/%d): LinkedListCreateAfter()\n", 2, 2);
    } else if ((newItem1 != NULL) ^ (newItem2_1 != NULL)) {
        printf("FAILED (%d/%d): LinkedListCreateAfter()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListCreateAfter()\n", 0, 2);
    }


    // Test for LinkedListGetFirst
    ListItem* firstItem = LinkedListGetFirst(listHead1);
    ListItem* firstItem2 = LinkedListGetFirst(listHead2);
    if ((firstItem == listHead1) && (firstItem2 == listHead2)) {
        printf("PASSED (%d/%d): LinkedListGetFirst()\n", 2, 2);
    } else if ((firstItem == listHead1) ^ (firstItem2 == listHead2)) {
        printf("FAILED (%d/%d): LinkedListGetFirst()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListGetFirst()\n", 0, 2);
    }


    // Test for LinkedListGetLast
    ListItem* lastItem = LinkedListGetLast(listHead1);
    ListItem* lastItem2 = LinkedListGetLast(listHead2);
    if ((lastItem == newItem1) && (lastItem2 == newItem2_2)) {
        printf("PASSED (%d/%d): LinkedListGetLast()\n", 2, 2);
    } else if ((lastItem == newItem1) ^ (lastItem2 == newItem2_2)) {
        printf("FAILED (%d/%d): LinkedListGetLast()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListGetLast()\n", 0, 2);
    }


    // Test for LinkedListGetSize
    int expectedSize1 = 2; // Size of the first list should be 2
    int expectedSize2 = 3; // Size of the second list should be 3

    int size1 = LinkedListSize(listHead1);
    int size2 = LinkedListSize(listHead2);

    // Test cases for size comparisons
    if ((size1 == expectedSize1) && (size2 == expectedSize2)) {
        printf("PASSED (%d/%d): LinkedListGetSize()\n", 2, 2);
    } else if ((size1 == expectedSize1) ^ (size2 == expectedSize2)) {
        printf("FAILED (%d/%d): LinkedListGetSize()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListGetSize()\n", 0, 2);
    }


    // Test for LinkedListSwapData
    int swapDataResult1 = LinkedListSwapData(newItem1, newItem2_1);
    int swapDataResult2 = LinkedListSwapData(newItem2_1, newItem2_2);

    if ((swapDataResult1 == EXIT_SUCCESS) && (swapDataResult2 == EXIT_SUCCESS)) {
        printf("PASSED (%d/%d): LinkedListSwapData()\n", 2, 2);
    } else if ((swapDataResult1 == EXIT_SUCCESS) ^ (swapDataResult2 == EXIT_SUCCESS)) {
        printf("FAILED (%d/%d): LinkedListSwapData()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListSwapData()\n", 0, 2);
    }


    // Test for LinkedListRemove
    char* removedData1 = LinkedListRemove(listHead1); // Remove the first item
    char* removedData2 = LinkedListRemove(listHead2); // Remove the first item of the second list 

    if ((removedData1 != NULL) && (removedData2 != NULL)) {
        printf("PASSED (%d/%d): LinkedListRemove()\n", 2, 2);
    } else if ((removedData1 != NULL) ^ (removedData2 != NULL)) {
        printf("FAILED (%d/%d): LinkedListRemove()\n", 1, 2);
    } else {
        printf("FAILED (%d/%d): LinkedListRemove()\n", 0, 2);
    }
    
    BOARD_End();
    while (1);
    return 0;
}

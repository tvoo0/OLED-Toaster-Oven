// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// User libraries:
#include "LinkedList.h"

// LinkedListNew function

ListItem *LinkedListNew(char *data) {
    // allocating memory
    ListItem* newItem = (ListItem*) malloc(sizeof (ListItem));

    if (newItem == NULL) {
        return NULL; // returns NULL if memory failed to allocate
    }

    // Set the data for the new ListItem
    newItem->data = data;
    newItem->nextItem = NULL; // Initialize the 'next' pointer to NULL

    return newItem;
}

// LinkedListCreateAfter function

ListItem *LinkedListCreateAfter(ListItem *item, char *data) {
    // Allocating memory
    ListItem* newItem = (ListItem*) malloc(sizeof (ListItem));

    if (newItem == NULL) {
        return NULL;
    }

    // Set the data for the new ListItem
    newItem->data = data;

    if (item != NULL) {
        // Link the new item after the given item
        newItem->nextItem = item->nextItem;
        newItem->previousItem = item;

        if (item->nextItem != NULL) {
            // Set the previousItem pointer of the item that originally came after item to point to newItem
            item->nextItem->previousItem = newItem;
        }
        item->nextItem = newItem;
    } else {
        // If item is NULL, this inserts the new item at the beginning of the list
        newItem->previousItem = NULL;
        newItem->nextItem = NULL;
    }

    return newItem;
}

// LinkedListGetFirst function

ListItem *LinkedListGetFirst(ListItem *list) {
    if (list == NULL) {
        return NULL;
    }

    // Traverse the list to find the head
    while (list->previousItem != NULL) {
        list = list->previousItem;
    }

    return list; // Return the first element in the list
}

// LinkedListGetLast function

ListItem* LinkedListGetLast(ListItem* list) {

    if (list == NULL) {
        return NULL;
    }

    // Traverse to the last node
    while (list->nextItem != NULL) {
      list = list->nextItem; 
    }

    return list;
}

// LinkedListGetSize function

int LinkedListSize(ListItem *list) {
    int size = 0;

    // Traverse the list while it's not NULL
    while (list != NULL) {
        size++;
        list = list->nextItem; // Move to the next item
    }
    return size;
}

// LinkedListRemove function

char *LinkedListRemove(ListItem *item) {
    // Check if the passed item is NULL
    if (item == NULL) {
        return NULL; // Signal an error
    }

    char *data = item->data;

    // Update the links of the items next to it
    if (item->previousItem != NULL) {
        item->previousItem->nextItem = item->nextItem;
    }
    if (item->nextItem != NULL) {
        item->nextItem->previousItem = item->previousItem;
    }

    // Free the memory used by the item
    free(item);

    return data;
}

// LinkedListSwapData function

int LinkedListSwapData(ListItem *firstItem, ListItem *secondItem) {
    // Check if either of the items is NULL
    if (firstItem == NULL || secondItem == NULL) {
        printf("ERROR: One or both items are NULL. Swap failed.\n");
        return EXIT_FAILURE;
    }

    // Swap the data pointers while preserving the location
    char *tempData = firstItem->data;
    firstItem->data = secondItem->data;
    secondItem->data = tempData;

    return EXIT_SUCCESS;
}

// LinkedListPrint function

int LinkedListPrint(ListItem *list) {
    // Check if the provided list is NULL
    if (list == NULL) {
        return EXIT_FAILURE;
    }

    // Start of list
    printf("[");
    while (list != NULL) {
        printf("%s", list->data);

        // Separating elements until the last one
        if (list->nextItem != NULL) {
            printf(", ");
        }

        list = list->nextItem;
    }
    printf("]\n"); // End of list

    return EXIT_SUCCESS;
}
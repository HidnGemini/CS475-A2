/*
 * heapsort.c
 *
 *  Created on: Jan 31, 2025
 *      Author: maddyS
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	length	Size of the heap
 */
void heapSort(Employee *A, int length) {
	buildHeap(A, length);
    int limit = length-1;
    while(limit >= 0) {
        swap(A, A+limit);
        limit--;
        heapify(A, 0, limit);
    }
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	length	Size of the heap
 */
void buildHeap(Employee *A, int length) {
	int lastParent = length/2-1;
    for (int i = lastParent; i >= 0; i--) {
        heapify(A, i, length);
    }
}

/**
 * Given the index of a child, calculate the index of its parent
 *
 * @param childIndex	index of child node
 */
int parent(int childIndex) {
    return (childIndex-1)/2;
}

/**
 * Given the index of the parent, calculate the index of leftChild
 *
 * @param parentIndex	index of parent node
 */
int leftChild(int parentIndex) {
    return 2*(parentIndex+1)-1;
}

/**
 * Given the index of the parent, calculate the index of rightChild
 *
 * @param parentIndex	index of parent node
 */
int rightChild(int parentIndex) {
    return 2*(parentIndex+1);
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	index	Index of current element to heapify
 * @param	length	Size of the heap
 */
void heapify(Employee *A, int index, int length) {
	if (index >= length/2) {
        return; // leaf node satisfies heap condition by default
    }

    int leftIndex = leftChild(index);
    int rightIndex = rightChild(index);

    if ((*(A+index)).salary > (*(A+leftIndex)).salary && (*(A+index)).salary > (*(A+rightIndex)).salary) {
        // greater than leftChild AND rightChild
        if ((*(A+rightIndex)).salary >= (*(A+leftIndex)).salary) {
            // swap parent and leftChild if leftChild is smaller
            swap(A+index, A+leftIndex);
            heapify(A, leftIndex, length); // recurse on left
        } else {
            // swap parent and rightChild if leftChild is larger
            swap(A+index, A+rightIndex);
            heapify(A, rightIndex, length); // recurse on right

        }
    } else if ((*(A+index)).salary > (*(A+leftIndex)).salary) {
        // greater than leftChild only; swap with left
        swap(A+index, A+leftIndex);
        heapify(A, leftIndex, length); // recurse
    } else if ((*(A+index)).salary > (*(A+rightIndex)).salary) {
        // greater than rightChild only; swap with right
        swap(A+index, A+rightIndex);
        heapify(A, rightIndex, length); // recurse
    } else {
        // parent is smaller than both children; return
        return;
    }
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2) {
	Employee temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	length	Size of the list
 */
void printList(Employee *A, int length) {
	printf("[{id=%s sal=%d}, ", (*(A)).name, (*(A)).salary);
    for (int i = 1; i<length-1; i++) {
        printf("{id=%s sal=%d}, ", (*(A+i)).name, (*(A+i)).salary);
    }
    printf("{id=%s sal=%d}]\n", (*(A+length-1)).name, (*(A+length-1)).salary);
}
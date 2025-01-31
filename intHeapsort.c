#include <stdio.h>

void printArr(int *arr, int length) {
    printf("[%d, ", *arr);
    for (int i = 1; i<length-1; i++) {
        printf("%d, ", *(arr+i));
    }
    printf("%d]\n", *(arr+length-1));
}

void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;

}

int parent(int child) {
    return (child-1)/2;
}

int leftChild(int parentIndex) {
    return 2*(parentIndex+1)-1;
}

int rightChild(int parentIndex) {
    return 2*(parentIndex+1);
}

void heapify(int *A, int index, int length) {
    if (index >= length/2) {
        return; // leaf node satisfies heap condition by default
    }

    int leftIndex = leftChild(index);
    int rightIndex = rightChild(index);

    if (*(A+index) > *(A+leftIndex) && *(A+index) > *(A+rightIndex)) {
        // greater than leftChild AND rightChild
        if (*(A+rightIndex) >= *(A+leftIndex)) {
            // swap parent and leftChild if leftChild is smaller
            swap(A+index, A+leftIndex);
            heapify(A, leftIndex, length); // recurse on left
        } else {
            // swap parent and rightChild if leftChild is larger
            swap(A+index, A+rightIndex);
            heapify(A, rightIndex, length); // recurse on right

        }
    } else if (*(A+index) > *(A+leftIndex)) {
        // greater than leftChild only; swap with left
        swap(A+index, A+leftIndex);
        heapify(A, leftIndex, length); // recurse
    } else if (*(A+index) > *(A+rightIndex)) {
        // greater than rightChild only; swap with right
        swap(A+index, A+rightIndex);
        heapify(A, rightIndex, length); // recurse
    } else {
        // parent is smaller than both children; return
        return;
    }
}

void buildHeap(int *A, int length) {
    int lastParent = length/2-1;
    for (int i = lastParent; i >= 0; i--) {
        heapify(A, i, length);
    }
}

void heapSort(int *A, int length) {
    buildHeap(A, length);
    int limit = length-1;
    while(limit >= 0) {
        swap(A, A+limit);
        limit--;
        heapify(A, 0, limit);
    }
}

int main(int argc, char *argv[]) {
    int arrSize = 15;
	int array[15] = {10,3,1,15,14,9,13,7,12,11,8,5,6,4,2};

    printArr(array, arrSize);

    heapSort(array, arrSize);

    printArr(array, arrSize);
	
	return 0;
}

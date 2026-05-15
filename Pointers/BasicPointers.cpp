#include "BasicPointers.h"
#include <iostream>

int BasicPointers::printValueAndAddress() {
    int x = 10;
    std::cout << "Value: " << x << std::endl;
    std::cout << "Address is: " << &x << std::endl;
    return 0;
    /*
        MEMORY DIAGRAM FOR THIS PROGRAM
        
        STACK
        -----------------
        x = 10   | 0x100
    */
}

int BasicPointers::printPointerAndValue() {
    int x = 20;
    int* ptr = &x;
    std::cout << "Pointer value (address): " << ptr << std::endl;
    return 0;
    /*
        MEMORY DIAGRAM

        STACK
        -----------------
        x   = 20     | 0x100
        ptr = 0x100  | 0x200
    */
}

int BasicPointers::dereferencePointer() {
    int x = 30;
    int *ptr = &x;

    std::cout << "Value using pointer: " << *ptr << std::endl;
    return 0;
    /*
        MEMORY DIAGRAM

        STACK
        -----------------
        x   = 30     | 0x100
        ptr = 0x100  | 0x200
    */
}

int BasicPointers::changeValueUsingPointer() {
    int x = 5;
    int *ptr = &x;
    std::cout << "Pointer address is: " << ptr << std::endl;
    *ptr = 50;
    std::cout << "Updated Pointer address is: " << ptr << std::endl;
    std::cout << "Updated value: " << x << std::endl;
    std::cout << "Updated pointer value is: " << *ptr << std::endl;
    /* Remember: By changing value using pointer does not change the pointer address. */
    return 0;
    /*
        MEMORY DIAGRAM

        STACK
        -----------------
        x   = 50     | 0x100
        ptr = 0x100  | 0x200
    */
}

void swap(int *a, int *b) {
    std::cout << "Address of A: " << a << ", Address of B: " << b << std::endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    std::cout << "Address of A: " << a << ", Address of B: " << b << std::endl;
    /*
        MEMORY DIAGRAM
        
        STACK
        -----------------
        x = 10  | 0x100
        y = 20  | 0x104

        AFTER SWAP

        STACK
        -----------------
        x = 20  | 0x100
        y = 10  | 0x104
    */
}

void BasicPointers::swapUsingPointers() {
    /* Although we are swapping values using pointers, their address remains same.*/
    int x = 10, y = 20;
    swap(&x, &y);
    std::cout << "X: " << x << ", Y: " << y << std::endl;    
}

void BasicPointers::arithmeticPointer() {
    int arr[] = {10, 20, 30};
    int *ptr = arr; // This pointer is pointing to an array stored in memory
    std::cout << "Size of arr in memory is: " << sizeof arr << " bytes" << std::endl;
    std::cout << "Size of pointer in memory is: " << sizeof ptr << " bytes" << std::endl;
    std::cout << *ptr << std::endl;
    ptr++;
    std::cout << *ptr << std::endl;
    ptr++;
    std::cout << *ptr << std::endl;
    ptr++;
    std::cout << *ptr << std::endl;
    /* Important thing to notice here is that when you point a integer pointer
        to any array, it always points to the first element of the array. When you
        increment it, it moves to the next element. And when the pointer runs out of
        size, the pointer gives -1502936921 value. */
    
    /*
        MEMORY DIAGRAM

        STACK
        --------------------------------
        arr[0]=10 | 0x100
        arr[1]=20 | 0x104
        arr[2]=30 | 0x108
        ptr=0x100 | 0x200
    */
}

void BasicPointers::traverseArrayUsingPointer() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(ptr + i) << " " << std::endl;
    }

    /*
        MEMORY DIAGRAM

        i=0 → 0x100 → 1
        i=1 → 0x104 → 2
        i=2 → 0x108 → 3
    */
}

void BasicPointers::pointerOrArrayIndexing() {
    int arr[] = {5, 10, 15};
    std::cout << arr[1] << std::endl;
    std::cout << *(arr + 1) << std::endl;

    // Both → 0x104 → value 10
}

void BasicPointers::sumOfArrayUsingPointer() {
    int arr[] = {1, 2, 3, 4};
    int* ptr = arr;
    int sum = 0;

    for(int i = 0; i < 4; i++) {
        sum += *(ptr + i);
    }
    std::cout << "Sum: " << sum << std::endl;

    /*
        MEMORY DIAGRAM

        ptr + 0 → arr[0]
        ptr + 1 → arr[1]
        ptr + 2 → arr[2]
    */
}

void BasicPointers::reverseArrayUsingPointers() {
    int arr[] = {1, 2, 3, 4, 5};
    int *start = arr;
    int *end = arr + 4;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " " << std::endl;
    }    
}

void BasicPointers::findMax() {
    int arr[] = {3, 7, 2, 9, 6};
    int *ptr = arr;
    int max = *ptr;

    for (int i = 0; i < 5; i++)
    {
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
        }        
    }
    std::cout << "Max: " << max << std::endl;
}

void BasicPointers::pointerToPointer() {
    int x = 100;
    int *ptr = &x;
    int **pptr = &ptr;

    std::cout << "Value is: " << **pptr << std::endl;

    /*
        MEMORY DIAGRAM

        STACK
        ---------------------------------
        x     = 100     | 0x100
        ptr   = 0x100   | 0x200
        pptr  = 0x200   | 0x300
    */
}

void increment(int *num) {
    (*num)++;
}

void BasicPointers::pointerArgument() {
    int x = 10;
    increment(&x);
    std::cout << "After increment: " << x << std::endl;
}

void BasicPointers::nullPointerHandling() {
    int *ptr = NULL;
    std::cout << "Address of pointer when null is: " << ptr << std::endl;
    if (ptr == NULL)
    {
        std::cout << "Pointer is NULL" << std::endl;
    }
    else
    {
        std::cout << *ptr << std::endl;
    }
    
    /*
        MEMORY DIAGRAM

        STACK
        -----------------
        ptr = 0x0
    */
}
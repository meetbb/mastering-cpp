#include "LevelTwoPointers.h"
#include <iostream>
using namespace std;

void modify(int *p) {
    *p = 99;
    cout << "Address of p is: " << p << endl;
    /*
        Here we are modifying same memory, not a copy.
    */
}

void LevelTwoPointers::pointerToFuncModification() {
    int x = 10;
    cout << x << endl; // 10
    modify(&x);
    cout << "After modification: " << x << endl;
}

void byValue(int x) {
    x = 50;
}

void byPointer(int *x) {
    *x = 50;
}

void LevelTwoPointers::callByValuevsPointer() {
    int x = 10, y = 20;
    byValue(x);
    byPointer(&y);
    cout << "X: " << x << "Y: " << y << endl;
}

void LevelTwoPointers::dynamicMemoryExp() {
    int *ptr = new int;
    cout << "Address of ptr is: " << ptr << endl;
    cout << "Value of ptr is: " << *ptr << endl;
    *ptr = 42;
    cout << "Address of ptr is: " << ptr << endl;
    cout << "Value of ptr is: " << *ptr << endl;
    delete ptr;
    cout << "Address of ptr after deleting is: " << ptr << endl;
    cout << "Value of ptr after deleting is: " << *ptr << endl;
}

void LevelTwoPointers::dynamicArrAllocation() {
    int n = 5;
    int *arr = new int[n];

    cout << "Pre processing" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * 10;
    }
    
    cout << "Post processing" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    delete[] arr;
    cout << "Array after deleting: " << arr << endl;
    cout << "Value of Array after deleting: " << arr << endl;
}

void LevelTwoPointers::constantPointer() {
    int x = 10, y = 20;

    const int* p1 = &x; // can't modify *p1
    int* const p2 = &x; // can't change p2
}
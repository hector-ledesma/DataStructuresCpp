// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Array {
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr) {
    std::cout << "Elements are" << std::endl;
    for (int i = 0; i < arr.length; i++)
        std::cout << arr.A[i]<<" ";

    std::cout << std::endl;
}

void Append(struct Array* arr, int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;

}

void Insert(struct Array* arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array* arr, int index) {
    int x = 0;
    if (index >= 0 && index <= arr->length) {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            //swap(&arr->A[i], &arr->A[i - 1]);
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

// The 3 params for binary search are low, high, key.
// Main thing is that low can't be greater than high.
// We need to find a middle by adding low and high and dividing by 2.
// If mid is larger than our key, we shorten the array to the left:
//      h = mid - 1
// Else, if mid is lower, we move to the right:
//      l = mid + 1
// Once we find our key, return it. Otherwise, return -1.
// I'll try to implement this before watching the lesson and see what I get right or wrong.
// With a loop first, and then recursively.

// Success!!
int LinearBinarySearch(struct Array* arr, int key) {
    int l = 0;
    int h = arr->length-1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr->A[mid] == key)
            return arr->A[mid];
        if (arr->A[mid] > key) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1;
}

// Success!!
int RBinarySearch(struct Array* arr, int l, int h, int key) {

    if (l <= h) {
        int mid = (l + h) / 2;
        if (arr->A[mid] == key)
            return arr->A[mid];
        if (arr->A[mid] > key)
            return RBinarySearch(arr, l, mid-1, key);
        return RBinarySearch(arr, mid+1, h, key);
    }

    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array* arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr) {
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr) {
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

float Avg(struct Array arr) {
    return (float) Sum(arr) / arr.length;
}

int main()
{
    struct Array arr = { {2,3,4,5,6,10,12,14,29}, 20, 9 };

    // Do binary search before screwing up the sort.
    // Linear.
    int siFound = LinearBinarySearch(&arr, 29);
    std::cout << "Found this item: " << siFound << std::endl;

    int notFound = LinearBinarySearch(&arr, 21);
    std::cout << "Couldn't find an item: " << notFound << std::endl;
    // Recursively
    int rSiFound = RBinarySearch(&arr, 0, arr.length-1, 29);
    std::cout << "Found this item recursively: " << rSiFound << std::endl;

    int rNotFound = RBinarySearch(&arr, 0, arr.length-1, 1);
    std::cout << "Couldn't find an item recursively: " << notFound << std::endl;
    std::cout << std::endl;

    int deleted = Delete(&arr, 2);
    std::cout << "Deleted element is: " << deleted << std::endl;
    Insert(&arr, 2, 12);
    Append(&arr, 10);
    int found = LinearSearch(&arr, 12);
    std::cout << "Found 12 at index: " << found << std::endl;

    Display(arr);

}
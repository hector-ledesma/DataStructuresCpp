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

int main()
{
    struct Array arr = { {2,3,4,5,6}, 20, 5 };
    int deleted = Delete(&arr, 2);
    std::cout << "Deleted element is: " << deleted << std::endl;
    Insert(&arr, 2, 12);
    Append(&arr, 10);
    int found = LinearSearch(&arr, 12);
    std::cout << "Found 12 at index: " << found << std::endl;

    Display(arr);

}
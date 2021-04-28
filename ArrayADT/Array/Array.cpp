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

void Reverse(struct Array* arr) {
    int* B;
    int i, j;

    B = new int[arr->length];

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];

    delete [] B;
}

void Reverse2(struct Array* arr) {
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array* arr, int x) {
    if (arr->length == arr->size)
        return;

    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr) {
    int i;
    for (i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array* arr) {
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0)i++;
        while (arr->A[j] >= 0)j--;
        if (i < j)swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array* Merge(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

// Set operations
// Under each method, there'll be a student-led implementation for unsorted sets.

// This Union method assumes both sets are sorted.
struct Array* Union(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else { // Main difference is that if we find values that are the same, we only add one and move both indices forward. This prevents duplicates.
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}
// For this, we first copy the first array into the third.
// As we add items from the second array, we have to check all existing items in the third array, including the ones just added.
struct Array* UnionUnsorted(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array;

    // Copy first array
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    // Copy second array.
    for (; j < arr2->length; j++) {
        // Check all items in arr3, from 0 to current.
        i = 0;
        // Loop will exit early if the elem in arr3 is the same.
        // But i will be = to k if there's no match.
        while (arr3->A[i] != arr2->A[j] && i < k)
            i++;
        // Therefore, all we have to check is if i == k to know that there was no duplicate.
        if (i == k)
            arr3->A[k++] = arr2->A[j];
        
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

// Copy of Union
// Should only copy element if they're equal
struct Array* Intersection(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i]) // Main difference is that if either Ai or Aj is smaller, move the corresponding index.
            j++;
        else { // And once we have matching elements, add them to the result.
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Should only copy element if they're present in both arrays.
struct Array* IntersectionUnsorted(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array;

    // We don't copy the first array blindly
    //for (; i < arr1->length; i++)
        //arr3->A[k++] = arr1->A[i];

    // Go through first array one by one.
    for (; i < arr1->length; i++) {
        // For every item in arr1, we want to check if it's present in arr2.
        j = 0;
        // Check from 0 to last of arr2.
        // Let's use while, so that we can easily have an early exit condition.
        while (arr1->A[i] != arr2->A[j] && j < arr2->length)
            j++;

        // If we exit early, it's cause we found a match. So enter it into arr3.
        if (j < arr2->length)
            arr3->A[k++] = arr1->A[i];

    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

// Copy from Union
// Only elements from first array get added.
struct Array* Difference(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else { // Only elements from first array get added that arn't in the second array.
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
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

    InsertSort(&arr, 13);
    Display(arr);

    std::cout << std::endl;
    std::cout << "Is it sorted? " << isSorted(arr) << std::endl;
    std::cout << std::endl;
    

    std::cout << "----------------" << std::endl;
    Display(arr);
    Reverse(&arr);
    Display(arr);
    Reverse2(&arr);
    Display(arr);
    std::cout << "----------------" << std::endl;

    // Sorted set methods
    std::cout << "----------------" << std::endl;
    int deleted = Delete(&arr, 2);
    std::cout << "Deleted element is: " << deleted << std::endl;
    Insert(&arr, 2, 12);
    Append(&arr, 10);
    int found = LinearSearch(&arr, 12);
    std::cout << "Found 12 at index: " << found << std::endl;

    std::cout << std::endl;
    std::cout << "Is it sorted? " << isSorted(arr) << std::endl;
    std::cout << std::endl;

    struct Array arr1 = { {2,6,10,15,25}, 10, 5 };
    struct Array arr2 = { {3,6,7,15,20}, 10, 5 };
    struct Array* arr3 = Merge(&arr1, &arr2);

    std::cout << "Merge:" << std::endl;
    Display(*arr3);
    
    std::cout << std::endl;
    struct Array* united = Union(&arr1, &arr2);
    std::cout << "Union:" << std::endl;
    Display(*united);

    std::cout << std::endl;
    struct Array* intersected = Intersection(&arr1, &arr2);
    std::cout << "Intersection:" << std::endl;
    Display(*intersected);

    std::cout << std::endl;
    struct Array* difference = Difference(&arr1, &arr2);
    std::cout << "Difference:" << std::endl;
    Display(*difference);
    std::cout << "----------------" << std::endl;

    std::cout << std::endl;
    std::cout << "----------------" << std::endl;

    struct Array unsorted1 = { {2,1,52,12,3}, 10, 5 };
    struct Array unsorted2 = { {4,12,2,52,10}, 10, 5 };
    
    std::cout << std::endl;
    struct Array* unitedUnsorted = UnionUnsorted(&unsorted1, &unsorted2);
    std::cout << "Union Unsorted:" << std::endl;
    Display(*unitedUnsorted);

    std::cout << std::endl;
    struct Array* intersectedUnsorted = IntersectionUnsorted(&unsorted1, &unsorted2);
    std::cout << "Intersection Unsorted:" << std::endl;
    Display(*intersectedUnsorted);

    std::cout << "----------------" << std::endl;


}
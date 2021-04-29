// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <class T>
class Array {
private:
    T *A;
    int size;
    int length;

    void swap(int* x, int* y);
public:
    Array() {
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int sz) {
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array() {
        delete[]A;
    }

    void Display();
    void Append(T x);
    void Insert(int index, T x);
    T Delete(int index);
    int LinearSearch(T key);
    T LinearBinarySearch(T key);
    T RBinarySearch(int l, int h, T key);
    T Get(int index);
    int Length();
    void Set(int index, T x);
    T Max();
    T Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(T x);
    int isSorted();
    void Rearrange();
    Array<T>* Merge(Array<T>* arr2);
    Array<T>* Union(Array<T>* arr2);
    Array<T>* UnionUnsorted(Array<T>* arr2);
    Array<T>* Intersection(Array<T>* arr2);
    Array<T>* IntersectionUnsorted(Array<T>* arr2);
    Array<T>* Difference(Array<T>* arr2);
    Array<T>* DifferenceUnsorted(Array<T>* arr2);
};

template<class T>
void Array<T>::Display() {
    std::cout << "Elements are" << std::endl;
    for (int i = 0; i < length; i++)
        std::cout << A[i]<<" ";

    std::cout << std::endl;
}

template<class T>
void Array<T>::Append(T x) {
    if (length < size)
        A[length++] = x;
}

template<class T>
void Array<T>::Insert(int index, T x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index) {
    int x = 0;
    if (index >= 0 && index <= length) {
        x = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }
    return 0;
}

template<class T>
void Array<T>::swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// This method returns index.
template<class T>
int Array<T>::LinearSearch(T key) {
    for (int i = 0; i < length; i++) {
        if (key == A[i]) {
            //swap(&arr->A[i], &arr->A[i - 1]);
            swap(&A[i], &A[0]);
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
template<class T>
T Array<T>::LinearBinarySearch(T key) {
    int l = 0;
    int h = length-1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (A[mid] == key)
            return A[mid];
        if (A[mid] > key) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1;
}

// Success!!
template<class T>
T Array<T>::RBinarySearch(int l, int h, T key) {

    if (l <= h) {
        int mid = (l + h) / 2;
        if (A[mid] == key)
            return A[mid];
        if (A[mid] > key)
            return RBinarySearch(l, mid-1, key);
        return RBinarySearch(mid+1, h, key);
    }

    return -1;
}

template<class T>
T Array<T>::Get(int index) {
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

template<class T>
int Array<T>::Length() {
    return length;
}

template<class T>
void Array<T>::Set(int index, T x) {
    if (index >= 0 && index < length)
        A[index] = x;
}

template<class T>
T Array<T>::Max() {
    int max = A[0];
    int i;
    for (i = 1; i < length; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

template<class T>
T Array<T>::Min() {
    int min = A[0];
    int i;
    for (i = 1; i < length; i++) {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

template<class T>
int Array<T>::Sum() {
    int s = 0;
    int i;
    for (i = 0; i < length; i++)
        s += A[i];
    return s;
}

template<class T>
float Array<T>::Avg() {
    return (float) Sum() / length;
}

template<class T>
void Array<T>::Reverse() {
    int* B;
    int i, j;

    B = new int[length];

    for (i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (i = 0; i < length; i++)
        A[i] = B[i];

    delete [] B;
}

template<class T>
void Array<T>::Reverse2() {
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        swap(&A[i], &A[j]);
    }
}

template<class T>
void Array<T>::InsertSort(T x) {
    if (length == size)
        return;

    int i = length - 1;
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

template<class T>
int Array<T>::isSorted() {
    int i;
    for (i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

template<class T>
void Array<T>::Rearrange() {
    int i, j;
    i = 0;
    j = length - 1;

    while (i < j) {
        while (A[i] < 0)i++;
        while (A[j] >= 0)j--;
        if (i < j)swap(&A[i], &A[j]);
    }
}

template<class T>
Array<T>* Array<T>::Merge(Array<T>* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array(length+arr2->length);

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = length + arr2->length;
    arr3->size = 10;

    return arr3;
}

// Set operations
// Under each method, there'll be a student-led implementation for unsorted sets.

// This Union method assumes both sets are sorted.
template<class T>
Array<T>* Array<T>::Union(Array<T>* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array<T>* arr3 = new Array<T>;

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (arr2->A[j] < A[i])
            arr3->A[k++] = arr2->A[j++];
        else { // Main difference is that if we find values that are the same, we only add one and move both indices forward. This prevents duplicates.
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}
// For this, we first copy the first array into the third.
// As we add items from the second array, we have to check all existing items in the third array, including the ones just added.
template<class T>
Array<T>* Array<T>::UnionUnsorted(Array<T>* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array<T>* arr3 = new Array<T>;

    // Copy first array
    for (; i < length; i++)
        arr3->A[k++] = A[i];

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
template<class T>
Array<T>* Array<T>::Intersection(Array<T>* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array<T>* arr3 = new Array<T>;

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < A[i]) // Main difference is that if either Ai or Aj is smaller, move the corresponding index.
            j++;
        else { // And once we have matching elements, add them to the result.
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Should only copy element if they're present in both arrays.
template<class T>
Array<T>* Array<T>::IntersectionUnsorted(Array<T>* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array<T>* arr3 = new Array<T>;

    // We don't copy the first array blindly
    //for (; i < arr1->length; i++)
        //arr3->A[k++] = arr1->A[i];

    // Go through first array one by one.
    for (; i < length; i++) {
        // For every item in arr1, we want to check if it's present in arr2.
        j = 0;
        // Check from 0 to last of arr2.
        // Let's use while, so that we can easily have an early exit condition.
        while (A[i] != arr2->A[j] && j < arr2->length)
            j++;

        // If we exit early, it's cause we found a match. So enter it into arr3.
        if (j < arr2->length)
            arr3->A[k++] = A[i];

    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

// Copy from Union
// Only elements from first array get added.
template<class T>
Array<T>* Array<T>::Difference(Array<T>* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array<T>* arr3 = new Array<T>;

    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (arr2->A[j] < A[i])
            j++;
        else { // Only elements from first array get added that arn't in the second array.
            i++;
            j++;
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Will only copy elements from array 1 that are not present in array 2.
template<class T>
Array<T>* Array<T>::DifferenceUnsorted(Array<T>* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array<T>* arr3 = new Array<T>;

    // We don't copy the first array blindly
    //for (; i < arr1->length; i++)
        //arr3->A[k++] = arr1->A[i];

    // Go through first array one by one.
    for (; i < length; i++) {
        // For every item in arr1, we want to check if it's present in arr2.
        j = 0;
        // Check from 0 to last of arr2.
        // Let's use while, so that we can easily have an early exit condition.
        while (A[i] != arr2->A[j] && j < arr2->length)
            j++;

        // If we hit the end, it's because this item is not present in arr2. So add it to arr3.
        if (j == arr2->length)
            arr3->A[k++] = A[i];

    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

template<class T>
int missingSol1(Array<T>* arr);

template<class T>
int missingSol2(Array<T>* arr);

template<class T>
void missingSol3(Array<T>* arr);

template<class T>
void missingSol4(Array<T>* arr);

template<class T>
void duplicateSol1(Array<T>* arr);

template<class T>
void duplicateSol2(Array<T>* arr);

int main()
{
    /*
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

    std::cout << std::endl;
    struct Array* differenceUnsorted = DifferenceUnsorted(&unsorted1, &unsorted2);
    std::cout << "Intersection Unsorted:" << std::endl;
    Display(*differenceUnsorted);

    std::cout << "----------------" << std::endl;
    */

    // Array challenges.
    // Single missing element in sorted arrays.

    std::cout << "Missing" << std::endl;
    std::cout << "----------------" << std::endl;
    Array<int> arr1 = Array<int>(10);
    arr1.Append(6);
    arr1.Append(7);
    arr1.Append(8);
    arr1.Append(9);
    arr1.Append(10);
    arr1.Append(11);
    arr1.Append(12);
    arr1.Append(13);
    arr1.Append(15);
    arr1.Append(16);

    std::cout << "\tSol 1:" << std::endl;
    int found1 = missingSol1(&arr1);
    std::cout <<"\t\t"<< found1 << std::endl;

    std::cout << "\tSol 2:" << std::endl;
    int found2 = missingSol2(&arr1);
    std::cout << "\t\t" << found2 << std::endl;

    // Multiple missing elementd in sorted arrays.

    Array<int> arr2 = Array<int>(10);
    arr2.Append(6);
    arr2.Append(7);
    arr2.Append(8);
    arr2.Append(9);
    arr2.Append(10);
    arr2.Append(11);
    arr2.Append(12);
    arr2.Append(14);
    arr2.Append(16);
    arr2.Append(17);

    std::cout << "\tSol 3:" << std::endl;
    missingSol3(&arr2);
    
    // Missing element(s) from unsorted array.
    std::cout << "\tSol 4:" << std::endl;
    missingSol4(&arr2);

    std::cout << std::endl;
    std::cout << "Duplicates" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << std::endl;

    Array<int> arr3 = Array<int>(10);
    arr3.Append(3);
    arr3.Append(6);
    arr3.Append(8);
    arr3.Append(8);
    arr3.Append(10);
    arr3.Append(12);
    arr3.Append(15);
    arr3.Append(15);
    arr3.Append(15);
    arr3.Append(20);

    std::cout << "\tSol 1:" << std::endl;
    duplicateSol1(&arr3);

    std::cout << "\tSol 2:" << std::endl;
    duplicateSol2(&arr3);

}

// This solution uses the formula (n*(n+1))/2
template<class T>
int missingSol1(Array<T>* arr) {
    int s = (arr->Get(arr->Length() - 1) * (arr->Get(arr->Length() - 1) + 1 )) / 2 ;
    // Check that lowest value is 1. Otherwise, subtract it from the calculation.
    if (arr->Get(0) > 1)
        s -= ((arr->Get(0)-1) * (arr->Get(0))) / 2;
    
    int sum = 0;
    // Go through our array and add all the values up.
    for (int i = 0; i < arr->Length(); i++)
        sum += arr->Get(i);
    // Difference will tell us missing element.
    return s - sum;
}

// This solution compares the difference between value and index.
template<class T>
int missingSol2(Array<T>* arr) {
    int diff = arr->Get(0);

    for (int i = 0; i < arr->Length(); i++) {
        if (arr->Get(i) - i != diff)
            return i + diff;
    }

    return -1;
}

// This solution uses index difference to find multiple missing elements.
template<class T>
void missingSol3(Array<T>* arr) {
    int diff = arr->Get(0);

    for (int i = 0; i < arr->Length(); i++) 
        if (arr->Get(i) - i != diff)
            while(diff<arr->Get(i) - i) {
                std::cout << "\t\t" << i + diff << std::endl;
                diff++;
            }
}

// This solution uses a hashmap to find single or multiple missing elements from an unsorted array.
// If we can't sort the array, but space is not an issue, we just use a hashmap.
template<class T>
void missingSol4(Array<T>* arr) {
    int l, h;
    l = h = arr->Get(0);
    // We'll want to find what are the highest and lowest value in the given array.
    // We could use the Min() and Max() methods but we can just find both in one iteration.
    for (int i = 0; i < arr->Length(); i++) {
        if (arr->Get(i) < l)
            l = arr->Get(i);
        if (arr->Get(i) > h)
            h = arr->Get(i);
    }
    // Declare an array as large as our highest value.
    int* hold = new int[h];
    for (int i = 0; i < h; i++)
        // Initialize all values to 0
        hold[i] = 0;

    for (int i = 0; i < arr->Length(); i++)
        // Extract values out of our given array and use them as index to assign to one.
        hold[arr->Get(i) - 1] = 1;
        
    // Loop from lowst to highest value found in original array.
    for (int j = l; j <= h; j++) {
        if (hold[j - 1] == 0)
            std::cout << "\t\t" << j << std::endl;
    } 

    delete[]hold;
}

// This solution uses two indices to find and count duplicates in a sorted array
template <class T>
void duplicateSol1(Array<T>* arr) {
    for (int i = 0; i < arr->Length(); i++) {
        // If we find that the next is a duplicate, go in deeeeep.
        if (arr->Get(i) == arr->Get(i + 1)) {
            int j = i + 1;
            // Go up as many times as we find duplicates with index j
            while (arr->Get(j) == arr->Get(i)) j++;
            // The difference between index j and i determine how many times that value was duplicated.
            std::cout << "\t\t" << "Value: " << arr->Get(i) << " duplicated " << j - i << " times." << std::endl;
            // Move index i up to where we finished checking.
            i = j - 1;
        }
    }
}

// This solution uses a hashmap.
template <class T>
void duplicateSol2(Array<T>* arr) {
    // Since it's sorted, we just need the largest/last value
    int* map = new int[arr->Get(arr->Length()-1)];

    // Initialize all indices to 0;
    for (int i = 0; i < arr->Get(arr->Length()-1); i++)
        map[i] = 0;

    // Same thing as before, extract values out of array and use as indices.
    for (int i = 0; i <= arr->Length(); i++)
        map[arr->Get(i)-1]++;

    for (int j = arr->Get(0); j <= arr->Get(arr->Length()-1); j++)
        if (map[j - 1] > 1) {
            std::cout << "\t\t" << "Value: " << j << " duplicated " << map[j-1] << " times." << std::endl;
        }
}

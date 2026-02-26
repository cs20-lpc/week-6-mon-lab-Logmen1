#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

template <typename T>
T findMaxRecTail(const T arr[], const int size, int index = 0)
{
    // TO DO: Implement your code
    if (index == size - 1)
        return arr[index];

    T maxOfRest = findMaxRecTail(arr, size, index + 1);

    if (arr[index] > maxOfRest) {
        maxOfRest = arr[index];
    }
    return maxOfRest;
}



template <typename T>
T findMaxRecBinarySplit(const T arr[], const int left, const int right)
{
    // TO DO: Implement your code
    
    // the base case: one element
    if (left == right)
        return arr[left];

    // Find midpoint
    int mid = left + (right - left) / 2;

    // recursively find max in left and right halves
    T leftMax = findMaxRecBinarySplit(arr, left, mid);
    T rightMax = findMaxRecBinarySplit(arr, mid + 1, right);

    // return the larger of the two
    if (leftMax > rightMax) {
        return leftMax;
    }
    else
        return rightMax;
}




int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
        << findMaxRecTail(myArray, SIZE) << endl
        << "From Binary split:"
        << findMaxRecBinarySplit(myArray, 0, SIZE - 1) << endl
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}


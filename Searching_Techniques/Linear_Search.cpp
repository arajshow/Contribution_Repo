// Linear search is a very simple search algorithm. In this type of search, a sequential search is made over all items one by one. Every item is checked and if a match is found then that particular item is returned, otherwise the search continues till the end of the data collection.

// Language: cpp
// Path: Searching_Techniques\Linear_Search.cpp

// Linear search in C++

#include <iostream>
using namespace std;

int main()
{
    int array[100], search, c, n;

    cout << "Enter number of elements in array : ";
    cin >> n;

    cout << "Enter " << n << " integers : ";

    // Loop to store each number in array
    for (c = 0; c < n; c++)
        cin >> array[c];

    cout << "Enter a number to search : ";
    cin >> search;

    // Loop to iterate through array to search for number
    for (c = 0; c < n; c++)
    {
        if (array[c] == search)
        { // If the number is found
            cout << search << " is present at location " << c + 1 << ".n";
            break;
        }
    }
    if (c == n)
        cout << search << " isn't present in the array.

    
    return 0;
}

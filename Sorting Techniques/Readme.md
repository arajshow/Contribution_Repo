Sorting is a technique that is implemented to arrange the data in a specific order. Sorting is required to ensure that the data which we use is in a particular order so that we can easily retrieve the required piece of information from the pile of data.
Here, we'll discuss 6 sorting techniques:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Shell Sort
5. Quick Sort
6. Merge Sort


### Bubble Sort
It is the most basic sorting algorithm with complexity of O(n<sup>2</sup>). Here is it's implementation in c++ :-
```cpp
void bubble_sort (int a[], int n) {
    int i, j, t;
    for(i = 0; i < n-1; ++i) {
        for(j = 0; j < n-i-1; ++j) {
            if(a[j+1] < a[j]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}
```
The problem with above implementation is even if array is sorted the program still keeps running we can solve this problem in the below implementation :-
```cpp
void bubble_sort (int a[], int n) {
    int i, sorted;
    do {
        sorted = 1;
        --n;
        for (i = 0; i < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                  /* Swap adjacent pair of items. */
                  int t = a[i];
                  a[i] = a[i + 1];
                  a[i + 1] = t;
                  sorted = 0;
            }
        }
    } while (!sorted);
}
```
### Selection Sort
Let's say __a__ is the array we have to sort then first we select the minimum element in the range __a[0] - a[n-1]__ where n is the size of the array then replace that element with __a[0]__ then again search for minimum element in the range __a[1] - a[n-1]__ and replace it with a[1] and keep on going like this. So we are searching for minimum element and then putting it in right place.
```cpp
void selection_sort(int a[], int n) {
    int i, j, iMin, t;
    for(j = 0; j < n-1; ++j) {
        iMin = j;
        for(i = j + 1; i < n; ++i) {
            if(a[i] < a[iMin])
                iMin = i;
        }
       // only swap if indexes are diffrent
        if(iMin != j) {
            t = a[iMin];
            a[iMin] = a[j];
            a[j] = t;
        }
    }
}
```
### Insertion Sort
Insertion sort also has complexity of O(n<sup>2</sup>) but is practically more efficient than the above 2 mentioned.
```cpp
void insertion_sort(int a[], int n) {
    int i,j, t;
    for(i=1;i<n;++i) {
        for(j = i; j > 0 && a[j] < a[j-1]; --j) {
            t = a[j];
            a[j] = a[j-1];
            a[j-1] = t;
        }
    }
}
```
A more efficient implementation
```cpp
void insertion_sort(int a[], int n) {
    int i,j, t;
    for(i=1;i<n;++i) {
        t = a[i];
        for(j = i; j > 0 && t < a[j-1]; --j) 
            a[j] = a[j-1];
        a[j] = t;
    }
}
```
### Shell Sort
It is modified version of insertion sort. As we can generalise the fact that if array is almost sorted insertion sort would take O(n) time. Shell sort uses the same conecpt but unlike insertion sort where we compare consecutive elements it compares elements at varying gaps.Here we decide the gap by 3h + 1 method.Average complexity of algorithm is O(n<sup>3/2</sup>) or O(log<sup>2</sup>n).
```cpp
void shell_sort(int a[], int n) {
    int i, j, t, h = 1;
    while(h < n/3) h = 3*h + 1; // vary the size as 1, 4, 13, 40, 121, 364, 1093 ...
    while(h >= 1) {
        // h sort the array
        for(i = h; i < n; ++i) {
            t = a[i];
            for(j = i; j >= h && t < a[j-h]; j-=h)
                a[j] = a[j-h];
            a[j] = t;
        }
        h /= 3;
    }
}
```
### Quick Sort
General runtime complexity is O(nlog(n)) and in worst case that is when array is reverse sorted it is O(n<sup>2</sup>).

```cpp
int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l]; // you can also choose a random pivot here we go for simple approach
   i = l; j = r+1;

   while( 1)
   {
       do ++i; while( a[i] <= pivot && i <= r );
       do --j; while( a[j] > pivot );
       if( i >= j ) break;
       t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}


void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
       // divide and conquer
       j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
}
```

### Merge Sort

```cpp

void merge(int a[], int l, int m, int r, int aux[]) {
    int i = l, j = m + 1;
    for(int k = l; k <= r; ++k) aux[k-l] = a[k];
    for(int k = l; k <= r; ++k ) {
        if(i > m) a[k] = aux[j++ - l];
        else if(j > r) a[k] = aux[i++ - l];
        else if(aux[i - l] < aux[j - l]) a[k] = aux[i++ - l];
        else a[k] = aux[j++ - l];
    }
}

void sort_util(int a[], int l, int r, int aux[]) {
    if (l < r) {
         int m = l + (r-l)/2;
         sort_util(a, l, m, aux);
         sort_util(a, m+1, r, aux);
         merge(a, l, m, r, aux);
    }
}

void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int *aux = new int[l-r+1]; // define an auxillary array we will be passing the same array around.
        sort_util(a, l, r, aux);
    }
}
```

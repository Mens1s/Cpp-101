#include <iostream>
#include <vector> // q2
#include <bits/stdc++.h> // q2

using namespace std;
const int MAX_INT = 32222222;
const int MIN_INT = -32222221;
/*
    Q2-)
        a) Implement a global templated C++ function that takes an array as a parameter. 
        Your function returns the median of the array without copying or modifying the array.
*/
template<typename T, size_t N>
T getMedian(T (&arr)[N]){
    T prev_min = MIN_INT;
    T curr_min = MAX_INT;
    T temp;
    for(int step = 0; step < N / 2 + 1; step++){
        
        curr_min = MAX_INT;
        
        for(int l = 0; l < N; l++)
            if(arr[l] > prev_min)   
                if(curr_min > arr[l])
                    curr_min = arr[l];
        
        temp = prev_min;
        prev_min = curr_min;

    }

    if(N % 2 == 0)
        return ( temp + curr_min ) / 2.0;
    
    else
       return prev_min;
    
}

int main(){
    double array[10] = {1,3,5,7,9,2,4,6,8,10};

    cout << getMedian(array);

    return 0;
}
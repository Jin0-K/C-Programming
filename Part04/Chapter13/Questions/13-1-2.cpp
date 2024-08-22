#include <iostream>

/*
int SumArray(int arr[], int len) {
    int sum = 0;
    for(int i=0; i < len; i++)
        sum += arr[i];
    
    return sum;
}
*/

template <typename T>
T SumArray(T arr[], int len) {
    T sum = 0;
    for (int i=0; i < len; i++)
        sum += arr[i];

    return sum;
}

int main(void) {
    int array[10];

    // Put values in array and print it out
    std::cout << "Array: [";
    for (int i=0; i < 10; i++) {
        array[i] = (i+1)*2;
        if (i) {
            std::cout << ", " << array[i];
        }
        else {
            std::cout << array[i];
        }
    }
    std::cout << ']' << std::endl;
    
    int array_sum = SumArray<int>(array, 10);
    std::cout << "Sum of the array: " << array_sum << std::endl;

    return 0;
}
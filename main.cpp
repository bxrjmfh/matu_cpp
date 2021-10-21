#include <iostream>

using namespace std;

template<typename T>T get_min(T* arr,int size){
    T temp=arr[0];
    for (int i = 1; i < size; ++i) {
        if(arr[i]<temp){
            temp=arr[i];
        }
    }
    return temp;
}
int main()

{

    int arr_int[6] = { 1, 2, 3, 4, 5, 6 };

    double arr_double[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    cout << get_max(arr_int, 6) << endl;

    cout << get_max(arr_double, 6) << endl;

    return 0;

}
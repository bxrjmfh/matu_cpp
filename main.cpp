#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>


using namespace std;
void sort(vector<int>arr) {
    for (int i = arr.size()-1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            int temp;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    vector<int> arr;
    int counter = 0;
    int temp = -1;
    do {
        cin >> temp;
        if (temp < 0) { break; }
        arr.push_back(temp);
        counter++;
        if (counter == 10) { break; }
    } while (1);

    vector<int> arr_even, arr_odd;
    for (int i=0;i<arr.size();i++) {
        if (arr[i] % 2 == 0) {
            arr_even.push_back(arr[i]);
        }
        else {
            arr_odd.push_back(arr[i]);
        }
    }
    sort(arr_odd);
    sort(arr_even);

    for (int i=0;i<arr_odd.size();i++ ) { cout << arr_odd[i] << " "; }
    for (int i=0;i<arr_even.size();i++ ) { cout << arr_even[i] << " "; }

}
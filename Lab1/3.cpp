#include <iostream>
using namespace std;

int main(){
    int arr[10];

    cout << "Enter the numbers in the array: " << endl;

    for(int i =0; i<10;i++){
        cin >> arr[i];
    };

    int max = arr[0];
    int min = arr[0];

    for(int i = 0; i<10; i++){
        if(arr[i]>max){ max = arr[i];};
        if(arr[i]<min){ min = arr[i];};
    }
    
    cout << "The max of this array is " << max << endl; 
    cout << "The min of this array is " << min << endl; 


    return 0;

};
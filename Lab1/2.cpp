#include <iostream>
using namespace std;

int main(){
    int arr[10];
    cout << "Enter the numbers in the array: " << endl;
    for(int i =0; i<10;i++){
        cin >> arr[i];
    };
    int evenSum = 0;
    for(int i = 9; i>=0; i--){
        if(arr[i]%2 == 0) evenSum++;
        cout << arr[i] << endl;
    }
    
    cout << "The amount of even numbers are " << evenSum << endl; 

    return 0;

};
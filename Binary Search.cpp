#include <iostream>

using namespace ::std;

int binsrch(int *a, int x, int low, int high){
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < a[mid]){
            high = mid - 1;
        }else if(x>a[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int v[15] = {23, 31, 36, 48, 59, 70, 76, 88, 99, 108, 120, 132, 154, 160, 177};

    cout << binsrch(v, 108, 5, 10);
    cout << endl;
    return 0;
    
}
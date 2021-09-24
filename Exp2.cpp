#include <iostream>

using namespace ::std;

int main(){
    double x[3][4]={
        {13.5,24.88,66.28,30.0},
        {2.84,412.15,13.2,9.9},
        {15.5,38.89,12.5,16.18}
    };
    double y[24];
    cout << "The x matrix:\n";

    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4;j++){
            cout << " " <<x[i][j] << " ";
            if(j==3){
                cout << endl;
            }
        }
    }
    cout << endl;
    cout << "The y array:\n";
    int counter = 0;

    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4;j++){
            y[counter] = x[i][j];
            counter++;
        }
    }
    counter = 0;

    while (counter < 12)
    {
        cout << " " << y[counter] << " ";
        counter++;
    }
    cout << endl;
    return 0;
}
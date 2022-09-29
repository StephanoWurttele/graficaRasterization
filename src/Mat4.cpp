//
// Created by stephano.wurttele on 29/09/2022.
//

#include "Mat4.h"
#include <iostream>

using namespace std;

void Mat4::print(){
    int i, j;
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < 4; ++i)
        for(j = 0; j < 4; ++j)
        {
            cout << " " << mat[4*i+j];
            if(j == 4-1)
                cout << endl;
        }

}

Mat4 Mat4::multiplicacion(Mat4 b) {
    int i,j,k;
    Mat4 mult(1);
    for(i = 0; i < 4; ++i)
        for(j = 0; j < 4; ++j)
            for(k = 0; k < 4; ++k)
                mult.mat[4*i+j] += mat[i*4+k] * b.mat[4*k+j];
    return mult;
}
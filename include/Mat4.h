//
// Created by stephano.wurttele on 29/09/2022.
//

#ifndef LAB7_MAT4_H
#define LAB7_MAT4_H

class Mat4{
public:
    float mat[16] = {0,0,0,0,
                  0,0,0,0,
                  0,0,0,0,
                  0,0,0,0};
    Mat4(bool identity = false){
        if(!identity) return;
        mat[0] = mat[5] = mat[10] = mat[15] = 1;
    };
    // type 0 = escala
    // type 1 = traslacion
    Mat4(float m11, float m22, float m33, int type){
        int a = 0, b = 5, c = 10;
        if(type == 1){ a = 3; b = 7; c = 11;};
        mat[a] = m11;
        mat[b] = m22;
        mat[c] = m33;
    };
    Mat4 multiplicacion(Mat4 b);
    void print();

};


#endif //LAB7_MAT4_H

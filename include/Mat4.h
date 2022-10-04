//
// Created by stephano.wurttele on 29/09/2022.
//

#ifndef LAB7_MAT4_H
#define LAB7_MAT4_H

class Mat4{
public:
    enum axis {x, y, z};

    float mat[16] = {0,0,0,0,
                  0,0,0,0,
                  0,0,0,0,
                  0,0,0,0};
    Mat4(bool identity = false){
        if(!identity) return;
        identidad();
    };
    // type 0 = escala
    // type 1 = traslacion
    Mat4(float m11, float m22, float m33, int type){

        int a = 0, b = 5, c = 10;
        if(type == 1){ identidad(); a = 3; b = 7; c = 11;};
        mat[a] = m11;
        mat[b] = m22;
        mat[c] = m33;
        mat[15] = 1;
    };

    Mat4 multiplicacion(Mat4 b);
    Mat4 rotacion(float theta, axis axi = x);
    void print();

    void identidad() {
        mat[0] = mat[5] = mat[10] = mat[15] = 1;
    }

};


#endif //LAB7_MAT4_H

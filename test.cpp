#include "Vector.hpp"
#include <stdio.h>

void printVect(Vector v, bool jump = false){
    printf("Vector(");
    for(int i = 0; i<v.getDim();i++){
        printf("%f", v.get(i));
        if(i != v.getDim()-1){
            printf(";");
        }
    }
    printf(")");
    if(jump){
        printf("\n");
    }
}

int main(){
    Vector v1 = Vector();
    Vector v2 = Vector(3);
    Vector v3 = Vector(v2);
    double arr[] = {1.0, 2.0, 3.0};
    for(int i = 0;i<3;i++){
        v2.setValueAt(i,arr[i]);
    }
    printVect(v2,true);
    printVect(v1,true);
    printVect(v3,true);
    Vector v4 = Vector(arr, 3);
    printVect(v4, true);
    Vector v5 = Vector(v4);
    if(v5 == v4){
        printf("Equals vector\n");
    }
    v5 = v4 + v4;
    printVect(v5, true);
    v5 = v4*3;
    printVect(v5, true);
    v5 = v4 - v4;
    printVect(v5, true);
    printf("\n");
}
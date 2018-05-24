#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

FILE * f;

int main() {
    int n;
    f = fopen("input.data", "r");
    fscanf("%i", &n);
    float M[3][n+1];
    for(int i = 1; i <= n; i++) {
        fscanf("%i%i", &M[0][i], &M[1][i]);
        M[2][i] = sqrt(pow(M[0][i], 2)+pow(M[1][i], 2));
    }
    fclose(f);
    for(int i = 2; i <= n; i++) {
        int fiu = i;
        int tata = i/2;
        while(M[2][fiu] < M[2][tata] && tata > 0) {
            swap(M[0][fiu], M[0][tata]);
            swap(M[1][fiu], M[1][tata]);
            swap(M[2][fiu], M[2][tata]);
            fiu = tata;
            tata = fiu/2;
        }
    }
    f = fopen("output.data", "w");
    for(int i = 1; i <= n; i++) {
        fprintf("%i %i %i\n", M[0][i], M[1][i], M[2][i]);
    }
    fclose(f);
    return 0;
}

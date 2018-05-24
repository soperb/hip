#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

FILE * f;

int main() {
    int n, m;
    f = fopen("input.data", "r");
    fscanf(f, "%i %i", &n, &m);
    double M[3][n+1];
    for(int i = 1; i <= n; i++) {
        fscanf(f, "%lf %lf", &M[0][i], &M[1][i]);
        printf("%lf %lf\n", M[0][i], M[1][i]);
        M[2][i] = sqrt(M[0][i]*M[0][i]+M[1][i]*M[1][i]);
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
        fprintf(f, "%lf %lf %lf\n", M[0][i], M[1][i], M[2][i]);
    }
    for(int i = m; i < n; i++) {
        swap(M[0][i], M[0][i+1]);
        swap(M[1][i], M[1][i+1]);
        swap(M[2][i], M[2][i+1]);
    }
    for(int i = m; i < n; i++) {
        int fiu = i;
        int tata = i/2;
        if(M[2][fiu] < M[2][tata] && tata > 0) {
            swap(M[0][fiu], M[0][tata]);
            swap(M[1][fiu], M[1][tata]);
            swap(M[2][fiu], M[2][tata]);
        }
    }
    for(int i = 1; i < n; i++) {
        fprintf(f, "\n%lf %lf %lf", M[0][i], M[1][i], M[2][i]);
    }
    fclose(f);
    return 0;
}

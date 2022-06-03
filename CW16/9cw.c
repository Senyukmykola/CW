//9.1.c

#include <stdio.h>
#include <stdlib.h>

float sum_sqr(float* arr, int n) {
    float s = 0.f;
    for (int i = 0; i < n; i++) {
        s += arr[i] * arr[i];
    }
    return s;
}

void main() {
    int n;
    scanf("%d", &n);
    float* mas = (float*)malloc(n * sizeof(float)); // dynamic array
    if (!mas) {
        printf("error in alloc memory");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%f", &mas[i]);
    }

    printf("s=%f", sum_sqr(mas, n));

    free(mas);
}

int input(int* m){
    int i=0;
    do{
        printf("a[%d]=",i);
        scanf("%d",&m[i]);
    } while(m[i++]!=0);

    return i-2;
}




//9.2.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int input(int* n) {
    int i = 0;
    do {
        printf("a[%d]=", i);
        scanf("%d", &n[i]);
    } while (n[i++] != 0);

    return i - 2;
}

int main() {
    int* memory = (int*)malloc(100 * sizeof(*memory));
    int n = input(memory);
    int cnt = 0, cnnt = 0;

    for (int i = 0; i < n; i++) {
        double tmp = sqrt(memory[i]);
        if (tmp * tmp == memory[i]) cnt++;
    }

    for (int i = 0; i < n; i++) {
        double tmp = cbrt(memory[i]);
        if (tmp * tmp * tmp == memory[i]) cnnt++;
    }

    printf("number of squeres = %d", cnt);
    printf("number of cubes = %d", cnnt);
    free(memory);
}



//9.3.c

#include <stdio.h>
#include <stdlib.h>

double* input_vector(int n) {
    double* a = (double*)calloc(n, sizeof(*a));
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }
    return a;
}

double* sub_vect(const double* v1, const double* v2, const unsigned n) {
    double* res = (double*)calloc(n, sizeof(double));
    for (int i = 0; i < n; i++) {
        res[i] = v1[i] - v2[i];
    }
    return res;
}

int sub_v2(const double* v1, const double* v2, double* v4, int n) {
    for (int i = 0; i < n; i++) {
        v4[i] = v1[i] - v2[i];
    }
    return 0;
}

void free_vect(double* v1) {
    free(v1);
}

void vect_out(double* v, int n) {
    printf("(%g", v[0]);
    for (int i = 0; i < n; i++) {
        printf(", %g", v[i]);
    }
    printf(")\n");
}

int main() {
    int n;
    printf("n=");
    scanf("%d", &n);

    double* v1 = input_vector(n);
    double* v2 = input_vector(n);

    double* v3 = sub_vect(v1, v2, n);
    vect_out(v3, n);

    double v4[5];
    sub_v2(v1, v2, v4, n);
    vect_out(v4, n);

    free_vect(v1);
    free_vect(v2);
}



//9.4.c

#include <stdio.h>
#include <stdlib.h>

double** input_mat(int n) {
    double** a = (double**)calloc(n, sizeof(*a)); // sizeof(*a)) has double* type
    for (int i = 0; i < n; i++) {
        a[i] = (double*)calloc(n, sizeof(*a[i]));
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    return a;
}

void free_matr(double** v1, int n) {
    for (int i = 0; i < n; i++) {
        free(v1[i]);
    }
    free(v1);
}

double** mult_matr( double** v1,  double** v2, unsigned dim) {
    double** res = (double**)calloc(dim, sizeof(double*));
    for (unsigned i = 0; i < dim; i++) {
        res[i] = (double*)calloc(dim, sizeof(res[i]));
        for (unsigned j = 0; j < dim; j++) {
            for (unsigned k = 0; k < dim; k++) {
                res[i][j] += v1[i][k] * v2[i][k];
            }
        }
    }
    return res;
}

void mat_out(double** v, unsigned n) {
    unsigned i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%g  ", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("n=");
    scanf("%d", &n);
    double** v1 = input_mat(n);
    double** v2 = input_mat(n);
    double** v3 = mult_matr(v1, v2, n);
    mat_out(v3, n);
    free_matr(v1, n);
    free_matr(v2, n);
    free_matr(v3, n);
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//Рассказать  про то, что нужно вынести в отдельные файлы, раздельная линковка, хэдеры

enum NUMROOTS {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
};

int LineEq (const double b, const double c, double* x1) {
    if (b == 0) {
        if (c == 0) {
            return INF_ROOTS;
        }
        else {
            return NO_ROOTS;
        }
    }
    else {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}


int QuadEq (const double a, const double b, const double c, double* x1, double* x2) {
    double discr = b * b - 4 * a * c;

    if (discr >= 0) {
        *x1 = (-b + sqrt(discr)) / (2 * a);
        *x2 = (-b - sqrt(discr)) / (2 * a);
        return TWO_ROOTS;
    }
    else {
        return NO_ROOTS;
    }

}


int combo_eq (const double a, const double b, const double c, double* x1, double* x2) { //TODO Name of fucntion
    if (a == 0) {
        return LineEq (b, c, x1);
    }
    else {
        return QuadEq (a, b, c, x1, x2);
    }
}

void NumVariables () {
    printf("\n Вы ввели ахинею \n\n Попробуйте снова!!!\n\n");
    while (getchar() != '\n') { continue; }
}

int main () {
    setlocale (LC_ALL, "Rus");
    printf ("\n\n ----------------------- \n Квадратное уравнение имеет вид ax^2+bx+c=0 \n");
    printf (" Введите переменные а, b, c: ");
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    while (scanf ("%lg %lg %lg", &a, &b, &c) != 3)  {
        NumVariables ();
    }
    int nRoots = combo_eq(a, b, c, &x1, &x2);
    switch (nRoots) {
        case INF_ROOTS: printf ("\n Бесконечное количество решений \n");
        break;

        case ONE_ROOT: printf (" x1 = %lg", x1);
        break;

        case TWO_ROOTS: printf ("\n x1= %lg \n x2= %lg \n", x1, x2);
        break;

        case NO_ROOTS: printf ("\n Нет решений в вещественных числах \n");
        break;
     }

    return 0;
}

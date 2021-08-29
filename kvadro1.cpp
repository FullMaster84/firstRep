#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <assert.h>

//Рассказать  про то, что нужно вынести в отдельные файлы, раздельная линковка, хэдеры

/*! These constants are used in functions of type INT
    so that functions will return to them.
*/
enum NUMROOTS {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
};

const double INFEL = 0.0000001;

/*! compares the entered values of variables with an error
*/
bool CmpZero (double value_type) {
    return fabs(value_type) < INFEL;
}


/*!  This function serves as a special case of solving the quadratic equation
     @param [in]  b ( coefficient )
     @param [in]  c ( coefficient )
     @param [out] x1 ( root of equation )

     @return Number of roots

     @note Constants are used: ONE_ROOTS, NO_ROOTS.
*/
int LineEq (const double b, const double c, double* x1) {
    assert (std:: isfinite (b));
    assert (std:: isfinite (c));
    assert (x1 != NULL);

    if (CmpZero (b)) {
        if (CmpZero (c)) {
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


/*!  This function is a solution to the quadratic equation
     @param [in]  a ( coefficient )
     @param [in]  b ( coefficient )
     @param [in]  c ( coefficient )
     @param [out] x1 ( 1st root of equation )
     @param [out] x2 ( 2nd root of equation )

     @return Number of roots

     @note Constants are used: TWO_ROOTS, NO_ROOTS.
*/
int QuadEq (const double a, const double b, const double c, double* x1, double* x2) {
    assert (std:: isfinite (a));
    assert (std:: isfinite (b));
    assert (std:: isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    double discr = b * b - 4 * a * c;

    if (discr >= 0) {
        if (CmpZero (discr)){
            *x1 = *x2 = -b / (2 * a);
            return ONE_ROOT;
        }
        else {
            *x1 = (-b + sqrt(discr)) / (2 * a);
            *x2 = (-b - sqrt(discr)) / (2 * a);
            return TWO_ROOTS;
        }
    }
    else {
        return NO_ROOTS;
    }

}


/*! \brief Combines special cases of solving a quadratic equation.
    Does checking for variables and roots.

     @param [in]  a ( coefficient )
     @param [in]  b ( coefficient )
     @param [in]  c ( coefficient )
     @param [out] x1 ( 1st root of equation )
     @param [out] x2 ( 2nd root of equation )

     @return Number of roots
*/
int ComboEq (const double a, const double b, const double c, double* x1, double* x2) {
    assert (std:: isfinite (a));
    assert (std:: isfinite (b));
    assert (std:: isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (CmpZero (a)) {
        return LineEq (b, c, x1);
    }
    else {
        return QuadEq (a, b, c, x1, x2);
    }
}


/*! This function checks the entered parameters of the coefficients for numerical values.
*/
void NumVariables () {
    printf("\n Вы ввели ахинею \n\n Попробуйте снова!!!\n\n");
    while (getchar() != '\n') { continue; }
}


/*! The main function that includes all the others.
    When entering data for a quadratic equation, outputs the answer depending on the data.
*/
int main () {
    setlocale (LC_ALL, "Rus");
    printf ("\n\n ----------------------- \n Квадратное уравнение имеет вид ax^2+bx+c=0 \n");
    printf (" Введите переменные а, b, c: ");
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    while (scanf ("%lg %lg %lg", &a, &b, &c) != 3)  {
        NumVariables ();
    }
    int nRoots = ComboEq(a, b, c, &x1, &x2);
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

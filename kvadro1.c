#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
setlocale (LC_ALL, "Rus");
double a, b, c, Discr, x1, x2;
printf ("Квадратное уравнение имеет вид ax^2+bx+c=0 \n");
printf ("Введите переменные а, b, c: ");
scanf ("%lg %lg %lg", &a, &b, &c);

Discr= b*b - 4*a*c;
if (a==0){
    if (b==0) {
        c=0;
        printf ("Бесконечное количество решений");
        }
    else {
        x1= -c/b;
        printf ("\n x1= %lg \n", x1);
        }
}
else{
    if (Discr>=0) {
        x1= (-b+sqrt(Discr))/(2*a);
        printf ("\n x1= %lg \n", x1);
        x2= (-b-sqrt(Discr))/(2*a);
        printf ("x2= %lg \n", x2);
        }
    else {
        printf ("\n Нет решения в вещественных числах");
        }

}

return 0;
}

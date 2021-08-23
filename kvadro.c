#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
   setlocale (LC_ALL, "Rus");
   int a, b, c, D;
   float x1, x2;
   printf ("Квадратное уравнение имеет вид ax^2+bx+c=0 \n");
   printf ("Введите переменную а: ");
   scanf ("%d", &a);
   printf ("Введите переменную b: ");
   scanf ("%d", &b);
    printf ("Введите переменную c: ");
   scanf ("%d", &c);
    D= b*b - 4*a*c;
    printf ("\n");
if (D>=0) {
    x1= (-b+sqrt(D))/(2*a);
printf ("\n x1= %f \n", x1);
 x2= (-b-sqrt(D))/(2*a);
printf ("x2= %f \n", x2);
}
else {
    printf ("\n Нет решения в вещественных числах");
}


return 0;
}

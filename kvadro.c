#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
   setlocale (LC_ALL, "Rus");
   int a, b, c, D;
   float x1, x2;
   printf ("���������� ��������� ����� ��� ax^2+bx+c=0 \n");
   printf ("������� ���������� �: ");
   scanf ("%d", &a);
   printf ("������� ���������� b: ");
   scanf ("%d", &b);
    printf ("������� ���������� c: ");
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
    printf ("\n ��� ������� � ������������ ������");
}


return 0;
}

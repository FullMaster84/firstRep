#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Ïðîâåðèòü âåðíîñòü ââîäà scanf, íåñêîëüêî ïîïûòîê
// ôóíêöèè
int main (){
    setlocale (LC_ALL, "Rus");
    printf ("\n\n ----------------------- \n Êâàäðàòíîå óðàâíåíèå èìååò âèä ax^2+bx+c=0 \n");
    printf (" Ââåäèòå ïåðåìåííûå à, b, c: ");
    double a, b, c, Discr, x1, x2;
    int ret = scanf ("%lg %lg %lg", &a, &b, &c);
    int Quad_eq ()
    {
        if (ret == 3){
            if (a == 0) {
                if (b == 0) {
                    return 3;
                }
                else {
                    x1 = -c/b;
                    return 1;
                }
            }
            else {
                Discr = b*b - 4*a*c;
                if (Discr >= 0) {
                    x1 = (-b + sqrt(Discr)) / (2*a);
                    x2 = (-b - sqrt(Discr)) / (2*a);
                    return 2;
                    }
                else {
                    return 0;
                    }
        }
    }
         else {
            return -1;
         }
    }
        int nRoots = Quad_eq(a, b, c, &x1, &x2);
        switch (nRoots){
            case 3: printf ("Áåñêîíå÷íîå êîëè÷åñòâî ðåøåíèé");
            break;
            case 1: printf (" x1 = %lg", x1);
            break;
            case 2: printf ("\n x1= %lg \n  x2= %lg \n", x1, x2);
            break;
            case 0: printf ("\n Íåò ðåøåíèé â âåùåñòâåííûõ ÷èñëàõ");
            break;
            case -1: printf("\n Âû ââåëè àõèíåþ \n\n Ïîïðîáóéòå ñíîâà!!!\n\n"); return main ();
            break;
            }
    }

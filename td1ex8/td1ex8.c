#include <stdio.h>
#include <stdlib.h>

/**
 Mini calculatrice pour entiers
 Pour les opérations sur les bits
 afficher les résultas en Hex
*/


int main()
{
    char op;
    int a, b;
    int c;
    printf("Bonjour!\n");
    printf("Programme Mini-Calculatritre pour entiers\n");
    printf("Pour Sortir Tapez Ctrl + C !\n");
    do
    {
        printf("Saisir une operation!\n");
        scanf("%d %[+-*/%&|^] %d", &a ,&op, &b);
        switch(op)
        {
                case '+':
                    printf("%d %c %d = %d\n", a , op , b , a + b);
                    break;
                case '-':
                    printf("%d %c %d = %d\n", a , op , b , a - b);
                    break;
                case '*':
                    printf("%d %c %d = %d\n", a , op , b , a * b);
                    break;
                case '/':
                    printf("%d %c %d = %d\n", a , op , b , a / b);
                    break;
                case '%':
                    printf("%d %c %d = %d\n", a , op , b , a % b);
                    break;
                case '&':
                    printf("%x %c %x = %x\n", a , op , b , a & b);
                    break;
                case '|':
                    printf("%x %c %x = %x\n", a , op , b , a | b);
                    break;
                case '^':
                    printf("%x %c %x = %x\n", a , op , b , a ^ b);
                    break;
                default:
                    printf("Invalid Operator\n");
        }
    } while((c = getchar()) != EOF );
    printf("Au revoir....");
    return 0;
}

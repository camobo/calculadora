#include<op1.h>
#include<op2.h>
#include<stdio.h>

int main(void) {
	int num1, num2;
	printf("*************************************\n");
	printf("*CALCULADORA*************************\n");
	printf("*************************************\n");

	printf("Introduce un número ");
	scanf("%d", &num1);
	printf("Ahora introduce otro ");
	scanf("%d", &num2);

	int resultado = suma(num1, num2);
	printf("El resultado de la suma es: ");
	printf("%d\n", resultado);
}

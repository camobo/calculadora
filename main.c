#include<op1.h>
#include<op2.h>
#include<stdio.h>

int main(void) {
	int num1, num2, opcion, resultado;
	printf("*************************************\n");
<<<<<<< HEAD
	printf("*CALCULADORA********master*****************\n");
=======
	printf("*CALCULADORA**testing***********************\n");
>>>>>>> testing
	printf("*************************************\n");

	printf("Elige la operación que quieres hacer:\n");
	printf("\t1. Sumar\n");
	printf("\t2. Restar\n");
	printf("\t3. Multiplicar\n");
	printf("\t4. Dividir\n");
	scanf("%d", &opcion);

	if ( opcion < 1 || opcion > 4) {
		printf("La opción que has elegido no es válida\n");
		return 1;
	}

	printf("Introduce un número: ");
	scanf("%d", &num1);
	printf("Ahora introduce otro: ");
	scanf("%d", &num2);

	switch(opcion) {
		case 1:
			resultado = suma(num1, num2);
			printf("El resultado de la operación es: %d\n", resultado);
			break;	
		case 2:
			resultado = resta(num1, num2);
			printf("El resultado de la operación es: %d\n", resultado);
			break;
		case 3:	
			resultado = multiplicacion(num1, num2);
			printf("El resultado de la operación es: %d\n", resultado);
			break;
		case 4:
			if ( num2 == 0 ) {
				printf("La división por 0 es una indeterminación\n");
				return 1;
			}

			resultado = division(num1, num2);
			printf("El resultado de la operación es: %d\n", resultado);
			break;
	}
			

	return 0;
}

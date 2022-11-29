#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define lugares_disponibles 10




void presentacion () {
	
	printf("________________ SISTEMA DE REFUGIO CANINO ___________________ \n\n\n");
	
}




struct Perro {

	char fecha_ingreso[130];
	char nombre[50];
	char raza[30];
	char color[30];
	int edad;
	float peso;
	
};




void registrarDatosPerro (struct Perro registro[lugares_disponibles]) {
	
	printf("REGISTRAR NUEVO PERRO \n\n\n");
	
	int contador_lugares = 10;
	
	for (int i = 1; i <= lugares_disponibles; i++) {
		
		fflush(stdin);
		printf("Fecha: ");
		gets(registro[i].fecha_ingreso);
		
		fflush(stdin);
		printf("Nombre: ");
		gets(registro[i].nombre);
		
		fflush(stdin);
		printf("Raza: ");
		gets(registro[i].raza);
		
		fflush(stdin);
		printf("Color: ");
		gets(registro[i].color);
		
		fflush(stdin);
		printf("Edad: ");
		scanf("%d", &registro[i].edad);
		
		fflush(stdin);
		printf("Peso: ");
		scanf("%f", &registro[i].peso);
		
		contador_lugares = contador_lugares -1;
		
		printf("\n\n");
		printf("Lugares disponibles: %i", contador_lugares);
		printf("\n\n");
		
	}
	
	if (contador_lugares == 0) {
		
		printf("\n\n");
		printf("Lo sentimos, ya no hay lugares disponibles");
		printf("\n\n");
		
	}
	
}




void finalizarRegistro(struct Perro registro[lugares_disponibles]) {
	
	system("cls");

	printf("TODOS LOS REGISTROS \n\n\n");
	
	printf("\n\n");
	
	for (int i = 1; i <= lugares_disponibles; i++) {
		
		printf("Fecha de ingreso: %s\n Nombre: %s\n Raza: %s\n Color: %s\n Edad: %i\n Peso: %.2f kg\n",
		registro[i].fecha_ingreso, registro[i].nombre, registro[i].raza, registro[i].color, registro[i].edad, registro[i].peso);
		
		printf("La clave numerica de tu perro es: %i\n\n", i);
		
	}
	
	printf("\n\n");
	
}




void desplegarDatosRegistro (struct Perro registro[lugares_disponibles]) {
	
	printf("CONSULTAR LOS REGISTROS \n\n");
	
	int clave_numerica;
	
	printf("Ingresa la clave numerica de tu perro para consultar su informacion: ");
	scanf("%d", &clave_numerica);
	printf("\n\n");
	
	for (int i = clave_numerica; i <= lugares_disponibles; i++) {
		
		if (clave_numerica == i) {
			
			printf("\n\n");
	

			printf("Fecha de ingreso: %s\n Nombre: %s\n Raza: %s\n Color: %s\n Edad: %i\n Peso: %.2f kg\n",
			registro[i].fecha_ingreso, registro[i].nombre, registro[i].raza, registro[i].color, registro[i].edad, registro[i].peso);
			
		}
		
	}
	
	printf("\n\n");
	
}




void salirSistema() {
	
	printf("Haz salido del sistema.");
	exit(1);
	
}




void errorMensaje() {
	
	printf("Esta opcion no es valida, intenta de nuevo.");
	exit(1);
	
}




void menuSistema () {
	
	int opcion_seleccionada;
	
	printf("Menu de opciones \n\n");
	
	do {
		
		printf("Ingresa el numero [1] para registrar a tu perro. \n");
		printf("Ingresa el numero [2] para consultar los datos de tu perro. \n");
		printf("Ingresa el numero [3] para salir del sistema. \n\n");
		
		printf("Ingresa una opcion: ");
		scanf("%i", &opcion_seleccionada);
		
		switch (opcion_seleccionada) {
			
			case 1:
				
				system("cls");
				struct Perro registro[lugares_disponibles];
				registrarDatosPerro(registro);
				finalizarRegistro(registro);
				
			break;
			
			case 2:
				
				system("cls");
				desplegarDatosRegistro(registro);
				
			break;
			
			case 3:
				
				system("cls");
				salirSistema();
				
			break;
			
			default:
			
				system("cls");
				errorMensaje();
				
			break;
			
		}
		
	} while (opcion_seleccionada != 4);
	
}


int main () {
	
	presentacion();
	menuSistema();
	
	getchar();
	return 0;
	
} 
/*
 * Funciones.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Patricio
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int SeleccionarOpcion()
{
	int opcionIngresada;
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	int opcion;
	float debitoAerolineas;
	float debitoLatam;
	float creditoAerolineas;
	float creditoLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float precioPorKmA;
	float precioPorKmL;

	do{
		printf("1. Ingresar Kilometros \n");
		printf("2. Ingresar Precio de Vuelos \n");
		printf("3. Calcular todos los costos \n");
		printf("4. Informar Resultados \n");
		printf("5. Carga forzada de datos \n");
		printf("6. Salir \n");

		printf("Elija una opcion: \n");
		scanf("%d", &opcionIngresada);

		switch(opcionIngresada)
		{
		case 1:
			printf("Ingrese una cantidad valida de Kilometros: \n");
			scanf("%f", &kilometros);
			printf("%2.f \n", kilometros);
			if(kilometros <= 0)
			{
				printf("Reingrese la cantidad de Kilometros. No debe ser menor o igual a 0.");
				scanf("%2f", &kilometros);
				printf("%f \n", kilometros);
			}
			break;
		case 2:
			printf("1. Aerolineas \n");
			printf("2. Latam \n");
			printf("Elija una opcion: ");
			scanf("%d", &opcion);

			switch(opcion)
			{
				case 1:
					printf("Ingrese el precio de vuelo para Aerolineas: \n");
					scanf("%f", &precioAerolineas);
					printf("%2.f \n", precioAerolineas);
					if(precioAerolineas <= 0)
					{
						printf("Reingrese el precio de Aerolineas. No debe ser menor o igual a 0.");
						scanf("%f", &precioAerolineas);
						printf("%2.f \n", precioAerolineas);
					}
					break;
				case 2:
					printf("Ingrese el precio de vuelo para Latam: \n");
					scanf("%f", &precioLatam);
					printf("%2.f \n", precioLatam);
					if(precioLatam <= 0)
					{
						printf("Reingrese el precio de Latam. No debe ser menor o igual a 0.");
						scanf("%f", &precioLatam);
						printf("%2.f \n", precioLatam);
					}
					break;
			}
			break;
		case 3:
			printf("Calculando... \n");
			debitoAerolineas = AumentoDescuento(1, precioLatam, 1, precioAerolineas);
			debitoLatam = AumentoDescuento(2, precioLatam, 1, precioAerolineas);
			creditoAerolineas = AumentoDescuento(1, precioLatam, 2, precioAerolineas);
			creditoLatam = AumentoDescuento(2, precioLatam, 2, precioAerolineas);
			bitcoinAerolineas = CalculoBitcoin(1, precioLatam, precioAerolineas);
			bitcoinLatam = CalculoBitcoin(2, precioLatam, precioAerolineas);
			precioPorKmA = PrecioPorKm(1, precioLatam, precioAerolineas, kilometros);
			precioPorKmL = PrecioPorKm(2, precioLatam, precioAerolineas, kilometros);

			break;
		case 4:
			printf("Aerolineas \n");
			printf("Tarjeta de Debito: %f \n", debitoAerolineas);
			printf("Tarjeta de Credito: %f \n", creditoAerolineas);
			printf("Bitcoin: %f \n", bitcoinAerolineas);
			printf("Precio por Kilometros: %f \n", precioPorKmA);
			printf("Latam \n");
			printf("Tarjeta de Debito: %f \n", debitoLatam);
			printf("Tarjeta de Credito: %f \n", creditoLatam);
			printf("Bitcoin: %f \n", bitcoinLatam);
			printf("Precio por Kilometros: %f \n", precioPorKmL);
			break;
		}


	} while(opcionIngresada != 6);

	return opcionIngresada;
}

float AumentoDescuento(int empresa, float precioLatam, float operacion, float precioAerolineas)
{
	float descuento;
	float aumento;

	if(empresa == 1 && operacion == 1)
	{
		descuento = precioAerolineas - (precioAerolineas * 0.10);

		return descuento;
	}
	else
	{
		if(empresa == 1 && operacion == 2)
		{
			aumento = precioAerolineas + (precioAerolineas * 0.25);

			return aumento;
		}
	}
	if(empresa == 2 && operacion == 1)
	{
	 	descuento = precioLatam - (precioLatam * 0.10);

		return descuento;
	}
	else
	{
		if(empresa == 2 && operacion == 2)
		{
			aumento = precioLatam + (precioLatam * 0.25);

			return aumento;
		}
	}
	return 0;
}
float CalculoBitcoin(int empresa, float precioAerolineas, float precioLatam)
{
	float bitcoin;

	if(empresa == 1)
	{
		bitcoin = precioAerolineas / 4626886,91;

		return bitcoin;
	}
	if(empresa == 2)
	{
		bitcoin = precioLatam / 4626886,91;

		return bitcoin;
	}
	return 0;
}
float PrecioPorKm(int empresa, float precioAerolineas, float precioLatam, float kilometros)
{
	float precioPorKm;

	if(empresa == 1)
	{
		precioPorKm = precioAerolineas / kilometros;

		return precioPorKm;
	}
	if(empresa == 2)
	{
		precioPorKm = precioLatam / kilometros;

		return precioPorKm;
	}
	return 0;
}




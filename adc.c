#include <math.h>
#include <wiringPi.h>
#include "iostream"
#include <stdio.h>

using namespace std;


//pines del Raspberry pi

#define d0 5
#define d1 6
#define d2 7
#define d3 8
#define d4 9
#define d5 10
#define d6 11
#define d7 12

int valor=0;

int adc(){
	int data [7]={0}; //Arreglo donde se guardan los bits que vienen del adc. TAmaño de 8 bits y inicializado en 0
	int decimal=0;   //Valor decimal del dato leido
	int i,y=0; //contadores
	
	//Obternicion de los valores enviados por el adc	
	data[0] = 0;//digitalRead(d0); //LSB del ADC
	data[1] = 1;//digitalRead(d1);
	data[2] = 0;//digitalRead(d2);
	data[3] = 0;//digitalRead(d3);
	data[4] = 1;//digitalRead(d4);
	data[5] = 1;//digitalRead(d5);
	data[6] = 0;//digitalRead(d6);
	data[7] = 1;//digitalRead(d7); //MSB del ADC
	// Conversion de valor binario a decimal
	for(i=0, y=0; i<8; i++,y++)
	{
		decimal += data[y] * pow(2, i); //El valor del subindice del arreglo data lo multiplica por la potencia de base 2 y
		//suma cada subindice para hacer la conversion de valor binario a decimal
	}

	return decimal; 
}

int  main(){
	valor=adc();
	cout<<valor<<endl;
	
	return 0;}

#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void main(){


FILE *q;
int i;

struct ALUMNO{

	int Legajo;
	char Carrera;
	char Nombre[20];
	};
struct PROFESOR{
	int DNI;
	int Sueldo;
	char Carrera;
	char Nombre[20];
	};
struct PERSONA{
	struct ALUMNO Alum;
	struct PROFESOR Prof;
	char CualEs;
	}x,y;

clrscr();

q=fopen("prueba.bin","wr");
printf("Legajo:");
scanf("%d",&x.Alum.Legajo);
fflush(stdin);
printf("Carrera");
scanf("%c",&x.Alum.Carrera);
fflush(stdin);
printf("Nombre:");
gets(x.Alum.Nombre);
fflush(stdin);
x.CualEs='A';
fwrite(&x,sizeof(PERSONA),1,q);
printf("DNI:");
fflush(stdin);

scanf("%d",&x.Prof.DNI);
fflush(stdin);
printf("Sueldo:");
scanf("%d",&x.Prof.Sueldo);
fflush(stdin);
printf("Nombre:");
gets(x.Prof.Nombre);
fflush(stdin);
x.CualEs='P';

fwrite(&x,sizeof(PERSONA),1,q);


fseek(q,-2*sizeof(PERSONA),1);


for(i=0;i<2;i++){
	fread(&y,sizeof(PERSONA),1,q);
	if(y.CualEs == 'A')
		printf("\nLegajo:%d\nCarrera:%c \nNombre:%s",y.Alum.Legajo,y.Alum.Carrera,y.Alum.Nombre);
	else
		printf("\n%d %d %s",y.Prof.DNI,y.Prof.Sueldo,y.Prof.Nombre);
}
fclose(q);

getch();


}
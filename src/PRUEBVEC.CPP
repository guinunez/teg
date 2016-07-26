#include <stdio.h>
#include <conio.h>


void lafuncion(char *lugar){

	int i;
	clrscr ();
	for (i=0;i<50;i++){
		printf("\t\t%d %s",i,*lugar + i);
		}
}

void main(){
	struct targeta{
	char elpais[13];
	char *elpa;
	char tipo;
	}paises[50],*pa;

	elpa=&paises[0].elpais;

	char nombre[13];
	int pos;
	do{
		clrscr();
		printf("\nEscribir la posici¢n del pa¡s");
		scanf("%s",pos);
		printf ("\n\nEscribir el nombre del pa¡s");
		gets(nombre);

		elpa += pos;

		*elpa=nombre;

		elpa -= pos;
	}while(nombre!="listo");

	lafuncion(elpa);
        getch();

}

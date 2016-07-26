#define __desarrol_h


void reagrupar (int t,int ronda,int flag){
				  //EN REALIDAD SERIA INCORPORAR EJERCITOS.

//TODA LA FUNCION DEBE ESTAR HECHA PARA LA PANTALLA CON EL MAPA, ­­CUIDADO!!

int gil=0;
int guille=0;
int cantidad=0;
int quepongo=0;
char nabo[13];//="            ";
	if ( ronda == 1 ){
		if ( flag == 0 )
			quepongo = 5;
		else
			quepongo = 3;

	}
	else{
//		if ( flag == 0 ){
			quepongo = 0;
			for (gil = 0;gil < 50; gil++){
				quepongo += paisejerc[t][gil];
			}
			quepongo /= 2;
//		}
	}


   //	printf("Presione cualquier tecla");

     //	getch();
	limpiarsec(1,21,79,24);
	//int largo,i;
	//printf("CONTROL %s",nom[0].nombre);
	do{
		fflush(stdin);
		limpiarsec(1,21,79,24);
		gotoxy(2,22); printf( "%s tiene %d ej‚rcitos para asignar", nom[t].nombre, quepongo);
		printf( "\n¨En qu‚ pa¡s desea colocar ej‚rcitos? ");
		gets(nabo);

		if (soniguales(nabo,"SALIR",1))break;

		guille = -1;
		while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 50){
			guille++;
			gotoxy(35,25);printf("Buscando...%s",paises[guille].elpais);
		}
		if (soniguales(nabo,paises[guille].elpais,1)){
			if (paisejerc[t][guille]){
				gotoxy(2,24);printf( "Cu ntos ej‚rcitos desea colocar en %s? ", paises[guille].elpais);
				do{
					scanf("%d", &cantidad);
					fflush(stdin);
					if ( quepongo < cantidad ){
						gotoxy(35,25);printf("Ud. tiene menos ej‚rcitos para asignar");
					}
				}while (quepongo < cantidad);
				paisejerc[t][guille] += cantidad;
				quepongo -= cantidad;
				}
				else{
				limpiarsec(1,21,79,24);
				gotoxy(35,25);printf("Ese pa¡s no te pertenece");
				}
		}
		else{

			limpiarsec(1,21,79,24);
			gotoxy(35,25);printf("Pa¡s no encontrado");
		     }

		}while (quepongo);


}



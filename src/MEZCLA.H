#define__mezcla_h


void ordenc (){                     //MEZCLA LAS CARTAS.

	int ordenado[50];
	int i,j,w,n;

	gotoxy(7,25);printf("Un Momento, ordenando cartas");

	for (i = 0;i < 50;i++){
		ordenado[i] = i;
		}
	randomize();
	for (j = 49;j >= 1 ;j--){
		n = (rand() % (j+1));
		orden[j] = ordenado[n];
		if(j>n){
			for (w = n;w <= j - 1;w++){
				gotoxy(36,25);printf("%d %d",50-j,w);
				ordenado[w] = ordenado[w + 1];
			}
		}
	}
		orden[0]=ordenado[0];
}

void turnos (int n, int ronda){
			    //ORDENA LOS TURNOS Y LOS MUESTRA POR PANTALLA.
int ordene[6], ordenado[6];
int i,j,w,y,m;

clrscr();

for ( i = 0;i < n;i++){
	ordenado[i] = i+1;
}

randomize();
for ( j = n-1;j >= 1; j--){
	y = (rand() % (j+1));
	ataque[j] = ordenado[y];
	if(j>y){
		for ( w = y; w <= j - 1;w++){
			ordenado[w] = ordenado[w + 1];
		}
	}

}
ataque[0]=ordenado[0];

for ( i = 0; i < n;i++){
	ordene[i] = i+1;
}
for ( j = n-1; j >= 1;j--){
	y = (rand() % (j+1));
	reagrup[j] = ordene[y];

	if (j>y){
		for ( w = y; w <= j-1;w++){
			ordene[w] = ordene[w + 1];
		}
	}

}
reagrup[0]=ordene[0];

printf( "El orden asignado en la ronda nø %d es:", ronda);

for ( m = 0; m < 3; m++){

	if ( m < n ){
		gotoxy(1,(m * 4)+5); printf("%s", nom[m].nombre);
		gotoxy(1, (m * 4) + 6); printf( "Ataque:        %d", ataque[m]);
		gotoxy(1, (m * 4) + 7); printf( "Reagrupamiento:%d", reagrup[m]);
		gotoxy(1, (m * 4) + 8); printf(" ");
	}
	if ( m + 3 < n ){
		gotoxy(39, (m * 4) + 5); printf("%s", nom[m + 3].nombre);
		gotoxy(39, (m * 4) + 6); printf( "Ataque:        %d", ataque[m + 3]);
		gotoxy(39, (m * 4) + 7); printf( "Reagrupamiento:%d", reagrup[m + 3]);
		gotoxy(39, (m * 4) + 8); printf(" ");

	}

}

gotoxy(1,19); printf( "Presione cualquier tecla para continuar");

getch();

}


void reppais (int n){   //REPARTE PAISES Y LOS MUESTRA POR PANTALLA(INC.).

int i,w,m,y;
//int lug;

clrscr();
for ( i = 0;i < 50 ;i+= n){
	for ( w = 0; w < n;w++){
		if ( i + w < 50 ){
			paisejerc[w][orden[i + w]] = 1;
		}
	}
}
for ( m = 0;m < n;m++){
	//lug = 1;
	//y = 0;
	clrscr();
	printf( "\n%s tiene los siguientes pa¡ses:\n\n\n",nom[m].nombre);

	/*
	do{
	       // TODO STE ALGORITMO ES PARA MOSTRAR Y UBICAR EN PANTALLA
	       //	       LOS PAISES DE CADA EJERCITO

		if ( paisejerc[m][y] == 1 && lug < 65){
			gotoxy(lug,4); printf("\n%s", paises[y].elpais);
			lug+=13;
			}else {
				if ( paisejerc[m][y] == 1 && lug < 143 ){
					gotoxy(lug - 65,6); printf("\n%s", paises[y].elpais);
					lug+=13;
				}else {
				if (paisejerc[m][y] == 1 && lug < 221){
					lug+=13;
					gotoxy(lug - 143,8);printf("\n%s", paises[y].elpais);
					}else{
					 if (paisejerc[m][y] == 1 && lug < 299){
						gotoxy(lug - 221,10);printf("\n%s",paises[y].elpais);
						lug+=13;
						}else{
						 if ( paisejerc[m][y] == 1){
				gotoxy(1,12);printf("\n%s",paises[y].elpais);
				lug+=13;
				}
			}
		}
		}
		}

		y++;

	}while (y < 50);
	*/
	for (y=0;y<50;y++){
		if (paisejerc[m][y] >= 1){
			printf("%s\t",paises[y].elpais);
			}
		}

	printf( "\n\nPresione cualquier tecla para continuar");
	getch();
}

}


void mostrarmision (int n){	//IMPRIME LAS MISIONES DE CADA JUGADOR.

	int what, i;
	clrscr();
	printf("\nInserte una hoja en su impresora y presione cualquier tecla");
	getch();

	for (i = 0 ;i < n;i++){
		printf ("\nSe est  imprimiendo la misi¢n de %s\n", nom[i].nombre);

		if (mision[i] >= 9){
			do{
			what = (rand() % n);
			mision[i] = what + 9;
			}while (mision[i] - 9 == i);
			fprintf (stdprn,"T.E.G.   MISION A SEGUIR: %s", nom[i].nombre);
			fprintf (stdprn,"\n\n%s %s %c", misiones[mision[i]], nom[mision[i] - 9].nombre,12);
		}
		else{
			fprintf (stdprn,"T.E.G.   MISION A SEGUIR: %s", nom[i].nombre);
			fprintf (stdprn,"\n\n%s %c", misiones[mision[i]],12);
	}

	delay(5000);

	if (i < n-1)
		printf("\nSaque la hoja ya impresa, inserte una nueva y presione cualquier tecla");
	else
		printf("\nSaque la hoja ya impresa y presione cualquier tecla");
		
        getch();
	clrscr();

}

}


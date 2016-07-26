#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifndef__limpiar_h
	#include "limpiar.h"
#endif


int seguncanje(int nro);//DA EL NUMERO DE EJERCITOS QUE SE OTORGAN SEGUN EL CANJE

#ifndef__comparac_h
	#include "comparac.h"
#endif


int ejercontin(int cual,int jug);


struct jugador{
	char nombre[20];
	char band;
	int tarjetas[7];
	int ncanjes;              // ES EL Nø DE CANJES DE TARJETAS
	int paso;              //INDICA EL PASO QUE LLEVA EFECTUADO EL JUGADOR
	int conquista;  //GUARDA LA POSICION DEL ULTIMO PAIS QUE CONQUISTO
			// (50 SI NO CONQUISTO EN LA RONDA)
	}nom[6];


struct targeta{
	char elpais[13];
	char tipo;
	}paises[50];

char continente[][19] = {"ASIA","EUROPA","AMERICA DEL NORTE","AMERICA DEL SUR","AFRICA","OCEANIA"};
char misiones[][150] = {"OCUPAR AFRICA, 5 PAISES DE AMERICA DEL NORTE Y 4 PAISES DE EUROPA","OCUPAR AMERICA DEL NORTE, 2 PAISES DE OCEANIA Y 4 DE ASIA","OCUPAR OCEANIA, AMERICA DEL NORTE Y 2 PAISES DE EUROPA","OCUPAR ASIA Y 2 PAISES DE AMERICA DEL SUR","OCUPAR EUROPA, 4 PAISES DE ASIA Y 2 PAISES DE AMERICA DEL SUR","OCUPAR 2 PAISES DE OCEANIA, 2 PAISES DE AFRICA, 2 PAISES DE AMERICA DEL SUR,     3 PAISES DE EURUPA, 4 PAISES DE AMERICA DEL NORTE Y 3 PAISES DE ASIA","OCUPAR OCEANIA, AFRICA Y 5 PAISES DE AMERICA DEL NORTE","OCUPAR AMERICA DEL SUR, 7 PAISES DE EUROPA Y 3 PAISES LIMITROFES ENTRE SI EN     CUALQUIER LUGAR DEL MAPA","OCUPAR AMERICA DEL SUR, AFRICA Y 4 PAISES DE ASIA","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO"};

int ataque[6];                 //ORDENES DE ATAQUE Y REAGRUPACION,
int reagrup[6];                //­CUIDADO!, SUS VALORES VARIAN DE 1 A 6.
int orden[50];                 //ORDEN DE LAS CARTAS, VARIA DE 0 A 49.
int ultimatargeta;	       //TIENE LA POSICION DE LA ULTIMA TARJETA.
int paisejerc[6][50];          //CANT. DE EJERCITOS QUE TIENE CADA PAIS.
int mision[6];                 //Nø DE MISION DE CADA JUGADOR (VAL.DE 0 A 15).
int limitrofes[50][50];	       //MATRIZ CONSTANTE QUE MUESTRA QUE PAIS ES
			       //LIMITROFE CON CUAL.



void ordenc ();                 //MEZCLA LAS CARTAS.
void nombres (int n);           //PIDE NOMBRES DE LOS JUGADORES.
void banderas (int n);          //PIDE LAS BANDERAS DE LOS JUGADORES.
void turnos (int n, int ronda); //ORDENA LOS TURNOS Y LOS MUESTRA POR PANTALLA.
void reppais (int n);           //REPARTE PAISES Y LOS MUESTRA POR PANTALLA(INC.).
void inicializacion ();         //INICIALIZA CIERTOS VECTORES QUE LUEGO PERMANECEN CONSTANTES.
void mostrarmision (int n);     //IMPRIME LAS MISIONES DE CADA JUGADOR.
//int estuya (, t AS INTEGER, w AS INTEGER);
void incorporarej (int t,int ronda,int flag);
void atacar(int t);
void reagrupar(int t);
void canjedef(int t);
void soltarj(int t);
void abandonar(int t);
void atacando(int desde, int hasta, int quien);
void case1(int *y0,int *y1,int t);
void case2(int *y0,int *y1,int *y2,int t);
void mostrarmapa(int cual);
void africa();
void asia();
void europa();
void americadelnorte();
void americadelsur();


int misioncumplida(int *cual, int n);//VERIFICA SI UN JUGADOR HA CUMPLIDO UNA
			//MISION, Y DEVUELVE EL Nø DE JUGADOR QUE LA CUMPLIO,
			//SI HAY MAS DE UN JUGADOR QUE HAYA CUMPLIDO, SE
			//DEVOLVERA EL Nø DEL PRIMERO EN ORDEN DE ATAQUE.
			//DEVUELVE 10 SI NADIE HA CUMPLIDO CON LAS MISIONES.
			//CUAL DEVUELVE 0 SI ERA LA MISION ESTANDAR Y 1 SI
			//CUMPLIO CON EL OBJETIVO COMUN (30 PAISES).


 int vereuro(char nabo[13]){
	int guille;
	guille = 16;
	while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 26){
		guille++;
		gotoxy(1,25);clreol();gotoxy(35,25);printf("Buscando...%s",paises[guille].elpais);
	}
	return guille;
}


int verasia(char nabo[13]){
	int guille;
	guille = 35;
	while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 50 ){
		guille++;
		gotoxy(1,25);clreol();gotoxy(35,25);printf("Buscando...%s",paises[guille].elpais);
	}
	return guille;
}


int vernort(char nabo[13]){
	int guille;
	guille = 25;
	while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 36){
		guille++;
		gotoxy(1,25);clreol();gotoxy(35,25);printf("Buscando...%s",paises[guille].elpais);
	}
	return guille;
}


int versud(char nabo[13]){
	int guille;
	guille = -1;
	while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 7){
		guille++;
		gotoxy(1,25);clreol();gotoxy(35,25);printf("Buscando...%s",paises[guille].elpais);
	}
	return guille;
}


int verafrica(char nabo[13]){
	int guille;
	guille = 10;
	while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 17){
		guille++;
		gotoxy(1,25);clreol();gotoxy(35,25);printf("Buscando...%s",paises[guille].elpais);
	}
	return guille;
}


int veroceania(char nabo[13]){
	int guille;
	guille = 6;
	while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 11){
		guille++;
		gotoxy(1,25);clreol();gotoxy(35,25);printf("Buscando...%s",paises[guille].elpais);
	}
	return guille;
}





void main(){

	randomize();
	clrscr();
	int n,ronda,i,t,flag,h,ntarj,xx;
	char opcion;
	textmode(BW40);

	do{
		clrscr();
		gotoxy(1,7);printf("Cantidad de jugadores:");
		scanf("%d",&n);
	}while (n > 6 || n < 2);
	fflush(stdin);
	inicializacion();
	ronda = 1;
	for (xx=0;xx<n;xx++){
		nom[xx].ncanjes=1;
		}
	for (xx=0;xx<n;xx++){
		nom[xx].tarjetas[1]=50;
		}
	for (xx=0;xx<n;xx++){
		nom[xx].conquista=50;
		}
	nombres(n);
	banderas(n);
	textmode(C80);

	turnos(n, ronda);
	ordenc();
	reppais(n);
	ordenc();
	ultimatargeta = 49;


	for (i = 0;i < n;i++){
		mision[i] = (rand() % 15);
	}

      //	mostrarmision(n);

       clrscr();

      /*	window(1,1,2,2);
	textcolor(BLACK);
	textbackground(WHITE);
	//cprintf("This is a test\r\n");
	*/
	gotoxy(1,1);
	printf("RONDA 1");

	textcolor(BLACK);
	textbackground(WHITE);
	gotoxy(2,3);
	//printf("1.)");

	textcolor(WHITE);
	textbackground(BLACK);

	gotoxy(1,4);
	printf("INCORP.");
	gotoxy(1,5);
	printf("EJERCITOS");

	textcolor(BLACK);
	textbackground(WHITE);

	gotoxy(2,7);
	printf("1.)");

	textcolor(WHITE);
	textbackground(BLACK);

	gotoxy(1,8);
	printf("ATACAR");

	textcolor(BLACK);
	textbackground(WHITE);

	gotoxy(2,10);
	printf("2.)");

	textcolor(WHITE);
	textbackground(BLACK);

	gotoxy(1,11);
	printf("REAGRUPAR");

	textcolor(BLACK);
	textbackground(WHITE);

	gotoxy(2,13);
	printf("3.)");

	textcolor(WHITE);
	textbackground(BLACK);

	gotoxy(1,14);
	printf("CANJE");
	gotoxy(1,15);
	printf("DEFENSIVO");

	textcolor(BLACK);
	textbackground(WHITE);

	gotoxy(2,17);
	printf("4.)");

	textcolor(WHITE);
	textbackground(BLACK);

	gotoxy(1,18);
	printf("SOLICITAR");
	gotoxy(1,19);
	printf("TARJETA");

	mostrarmapa(0);


	for (t = 0 ;t < n;t++){
		flag = 0;
		h = reagrup[t];
		incorporarej(h-1, ronda, flag);
	}

	for (t = 0 ;t < n;t++){
		flag = 1;
		h = reagrup[t];
		incorporarej(h-1, ronda, flag);
	}

	for (t=0;t<n;t++){
		for(ntarj=0;ntarj<7;ntarj++){
			nom[t].tarjetas[ntarj]=50;
			}
		}



	//getch();


//AHORA EMPIEZA EL JUEGO...
// DESARROLLAR FUNCIONES Y BUCLE, HAY QUE CAMBIAR LA FUNCION REAGRUPAR (YA
// TERMINADA) POR INCORPORAR, Y ADEMAS HAY QUE MEJORARLA PARA SU USO DENTRO DEL
// INICIO DE HOSTILIDADES.
	do{
	//BUCLE MAYOR, SE SALE DE L CUANDO ALGUIEN TERMINA LA MISION
		gotoxy(7,1);
		printf("%d",ronda);
	   if (ronda != 1){
		for (t=0;t<n;t++){
		incorporarej(reagrup[t]-1,ronda,flag);
		}
	   }
		for (t = 0; t< n;t++){	//VARIA EL TURNO DE CADA JUGADOR
			do{
			mostrarmapa(0);
			limpiarsec(1,21,79,24);
			gotoxy(1,21);
			printf("%s elija su opci¢n:",nom[ataque[t]-1].nombre);
			opcion=getch();
			//fflush(stdin);
			switch(opcion) {
			  case '1': atacar(ataque[t]-1);break;
			  case '2': reagrupar(ataque[t]-1);break;
			  case '3': canjedef(ataque[t]-1);break;
			  case '4': soltarj(ataque[t]-1);break;

			  case '5': abandonar(ataque[t]-1);break;

			  }
			}while (!(opcion == '5') && nom[ataque[t]-1].paso != 5);
			nom[ataque[t]-1].paso=1;
			nom[ataque[t]-1].conquista = 50;

		}

	ronda++;
	//}while (misioncumplida(&cualmision,n) == 10);
	}while (!(opcion == '5'));





}

void abandonar(int t){
	printf("Abandona %s",nom[t].nombre);
}


void atacando(int desde,int hasta,int giles){

	int gil;
	int ataquej,defensa;
	int dadosat,dadosdef;
	int x[3],y[3];
	int m,r,n;
	int t,wi,cant,hi;
	char op='s';
        fflush(stdin);

do{

	op = 's';
	limpiarsec(1,21,79,24);
	//giles=-1;
	gil=-1;
	ataquej=0;
	defensa=0;
	dadosat=0;
	dadosdef=0;
	m=0;
	r=0;
	n=0;
	t=0;
	wi=0;
	cant=0;
	for(hi=0;hi<3;hi++){
		x[hi]=0;
		y[hi]=0;
	}

  /*	while (!(paisejerc[giles][desde]) && giles < 6){
		giles++;
		gotoxy(35,25);clreol();printf("Buscando...%s",nom[giles].nombre);
	}
  */
	if (paisejerc[giles][desde] > 1){
		ataquej = paisejerc[giles][desde] - 1;
		if(ataquej <= 3)
			dadosat = ataquej;
		else
			dadosat = 3;
	//randomize();

	for(m=0;m<dadosat;m++){
		r = (rand() % 6) + 1;
		switch (m){
		  case 0: x[0]=r;x[1]=0;x[2]=0;break;
		  case 1: case1(&x[0],&x[1],r);x[2]=0;break;
		  case 2: case2(&x[0],&x[1],&x[2],r);break;
		  default:printf("HAY ERROR EN CALCULO DE ATAQUE");
		  }
		r=0;

	}

	}
	else{
		gotoxy(35,25);clreol();printf("No es posible atacar con 1 ej‚rcito");
		op = 'n';
		//printf("ERROR EN ASIGNACION DE EJERCITOS(ENCONTRADO EN MODULO ATACANDO)");
	}
	while (!(paisejerc[gil][hasta]) && gil < 6){
		gil++;
		gotoxy(35,25);clreol();printf("Buscando...%s",nom[gil].nombre);
	}
	if (paisejerc[gil][hasta] >= 1 && gil != giles){
		defensa = paisejerc[gil][hasta];
		if(defensa <=3)
			dadosdef = defensa;
		else
			dadosdef = 3;

	//randomize();

	   for(n=0;n<dadosdef;n++){

		t = (rand() % 6) + 1;
		switch (n){
		  case 0: y[0]=t;y[1]=0;y[2]=0;break;
		  case 1:case1(&y[0],&y[1],t);y[2]=0;break;
		  case 2:case2(&y[0],&y[1],&y[2],t);break;
		  default:printf("HAY ERROR EN CALCULO DE DEFENSA");
		  }
		t=0;

	   }

	}
	else{
		gotoxy(35,25);clreol();printf("Pa¡s ya conquistado");
		op = 'n';
	}

	limpiarsec(1,21,79,24);

	for (wi=0;wi<3;wi++){
		if (x[wi] != 0 && y[wi] !=0){
			gotoxy(10,21);clreol();printf("%s\t%s",nom[giles].nombre,nom[gil].nombre);
			delay(70);
			gotoxy(10,wi+22);clreol();printf("%d\t\t%d",x[wi],y[wi]);

			if(x[wi] > y[wi]){
				gotoxy(35,25);clreol();printf("Ataque exitoso");
				paisejerc[gil][hasta]--;
				mostrarmapa(0);
				if (paisejerc[gil][hasta]==0){
				    do{
					gotoxy(1,21);clreol();printf("¨Cuantos ej‚rcitos desea pasar?");
					scanf("%d",&cant);
					fflush(stdin);
				    }while (cant > 3 || cant < 1 || paisejerc[giles][desde]<=cant);
				    paisejerc[giles][hasta] += cant;
				    paisejerc[giles][desde] -= cant;
				    cant = 0;
				    nom[giles].conquista = hasta;
				    op = 'n';
				    mostrarmapa(0);
				}


			}
			else{
				gotoxy(35,25);clreol();printf("Defensa exitosa");
				paisejerc[giles][desde]--;
				mostrarmapa(0);
				if (paisejerc[giles][desde] == 1){
					gotoxy(35,25);clreol();printf("Ya no es posible atacar.");
					op = 'n';
				}
			}
			delay(500);
		}
	}

	if(paisejerc[gil][hasta] && op != 'n'){
		gotoxy(1,21);clreol();printf("¨Seguir atacando al mismo pa¡s? (S/N)");
		op=getch();


	}
	else{
	  if (op != 'n'){
	    do{
		gotoxy(1,21);clreol();printf("¨Cuantos ej‚rcitos desea pasar?");
		scanf("%d",&cant);
		fflush(stdin);
	    }while (cant > 3 || cant < 1 || paisejerc[giles][desde]<=cant);
	    paisejerc[giles][hasta] += cant;
	    paisejerc[giles][desde] -= cant;
	    cant = 0;
	    nom[giles].conquista = hasta;
	    op = 'n';
	    mostrarmapa(0);
	  }
	}

}while(!(op == 'n' || op == 'N'));

}



void atacar(int w){

char origen[13],dest[13],seguir;
int guille,giles;
int loc;

if (nom[w].paso <= 1){
	gotoxy(5,9);
	printf("%c",30);
	gotoxy(1,1);
	nom[w].paso=2;
     do{
	gotoxy(35,21);clreol();printf("Desde: ");
	gets(origen);
	guille = -1;
	while (!(soniguales(origen,paises[guille].elpais,1)) && guille < 50){
		guille++;
		gotoxy(35,25);clreol();printf("Buscando...%s",paises[guille].elpais);
	}
	if (soniguales(origen,paises[guille].elpais,1)){
		if (paisejerc[w][guille]){
		   if(paisejerc[w][guille] > 1){

		     do{
			gotoxy(35,23);clreol();printf("Hasta: ");
			loc = 0;
			gets(dest);
			giles = -1;
			while (!(soniguales(dest,paises[giles].elpais,1)) && giles < 50){
				giles++;
				gotoxy(35,25);clreol();printf("Buscando...%s",paises[giles].elpais);
			}
			if (soniguales(dest,paises[giles].elpais,1)){
				if (paisejerc[w][giles]){
					limpiarsec(1,21,79,24);
					gotoxy(35,25);clreol();printf("Ese pa¡s ya es tuyo");
					loc = 1;

				}
				else{
				    if(limitrofes[giles][guille]){
					limpiarsec(1,21,79,24);
					atacando(guille,giles,w);
				    }
				    else{
					gotoxy(35,25);clreol();printf("Los pa¡ses no son lim¡trofes");
					}


					}
				}
			else{
				limpiarsec(1,21,79,24);
				gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
				loc = 1;
			     }
		      }while (loc == 1);
		    }
		    else{
			limpiarsec(1,21,79,24);
			gotoxy(35,25);clreol();printf("No hay suficientes ej‚rcitos para atacar");
			}


		}
		else{
			limpiarsec(1,21,79,24);
			gotoxy(35,25);clreol();printf("Ese pa¡s no te pertenece");
			}
		}
	else{
		limpiarsec(1,21,79,24);
		gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
	     }

       gotoxy(1,21);clreol();printf("¨Continuar los ataques? (S/N)?");
       seguir=getch();

    }while(!(seguir == 'n' || seguir == 'N'));





}
else{
	gotoxy(35,25);clreol();
	printf("Ya no es posible atacar");

}
	gotoxy(5,9);
	printf(" ");
	gotoxy(1,1);

}

void banderas (int n){

	int h;
	h=n+1;
	n=h-1;
}


/*int estuya (paisejerc() AS INTEGER, t AS INTEGER, w AS INTEGER){
	estuya = paisejerc(t, w);

}
  */


void canjedef(int t){

int variac,wer,algo,algomas;
int A=0,B=0,C=0,X=0;
int no,guille,busqueda,comod;
char cambio[13],eltipo[3];
int cualmodifico[3];
int verificador,quepongo;


if (nom[t].paso <=3){
	gotoxy(5,16);
	printf("%c",30);
	gotoxy(1,1);
	nom[t].paso=4;

	if(nom[t].conquista < 50){

	for(variac=0;variac<7;variac++){
	   if (nom[t].tarjetas[variac] != 50){
		switch(paises[nom[t].tarjetas[variac]].tipo){
		 case 'A':A++;break;
		 case 'B':B++;break;
		 case 'C':C++;break;
		 case 'X':X++;break;
		 default:printf("ERROR EN TIPOS DE TARJETAS");break;
		 }
		}
	}
	if (A+X >= 3 || B+X >=3 || C+X >=3 || (A+X && B && C) ||  (A && B+X && C) ||  (A && B && C+X) ){

		for(wer=1;wer<=3;wer++){
		   do{
			no=0;
			printf("%dø.Tarj.: ",wer);
			gets(cambio);
			fflush(stdin);
			guille = -1;
			while (!(soniguales(cambio,paises[guille].elpais,1)) && guille < 50){
				guille++;
				gotoxy(35,25);clreol();printf("Buscando...%s",paises[guille].elpais);
			}

			if (soniguales(cambio,paises[guille].elpais,1)){
				busqueda = 0;
				do{
				busqueda++;
				}while(!(nom[t].tarjetas[busqueda] == guille) || busqueda < 7);
					if (nom[t].tarjetas[busqueda] == guille){
						eltipo[wer-1]=paises[guille].tipo;
						cualmodifico[wer-1]=busqueda;
						}
					else{
						gotoxy(35,25);clreol();printf("Esa tarjeta no es tuya");
						no++;
						}
			}
			else{
			limpiarsec(1,21,79,24);
			gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
			no++;
			}
		}while (no);
	}
	comod = 0;
	for(wer=0;wer<3;wer++){
		if(eltipo[wer]== 'X')
			comod++;
	}
	verificador=quepongo;
	switch(comod){
		case 3: quepongo += seguncanje(t);break;
		case 2: quepongo += seguncanje(t);break;
		case 1: quepongo += seguncanje(t);break;
		case 0: quepongo += thechange(eltipo[0],eltipo[1],eltipo[2],t);break;
		default: printf("Hay error en CANJE");break;
		}
	if (verificador != quepongo){
		nom[t].ncanjes++;
		for (algo=0;algo<2;algo++){
			for (algomas=0;algomas<6;algomas++){
				nom[t].tarjetas[cualmodifico[algo]]=nom[t].tarjetas[cualmodifico[algo+1]];
				nom[t].tarjetas[cualmodifico[algo+1]]=50;
			}

		}


	}

     paisejerc[t][nom[t].conquista] += quepongo;



    }
    else{
    gotoxy(35,25);clreol();printf("No se puede efectuar ning£n cambio");
    }
}
else{
	gotoxy(35,25);clreol();
	printf("Tendr¡a que haber conquistado un pa¡s antes");

}
}
else{
	gotoxy(35,25);clreol();
	gotoxy(35,25);clreol();printf("Ya no es posible hacer canje defensivo");

}

	gotoxy(5,16);
	printf(" ");
	gotoxy(1,1);
	nom[t].paso=4;


}

void case1(int *y0,int *y1,int t){
	 if(t > *y0){
		*y1=*y0;
		*y0=t;
		}
	  else{
		*y1=t;
		}
}
void case2(int *y0,int *y1,int *y2,int t){

	if(t > *y0){
		*y2=*y1;
		*y1=*y0;
		*y0=t;
		}
		else if(t > *y1){
			*y2=*y1;
			*y1=t;
		}
		else {

			*y2=t;
		}
}
void incorporarej (int t,int ronda,int flag){

//TODA LA FUNCION DEBE ESTAR HECHA PARA LA PANTALLA CON EL MAPA, ­­CUIDADO!!
//VALORES DE FLAG:CUANDO RONDA =1: 0.-CANT. DE PAISES = 5;
//				   1.-CANT. DE PAISES = 3;
//	 CUANDO RONDA != 1: 0.-NO HAY CONTINENTES OCUPADOS;
//			    1.-ASIA OCUPADA;
//			    2.-EUROPA;
//			    4.-AMERICA DEL NORTE;
//			    8.-AMERICA DEL SUR;
//			    16.-AFRICA;
//			    32.-OCEANIA;
//			    OTROS NUMEROS: SUMA DE LOS NUMEROS DE
//				CADA CONTINENTE (EJ.:AFRICA Y EUROPA: 16+2=18
gotoxy(5,6);
printf("%c",30);
gotoxy(1,1);

int gil=0;
int guille=0;
int cantidad=0;
int quepongo=0;
int quepongoaca=0;
int variac=0;
int A,B,C,X;
char op, cambio[13], eltipo[3];
int wer,no,busqueda,comod,cual;
int cualmodifico[3];
int verificador,algo,algomas;

char nabo[13];//="            ";
	if ( ronda == 1 ){
		if ( flag == 0 )
			quepongo = 5;
		else
			quepongo = 3;

	}
	else{
			quepongo = 0;
			for (gil = 0;gil < 50; gil++){
				if(paisejerc[t][gil])
					quepongo++ ;
			}
			if (quepongo >= 6)
				quepongo /= 2;
			else
				quepongo = 3;


	cual=0;
	for(cual=0;cual<6;cual++){
		do{
			if (ejercontin(cual,t)){
				quepongoaca = ejercontin(cual,t);
				gotoxy(35,25);clreol();printf("%s Ha conquistado %s, son %d ej‚rcitos a asignar",nom[t].nombre,continente[cual],quepongoaca);
				gotoxy(35,25);clreol();printf( "\n¨En qu‚ pa¡s desea colocar ej‚rcitos? ");
				gets(nabo);

				if (soniguales(nabo,"SALIR",1))break;
				switch(cual){
				 case 0:guille=verasia(nabo);break;
				 case 1:guille=vereuro(nabo);break;
				 case 2:guille=vernort(nabo);break;
				 case 3:guille=versud(nabo);break;
				 case 4:guille=verafrica(nabo);break;
				 case 5:guille=veroceania(nabo);break;
				 default: printf("Error en Continentes");break;
				 }
				if (soniguales(nabo,paises[guille].elpais,1)){
					if (paisejerc[t][guille]){
						gotoxy(2,24);clreol();printf( "Cu ntos ej‚rcitos desea colocar en %s? ", paises[guille].elpais);
						do{
							scanf("%d", &cantidad);
							fflush(stdin);
							if ( quepongoaca < cantidad ){
								gotoxy(35,25);clreol();printf("Ud. tiene menos ej‚rcitos para asignar");
							}
						}while (quepongoaca < cantidad);
						paisejerc[t][guille] += cantidad;
						quepongoaca -= cantidad;
						}
					else{
						limpiarsec(1,21,79,24);
						gotoxy(35,25);clreol();printf("Ese pa¡s no te pertenece");
					}
				}
				else{
					limpiarsec(1,21,79,24);
					gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
				}
			}
		}while (quepongoaca);

	}

//A PARTIR DE ACA ES PARA CANJE DE TARJETAS

limpiarsec(1,21,79,24);
A=0;
B=0;
C=0;
X=0;
for(variac=0;variac<7;variac++){
	if (nom[t].tarjetas[variac] != 50){
		switch(paises[nom[t].tarjetas[variac]].tipo){
		 case 'A':A++;break;
		 case 'B':B++;break;
		 case 'C':C++;break;
		 case 'X':X++;break;
		 default:printf("ERROR EN TIPOS DE TARJETAS");break;
		 }
	}
	else break;

	}
if (A+X >= 3 || B+X >=3 || C+X >=3 || (A+X && B && C) ||  (A && B+X && C) ||  (A && B && C+X) ){
	do{
		gotoxy(1,21);clreol();printf("¨Desea canjear sus tarjetas? (S/N)");
		op=getch();
		if (!(op == 'n' || op == 'N')){
			for(wer=1;wer<=3;wer++){
			   do{
				no=0;
				gotoxy(1,21+wer);clreol();printf("%dø.Tarj.: ",wer);
				gets(cambio);
				guille = -1;
				while (!(soniguales(cambio,paises[guille].elpais,1)) && guille < 50){
					guille++;
					gotoxy(35,25);clreol();printf("Buscando...%s",paises[guille].elpais);
				}

				if (soniguales(cambio,paises[guille].elpais,1)){
					busqueda = 0;
					do{
					busqueda++;
					}while(!(nom[t].tarjetas[busqueda] == guille) && busqueda < 7);
						if (nom[t].tarjetas[busqueda] == guille){
							eltipo[wer-1]=paises[guille].tipo;
							cualmodifico[wer-1]=busqueda;
						}
						else{
							gotoxy(35,25);clreol();printf("Esa tarjeta no es tuya");
							no++;
							}
					}
				else{
				limpiarsec(1,21,79,24);
				gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
				no++;
				}
			}while (no);
		}
		comod = 0;
		for(wer=0;wer<3;wer++){
			if(eltipo[wer]== 'X')
				comod++;
		}
		verificador=quepongo;
		switch(comod){
			case 3: quepongo += seguncanje(t);break;
			case 2: quepongo += seguncanje(t);break;
			case 1: quepongo += seguncanje(t);break;
			case 0: quepongo += thechange(eltipo[0],eltipo[1],eltipo[2],t);break;
			default: printf("Hay error en CANJE");break;
			}
		if (verificador != quepongo){
			nom[t].ncanjes++;
			for (algo=0;algo<2;algo++){
				for (algomas=0;algomas<6;algomas++){
					nom[t].tarjetas[cualmodifico[algo]]=nom[t].tarjetas[cualmodifico[algo+1]];
					nom[t].tarjetas[cualmodifico[algo+1]]=50;
				}

			}


		}
		}
	}while (!(op == 'n' || op == 'N'));
}
}




   //	printf("Presione cualquier tecla");

     //	getch();
	limpiarsec(1,21,79,24);
	//int largo,i;
	//printf("CONTROL %s",nom[0].nombre);
	do{
		fflush(stdin);
		limpiarsec(1,21,79,24);
		gotoxy(1,22);clreol(); printf( "%s tiene %d ej‚rcitos para asignar", nom[t].nombre, quepongo);
		printf( "\n¨En qu‚ pa¡s desea colocar ej‚rcitos? ");
		gets(nabo);

		if (soniguales(nabo,"SALIR",1))break;

		guille = -1;
		while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 50){
			guille++;
			gotoxy(35,25);clreol();printf("Buscando...%s",paises[guille].elpais);
		}
		if (soniguales(nabo,paises[guille].elpais,1)){
			if (paisejerc[t][guille]){
				gotoxy(2,24);clreol();printf( "Cu ntos ej‚rcitos desea colocar en %s? ", paises[guille].elpais);
				do{
					scanf("%d", &cantidad);
					fflush(stdin);
					if ( quepongo < cantidad ){
						gotoxy(35,25);clreol();printf("Ud. tiene menos ej‚rcitos para asignar");
					}
				}while (quepongo < cantidad);
				paisejerc[t][guille] += cantidad;
				quepongo -= cantidad;
				}
				else{
				limpiarsec(1,21,79,24);
				gotoxy(35,25);clreol();printf("Ese pa¡s no te pertenece");
				}
		}
		else{

			limpiarsec(1,21,79,24);
			gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
		     }

	}while (quepongo);

gotoxy(5,6);
printf(" ");
gotoxy(1,1);

}


void inicializacion (){

int l,m;



strcpy(paises[0].elpais,"ARGENTINA");
paises[0].tipo = 'X';
strcpy(paises[1].elpais,"BRASIL");
paises[1].tipo = 'B';
strcpy(paises[2].elpais,"CHILE");
paises[2].tipo = 'A';
strcpy(paises[3].elpais,"COLOMBIA");
paises[3].tipo = 'A';
strcpy(paises[4].elpais,"PERU");
paises[4].tipo = 'B';
strcpy(paises[5].elpais,"URUGUAY");
paises[5].tipo = 'A';
strcpy(paises[6].elpais,"AUSTRALIA");
paises[6].tipo = 'C';
strcpy(paises[7].elpais,"BORNEO");
paises[7].tipo = 'B';
strcpy(paises[8].elpais,"JAVA");
paises[8].tipo = 'C';
strcpy(paises[9].elpais,"SUMATRA");
paises[9].tipo = 'A';
strcpy(paises[10].elpais,"EGIPTO");
paises[10].tipo = 'A';
strcpy(paises[11].elpais,"ETIOPIA");
paises[11].tipo = 'A';
strcpy(paises[12].elpais,"MADAGASCAR");
paises[12].tipo = 'B';
strcpy(paises[13].elpais,"SAHARA");
paises[13].tipo = 'C';
strcpy(paises[14].elpais,"SUDAFRICA");
paises[14].tipo = 'C';
strcpy(paises[15].elpais,"ZAIRE");
paises[15].tipo = 'B';
strcpy(paises[16].elpais,"ALEMANIA");
paises[16].tipo = 'B';
strcpy(paises[17].elpais,"ESPA¥A");
paises[17].tipo = 'A';
strcpy(paises[18].elpais,"FRANCIA");
paises[18].tipo = 'A';
strcpy(paises[19].elpais,"GRAN BRETA¥A");
paises[19].tipo = 'B';
strcpy(paises[20].elpais,"ITALIA");
paises[20].tipo = 'A';
strcpy(paises[21].elpais,"ISLANDIA");
paises[21].tipo = 'B';
strcpy(paises[22].elpais,"POLONIA");
paises[22].tipo = 'C';
strcpy(paises[23].elpais,"RUSIA");
paises[23].tipo = 'A';
strcpy(paises[24].elpais,"SUECIA");
paises[24].tipo = 'B';
strcpy(paises[25].elpais,"ALASKA");
paises[25].tipo = 'B';
strcpy(paises[26].elpais,"CALIFORNIA");
paises[26].tipo = 'C';
strcpy(paises[27].elpais,"CANADA");
paises[27].tipo = 'C';
strcpy(paises[28].elpais,"GROENLANDIA");
paises[28].tipo = 'A';
strcpy(paises[29].elpais,"LABRADOR");
paises[29].tipo = 'C';
strcpy(paises[30].elpais,"MEJICO");
paises[30].tipo = 'C';
strcpy(paises[31].elpais,"NUEVA YORK");
paises[31].tipo = 'B';
strcpy(paises[32].elpais,"OREGON");
paises[32].tipo = 'C';
strcpy(paises[33].elpais,"TERRANOVA");
paises[33].tipo = 'C';
strcpy(paises[34].elpais,"YUKON");
paises[34].tipo = 'A';
strcpy(paises[35].elpais,"ARABIA");
paises[35].tipo = 'C';
strcpy(paises[36].elpais,"ARAL");
paises[36].tipo = 'C';
strcpy(paises[37].elpais,"CHINA");
paises[37].tipo = 'B';
strcpy(paises[38].elpais,"GOBI");
paises[38].tipo = 'A';
strcpy(paises[39].elpais,"INDIA");
paises[39].tipo = 'A';
strcpy(paises[40].elpais,"IRAN");
paises[40].tipo = 'A';
strcpy(paises[41].elpais,"ISRAEL");
paises[41].tipo = 'B';
strcpy(paises[42].elpais,"JAPON");
paises[42].tipo = 'C';
strcpy(paises[43].elpais,"KAMCHATKA");
paises[43].tipo = 'A';
strcpy(paises[44].elpais,"MALASIA");
paises[44].tipo = 'C';
strcpy(paises[45].elpais,"MONGOLIA");
paises[45].tipo = 'B';
strcpy(paises[46].elpais,"SIBERIA");
paises[46].tipo = 'B';
strcpy(paises[47].elpais,"TAIMIR");
paises[47].tipo = 'X';
strcpy(paises[48].elpais,"TARTARIA");
paises[48].tipo = 'C';
strcpy(paises[49].elpais,"TURQUIA");
paises[49].tipo = 'B';



for (l=0;l<50;l++){
	for (m=0;m<50;m++)limitrofes[l][m]=0;
	}
limitrofes[0][1] = 1;
limitrofes[0][2] = 1;
limitrofes[0][4] = 1;
limitrofes[0][5] = 1;
limitrofes[1][0] = 1;
limitrofes[1][3] = 1;
limitrofes[1][4] = 1;
limitrofes[1][5] = 1;
limitrofes[1][13] = 1;
limitrofes[2][0] = 1;
limitrofes[2][4] = 1;
limitrofes[2][6] = 1;
limitrofes[3][1] = 1;
limitrofes[3][4] = 1;
limitrofes[3][30] = 1;
limitrofes[4][0] = 1;
limitrofes[4][1] = 1;
limitrofes[4][2] = 1;
limitrofes[4][3] = 1;
limitrofes[5][0] = 1;
limitrofes[5][1] = 1;
limitrofes[6][2] = 1;
limitrofes[6][7] = 1;
limitrofes[6][8] = 1;
limitrofes[6][9] = 1;
limitrofes[7][6] = 1;
limitrofes[7][44] = 1;
limitrofes[8][6] = 1;
limitrofes[9][6] = 1;
limitrofes[9][39] = 1;
limitrofes[10][11] = 1;
limitrofes[10][12] = 1;
limitrofes[10][13] = 1;
limitrofes[10][22] = 1;
limitrofes[10][41] = 1;
limitrofes[10][49] = 1;
limitrofes[11][10] = 1;
limitrofes[11][13] = 1;
limitrofes[11][14] = 1;
limitrofes[11][15] = 1;
limitrofes[12][10] = 1;
limitrofes[12][15] = 1;
limitrofes[13][10] = 1;
limitrofes[13][11] = 1;
limitrofes[13][15] = 1;
limitrofes[13][1] = 1;
limitrofes[13][17] = 1;
limitrofes[14][11] = 1;
limitrofes[14][15] = 1;
limitrofes[15][11] = 1;
limitrofes[15][12] = 1;
limitrofes[15][13] = 1;
limitrofes[15][14] = 1;
limitrofes[16][18] = 1;
limitrofes[16][19] = 1;
limitrofes[16][20] = 1;
limitrofes[16][22] = 1;
limitrofes[17][13] = 1;
limitrofes[17][18] = 1;
limitrofes[17][19] = 1;
limitrofes[18][16] = 1;
limitrofes[18][17] = 1;
limitrofes[18][20] = 1;
limitrofes[19][16] = 1;
limitrofes[19][17] = 1;
limitrofes[19][21] = 1;
limitrofes[20][16] = 1;
limitrofes[20][18] = 1;
limitrofes[21][19] = 1;
limitrofes[21][24] = 1;
limitrofes[21][28] = 1;
limitrofes[22][10] = 1;
limitrofes[22][16] = 1;
limitrofes[22][23] = 1;
limitrofes[22][49] = 1;
limitrofes[23][22] = 1;
limitrofes[23][24] = 1;
limitrofes[23][36] = 1;
limitrofes[23][40] = 1;
limitrofes[23][49] = 1;
limitrofes[24][21] = 1;
limitrofes[24][23] = 1;
limitrofes[25][32] = 1;
limitrofes[25][34] = 1;
limitrofes[25][43] = 1;
limitrofes[26][30] = 1;
limitrofes[26][31] = 1;
limitrofes[26][32] = 1;
limitrofes[27][31] = 1;
limitrofes[27][33] = 1;
limitrofes[27][34] = 1;
limitrofes[27][32] = 1;
limitrofes[28][21] = 1;
limitrofes[28][29] = 1;
limitrofes[28][31] = 1;
limitrofes[29][28] = 1;
limitrofes[29][33] = 1;
limitrofes[30][3] = 1;
limitrofes[30][26] = 1;
limitrofes[31][26] = 1;
limitrofes[31][27] = 1;
limitrofes[31][28] = 1;
limitrofes[31][32] = 1;
limitrofes[31][33] = 1;
limitrofes[32][25] = 1;
limitrofes[32][26] = 1;
limitrofes[32][31] = 1;
limitrofes[32][27] = 1;
limitrofes[32][34] = 1;
limitrofes[33][27] = 1;
limitrofes[33][29] = 1;
limitrofes[33][31] = 1;
limitrofes[34][25] = 1;
limitrofes[34][27] = 1;
limitrofes[34][32] = 1;
limitrofes[35][41] = 1;
limitrofes[35][49] = 1;
limitrofes[36][23] = 1;
limitrofes[36][40] = 1;
limitrofes[36][45] = 1;
limitrofes[36][46] = 1;
limitrofes[36][48] = 1;
limitrofes[37][38] = 1;
limitrofes[37][39] = 1;
limitrofes[37][42] = 1;
limitrofes[37][43] = 1;
limitrofes[37][44] = 1;
limitrofes[37][45] = 1;
limitrofes[37][46] = 1;
limitrofes[37][40] = 1;
limitrofes[38][37] = 1;
limitrofes[38][45] = 1;
limitrofes[38][40] = 1;
limitrofes[39][9] = 1;
limitrofes[39][37] = 1;
limitrofes[39][40] = 1;
limitrofes[39][44] = 1;
limitrofes[40][23] = 1;
limitrofes[40][36] = 1;
limitrofes[40][37] = 1;
limitrofes[40][38] = 1;
limitrofes[40][39] = 1;
limitrofes[40][45] = 1;
limitrofes[40][46] = 1;
limitrofes[40][49] = 1;
limitrofes[41][10] = 1;
limitrofes[41][35] = 1;
limitrofes[41][49] = 1;
limitrofes[42][37] = 1;
limitrofes[42][43] = 1;
limitrofes[43][25] = 1;
limitrofes[43][37] = 1;
limitrofes[43][42] = 1;
limitrofes[43][46] = 1;
limitrofes[44][7] = 1;
limitrofes[44][37] = 1;
limitrofes[44][39] = 1;
limitrofes[45][36] = 1;
limitrofes[45][37] = 1;
limitrofes[45][38] = 1;
limitrofes[45][40] = 1;
limitrofes[45][46] = 1;
limitrofes[46][36] = 1;
limitrofes[46][37] = 1;
limitrofes[46][40] = 1;
limitrofes[46][43] = 1;
limitrofes[46][47] = 1;
limitrofes[46][48] = 1;
limitrofes[46][45] = 1;
limitrofes[47][46] = 1;
limitrofes[47][48] = 1;
limitrofes[48][36] = 1;
limitrofes[48][46] = 1;
limitrofes[48][47] = 1;
limitrofes[49][10] = 1;
limitrofes[49][22] = 1;
limitrofes[49][23] = 1;
limitrofes[49][35] = 1;
limitrofes[49][40] = 1;
limitrofes[49][41] = 1;

}

void mostrarmapa(int cual){

	switch(cual){
	  case 0:africa();break;
	  case 1:asia();break;
	  case 2:europa();break;
	  case 3:americadelnorte();break;
	  case 4:americadelsur();break;
	  default:printf("ERROR EN LLAMADO DEL MAPA");
	}

}








void mostrarmision (int n){

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



void nombres (int n){
	char ok;
	int x,ma,no;
	//KEY 4, "REGRESAR"
	for ( x = 0;x < n;x++){
		clrscr();
		printf("\n\n\n\nIngrese el nombre del ej‚rcito %d \n(en caso de error tipee REGRESAR)\n\n",x+1);
		gets(nom[x].nombre);
		if (soniguales(nom[x].nombre,"REGRESAR",1)){
			if (x > 0){
				x = x - 2;
				}
			else if (x<=0){
				printf("\n\n\n   No hay otros ej‚rcitos");
				delay(2000);
				x = x - 1;
				}

			}
		}
do{
	delay(500);
	clrscr();

	for ( ma = 0 ;ma < n;ma++){
		printf("\n%d %s\n",ma+1, nom[ma].nombre);
	}
	printf ("\n\n¨Todos los nombres est n bien? (S/N)");
	/* deber¡a ser con gets y puts*/ ok=getchar();
	if (ok == 'n'|| ok == 'N'){
		do{
			printf("\n¨Qu‚ ej‚rcito tiene error?");
			scanf("%d",&no);
			fflush(stdin);
			if( no < 1 || no > n){
				printf ("Ej‚rcito no existente");
			}
			if (no == 0){
				ok = 's';
				}
		}while (!(no >= 0 && no <= n));
		if (no != 0 ){
			printf ("Escriba el nombre correcto:");
			/* deber¡a ser con gets y puts*/ gets(nom[no-1].nombre);
		}
	}
}while (ok == 'n'|| ok == 'N');

}




void ordenc (){

	int ordenado[50];
	int i,j,w,n;

	gotoxy(7,25);printf("Un Momento, ordenando cartas");

	for (i = 0;i < 50;i++){
		ordenado[i] = i;
		}
	//randomize();
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

void reagrupar(int t){

int paisejercitos[6][50];
int m,n,guille,loc,giles;
char origen[13],dest[13];
char seguir;
int cant;

if (nom[t].paso <=2){
	gotoxy(5,12);
	printf("%c",30);
	gotoxy(1,1);
	nom[t].paso=3;
	for (m=0;m<6;m++){
		for (n=0;n<50;n++){
			paisejercitos[m][n] = paisejerc[m][n];
		}
	}

	do{


	gotoxy(35,21);clreol();printf("Desde: ");
	gets(origen);
	guille = -1;
	while (!(soniguales(origen,paises[guille].elpais,1)) && guille < 50){
		guille++;
		gotoxy(35,25);clreol();printf("Buscando...%s",paises[guille].elpais);
	}
	if (soniguales(origen,paises[guille].elpais,1)){
		if (paisejerc[t][guille]){
		   if(paisejercitos[t][guille] > 1){

		     do{
			gotoxy(35,23);clreol();printf("Hasta: ");
			loc = 0;
			gets(dest);
			giles = -1;
			while (!(soniguales(dest,paises[giles].elpais,1)) && giles < 50){
				giles++;
				gotoxy(35,25);clreol();printf("Buscando...%s",paises[giles].elpais);
			}
			if (soniguales(dest,paises[giles].elpais,1)){
				if (paisejerc[t][giles]){
				   if(limitrofes[giles][guille]){

				  //	limpiarsec(1,21,79,24);
				  //	gotoxy(35,25);clreol();printf("Pasaje exitoso");
					gotoxy(10,24);clreol();printf("¨Cu ntos Ej‚rcitos desea pasar?");
                                     cant = 0;
				     do{
					scanf("%d",&cant);
					fflush(stdin);
					if(cant < 1){
					     gotoxy(35,25);clreol();printf("Se debe pasar al menos 1 ej‚rcito");
					}
					else {
						if(cant > paisejercitos[t][guille]){
							gotoxy(35,25);clreol();printf("S¢lo puede pasar %d ej‚rcitos",paisejercitos[t][guille]-1);
						}
					}
				     }while(cant < 1 || cant > paisejercitos[t][guille]);
				     paisejercitos[t][giles]++;
				     paisejercitos[t][guille] -= cant;
				     paisejerc[t][guille] -= cant;
				     paisejerc[t][giles] += cant;
				   }
				    else{
					gotoxy(35,25);clreol();printf("Los pa¡ses no son lim¡trofes");
					}



				}
				else{
				    loc = 1;
				    limpiarsec(1,21,79,24);
				    gotoxy(35,25);clreol();printf("El pa¡s de destino no te pertenece");
				    }
			}
			else{
				limpiarsec(1,21,79,24);
				gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
				loc = 1;
			     }
		      }while (loc == 1);
		    }
		    else{
			limpiarsec(1,21,79,24);
			gotoxy(35,25);clreol();printf("No hay suficientes ej‚rcitos para pasar");
			}


		}
		else{
			limpiarsec(1,21,79,24);
			gotoxy(35,25);clreol();printf("Ese pa¡s no te pertenece");
			}
		}
	else{
		limpiarsec(1,21,79,24);
		gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
	     }

       gotoxy(1,21);clreol();printf("¨Continuar el reagrupamiento? (S/N)?");
       seguir=getch();


	}while(seguir == 's' || seguir == 'S');






}
else{
	gotoxy(35,25);clreol();
	printf("Ya no es posible reagrupar");

}
	gotoxy(5,12);
	printf(" ");
	gotoxy(1,1);


}

void reppais (int n){

int i,w,m,y;
//int lug;

clrscr();

if(n==2 || n==5){
	for ( i = 0;i < 50 ;i+= n){
		for ( w = 0; w < n;w++){
			if ( i + w < 50 ){
				paisejerc[w][orden[i + w]] = 1;
			}
		}
	}
}
else{
	for ( i = 0;i < 48 ;i+= n){
		for ( w = 0; w < n;w++){
			if ( i + w < 48 ){
				paisejerc[w][orden[i + w]] = 1;
			}
		}
	}
	//randomize();
	w=rand() % n;
	paisejerc[w][orden[48]] = 1;
	//randomize();
	do{
		i=rand() % n;
	}while(i==w);
	paisejerc[i][orden[49]] = 1;

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

void soltarj(int t){

int listo,variac;
int cuales;
int wer,no,guille,busqueda;
int eltipo[3],cualmodifico[3];
char cambio[13],nabo[13];
int comod,verificador,quepongo=0;
int algo,algomas,cantidad;

if (nom[t].paso <=4){
	gotoxy(5,20);
	printf("%c",30);
	gotoxy(1,1);
	nom[t].paso=5;

	if(nom[t].conquista != 50){
		gotoxy(1,25);clreol();gotoxy(20,25);
		printf("Inserte una hoja en la impresora y presione cualquier tecla");
		getch();
		listo = 0;
		for(variac=0;variac<7;variac++){
			if(nom[t].tarjetas[variac] == 50 && listo == 0){
			     nom[t].tarjetas[variac] = orden[ultimatargeta];
			     nom[t].tarjetas[variac+1] = 50;
			     if (ultimatargeta == 0){
				ordenc();
				ultimatargeta = 50;
			     }
			     ultimatargeta--;
			     listo = 1;
			     cuales = variac;
			}
			if(nom[t].tarjetas[variac] != 50){
			   if(paisejerc[t][nom[t].tarjetas[variac]]){
				gotoxy(1,25);clreol();printf("%s posee %s, se le agregar n 2 ej‚rcitos ah¡",nom[t].nombre,paises[nom[t].tarjetas[cuales]].elpais);
				paisejerc[t][nom[t].tarjetas[variac]] += 2;
			   }
			}
		}
		fprintf (stdprn,"T.E.G.   TARJETA: %s", nom[t].nombre);
		fprintf (stdprn,"\n\n%s '%c' %c", paises[nom[t].tarjetas[cuales]].elpais, paises[nom[t].tarjetas[cuales]].tipo,12);
		gotoxy(35,25);clreol();printf("Se est  imprimiendo la tarjeta");
		delay(5000);
		gotoxy(1,25);clreol();gotoxy(20,25);printf("Saque la hoja ya impresa y presione cuaquier tecla");
		getch();
		if(variac == cuales){

			gotoxy(35,25);clreol();printf("Debe hacer un cambio de tarjetas, cupo llenado");
			for(wer=1;wer<=3;wer++){
				   do{
					no=0;
					printf("%dø.Tarj.: ",wer);
					gets(cambio);
					fflush(stdin);
					guille = -1;
					while (!(soniguales(cambio,paises[guille].elpais,1)) && guille < 50){
						guille++;
						gotoxy(35,25);clreol();printf("Buscando...%s",paises[guille].elpais);
					}

					if (soniguales(cambio,paises[guille].elpais,1)){
						busqueda = 0;
						do{
						busqueda++;
						}while(!(nom[t].tarjetas[busqueda] == guille) || busqueda < 7);
							if (nom[t].tarjetas[busqueda] == guille){
								eltipo[wer-1]=paises[guille].tipo;
								cualmodifico[wer-1]=busqueda;
								}
							else{
								gotoxy(35,25);clreol();printf("Esa tarjeta no es tuya");
								no++;
								}
					}
					else{
					limpiarsec(1,21,79,24);
					gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
					no++;
					}
				}while (no);
			}
			comod = 0;
			for(wer=0;wer<3;wer++){
				if(eltipo[wer]== 'X')
					comod++;
			}
			verificador=quepongo;
			switch(comod){
				case 3: quepongo += seguncanje(t);break;
				case 2: quepongo += seguncanje(t);break;
				case 1: quepongo += seguncanje(t);break;
				case 0: quepongo += thechange(eltipo[0],eltipo[1],eltipo[2],t);break;
				default: printf("Hay error en CANJE");break;
				}
			if (verificador != quepongo){
				nom[t].ncanjes++;
				for (algo=0;algo<2;algo++){
					for (algomas=0;algomas<6;algomas++){
						nom[t].tarjetas[cualmodifico[algo]]=nom[t].tarjetas[cualmodifico[algo+1]];
						nom[t].tarjetas[cualmodifico[algo+1]]=50;
					}

				}


			}

	do{
		fflush(stdin);
		limpiarsec(1,21,79,24);
		gotoxy(1,22);clreol(); printf( "%s tiene %d ej‚rcitos para asignar", nom[t].nombre, quepongo);
		printf( "\n¨En qu‚ pa¡s desea colocar ej‚rcitos? ");
		gets(nabo);

		if (soniguales(nabo,"SALIR",1))break;

		guille = -1;
		while (!(soniguales(nabo,paises[guille].elpais,1)) && guille < 50){
			guille++;
			gotoxy(35,25);clreol();printf("Buscando...%s",paises[guille].elpais);
		}
		if (soniguales(nabo,paises[guille].elpais,1)){
			if (paisejerc[t][guille]){
				gotoxy(2,24);clreol();printf( "Cu ntos ej‚rcitos desea colocar en %s? ", paises[guille].elpais);
				do{
					scanf("%d", &cantidad);
					fflush(stdin);
					if ( quepongo < cantidad ){
						gotoxy(35,25);clreol();printf("Ud. tiene menos ej‚rcitos para asignar");
					}
				}while (quepongo < cantidad);
				paisejerc[t][guille] += cantidad;
				quepongo -= cantidad;
				}
				else{
				limpiarsec(1,21,79,24);
				gotoxy(35,25);clreol();printf("Ese pa¡s no te pertenece");
				}
		}
		else{

			limpiarsec(1,21,79,24);
			gotoxy(35,25);clreol();printf("Pa¡s no encontrado");
		     }

		}while (quepongo);

		}

	}
	else{
		gotoxy(35,25);clreol();
		printf("Deber¡as haber conquistado al menos 1 Pa¡s");
	}


}
else{
	gotoxy(35,25);clreol();
	printf("Ya no es posible solicitar tarjeta");

}

gotoxy(5,20);
printf(" ");
gotoxy(1,1);

}

void turnos (int n, int ronda){

int ordene[6];
int ordenado[6];
int i,j,w,y,m;

clrscr();

for ( i = 0;i < n;i++){
	ordenado[i] = i+1;
}

//randomize();
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

int seguncanje(int nro){
	int valor;
	int result;

	valor=nom[nro].ncanjes;
	switch(valor){
	 case 1:result=4;break;
	 case 2:result=7;break;
	 case 3:result=10;break;
	 default:result = 5*(valor-1);
	}
	return result;

}



int verzero(int jug){
	int a,valor,nohay=0;
	for (a=36;a<50;a++){
		if (paisejerc[jug][a])
			valor = 7;
		else
			nohay++;
		}
	if (nohay)
		valor = 0;

	return valor;
}
int veruno(int jug){
	int a,valor,nohay=0;
	for (a=17;a<26;a++){
		if (paisejerc[jug][a])
			valor = 5;
		else
			nohay++;
		}
	if (nohay)
		valor = 0;

     return valor;

}
int verdos(int jug){
	int a,valor,nohay=0;
	for (a=26;a<36;a++){
		if (paisejerc[jug][a])
			valor = 5;
		else
			nohay++;
		}
	if (nohay)
		valor = 0;

	return valor;

}

int vertres(int jug){
	int a,valor,nohay=0;
	for (a=0;a<7;a++){
		if (paisejerc[jug][a])
			valor = 3;
		else
			nohay++;
		}
	if (nohay)
		valor = 0;

	return valor;
}
int vercuatro(int jug){
	int a,valor,nohay=0;
	for (a=11;a<17;a++){
		if (paisejerc[jug][a])
			valor = 3;
		else
			nohay++;
		}
	if (nohay)
		valor = 0;

       return valor;
}

int vercinco(int jug){
	int a,valor, nohay=0;
	for (a=7;a<11;a++){
		if (paisejerc[jug][a])
			valor = 2;
		else
			nohay++;
		}
	if (nohay)
		valor = 0;

	return valor;
}





int ejercontin(int cual,int jug){
	int valor=0;

	switch (cual){
		case 0:valor = verzero(jug);break;
		case 1:valor = veruno(jug);break;
		case 2:valor = verdos(jug);break;
		case 3:valor = vertres(jug);break;
		case 4:valor = vercuatro(jug);break;
		case 5:valor = vercinco(jug);break;
		default: printf("Error en c lculo de Ej‚rcitos por continente");
		}
	return valor;
}




/*

int misioncumplida(int *cual,int n){

	listo = 0;
	a=0;
	do{
		cantidad = 0;
		for(b=0;b<50;b++){
			if (paisejerc[a][b])
				cantidad++;
		}
		if (cantidad >= 30){
			ganador = a;
			cual = 1;
			listo = 1;
		}
		a++;
		if (listo == 0){
			switch(mision[a]){
			  case 0:ganador = misionzero(a);break;
			  case 1:ganador = misionuno(a);break;
			  case 2:ganador = misiondos(a);break;
			  case 3:ganador = misiontres(a);break;
			  case 4:ganador = misioncuatro(a);break;
			  case 5:ganador = misioncinco(a);break;
			  case 6:ganador = misionseis(a);break;
			  case 7:ganador = misionsiete(a);break;
			  case 8:ganador = misionocho(a);break;
			  default:ganador = destruccion(a);
			}
		}



	}while (a<n && listo==0);






}
*/



void africa(){

	 int a,b;

	 limpiarsec(10,1,79,20);

	 gotoxy (12,5);printf("A BRASILÍ");
	 gotoxy (22,1);printf("                 A TURQUIA");
	 gotoxy (22,2);printf(" A ESPA¥A               A ISRAEL ");
	 gotoxy (22,3);printf("        A POLONIA   º               ");
	 gotoxy (22,4);printf("ÚÄÄÄÄÐÄÄ¿         ÚÄÐÄÄÄÄÄÄÐ¿       ");
	 gotoxy (22,5);printf("µ       ÀÄÄÄÂÄÐÄÄÄÄÙ         ³       ");
	 gotoxy (22,6);printf("³ SAHARA    ÃÄÄ¿  EGIPTO     ÆÍÍÍÍÍ»  ");
	 gotoxy (22,7);printf("À¿         ÚÙ  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄ´     º  ");
	 gotoxy (22,8);printf(" Ç¿       ÚÙ   ETIOPIA      ÚÙ     º   ");
	 gotoxy (22,9);printf(" ºÀ¿     ÚÁÄÄÄ¿            ÚÙ      º  ");
	 gotoxy (22,10);printf(" º ÀÂÄÄÄÄÙ    ÀÄÄÂÄÄÄÄÄÄÄÄÂÙ       º  ");
	 gotoxy (22,11);printf(" º  À¿  ZAIRE   ÚÙ       ÚÙ       ÚÐ¿");
	 gotoxy (22,12);printf(" º   À¿      ÚÄÄÙ       ÚÙ        ³MADAGASCAR");
	 gotoxy (22,13);printf(" º    À¿    ÚÙ         ÚÙ         ³ ³");
	 gotoxy (22,14);printf(" º     À¿  ÚÙ         ÚÙ          ³ ³");
	 gotoxy (22,15);printf(" º      ÀÂÄÙSUDAFRICAÚÙ           ³ ³");
	 gotoxy (22,16);printf(" º       À¿         ÚÙ            ÀÒÙ");
	 gotoxy (22,17);printf(" º        À¿       ÚÙ              º   ");
	 gotoxy (22,18);printf(" º         ÀÄÄÄÄÄÄÄÙ               º   ");
	 gotoxy (22,19);printf(" ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");

	   for(a=0;a<6;a++){
		for (b=10;b<16;b++){
			if (paisejerc[a][b]){
				switch(b){
				  case 10:gotoxy(45,5);printf("%d",paisejerc[a][b]);break;
				  case 11:gotoxy(42,9);printf("%d",paisejerc[a][b]);break;
				  case 12:gotoxy(58,13);printf("%d",paisejerc[a][b]);break;
				  case 13:gotoxy(26,5);printf("%d",paisejerc[a][b]);break;
				  case 14:gotoxy(38,16);printf("%d",paisejerc[a][b]);break;
				  case 15:gotoxy(30,12);printf("%d",paisejerc[a][b]);break;
				}
			}
		}
	   }


}


void europa(){

	int a,b;

	limpiarsec(10,1,79,20);

	gotoxy(10,2);printf("AÍÍÍ");
	gotoxy(10,3);printf("ALAS-");
	gotoxy(10,4);printf("KA");
	gotoxy(15,1);printf("ÚÄÄÄÄÄÄÄ¿                   ÚÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄ¿ÍÍÍA ARAL");
	gotoxy(15,2);printf("µISLANDIA                   ³ SUECIA  ³      ÀÄÄÄ¿");
	gotoxy(15,3);printf("³       ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ         ³ RUSIA    ÀÄÄ¿ÍÍA IRAN");
	gotoxy(15,4);printf("ÀÄÄÄÒÄÄÄÙ                   ÀÄÄÄÄÄÄÄÄÄÁÄ¿           ÀÄ¿");
	gotoxy(15,5);printf("    º                                   ³             À¿ÍA TUR-");
	gotoxy(15,6);printf("    º                                   ÃÄÄÄÄÄ¿        À¿  QUIA");
	gotoxy(15,7);printf("    º           ÚÄÄÄ¿                   ³     ÀÄÄÄÄÄ¿   À¿");
	gotoxy(15,8);printf("    º          ÚÙ   ³                   ³           ÀÄÄÄÄÁÄÄ¿");
	gotoxy(15,9);printf("    º         ÚÙGRAN³                  ÚÙ  POLONIA          ³");
	gotoxy(15,10);printf("    ÈÍÍÍÍÍÍÍÍÍµBRE- ³                 ÚÁÄÄÄÄÄÄÄÄÄ¿          ÆÍÍÍA");
	gotoxy(15,11);printf("              ³TA¥A ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍ¾          ÀÄÄÄÄ¿   ÚÄÙEGIP-");
	gotoxy(15,12);printf("              ÀÄÄÒÄÄÙ         ÚÄÄÂÄÙ                  ÀÄÂÄÙ   TO");
	gotoxy(15,13);printf("                 º       ÚÄÄÄÄÙ  ÀÄÄÄÄ¿  ALEMANIA    ÚÄÄÙ");
	gotoxy(15,14);printf("                 º     ÚÄÙ            ÀÄÄÄÄ¿      ÚÄÄÙ");
	gotoxy(15,15);printf("                 º ÚÄÂÄÙ                   ÀÄÄ¿   ³");
	gotoxy(15,16);printf("           ÚÄÄÄÄÄÐÄÙ ³      FRANCIA         ÚÄÁÄÄÄ´");
	gotoxy(15,17);printf("           ³         ÀÄÄ¿             ÚÄÄÄÄÄÁ¿ITA-À¿");
	gotoxy(15,18);printf("           ³  ESPA¥A   ÚÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      ³LIA  ³");
	gotoxy(15,19);printf("           ÀÄÄÄÄÄÄÄÄÄÄÙ                     ³     ³");
	gotoxy(15,20);printf("              A SAHARA                       ÀÄÄÄÄÄÙ");



	   for(a=0;a<6;a++){
		for (b=16;b<25;b++){
			if (paisejerc[a][b]){
				switch(b){
				  case 16:gotoxy(60,12);printf("%d",paisejerc[a][b]);break;
				  case 17:gotoxy(31,17);printf("%d",paisejerc[a][b]);break;
				  case 18:gotoxy(45,15);printf("%d",paisejerc[a][b]);break;
				  case 19:gotoxy(32,8);printf("%d",paisejerc[a][b]);break;
				  case 20:gotoxy(61,19);printf("%d",paisejerc[a][b]);break;
				  case 21:gotoxy(19,3);printf("%d",paisejerc[a][b]);break;
				  case 22:gotoxy(46,8);printf("%d",paisejerc[a][b]);break;
				  case 23:gotoxy(44,4);printf("%d",paisejerc[a][b]);break;
				  case 24:gotoxy(31,3);printf("%d",paisejerc[a][b]);break;
				}
			}
		}
	   }


}


void americadelsur(){

	int a,b;

	 limpiarsec(10,1,79,20);
	   gotoxy (18,1);printf("A MALASIA");
	   gotoxy (21,2);printf("");
	   gotoxy (20,3);printf("ÚÄ¿");
	   gotoxy (20,4);printf("³BORNEO");
	   gotoxy (20,5);printf("³ ³");
	   gotoxy (20,6);printf("³ ³");
	   gotoxy (20,7);printf("ÀÒÙ");
	   gotoxy (21,8);printf("º");
	   gotoxy (21,9);printf("º");

	   gotoxy (11,2);printf("A INDIA");
	   gotoxy (14,3);printf("");
	   gotoxy (14,4);printf("º");
	   gotoxy (14,5);printf("º");
	   gotoxy (13,6);printf("ÚÐ¿");
	   gotoxy (13,7);printf("³ ³");
	   gotoxy (13,8);printf("³SUMATRA");
	   gotoxy (13,9);printf("ÀÒÙ");
	   gotoxy (14,10);printf("º");
	   gotoxy (14,11);printf("ÈÍÍ");




	   gotoxy (25,5);printf("ÚÄ¿");
	   gotoxy (25,6);printf("³ ³");
	   gotoxy (25,7);printf("³JAVA");
	   gotoxy (25,8);printf("ÀÒÙ");
	   gotoxy (26,9);printf("º");





	   gotoxy (17,10);printf("ÚÄÄÄÐÄÄÄÄÐÄÄÄÄÄ¿ ");
	   gotoxy (17,11);printf("µ  AUSTRALIA   ³  ");
	   gotoxy (17,12);printf("³              ÆÍÍÍÍÍÍÍÍÍ");
	   gotoxy (17,13);printf("À¿            ÚÙ ");
	   gotoxy (17,14);printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ");

	gotoxy (37,2);printf(" A MEJICO");
	gotoxy (37,3);printf("                        ÉÍÍÍÍÍÍÍÍÍA SAHARA");
	gotoxy (37,4);printf("ÚÄÄÄÄÐÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÐ¿");
	gotoxy (37,5);printf("ÀÄ¿COLOMBIAÃÄÙ           ÚÙ");
	gotoxy (37,6);printf("  À¿       ³  BRASIL    ÚÙ");
	   gotoxy (40,7);printf("ÃÄÄÄÄÄÄÄ´           ÚÙ");
	   gotoxy (40,8);printf("³ PERU  ³          ÚÙ");
	   gotoxy (40,9);printf("ÃÄÄÂÄÄÄÄÁÂÄÄÄÄÄÄÄÄÄ´");
	   gotoxy (40,10);printf("³ C³     À¿URUGUAY ³");
	   gotoxy (40,11);printf("À¿H³      À¿      ÚÙ");
	   gotoxy (40,12);printf("ÍµI³       ÀÄÄ¿  ÚÙ ");
	   gotoxy (40,13);printf(" ³L³          ÀÄÂÙ");
	   gotoxy (40,14);printf(" ³E³ARGENTINA  ÚÙ");
	   gotoxy (40,15);printf(" ³ ³          ÚÙ");
	   gotoxy (40,16);printf(" À¿À¿        ÚÙ");
	   gotoxy (40,17);printf("  À¿À¿      ÚÙ");
	   gotoxy (40,18);printf("   ÀÂÙ    ÚÄÙ");
	   gotoxy (40,19);printf("    ³   ÚÄÙ");
	   gotoxy (40,20);printf("    ÀÄÄÄÙ");

	   for(a=0;a<6;a++){
		for (b=0;b<10;b++){
			if (paisejerc[a][b]){
				switch(b){
				  case 0:gotoxy(48,15);printf("%d",paisejerc[a][b]);break;
				  case 1:gotoxy(54,7);printf("%d",paisejerc[a][b]);break;
				  case 2:gotoxy(42,15);printf("%d",paisejerc[a][b]);break;
				  case 3:gotoxy(43,6);printf("%d",paisejerc[a][b]);break;
				  case 4:gotoxy(47,8);printf("%d",paisejerc[a][b]);break;
				  case 5:gotoxy(56,11);printf("%d",paisejerc[a][b]);break;
				  case 6:gotoxy(23,12);printf("%d",paisejerc[a][b]);break;
				  case 7:gotoxy(21,5);printf("%d",paisejerc[a][b]);break;
				  case 8:gotoxy(26,6);printf("%d",paisejerc[a][b]);break;
				  case 9:gotoxy(14,7);printf("%d",paisejerc[a][b]);break;
				}
			}
		}
           }






}


void americadelnorte(){

	int a,b;

	 limpiarsec(10,1,79,20);
	   gotoxy (11,1); printf("              ³                ³           ³          ÆÍÍÍÍÍÍGROEN- ³  ");
	   gotoxy (11,2); printf("              ³      CANADA    ÆÍÍÍÍÍÍÍÍÍÍ»³ LABRADOR ³     ³LANDIA ³  ");
	   gotoxy (11,3); printf("              ÃÄÄÄÄÄÄÄÄÄÄ¿     ÃÄÄÄÄÄÄÄÄÄÄºÁÄÄÄÄÄÄÄÄÄÄ´     É       ³  ");
	   gotoxy (11,4); printf("              ³YUKON     ÃÂÄÄÄÄÙ          È           ³     ºÄÒÄÄÄÄÄÙ                        ");
	   gotoxy (11,5); printf("              ÃÄÄÄÄÄÂÄÄÄÄÙ³ NUEVA YORK    ³ TERRANOVA ³     º º                              ");
	   gotoxy (11,6); printf("       ÚÄÄÄÄÄÄÙ     ³ORE- ÃÄÄÄÄÄÄÄÄÄÄÄÄÄºÄÅÄÄÄÄÄÄÄÄÄÄÄÙ     º  A IS-	                            ");
	   gotoxy (11,7); printf("       ³            ³GON  ³             ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼   LANDIA          ");
	   gotoxy (11,8); printf("       ³  ALASKA    ³     ³  CALIFORNIA   ³                    ");
	   gotoxy (11,9); printf("       ÀÄÄÒÄÄÄÄÄÄÄÄÄÁÄÄÂÄÄÙ          ÚÄÄÄÄÙ                      ");
	   gotoxy (11,10); printf("                      ³  ÚÄ¿        ³	                                ");
	   gotoxy (11,11); printf("      A KATMCHATCA     ³  À¿À¿       ³                              ");
	   gotoxy (11,12); printf("                       ÀÄÄÄÙ ÃÄÄÄÄÄÂÄÙ                    ");
	   gotoxy (11,13); printf("                             ³     ³											");
	   gotoxy (11,14); printf("                             ³     ÀÄÄÄ¿			");
	   gotoxy (11,15); printf("                             ³ MEJICO  ³							");
	   gotoxy (11,16); printf("                             ÀÒÄÄÄÄÄÄÄÄÙ");
	   gotoxy (11,17); printf("			      º A COLOMBIA					");
	   gotoxy (11,18); printf("                                            ");
	   gotoxy (11,19); printf("");
	   gotoxy (11,20); printf("");


	   for(a=0;a<6;a++){
		for (b=25;b<35;b++){
			if (paisejerc[a][b]){
				switch(b){
				  case 25:gotoxy(33,7);printf("%d",paisejerc[a][b]);break;
				  case 26:gotoxy(43,9);printf("%d",paisejerc[a][b]);break;
				  case 27:gotoxy(34,1);printf("%d",paisejerc[a][b]);break;
				  case 28:gotoxy(74,3);printf("%d",paisejerc[a][b]);break;
				  case 29:gotoxy(57,1);printf("%d",paisejerc[a][b]);break;
				  case 30:gotoxy(42,14);printf("%d",paisejerc[a][b]);break;
				  case 31:gotoxy(44,4);printf("%d",paisejerc[a][b]);break;
				  case 32:gotoxy(32,8);printf("%d",paisejerc[a][b]);break;
				  case 33:gotoxy(56,4);printf("%d",paisejerc[a][b]);break;
				  case 34:gotoxy(32,4);printf("%d",paisejerc[a][b]);break;
				}
			}
		}
	   }
}


void asia(){

	 int a,b;

	 limpiarsec(10,1,79,20);
	   gotoxy (11,1); printf("            ÚÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÂÄÂÄÄÄÄÄÄÄÄÄÄÄ¿ ");
	   gotoxy (11,2); printf("            ³ARALÃ¿TARTARIA   ³TAIMIR   ³ ³KATMCHATCA ÆÍ»");
	   gotoxy (11,3); printf("            ³    ³ÀÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÙ ³           ³ º");
	   gotoxy (11,4); printf("         ÉÍÍµ    ³   SIBERIA              ³           ³ º ÚÄÄÄÄÄÄÄ¿ ");
	   gotoxy (11,5); printf("         º  ÃÄÄÄÄÅÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÂÄÄÄÄÄ·ÄÄÙ ÈÍµ       ³");
	   gotoxy (11,6); printf(" A RUSIAÍ¹  ³ I  ³MONGOLIA³                  ÆÍ»   º      ³ JAPON ³");
	   gotoxy (11,7); printf("         º  ³ R  ³        ³    CHINA       ÚÄÙ ÈÍÍÍºÍÍÍÍÍÍµ       ³");
	   gotoxy (11,8); printf("         ÌÍÍµ A  ÃÄÄÄÄÄÄÄÄ´             ÚÄÄÙ       º      ³       ³");
	   gotoxy (11,9); printf("A POLONIAº  ³ N  ³GOBI    ³          ÚÄÄÙ                ÀÄÄÄÄÄÄÄÙ");
	   gotoxy (11,10); printf("       º   ³    ÃÄÄÄÄÄÄÄÄÙ       ÚÄÄÙ          A ALASKA");
	   gotoxy (11,11); printf("      º º   ³    ÀÄÄ¿             ³");
	   gotoxy (11,12); printf("     ÚÐÄÐÄÄÄÁÄÄÄÄÄÂÂÁÄÄÄÄÄÄÂÄÄÄÄÄÄ´");
	   gotoxy (11,13); printf("   ÉÍµTURQUIA     ³³ INDIA ³MALASIAÍÍÍ»");
	   gotoxy (11,14); printf("   º ÃÄÄÄÄÄÄÄÄÂÄÂÄÙ³       ³      ³   ");
	   gotoxy (11,15); printf("   ÌÍµISRAEL  ³ ³  ÀÄÄ·ÄÄÄÄÁÄÄÄÄÄÄÙ  A BORNEO");
	   gotoxy (11,16); printf("   º ÃÄÄÄÄÄÄÄÄÙ ³     º ");
	   gotoxy (11,17); printf("   º ³ARABIA    ³      ");
	   gotoxy (11,18); printf("   º ÀÄÄÄÄÄÄÄÄÄÄÙ    A SUMATRA");
	   gotoxy (11,19); printf("   ");
	   gotoxy (11,20); printf(" A  EGIPTO");


	   for(a=0;a<6;a++){
		for (b=35;b<50;b++){
			if (paisejerc[a][b]){
				switch(b){
				  case 35:gotoxy(35,17);printf("%d",paisejerc[a][b]);break;
				  case 36:gotoxy(24,3);printf("%d",paisejerc[a][b]);break;
				  case 37:gotoxy(40,8);printf("%d",paisejerc[a][b]);break;
				  case 38:gotoxy(34,9);printf("%d",paisejerc[a][b]);break;
				  case 39:gotoxy(32,14);printf("%d",paisejerc[a][b]);break;
				  case 40:gotoxy(24,10);printf("%d",paisejerc[a][b]);break;
				  case 41:gotoxy(34,15);printf("%d",paisejerc[a][b]);break;
				  case 42:gotoxy(71,7);printf("%d",paisejerc[a][b]);break;
				  case 43:gotoxy(56,3);printf("%d",paisejerc[a][b]);break;
				  case 44:gotoxy(41,14);printf("%d",paisejerc[a][b]);break;
				  case 45:gotoxy(30,7);printf("%d",paisejerc[a][b]);break;
				  case 46:gotoxy(41,4);printf("%d",paisejerc[a][b]);break;
				  case 47:gotoxy(47,2);printf("%d",paisejerc[a][b]);break;
				  case 48:gotoxy(38,2);printf("%d",paisejerc[a][b]);break;
				  case 49:gotoxy(26,13);printf("%d",paisejerc[a][b]);break;
				}
			}
		}
	   }

}
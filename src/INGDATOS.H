#define__ingdatos_h


void banderas (int n){ 		     //PIDE LAS BANDERAS DE LOS JUGADORES.

	int h;
        h=n+1;
	n=h-1;
}



void nombres (int n){        		//PIDE NOMBRES DE LOS JUGADORES.
	char ok,extra[1];
	int x,ma,no;
	//KEY 4, "REGRESAR"
	for ( x = 0;x < n;x++){
		clrscr();
		printf("\n\nIngrese el nombre del ej‚rcito %d \n(en caso de error tipee REGRESAR)",x+1);
		gets(nom[x].nombre);
		if (soniguales(nom[x].nombre,"REGRESAR",1)){
			if (x > 0){
				x = x - 2;
				}
			else if (x<=0){
				printf("\n\n   No hay otros ej‚rcitos");
				delay(2000);
				x = x - 1;
				}

			}
		}
do{     delay(500);
	clrscr();
	for ( ma = 0 ;ma < n;ma++){
		printf("%d %s\n",ma+1, nom[ma].nombre);
	}
	printf ("¨Todos los nombres est n bien? (S/N)");
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
			gets(extra);
			/* deber¡a ser con gets y puts*/ gets(nom[no-1].nombre);
		}
	}
}while (ok == 'n'|| ok == 'N');

}



void inicializacion (){
	     //INICIALIZA CIERTOS VECTORES QUE LUEGO PERMANECEN CONSTANTES.

int l,m;


strcpy(paises[0].elpais,"TURQUIA");
strcpy(paises[1].elpais,"ARGENTINA");
strcpy(paises[2].elpais,"BRASIL");
strcpy(paises[3].elpais,"CHILE");
strcpy(paises[4].elpais,"COLOMBIA");
strcpy(paises[5].elpais,"PERU");
strcpy(paises[6].elpais,"URUGUAY");
strcpy(paises[7].elpais,"AUSTRALIA");
strcpy(paises[8].elpais,"BORNEO");
strcpy(paises[9].elpais,"JAVA");
strcpy(paises[10].elpais,"SUMATRA");
strcpy(paises[11].elpais,"EGIPTO");
strcpy(paises[12].elpais,"ETIOPIA");
strcpy(paises[13].elpais,"MADAGASCAR");
strcpy(paises[14].elpais,"SAHARA");
strcpy(paises[15].elpais,"SUDAFRICA");
strcpy(paises[16].elpais,"ZAIRE");
strcpy(paises[17].elpais,"ALEMANIA");
strcpy(paises[18].elpais,"ESPA¥A");
strcpy(paises[19].elpais,"FRANCIA");
strcpy(paises[20].elpais,"GRAN BRETA¥A");
strcpy(paises[21].elpais,"ITALIA");
strcpy(paises[22].elpais,"ISLANDIA");
strcpy(paises[23].elpais,"POLONIA");
strcpy(paises[24].elpais,"RUSIA");
strcpy(paises[25].elpais,"SUECIA");
strcpy(paises[26].elpais,"ALASKA");
strcpy(paises[27].elpais,"CALIFORNIA");
strcpy(paises[28].elpais,"CANADA");
strcpy(paises[29].elpais,"GROENLANDIA");
strcpy(paises[30].elpais,"LABRADOR");
strcpy(paises[31].elpais,"MEJICO");
strcpy(paises[32].elpais,"NUEVA YORK");
strcpy(paises[33].elpais,"OREGON");
strcpy(paises[34].elpais,"TERRANOVA");
strcpy(paises[35].elpais,"YUKON");
strcpy(paises[36].elpais,"ARABIA");
strcpy(paises[37].elpais,"ARAL");
strcpy(paises[38].elpais,"CHINA");
strcpy(paises[39].elpais,"GOBI");
strcpy(paises[40].elpais,"INDIA");
strcpy(paises[41].elpais,"IRAN");
strcpy(paises[42].elpais,"ISRAEL");
strcpy(paises[43].elpais,"JAPON");
strcpy(paises[44].elpais,"KAMCHATKA");
strcpy(paises[45].elpais,"MALASIA");
strcpy(paises[46].elpais,"MONGOLIA");
strcpy(paises[47].elpais,"SIBERIA");
strcpy(paises[48].elpais,"TAIMIR");
strcpy(paises[49].elpais,"TARTARIA");


for (l=0;l<50;l++){
	for (m=0;m<50;m++)limitrofes[l][m]=0;
	}
limitrofes[1][2] = 1;
limitrofes[1][3] = 1;
limitrofes[1][5] = 1;
limitrofes[1][6] = 1;
limitrofes[2][1] = 1;
limitrofes[2][4] = 1;
limitrofes[2][5] = 1;
limitrofes[2][6] = 1;
limitrofes[2][14] = 1;
limitrofes[3][1] = 1;
limitrofes[3][5] = 1;
limitrofes[3][7] = 1;
limitrofes[4][2] = 1;
limitrofes[4][5] = 1;
limitrofes[4][31] = 1;
limitrofes[5][1] = 1;
limitrofes[5][2] = 1;
limitrofes[5][3] = 1;
limitrofes[5][4] = 1;
limitrofes[6][1] = 1;
limitrofes[6][2] = 1;
limitrofes[7][3] = 1;
limitrofes[7][8] = 1;
limitrofes[7][9] = 1;
limitrofes[7][10] = 1;
limitrofes[8][7] = 1;
limitrofes[8][45] = 1;
limitrofes[9][7] = 1;
limitrofes[10][7] = 1;
limitrofes[10][40] = 1;
limitrofes[11][12] = 1;
limitrofes[11][13] = 1;
limitrofes[11][14] = 1;
limitrofes[11][23] = 1;
limitrofes[11][42] = 1;
limitrofes[11][50] = 1;
limitrofes[12][11] = 1;
limitrofes[12][14] = 1;
limitrofes[12][15] = 1;
limitrofes[12][16] = 1;
limitrofes[13][11] = 1;
limitrofes[13][16] = 1;
limitrofes[14][11] = 1;
limitrofes[14][12] = 1;
limitrofes[14][16] = 1;
limitrofes[14][2] = 1;
limitrofes[14][18] = 1;
limitrofes[15][12] = 1;
limitrofes[15][16] = 1;
limitrofes[16][12] = 1;
limitrofes[16][13] = 1;
limitrofes[16][14] = 1;
limitrofes[16][15] = 1;
limitrofes[17][19] = 1;
limitrofes[17][20] = 1;
limitrofes[17][21] = 1;
limitrofes[17][23] = 1;
limitrofes[18][14] = 1;
limitrofes[18][19] = 1;
limitrofes[18][20] = 1;
limitrofes[19][17] = 1;
limitrofes[19][18] = 1;
limitrofes[19][21] = 1;
limitrofes[20][17] = 1;
limitrofes[20][18] = 1;
limitrofes[20][22] = 1;
limitrofes[21][17] = 1;
limitrofes[21][19] = 1;
limitrofes[22][20] = 1;
limitrofes[22][25] = 1;
limitrofes[22][29] = 1;
limitrofes[23][11] = 1;
limitrofes[23][17] = 1;
limitrofes[23][24] = 1;
limitrofes[23][50] = 1;
limitrofes[24][23] = 1;
limitrofes[24][25] = 1;
limitrofes[24][37] = 1;
limitrofes[24][41] = 1;
limitrofes[24][50] = 1;
limitrofes[25][22] = 1;
limitrofes[25][24] = 1;
limitrofes[26][33] = 1;
limitrofes[26][35] = 1;
limitrofes[26][44] = 1;
limitrofes[27][31] = 1;
limitrofes[27][32] = 1;
limitrofes[27][33] = 1;
limitrofes[28][32] = 1;
limitrofes[28][34] = 1;
limitrofes[28][35] = 1;
limitrofes[28][33] = 1;
limitrofes[29][22] = 1;
limitrofes[29][30] = 1;
limitrofes[29][32] = 1;
limitrofes[30][29] = 1;
limitrofes[30][34] = 1;
limitrofes[31][4] = 1;
limitrofes[31][27] = 1;
limitrofes[32][27] = 1;
limitrofes[32][28] = 1;
limitrofes[32][29] = 1;
limitrofes[32][33] = 1;
limitrofes[32][34] = 1;
limitrofes[33][26] = 1;
limitrofes[33][27] = 1;
limitrofes[33][32] = 1;
limitrofes[33][28] = 1;
limitrofes[33][35] = 1;
limitrofes[34][28] = 1;
limitrofes[34][30] = 1;
limitrofes[34][32] = 1;
limitrofes[35][26] = 1;
limitrofes[35][28] = 1;
limitrofes[35][33] = 1;
limitrofes[36][42] = 1;
limitrofes[36][50] = 1;
limitrofes[37][24] = 1;
limitrofes[37][41] = 1;
limitrofes[37][46] = 1;
limitrofes[37][47] = 1;
limitrofes[37][49] = 1;
limitrofes[38][39] = 1;
limitrofes[38][40] = 1;
limitrofes[38][43] = 1;
limitrofes[38][44] = 1;
limitrofes[38][45] = 1;
limitrofes[38][46] = 1;
limitrofes[38][47] = 1;
limitrofes[38][41] = 1;
limitrofes[39][38] = 1;
limitrofes[39][46] = 1;
limitrofes[39][41] = 1;
limitrofes[40][10] = 1;
limitrofes[40][38] = 1;
limitrofes[40][41] = 1;
limitrofes[40][45] = 1;
limitrofes[41][24] = 1;
limitrofes[41][37] = 1;
limitrofes[41][38] = 1;
limitrofes[41][39] = 1;
limitrofes[41][40] = 1;
limitrofes[41][46] = 1;
limitrofes[41][47] = 1;
limitrofes[41][50] = 1;
limitrofes[42][11] = 1;
limitrofes[42][36] = 1;
limitrofes[42][50] = 1;
limitrofes[43][38] = 1;
limitrofes[43][44] = 1;
limitrofes[44][26] = 1;
limitrofes[44][38] = 1;
limitrofes[44][43] = 1;
limitrofes[44][47] = 1;
limitrofes[45][8] = 1;
limitrofes[45][38] = 1;
limitrofes[45][40] = 1;
limitrofes[46][37] = 1;
limitrofes[46][38] = 1;
limitrofes[46][39] = 1;
limitrofes[46][41] = 1;
limitrofes[46][47] = 1;
limitrofes[47][37] = 1;
limitrofes[47][38] = 1;
limitrofes[47][41] = 1;
limitrofes[47][44] = 1;
limitrofes[47][48] = 1;
limitrofes[47][49] = 1;
limitrofes[47][46] = 1;
limitrofes[48][47] = 1;
limitrofes[48][49] = 1;
limitrofes[49][37] = 1;
limitrofes[49][47] = 1;
limitrofes[49][48] = 1;
limitrofes[50][11] = 1;
limitrofes[50][23] = 1;
limitrofes[50][24] = 1;
limitrofes[50][36] = 1;
limitrofes[50][41] = 1;
limitrofes[50][42] = 1;

}





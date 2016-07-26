#define__comparac_h


int soniguales(char primera[20],char segunda[20],int mayusc){
	int largo1,largo2,noes,valor,i;
	char primeraaux[20];
	largo1 = strlen(primera);
	largo2 = strlen(segunda);
	if (mayusc==1){                                   //EL LAZO SI ESTA
		for (i=0; i<largo1; i++){               //HECHO PARA VERIFICAR
			switch(primera[i]){             //SI LA COMPARACION SE
			  case '¤': primeraaux[i] = '¥';break;     //HACE SIN
			  case ' ': primeraaux[i] = 'A';break; //IMPORTAR LAS
			  case '‚': primeraaux[i] = 'E';break;   //MAYUSCULAS
			  case '¡': primeraaux[i] = 'I';break;
			  case '¢': primeraaux[i] = 'O';break;
			  case '£': primeraaux[i] = 'O';break;
			  default:  primeraaux[i] = toupper(primera[i]);break;
			  }

		}
	}
	if (largo1==largo2){
		for (i=0;i<largo1;i++){
			if (!(primeraaux[i]==segunda[i] || primera[i]==segunda[i])){
				noes=1;
				}
			}
        }
	else{
		noes=1;
		}
	if (noes==1)
		valor=0;
	else
		valor=1;
	return valor;
}



int thechange(char eltipo0,char eltipo1,char eltipo2,int nro){
	int devolver;
	if((eltipo0==eltipo1 && eltipo0==eltipo2) || (eltipo0!=eltipo1 && eltipo0!=eltipo2 && eltipo1!=eltipo2)){
		devolver = seguncanje(nro);
		}
	else{
		devolver = 0;
		printf("No Hay Concordancia");
		}
        return devolver;
	}


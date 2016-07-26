#include <stdio.h>
#include <conio.h>

void retroceder(int *posic,int *pantallax){
	if(*posic == 0)
		clreol;
	else{
		(*posic)--;
		(*pantallax)--;
	}


}


void capturar(char vector[],int tamano,int pantx,int panty){
  char n;
  int r,pos=0;
  do {
   gotoxy(pantx,panty);

     n= getche();
		     r = n;
       switch(r){
       case 8: retroceder(&pos,&pantx);clreol(); break;
       case 9: clrscr();printf("mostrarmapa(1)");gotoxy(pantx,panty);getch(); break;
       case 13: break;
       case 27:printf("guardarjuego()"); break;
       default: vector[pos]=n;pantx++;pos++;
       }
	gotoxy(pantx,panty);
    }while(r!=13 && pos<tamano);
    vector[pos]='\0';
  }

void main(){

char cual[13];
clrscr();


capturar(cual,12,5,5);

clrscr();
printf("%s",cual);

getch();
}
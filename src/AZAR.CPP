#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

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

void main(){

	int m,n,dadosdef,dadosat;
	int r,t,wi,hi;
	int x[3],y[3];
	char op;

   do{
        n=0;
	m=0;
	r=0;
	n=0;
	t=0;
	wi=0;
	for(hi=0;hi<3;hi++){
		x[hi]=0;
		y[hi]=0;
	}


	clrscr();
	dadosat=3;
	dadosdef=3;
	randomize();

	for(m=0;m<dadosat;m++){
		r = (rand() % 6) + 1;
		switch (m){
		  case 0: x[0]=r;break;
		  case 1: case1(&x[0],&x[1],r);break;
		  case 2: case2(&x[0],&x[1],&x[2],r);break;
		  default:printf("HAY ERROR EN CALCULO DE ATAQUE");
		  }
		r=0;
        }
	randomize();

	for(n=0;n<dadosdef;n++){

		t = (rand() % 6) + 1;
		switch (n){
		  case 0: y[0]=t;break;
		  case 1:case1(&y[0],&y[1],t);break;
		  case 2:case2(&y[0],&y[1],&y[2],t);break;
		  default:printf("HAY ERROR EN CALCULO DE DEFENSA");
		  }
		t=0;

	}
	for(wi=0;wi<3;wi++){
		printf("\n\n%d\t\t%d",x[wi],y[wi]);
	}
	op=getch();
   }while(op != 's');
}
#include <stdio.h>
#include <conio.h>

void main(){
	clrscr();
	struct UNA{
		int x;
		int *y;
		}m,*p,**q;
	q=&p;
	p->m.x;

//	y=&m.x;
	printf("Dir. de m.x: %d\nDir. de *p: %d\nDir. de **q: %d\nVal. de q(&p): %d\nVal. de p(&m.x): %d",&m.x,&p,&q,q,p);
        getch();

}
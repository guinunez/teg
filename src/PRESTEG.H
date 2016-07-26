#define__presteg_h
#if!defined__graphics_h
	#include <graphics.h>
#endif
#if!defined__process_h
	#include <process.h>
#endif


void menu(char *elecc){
   char elecc2;
   int style;
   int size=1;
   clrscr();
   settextjustify(LEFT_TEXT, LEFT_TEXT);
   textcolor(LIGHTBLUE);
   /* loop through the available text styles */

      cleardevice();
      style = SANS_SERIF_FONT;
	 size = 20;

      /* select the text style */
      settextstyle(style, HORIZ_DIR, size);
      do{
	 outtextxy(90,150,"A - COMENZAR EL JUEGO.");
	 //outtextxy(90,180,"B - CARGAR EL JUEGO.");
	 outtextxy(90,210,"B - SALIR A D.O.S..");
	  *elecc=getch();
	  if (*elecc=='a'|| *elecc=='A'){
	  outtextxy(200,300,"ESPERE UN MOMENTO, POR FAVOR.");
	  delay(1000);
       }
       /*else if (*elecc =='b'|| *elecc=='B'){
	  outtextxy(200,300,"EL JUEGO SERA CARGADO.");
	}
	*/
	      else if (*elecc =='b'|| *elecc=='B'){
	      outtextxy(200,300,"GRACIAS POR JUGAR.");
	      }
	      else if( *elecc != 'a' || *elecc !='b'|| *elecc !='c'){
		cleardevice();
		outtextxy(200,300,"LA ELECCION PROPUESTA NO CORRESPONDE.");
	      }
      }while(!(*elecc == 'a' || *elecc=='A') && !(*elecc =='b'|| *elecc=='B') && !(*elecc =='c'|| *elecc!='C'));
      *elecc=toupper(*elecc);


}
void presentacion(char *ser)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int style, midx, midy;
   int size;
   int result;

   clrscr();
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("ERROR GRAFICO: %s\n", grapherrormsg(errorcode));
      printf("PRESIONE CUALQUIER TECLA PARA CONTINUAR:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;

   settextjustify(CENTER_TEXT, CENTER_TEXT);
   textcolor(LIGHTBLUE);

      cleardevice();
      style = TRIPLEX_FONT;
      size = 8;

      settextstyle(style, HORIZ_DIR, size);

      outtextxy(midx, midy,"T. E. G. ");
      getch();
/*
result = spawnl(P_WAIT, "rd_demo","presteg.pcx","18");
if (result == -1)
{
   perror("Error from spawnl");
   getch();
   exit(1);
}

*/

     menu(ser);
     /* clean up */
   closegraph();
}

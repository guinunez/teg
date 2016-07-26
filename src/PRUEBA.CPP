#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <process.h>
#include <graphics.h>


void main(){
   int result;
   //int num = 18;
   //char caracter[11]="presteg.pcx";


result = spawnl(P_WAIT, "C:\\TEMP\\TEG\\PRACTICO.EXE","ab");
if (result == -1)
{
   perror("Error from spawnl");
   getch();
   exit(1);
}
getch();

}
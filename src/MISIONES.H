
#include <string.h>
#include <stdio.h>

int main(void)
{
   int i;
   FILE *stream;
   char mis[][150] = {"OCUPAR AFRICA, 5 PAISES DE AMERICA DEL NORTE Y 4 PAISES DE EUROPA","OCUPAR AMERICA DEL NORTE, 2 PAISES DE OCEANIA Y 4 DE ASIA","OCUPAR OCEANIA, AMERICA DEL NORTE Y 2 PAISES DE EUROPA","OCUPAR ASIA Y 2 PAISES DE AMERICA DEL SUR","OCUPAR EUROPA, 4 PAISES DE ASIA Y 2 PAISES DE AMERICA DEL SUR","OCUPAR 2 PAISES DE OCEANIA, 2 PAISES DE AFRICA, 2 PAISES DE AMERICA DEL SUR,     3 PAISES DE EURUPA, 4 PAISES DE AMERICA DEL NORTE Y 3 PAISES DE ASIA","OCUPAR OCEANIA, AFRICA Y 5 PAISES DE AMERICA DEL NORTE","OCUPAR AMERICA DEL SUR, 7 PAISES DE EUROPA Y 3 PAISES LIMITROFES ENTRE SI EN     CUALQUIER LUGAR DEL MAPA","OCUPAR AMERICA DEL SUR, AFRICA Y 4 PAISES DE ASIA","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO","DESTRUIR AL EJERCITO"};

   char misiones[15][150];

   if ((stream = fopen("DUMMY.FIL", "w+"))
       == NULL)
   {
      fprintf(stderr, "Cannot open output file.\n");
      return 1;
   }

   /* write some data to the file */
   for(i=0;i<15;i++){
	fwrite(mis[i], strlen(mis[i])+1, 1, stream);
   }
   /* seek to the beginning of the file */
   fseek(stream, SEEK_SET, 0);

   /* read the data and display it */
   fread(misiones[0], strlen(mis[1])+1, 1, stream);
   printf("%s\n", misiones[0]);

   fclose(stream);
   return 0;
}

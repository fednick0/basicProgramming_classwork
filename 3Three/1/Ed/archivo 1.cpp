#include<stdio.h>
#include<conio.h>

int main(){
	FILE *archivo;
	char c=0;
	archivo=fopen("c:\\prueba.txt","r+");
	if(archivo!=NULL)	{
		while(!feof(archivo)){
			c=fgetc(archivo);
			putchar(c);
		}
	}
	else{
		printf("Error");
	}
	fclose(archivo);
	getch();
}

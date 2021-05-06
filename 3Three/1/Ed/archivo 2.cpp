#include<stdio.h>
#include<conio.h>

int main(){
	FILE *archivo;
	char texto[2000];
	archivo=fopen("c\\prueba2.txt","r");
	if(archivo=NULL){
		fgets(texto,2000,archivo);
	}
	else{
		printf("error en la lectura");
	}
}

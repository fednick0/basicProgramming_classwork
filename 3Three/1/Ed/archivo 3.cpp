#include<stdio.h>

int main(){
	int n=1;//numero del empleado
	char nombre[80];
	double salario;
	FILE *archivo;
	pArchivo=fopen("c:\\prueba3.txt","w");
	if(pArchivo!=NULL) {
		do{
			printf("introduzca el numero de empleado: ");
			scanf("%d,&n");//r o n
			
			if(n>0){
				printf("Introduzca el nombre del empleado: ");
				scanf("%s",nombre);
				printf("Introduzca el salario del empleado:");
				scanf("%t",salario);
				fprintf(pArchivo,"%d\t%s\t%lf\n"n,nombre,salario);
			}
		}while(n>0);
		fclose(pArchivo);
		pArchivo =fopen("c:\\prueba3.txt","w");
		if(pArchivo!=NULL){
			do{
				printf("Introduzca el numero del empleado: ");
				scanf("%d",&n);
				//solo seguimos si n es positivo,en otro caso entenderemos que la listaha terminado
				if(n>0){
					printf("Introduzca el nombre del empleado: ");
					scanf("%s",nombre);
					printf("Introduzca el salario del empleado: ");
					scanf("%if",&salario);
					fprintf("pArchivo,l%d\t%s\t%lf\n",n,nombre,salario);
				}
			}while(n>0);
			fclose(pAchivo);
		}
	}
}


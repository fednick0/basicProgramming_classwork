/*  
    Programa que realiza validaciones a diferentes
    tipos de datos para despues ser utilizadas
    como un bliblioteca.
    
    el menu utiliza las teclas de funcion F1 - F6
    y ademas la tecla esc para su funcionamiento
    
    el menu se encuentra validado
    
    Docente: Miguel Angel Navarro Moreno
    Fecha: 31/01/2017
    Materia: Estructura  de datos I
    Paradigma: Estructurado.
    
    observaciones:  en proceso
    
*/



/************* DECLARACIÓN DE LIBRERIAS **************/
# include <iostream>
# include <windows.h>
# include <conio.h>

using namespace std;

/**************** VARIABLES GLOBALES *****************/


/************ DECLARACIÓN (Prototipos) DE FUNCIONES ***************/
char menu (void);
void gotoxy(int,int);
int Venterop(int,int);  //Validar un entero positivo de 4 Bytes  (limite 4294967295)
double Vreal(int,int); //Validar un flotante positivo o negativo
char *nomArchivo (int,int);



char o;


int main (){   // INICIO DEL MAIN

	//DECLARACIÓN DE VARIABLES
	char opc;
	
	do { //Do principal- contiene la estructura general del programa
	
	
	
		opc= menu();
	
		int ent=0;
		double real=0;
		char *nArchivo;
			
		switch (opc){
			
			case 59: //F1
				
				
			 	system("cls");
			 	gotoxy(20,2);cout<<"Ingrese un valor entero positivo: ";  //mas 34
			 	
			 	ent=Venterop(54,2);//LLAMAR A LA FUNCION VALIDAR
				
				//UNA VEZ LA VALIDACION ES EXITOSA		
			 	gotoxy(20,4);cout<<"ENTERO VALIDADO Y LISTO PARA UTILIZAR";
			 	gotoxy(20,6);cout<<"Presione cualquier tecla para continuar...";
			 	
			 	o=getch();

				break;
				
			case 60://F2
				
				system("cls");
			 	gotoxy(20,2);cout<<"Ingrese un valor real: ";
			 	real=Vreal(43,2);
			 	
			 	//UNA VEZ LA VALIDACION ES EXITOSA		
			 	gotoxy(20,4);cout<<"REAL VALIDADO Y LISTO PARA UTILIZAR";
			 	gotoxy(20,6);cout<<"Presione cualquier tecla para continuar...";
			 	
			 	o=getch();
				
				break;
				
			case 61://F3
				 
				 //PENDIENTE EL RETORNO DEL PUNTERO
				 
				char nombre[12];
				system("cls");
			 	gotoxy(20,2);cout<<"Ingrese un nombre de archivo valido de 8 caracteres como maximo: ";
			 	nArchivo = nomArchivo(85,2);
			 	
			 	
			 	cout<<"Nombre="<<*nArchivo;
			 	
			 	//UNA VEZ LA VALIDACION ES EXITOSA		
			 	gotoxy(20,4);cout<<"NOMBRE VALIDADO Y LISTO PARA UTILIZAR";
			 	gotoxy(20,6);cout<<"Presione cualquier tecla para continuar...";
			 	
			 	o=getch();
				
				break;
				
			case 62://F4
				
				system("cls");
			 	cout<<"Presione cualquier tecla para continuar";
			 	o=getch();
				
				break;
				
			case 63://F5
				
				system("cls");
			 	cout<<"Presione cualquier tecla para continuar";
			 	o=getch();
				
				break;
				
			case 64://F6
				
				system("cls");
			 	cout<<"Presione cualquier tecla para continuar";
			 	o=getch();
				
				break;
				
			case 27://Esc.
				system("cls");
				gotoxy(32,21);cout<<"GRACIAS POR PASAR";
				Sleep(2500);
				
				break;
					
			default:
				
				if (opc !=27){
					Beep(1000,100);
				}
		
		}//Fin del Switch	
			
		
	}while(opc !=27);

	return 0;	

}//FIN DEL MAIN


/*****************     FUNCIONES     ****************/

//FUNCION MENU ++++++++++++++++++++++++++++++++++++++++++++++
char menu(){
	
	char opc1 = '\0'; //Declaracion de variable local para manejo de la opcion
	
	system("cls");
	
	gotoxy(20,3); cout<<"Menu Validaciones";
	gotoxy(20,5); cout<<"[F1] Validar un entero positivo de 4Bytes";
	gotoxy(20,6); cout<<"[F2] Validar un número real con signo";
	gotoxy(20,7); cout<<"[F3] Validar nombre de archivo Valido de 8 caracteres";
	gotoxy(20,8); cout<<"[F4] Validar edad";
	gotoxy(20,9); cout<<"[F5] Validar Codigo postal";
	gotoxy(20,10);cout<<"[F6] Validar email";
	gotoxy(20,11);cout<<"ESC. Salir";
	gotoxy(20,13);cout<<"Seleccione una opcion: ";
	
	//Captura de la opcion
	opc1 = getch();
	
	if (opc1==0){
		
		opc1 = getch();
	}
	
	return opc1;//Retornar la opcion ingresada
	
	
}


//FUNCION PARA VALIDAR ENTEROS POSITIVOS DE TAMAÑO UNSIGNED INT
int Venterop(int x, int y){
	
	
	int valor=-1, ban=0;
	
	do{
		int lon=0;
		char entero[12];
		memset(entero,0,sizeof(entero));
		gotoxy(x,y);
		gets(entero);
		ban=0;
		
		lon=strlen(entero);
		
		//COMPROBAR SI TODOS LOS CARACTERES INGRESDOS SON DIGITOS
		for(int c=0; c<lon; c++){
			
			if(isdigit(entero[c])=='\0'){ //SI ALGUNO DE LOS CARACTERES INGRESADOS NO ES DIGITO
				
				ban=1;//ACTIVA LA BANDERA DE ERROR
				
			}
			
		}
		
		//COMPRUEBA QUE LA CADENA NO ESTE VACIA
		if(lon==0){
			
			ban=1;//ACTIVA LA BANDERA DE ERROR
			
		}
		
		valor=atoi(entero);// convierte la cadena en Entero
		
		//SE COMPRUEBA QUE EL VALO ESTE DENTRO DE LOS RANGOS DE UN VALOR ENTERO O INT SIN SIGNO
		if(valor<0 || valor > 429496729){
			
			ban=1;
			
		}
		
		//cOMPRUEBA LA BANDERA DE ERROR Y ENVIA SONIDO DE ERROR
		if (ban==1){
			
			Beep(1000,100);
			gotoxy(x,y);
			cout<<"                        ";
			
		}
		
	}while(ban!=0);
	
	return valor;
	
}//FIN DE LA FUNCION PARA VALIDAR ENTEROS POSITIVOS


//FUNCION  PARA VALIDAR FLOTANTES CON SIGNO
double Vreal(int x,int y){
	
	double valor=0;
	int ban=0;
	
	do{//Inicio del do principal
	
		char r[60]; memset(r,0,sizeof(r));
		int lon=0, numpuntos=0;
		
		gotoxy(x,y);//Coloca el cursor en posicion de ingresar
		gets(r);  //Captura la cadena r
		ban=0;
		
		lon=strlen(r);  //regresa la longitud de la cadena r
		
		
		/*If para comprobar que en la primera posicion de la cadena
		  no existen numeros extraños o diferentes a (+, -, ., digitos)*/
	
		if(r[0]!='+' && r[0]!='-' && r[0]!='.' && isdigit(r[0])=='\0'){
			
			ban=1;   //la cadena no inicia con un caracter valido (+, -, ., digitos)
			
		}
		
		//Recorrer la cadena r para contar el numero de puntos
		for(int c=0; c<lon; c++){ //Inicio For1
			
			if(r[c]=='.'){
				
				numpuntos ++; //incrementa cada vez que se encuentra un punto
				
			}
			
			if(numpuntos>1){
				
				ban=2;   //Bandera para indicar que hay mas de dos puntos en la cadena
				
			}
			
		}//Fin For1
		
		if(numpuntos==0 || numpuntos==1){//Apertura de if Z
			
			//comprobar la cadena a partir del indice 1
			for (int c=1; c<lon; c++){//Inicio For2
				
				if(isdigit(r[c])=='\0' && r[c]!='.'){
					
					ban=3;
					
				}
				
			}//Fin de For2
			
			int mantista=0;
			
			//contar los digitos despues del punto (mantista)
			for(int c=0; c<lon; c++){//Inicio de For3
				
				if (r[c]=='.'){
					
					c++;
					
					for(int i=c; i<lon; i++){
						
						mantista++;
						
					}
					
				}
				
			}//Fin de For3
			
			if(mantista>15){
				
				ban=4;  //mantista mayor a 15 digitos de presición 
				
			}
			
			
		}//Cierre del if z
		
		valor=atof(r);  //Convertir la cadena a double
		
		//VALIDAR EL RANGO DEL VALOR DOUBLE
		
		switch(ban){
			
			case 1:
				
				
				Beep(1000,100);
				gotoxy(x,y);cout<<"                                              ";
				gotoxy(x,y);cout<<"ERROR";
				Sleep(2000);
				gotoxy(x,y);cout<<"                                              ";
				break;
				
			case 2:
				
				
				Beep(1000,100);
				gotoxy(x,y);cout<<"                                              ";
				gotoxy(x,y);cout<<"ERROR";
				Sleep(2000);
				gotoxy(x,y);cout<<"                                              ";
				break;
				
			case 3:
				
				
				Beep(1000,100);
				gotoxy(x,y);cout<<"                                              ";
				gotoxy(x,y);cout<<"ERROR";
				Sleep(2000);
				gotoxy(x,y);cout<<"                                              ";
				break;
				
			case 4:
				
				
				Beep(1000,100);
				gotoxy(x,y);cout<<"                                              ";
				gotoxy(x,y);cout<<"ERROR";
				Sleep(2000);
				gotoxy(x,y);cout<<"                                              ";
				break;
			
		}
		
		
		
	}while(ban!=0);//Fn del do principal
	
	return valor;
	
}


char *nomArchivo(int x, int y){
	
	char nombre[13]; memset(nombre,0,sizeof(nombre));
	char* pn=NULL;
	
	gotoxy(x,y);
	gets(nombre);
	
	pn=nombre;
	
	return pn;
	
}


//FUNCION GOTOXY ++++++++++++++++++++++++++++++++++++++++++++
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }











 


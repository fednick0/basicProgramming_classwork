/*  
    Programa que muestra la estructura de un menu
    basico, para ser utilizado en una estructura para 
    crear archivos de texto, agregar registros,
    eliminar registros, editar registros etc
    
    el menu utiliza las teclas de funcion F1 - F6
    y ademas la tecla esc para su funcionamiento
    
    el menu se encuentra validado
    
    Docente: Miguel Angel Navarro Moreno
    Fecha: 17/01/2017
    Materia: Estructura  de datos I
    Paradigma: Estructurado.
    
    observaciones:  El programa no esta validado al 100%
    
    
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


int main (){   // INICIO DEL MAIN

	//DECLARACIÓN DE VARIABLES
	char opc;
	
	do { //Do principal- contiene la estructura general del programa
	
	
	
		opc= menu();
	
		switch (opc){
			
			case 59: //F1
				
			 	system("cls");
			 	cout<<"Bienvenidos a la seccion para crear o abrir un archivo";
			 	Sleep(3000);
				
				break;
				
			case 60://F2
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para agregar registros al archivo";
			 	Sleep(3000);
				
				break;
				
			case 61://F3
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para mostrar los registros";
			 	Sleep(3000);
				
				break;
				
			case 62://F4
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para buscar registros";
			 	Sleep(3000);
				
				break;
				
			case 63://F5
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para editar registros";
			 	Sleep(3000);
				
				break;
				
			case 64://F6
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para eliminar registros ";
			 	Sleep(3000);
				
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
	
	gotoxy(28,3); cout<<"Menu Agenda";
	gotoxy(28,5); cout<<"[F1] Crear o abrir archivo";
	gotoxy(28,6); cout<<"[F2] Agregar Registro";
	gotoxy(28,7); cout<<"[F3] Mostrar Registros";
	gotoxy(28,8); cout<<"[F4] Buscar Registro";
	gotoxy(28,9); cout<<"[F5] Modificar Registro";
	gotoxy(28,10);cout<<"[F6] Eliminar Registro";
	gotoxy(28,11);cout<<"ESC. Salir";
	gotoxy(28,13);cout<<"Seleccione una opcion: ";
	
	//Captura de la opcion
	opc1 = getch();
	
	if (opc1==0){
		
		opc1 = getch();
	}
	
	return opc1;//Retornar la opcion ingresada
	
	
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











 


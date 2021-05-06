import java.io.*;

public class MAYOR_3 { //Inicia class
	public static void main(String[] args)throws IOException{ //Inicia main
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		//Programa que solicita al usuario tres enteros e imprime el mayor de esos tres numeros
		
		int n1, n2, n3;
		
		System.out.print("Ingrese primer valor entero: ");
		n1 = Integer.parseInt(leer.readLine());
		System.out.print("Ingrese segundo valor entero: ");
		n2 = Integer.parseInt(leer.readLine());
		System.out.print("Ingrese tercer valor entero: ");
		n3 = Integer.parseInt(leer.readLine());
		System.out.print("\n\n");
				
		if (n1 > n2 && n1 > n3)
			System.out.print("El mayor es: " + n1);
		else if (n2 > n1 && n2 > n3)
			System.out.print("El mayor es: " + n2);
		else if (n3 > n1 && n3 > n2)
			System.out.print("El mayor es: " + n3);
		else
			System.out.print("Error");
		
	} //Cierra main
} //Cierra class

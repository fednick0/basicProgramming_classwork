import java.io.*;

public class MAYOR_9 {
	public static void main(String[] args) throws IOException{
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		int[] numeros = new int[9];
		int mayor = 0;
		boolean igual = false;
		
		System.out.print("Ingrese los nueve enteros consecutivamente:\n");
		
		for (int x = 0; x < 9; x++){
			numeros[x] = Integer.parseInt(leer.readLine());
			
			if(x > 0 && numeros[x] > numeros[mayor]) {
				mayor = x;
				igual = false;
			}
			else if (x > 0 && numeros[x] == numeros[mayor])
				igual = true;
		}
		
		if(igual)
			System.out.print("\n\nNo existe número mayor");
		else
			System.out.print("\n\nEl mayor es: " + numeros[mayor]);
		
	}
}
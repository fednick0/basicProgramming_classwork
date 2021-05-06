import java.io.*;

public class OPERACION_USER {
	public static void main(String[] args)throws IOException{
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		float n1, n2, n3, n4, result;
		
		System.out.print("Ingrese primer valor: ");
		n1 = Float.parseFloat(leer.readLine());
		System.out.print("Ingrese segundo valor: ");
		n2 = Float.parseFloat(leer.readLine());
		System.out.print("Ingrese tercer valor: ");
		n3 = Float.parseFloat(leer.readLine());
		System.out.print("Ingrese cuerto valor: ");
		n4 = Float.parseFloat(leer.readLine());
		
		result = n1 + n2 + n3 + n4;
		System.out.print("\n\nSuma: " + result);
		result = n1 - n2 - n3 - n4;
		System.out.print("\nResta: " + result);
		result = n1 * n2 * n3 * n4;
		System.out.print("\nMultiplicacion: " + result);
		
		if(n2 != 0 && n3 != 0 && n4 != 0){
			result = n1 / n2 / n3 / n4;
			System.out.print("\nDivicion: " + result);
			result = n1 % n2 % n3 % n4;
			System.out.print("\nResiduo: " + result);
		}
		else
			System.out.print("\nError al realizar divicion y residuo, resultados infinitos");
	}
}

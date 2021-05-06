import java.io.*;

public class SUMA_USER {
	public static void main(String[] args)throws IOException{
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		int n1, n2, r;
		
		System.out.print("Ingrese primer valor entero: ");
		n1 = Integer.parseInt(leer.readLine());
		System.out.print("Ingrese Segundo valor entero: ");
		n2 = Integer.parseInt(leer.readLine());
		
		r = n1 + n2;
		
		System.out.print("\n\nResultado de la suma es: " + r);
	}
}
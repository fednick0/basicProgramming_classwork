import java.io.*;

public class PRUEBA_PSVM {
	public static void main(String[] args)throws IOException {
	
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		int numb, pot;
		
		System.out.print("Numero: "); numb = Integer.parseInt(leer.readLine()); 
		System.out.print("Potencia: "); pot = Integer.parseInt(leer.readLine());
		
		System.out.println("\n\nResultado: " + Math.pow(numb, pot));
		
	}
}

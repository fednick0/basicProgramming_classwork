import java.io.*;

public class VOCALES {
	public static void main(String[] args) throws IOException {
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
			
		String frase, reiniciar;
		int a, e, i, o, u;

		do{
			
			a = 0;
			e = 0;
			i = 0;
			o = 0;
			u = 0;
			
			System.out.print("Ingrese frase a evaluar cuantas vocales tiene\n--->");
			frase = leer.readLine();
			
			for(int x = 0; x < frase.length(); x++){
				switch(frase.charAt(x)){
				case 'a':
				case 'A':
					a++;
					break;
					
				case 'e':
				case 'E':
					e++;
					break;
					
				case 'i':
				case 'I':
					i++;
					break;
					
				case 'o':
				case 'O':
					o++;
					break;
					
				case 'u':
				case 'U':
					u++;
					break;
				} //switch
			} //for
			
			System.out.print("\n\nSe han utilizado:\n"
					+ a + " - a\n"
					+ e + " - e\n"
					+ i + " - i\n"
					+ o + " - o\n"
					+ u + " - u\n");
			
			System.out.print("\nDesea reiniciar? s/n\n--->");
			reiniciar = leer.readLine();
			
		} while(reiniciar.equals("s") || reiniciar.equals("S"));
		
	} //main
} //class

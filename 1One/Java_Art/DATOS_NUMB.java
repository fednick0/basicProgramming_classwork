import java.io.*;

public class DATOS_NUMB {
	public static void main(String[] args) throws IOException{
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		double numb = 0;
		char sn;
		boolean primo;
		String irra, p1, eul;
		
		do{
			
			primo = true;
			p1 = "";
			eul = "";
			
			System.out.print("Ingrese el numero que desee evaluar: ");
			irra = leer.readLine();
			numb = Double.parseDouble(irra);
			
			for(int x = 0; x < irra.length(); x++){
				p1 += String.valueOf(Math.PI).substring(x, x + 1);
				eul += String.valueOf(Math.E).substring(x, x + 1);
			}
			
			//System.out.print("\nPI: " + String.valueOf(Math.PI) + "\nEuler: " + String.valueOf(Math.E));
			
			/* - double 2.23e-308 <= |X| <= 1.79e308
			 * - float 1.18e-38 <= |X| <= 3.40e38 
			 * - int -2,147,483,648 <= X <= 2,147,483,647
			 * http://www.zator.com/Cpp/E2_2_4.htm
			 * 
			 * - Natural, entero positivo
			 * - Entero, mas menos incluyendo cero
			 * - Racional, decimal mas menos diferente cero
			 * - Irracional, infinitas cifras decimales no periodicas pi, euler, aureo
			 * - Real, todos los numeros incluyendo cero
			 * - Imaginario sqrt(-1)
			 * - Complejo, real + imaginario
			 * http://www.ditutor.com/numeros_naturales/clasificacion_numeros.html
			 */
			
			System.out.print("\nCaracteristicas:\n - Real");
			if(numb > 0 && numb % 1 == 0)
				System.out.print("\n - Natural");
			if(numb % 1 == 0){
				System.out.print("\n - Entero");
			
				if(numb > 1){
					for(double ms = 2; ms < numb; ms++)
						if(numb%ms == 0) {
							primo = false;
							break;
						}
				}
				else if(numb < -1){
					for(double mn = -2; mn > numb; mn--)
						if(numb%mn == 0) {
							primo = false;
							break;
						}
				}
				else
					primo = false;
			}
			else if(!irra.equals(p1) && !irra.equals(eul)){
				System.out.print("\n - Racional");
				primo = false;
			}
			else{
				System.out.print("\n - Irracional");
				primo = false;
			}
			if(primo)
				System.out.print("\n - Primo");			
			
			System.out.print("\n\nRepetir? S/N\n--->");
			sn = leer.readLine().charAt(0);
			System.out.println("\n");
		}
		while(sn == 's' || sn == 'S');
		
	} //Cierra main 
} //Cierra class

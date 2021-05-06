import java.io.*;

/*
 *		https://sites.google.com/site/ea7ahg/_/rsrc/1331322713891/codigos/codigo-morse-cw/morse.gif
 */

public class MORSE { //Inicia class
	public static void main(String[] args)throws IOException { //Inicia main
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		char sn = 'n';
		
		do { //Inicia do while
			
			String frac;
			Boolean error = false;
			
			System.out.print("Ingrese la palabra/frase que descea convertir a codigo morse unica y"
					+ "\nexclusivamente con LETRAS MAYUSCULAS y NUMEROS, no con caracteres \"especiales\"\n--->");
			frac = leer.readLine();
			System.out.print("\n\nCodigo Morse:\n");
	
			for(int x = 0; x < frac.length(); x++) { //Inicia for
				
				if (error)
					break;
				
				//letra = frac.substring(x, x+1);
				//System.out.print("\n" + letra);
				
				switch(frac.substring(x, x+1)){ //Inicia switch
				case "A":
					System.out.print(" ·- ");
					break;
				case "B":
					System.out.print(" -··· ");
					break;
				case "C":
					System.out.print(" -·-· ");
					break;
				case "D":
					System.out.print(" -·· ");
					break;
				case "E":
					System.out.print(" · ");
					break;
				case "F":
					System.out.print(" ··-· ");
					break;
				case "G":
					System.out.print(" --· ");
					break;
				case "H":
					System.out.print(" ···· ");
					break;
				case "I":
					System.out.print(" ·· ");
					break;
				case "J":
					System.out.print(" ·--- ");
					break;
				case "K":
					System.out.print(" -·- ");
					break;
				case "L":
					System.out.print(" ·-·· ");
					break;
				case "M":
					System.out.print(" -- ");
					break;
				case "N":
					System.out.print(" -· ");
					break;
				case "O":
					System.out.print(" --- ");
					break;
				case "P":
					System.out.print(" ·--· ");
					break;
				case "Q":
					System.out.print(" --·- ");
					break;
				case "R":
					System.out.print(" ·-· ");
					break;
				case "S":
					System.out.print(" ··· ");
					break;
				case "T":
					System.out.print(" - ");
					break;
				case "U":
					System.out.print(" ··- ");
					break;
				case "V":
					System.out.print(" ···- ");
					break;
				case "W":
					System.out.print(" ·-- ");
					break;
				case "X":
					System.out.print(" -··- ");
					break;
				case "Y":
					System.out.print(" -·-- ");
					break;
				case "Z":
					System.out.print(" --·· ");
					break;
				case "0":
					System.out.print(" ----- ");
					break;
				case "1":
					System.out.print(" ·---- ");
					break;
				case "2":
					System.out.print(" ··--- ");
					break;
				case "3":
					System.out.print(" ···-- ");
					break;
				case "4":
					System.out.print(" ····- ");
					break;
				case "5":
					System.out.print(" ····· ");
					break;
				case "6":
					System.out.print(" -···· ");
					break;
				case "7":
					System.out.print(" --··· ");
					break;
				case "8":
					System.out.print(" ---·· ");
					break;
				case "9":
					System.out.print(" ----· ");
					break;
				case ",":
					System.out.print(" --··-- ");
					break;
				case ":":
					System.out.print(" ---··· ");
					break;
				case "?":
					System.out.print(" ··--·· ");
					break;
				case "'":
					System.out.print(" ·----· ");
					break;
				case "-":
					System.out.print(" -····- ");
					break;
				case "(":
					System.out.print(" -·--·- ");
					break;
				case ")":
					System.out.print(" -·--·- ");
					break;	
			/*  case """:
					System.out.print(" ·-··-· ");
					break; */
				case " ":
					System.out.print(" / "); // System.out.print(" ·-·-·- ");
					break;
				default:
					error = true;
				} //Cierra switch
			} //Cierra for
			
			if (error)
				System.out.print("¿?¿?¿? Se ha encontrado un error en la palabra/frace introducida");
			
			System.out.print("\n\nDesea reiniciar el programa? S/N: ");
			sn = leer.readLine().charAt(0);
			System.out.println("\n\n\n\n\n\n\n\n\n\n"); //No puedo limpiar la consola System("cls"); en C++
			
		}while(sn == 's' || sn == 'S'); //Cierra do while
		
	} //Cierra main
} //Cierra class
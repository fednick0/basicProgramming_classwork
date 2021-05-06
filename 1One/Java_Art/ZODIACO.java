import java.io.*;

public class ZODIACO {
	public static void main(String[] args) throws IOException{
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		int dia, mes;
		
		System.out.print("Ingrese su dia y mes de nacimiento con enteros");
		System.out.print("\nDia: ");
		dia = Integer.parseInt(leer.readLine());
		System.out.print("Mes: ");
		mes = Integer.parseInt(leer.readLine());
		System.out.print("\n\n");
		
		switch (mes){
		
			case 1:
				if(dia >= 1 && dia <= 19)
					System.out.print("Capricornio");
				else if(dia >=20 && dia <= 31)
					System.out.print("Acuario");
				else
					System.out.print("Dia no existe");
				break;
				
			case 2:
				if(dia >= 1 && dia <= 18)
					System.out.print("Acuario");
				else if(dia >=19 && dia <= 29)
					System.out.print("Piscis");
				else
					System.out.print("Dia no existe");
				break;
				
			case 3:
				if(dia >= 1 && dia <= 20)
					System.out.print("Piscis");
				else if(dia >=21 && dia <= 31)
					System.out.print("Aries");
				else
					System.out.print("Dia no existe");
				break;
				
			case 4:
				if(dia >= 1 && dia <= 19)
					System.out.print("Aries");
				else if(dia >= 20 && dia <= 30)
					System.out.print("Tauro");
				else
					System.out.print("Dia no existe");
				break;
				
			case 5:
				if(dia >= 1 && dia <= 20)
					System.out.print("Tauro");
				else if(dia >= 21 && dia <= 31)
					System.out.print("Geminis");
				else
					System.out.print("Dia no existe");
				break;
				
			case 6:
				if(dia >= 1 && dia <= 20)
					System.out.print("Geminis");
				else if(dia >= 21 && dia <= 30)
					System.out.print("Cancer");
				else
					System.out.print("Dia no existe");
				break;
				
			case 7:
				if(dia >= 1 && dia <= 22)
					System.out.print("Cancer");
				else if(dia >= 23 && dia <= 31)
					System.out.print("Leo");
				else
					System.out.print("Dia no existe");
				break;
				
			case 8:
				if(dia >= 1 && dia <= 22)
					System.out.print("Leo");
				else if(dia >= 23 && dia <= 31)
					System.out.print("Virgo");
				else
					System.out.print("Dia no existe");
				break;
				
			case 9:
				if(dia >= 1 && dia <= 22)
					System.out.print("Virgo");
				else if(dia >= 23 && dia <= 30)
					System.out.print("Libra");
				else
					System.out.print("Dia no existe");
				break;
				
			case 10:
				if(dia >= 1 && dia <= 22)
					System.out.print("Libra");
				else if(dia >= 23 && dia <= 31)
					System.out.print("Escorpio");
				else
					System.out.print("Dia no existe");
				break;
				
			case 11:
				if(dia >= 1 && dia <= 21)
					System.out.print("Escorpio");
				else if(dia >= 22 && dia <= 30)
					System.out.print("Sagitario");
				else
					System.out.print("Dia no existe");
				break;
				
			case 12:
				if(dia >= 1 && dia <= 21)
					System.out.print("Sagitario");
				else if(dia >= 22 && dia <= 31)
					System.out.print("Capricornio");
				else
					System.out.print("Dia no existe");
				break;
				
			default:
				System.out.print("Mes no existe");
		}
		
	}
}

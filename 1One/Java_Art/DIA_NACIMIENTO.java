import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class DIA_NACIMIENTO {
	public static void main(String[] args)throws IOException{
		
		Calendar calendario = GregorianCalendar.getInstance();
		SimpleDateFormat forma = new SimpleDateFormat("EEEEE");
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		int dia, mes, agno;
		
		System.out.print("Ingrese lo que se le pida con enteros");
		System.out.print("\nDia: "); dia = Integer.parseInt(leer.readLine());
		System.out.print("Mes: "); mes = Integer.parseInt(leer.readLine());
		System.out.print("Año: "); agno = Integer.parseInt(leer.readLine());
		
		if (mes == 1 && dia > 0 && dia <= 31 ||
			agno % 4 == 0 && mes == 2 && dia > 0 && dia <= 29 ||
			mes == 2 && dia > 0 && dia <= 28 ||
			mes == 3 && dia > 0 && dia <= 31 ||
			mes == 4 && dia > 0 && dia <= 30 ||
			mes == 5 && dia > 0 && dia <= 31 ||
			mes == 6 && dia > 0 && dia <= 30 ||
			mes == 7 && dia > 0 && dia <= 31 ||
			mes == 8 && dia > 0 && dia <= 31 ||
			mes == 9 && dia > 0 && dia <= 30 ||
			mes == 10 && dia > 0 && dia <= 31 ||
			mes == 11 && dia > 0 && dia <= 30 ||
			mes == 12 && dia > 0 && dia <= 31) {
		
			calendario.set(Calendar.DAY_OF_MONTH, dia);
			calendario.set(Calendar.MONTH, mes-1);
			calendario.set(Calendar.YEAR, agno);
			
			//System.out.print(calendario.get(Calendar.DAY_OF_WEEK);
			System.out.println("\nEl dia de la semana en que nacio fue: " + forma.format(calendario.getTime()));
		}
		else
			System.out.println("\nEl dia introducido no existe");
				
	}
}

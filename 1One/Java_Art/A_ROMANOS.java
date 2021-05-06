import java.io.*;

public class A_ROMANOS {
	
	public static String arabig, romano;
	public static boolean error, puede;
	
	
	
	public static void uno(){		
		if(arabig.endsWith("9")){
			romano = "IX";
			arabig = arabig.substring(0, arabig.length() - 1);
		}	
		else if(arabig.endsWith("8")){
			romano = "VIII";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("7")){
			romano = "VII";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("6")){
			romano = "VI";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("5")){
			romano = "V";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("4")){
			romano = "IV";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("3")){
			romano = "III";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("2")){
			romano = "II";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("1")){
			romano = "I";
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("0"))
			arabig = arabig.substring(0, arabig.length() - 1);
		else
			error = true;
	} //uno()
	
	
	
	public static void diez(){
		if(arabig.endsWith("9")){
			romano = "XC" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}	
		else if(arabig.endsWith("8")){
			romano = "LXXX" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("7")){
			romano = "LXX" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("6")){
			romano = "LX" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("5")){
			romano = "L" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("4")){
			romano = "XL" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("3")){
			romano = "XXX" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("2")){
			romano = "XX" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("1")){
			romano = "X" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("0"))
			arabig = arabig.substring(0, arabig.length() - 1);
		else
			error = true;
	} //diez()
	
	
	
	public static void cien(){
		if(arabig.endsWith("9")){
			romano = "CM" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}	
		else if(arabig.endsWith("8")){
			romano = "DCCC" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("7")){
			romano = "DCC" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("6")){
			romano = "DC" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("5")){
			romano = "D" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("4")){
			romano = "CD" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("3")){
			romano = "CCC" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("2")){
			romano = "CC" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("1")){
			romano = "C" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("0"))
			arabig = arabig.substring(0, arabig.length() - 1);
		else
			error = true;
	} //cien()
	
	
	
	public static void mil(){
		if(arabig.endsWith("3")){
			romano = "MMM" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("2")){
			romano = "MM" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else if(arabig.endsWith("1")){
			romano = "M" + romano;
			arabig = arabig.substring(0, arabig.length() - 1);
		}
		else
			error = true;
	} //mil()
	
	
	
	public static void main(String[] args) throws IOException{
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		String repit;
		
		do{
			romano = "";
			error = false;
			puede = false;
			
			System.out.print("\nIngrese numero a convertir: ");
			arabig = leer.readLine().trim();
			if(arabig.length() == 0)
				error = true;
			
			for(int x = 4; x >= 0; x--){
				if(error || arabig.length() == 0)
					break;
				
				switch(x){
				case 1:
					A_ROMANOS.mil();
					break;
					
				case 2:
					A_ROMANOS.cien();
					break;
					
				case 3:
					A_ROMANOS.diez();
					break;
					
				case 4:
					A_ROMANOS.uno();
					break;
					
				default:
					error = true;
				} //switch
			} //for		
			
			if(error)
				System.out.print("\n\nError encontrado D:");
			else					
				System.out.print("\n\nNumero romano: " + romano);
			
			System.out.print("\nDesea reiniciar? s/n\n--->");
			repit = leer.readLine().trim();
		} while(repit.equals("s") || repit.equals("S"));
		
	} //main
} //class
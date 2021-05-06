import java.io.*;

public class A_ARABIGOS {	
	
	public static boolean error, puede;
	public static String romano, arabig;
	
	
	
	public static void mil(){
		if(puede)
			arabig = "0" + arabig;
		
		if(romano.endsWith("MMM")){
			arabig = "3" + arabig;
			romano = romano.substring(0, romano.length() - 3);
		}
		else if(romano.endsWith("MM")){
			arabig = "2" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("M")){
			arabig = "1" + arabig;
			romano = romano.substring(0, romano.length() - 1);
		}
		else
			error = true;
	} //mil()
	
	
	
	public static void cien(){		
		if(puede)
			arabig = "0" + arabig;
		puede = false;
		
		if(romano.endsWith("CM")){
			arabig = "9" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}	
		else if(romano.endsWith("DCCC")){
			arabig = "8" + arabig;
			romano = romano.substring(0, romano.length() - 4);
		}
		else if(romano.endsWith("DCC")){
			arabig = "7" + arabig;
			romano = romano.substring(0, romano.length() - 3);
		}
		else if(romano.endsWith("DC")){
			arabig = "6" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("CD")){
			arabig = "4" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("D")){
			arabig = "5" + arabig;
			romano = romano.substring(0, romano.length() - 1);
		}
		else if(romano.endsWith("CCC")){
			arabig = "3" + arabig;
			romano = romano.substring(0, romano.length() - 3);
		}
		else if(romano.endsWith("CC")){
			arabig = "2" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("C")){
			arabig = "1" + arabig;
			romano = romano.substring(0, romano.length() - 1);
		}
		else if(romano.contains("M"))
			puede = true;
		else
			error = true;
	} //cien()
	
	
	
	public static void diez(){
		if(puede)
			arabig = "0";
		puede = false;
		
		if(romano.endsWith("XC")){
			arabig = "9" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}	
		else if(romano.endsWith("LXXX")){
			arabig = "8" + arabig;
			romano = romano.substring(0, romano.length() - 4);
		}
		else if(romano.endsWith("LXX")){
			arabig = "7" + arabig;
			romano = romano.substring(0, romano.length() - 3);
		}
		else if(romano.endsWith("LX")){
			arabig = "6" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("XL")){
			arabig = "4" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("L")){
			arabig = "5" + arabig;
			romano = romano.substring(0, romano.length() - 1);
		}
		else if(romano.endsWith("XXX")){
			arabig = "3" + arabig;
			romano = romano.substring(0, romano.length() - 3);
		}
		else if(romano.endsWith("XX")){
			arabig = "2" + arabig;
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("X")){
			arabig = "1" + arabig;
			romano = romano.substring(0, romano.length() - 1);
		}
		else if(romano.contains("C") || romano.contains("M") || romano.contains("D"))
			puede = true;
		else 
			error = true;
	} //diez()
	
	
	
	public static void uno(){		
		if(romano.endsWith("IX")){
			arabig = "9";
			romano = romano.substring(0, romano.length() - 2);
		}	
		else if(romano.endsWith("VIII")){
			arabig = "8";
			romano = romano.substring(0, romano.length() - 4);
		}
		else if(romano.endsWith("VII")){
			arabig = "7";
			romano = romano.substring(0, romano.length() - 3);
		}
		else if(romano.endsWith("VI")){
			arabig = "6";
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("IV")){
			arabig = "4";
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("V")){
			arabig = "5";
			romano = romano.substring(0, romano.length() - 1);
		}
		else if(romano.endsWith("III")){
			arabig = "3";
			romano = romano.substring(0, romano.length() - 3);
		}
		else if(romano.endsWith("II")){
			arabig = "2";
			romano = romano.substring(0, romano.length() - 2);
		}
		else if(romano.endsWith("I")){
			arabig = "1";
			romano = romano.substring(0, romano.length() - 1);
		}
		else if(romano.contains("X") || romano.contains("L") || romano.contains("C") ||
				romano.contains("M") || romano.contains("D"))
			puede = true;
		else
			error = true;
	} //uno()
	

	
	public static void main(String[] args) throws IOException{
		
		BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
		
		String reinicio;
		
		do{
			arabig = "";
			error = false;
			puede = false;
			
			System.out.print("\nIngrese numero romano: ");
			romano = leer.readLine().trim().toUpperCase();
			if(romano.length() == 0)
				error = true;
			
			for(int x = 4; x >= 0; x--){
				if(error || romano.length() == 0)
					break;	
				
				switch(x){				
				case 1:
					A_ARABIGOS.mil();
					break;
					
				case 2:
					A_ARABIGOS.cien();
					break;
					
				case 3:
					A_ARABIGOS.diez();
					break;
					
				case 4:
					A_ARABIGOS.uno();
					break;
				
				default:
					error = true;
				} //switch
			} //for
			
			if(error)
				System.out.print("\n\nError encontrado D:");
			else					
				System.out.print("\n\nNumero arabigo: " + arabig);
			
			System.out.print("\nDesea reiniciar? s/n\n--->");
			reinicio = leer.readLine().trim();
		} while(reinicio.equals("s") || reinicio.equals("S"));
		
	} //main
} //class
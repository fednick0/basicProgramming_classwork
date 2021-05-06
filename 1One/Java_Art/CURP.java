import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class CURP extends JFrame{
	
	private JLabel lapeido_p, lapeido_m, lnombres, fecha, subnombres, lagno, lmes, ldia, lsexo, lestado;
	private JTextField apeido_p, apeido_m, nombres, curp;
	private JComboBox mes, estado;
	private JSpinner agno, dia;
	private JButton generar, limpiar;
	private JRadioButton hombre, mujer;
	private ButtonGroup grupo_radio;
	private int dia_limite = 31;
	private boolean bisiesto = true;
	private String parte_mes = "01", parte_sexo = "H", parte_estado = "AS", curp_final;
	
	public CURP(){
		this.setResizable(false);
		this.setTitle("CURP");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(335, 420);
		this.setLayout(null);
		//this.setContentPane(new JLabel(new ImageIcon(Toolkit.getDefaultToolkit().getImage("def.png"))));
		this.setLocation(150, 150);
		//this.pack();
		
		contenido();
		this.setVisible(true);
	}
	
	public void contenido(){
		JLabel subnombres = new JLabel("Nombre");
		subnombres.setBounds(5, 5, 130, 20);
		subnombres.setFont(new Font("Arial", 1, 16));
		this.add(subnombres);
		
		JLabel lapeido_p = new JLabel("Apeido paterno:");
		lapeido_p.setBounds(15, 25, 130, 20);
		lapeido_p.setFont(new Font("Arial", 0, 16));
		this.add(lapeido_p);
		
		JTextField apeido_p = new JTextField();
		apeido_p.setBounds(150, 25, 175, 25);
		this.add(apeido_p);
		
		JLabel lapeido_m = new JLabel("Apeido materno:");
		lapeido_m.setBounds(15, 60, 130, 20);
		lapeido_m.setFont(new Font("Arial", 0, 16));
		this.add(lapeido_m);
		
		JTextField apeido_m = new JTextField();
		apeido_m.setBounds(150, 60, 175, 25);
		this.add(apeido_m);
		
		JLabel lnombre = new JLabel("Nombre(s):");
		lnombre.setBounds(15, 95, 130, 20);
		lnombre.setFont(new Font("Arial", 0, 16));
		this.add(lnombre);
		
		JTextField nombre = new JTextField();
		nombre.setBounds(150, 95, 175, 25);
		this.add(nombre);
		
		JLabel fecha = new JLabel("Fecha de nacimiento");
		fecha.setBounds(5, 135, 160, 25);
		fecha.setFont(new Font("Arial", 1, 16));
		this.add(fecha);
		
		JLabel lagno = new JLabel("Año");
		lagno.setBounds(15, 160, 60, 20);
		lagno.setFont(new Font("Arial", 0, 16));
		this.add(lagno);
		
		JSpinner agno = new JSpinner();
		agno.setValue(2016);
		agno.setFont(new Font("Arial", 0, 16));
		agno.setBounds(15, 180, 60, 25);
		this.add(agno);
		
		JLabel lmes = new JLabel("Mes");
		lmes.setBounds(100, 160, 60, 20);
		lmes.setFont(new Font("Arial", 0, 16));
		this.add(lmes);
		
		JComboBox mes = new JComboBox();
		mes.setFont(new Font("Arial", 0, 16));
		mes.setBounds(100, 180, 110, 25);
		mes.addItem("Enero");
		mes.addItem("Febrero");
		mes.addItem("Marzo");
		mes.addItem("Abril");
		mes.addItem("Mayo");
		mes.addItem("Junio");
		mes.addItem("Julio");
		mes.addItem("Agosto");
		mes.addItem("Septiembre");
		mes.addItem("Octubre");
		mes.addItem("Noviembre");
		mes.addItem("Diciembre");
		this.add(mes);
		
		JLabel ldia = new JLabel("Dia");
		ldia.setBounds(230, 160, 60, 20);
		ldia.setFont(new Font("Arial", 0, 16));
		this.add(ldia);
		
		JSpinner dia = new JSpinner();
		dia.setValue(1);
		dia.setFont(new Font("Arial", 0, 16));
		dia.setBounds(230, 180, 60, 25);
		this.add(dia);
		
		JLabel lsexo = new JLabel("Sexo");
		lsexo.setBounds(5, 210, 60, 20);
		lsexo.setFont(new Font("Arial", 1, 16));
		this.add(lsexo);

		JRadioButton hombre = new JRadioButton("Hombre");
		hombre.setBounds(15, 230, 90, 20);
		hombre.setFont(new Font("Arial", 0, 16));
		hombre.setSelected(true);
		this.add(hombre);
		
		JRadioButton mujer = new JRadioButton("Mujer");
		mujer.setBounds(15, 250, 90, 20);
		mujer.setFont(new Font("Arial", 0, 16));
		mujer.setSelected(false);
		this.add(mujer);
		
		ButtonGroup radio_grupo = new ButtonGroup();
		radio_grupo.add(mujer);
		radio_grupo.add(hombre);
		
		JLabel lestado = new JLabel("Estado");
		lestado.setBounds(120, 210, 60, 20);
		lestado.setFont(new Font("Arial", 1, 16));
		this.add(lestado);
		
		JComboBox estado = new JComboBox();
		estado.setFont(new Font("Arial", 0, 16));
		estado.setBounds(120, 235, 170, 25);
		estado.addItem("Aguascalientes");
		estado.addItem("Baja California");
		estado.addItem("Baja California Sur");
		estado.addItem("Campeche");
		estado.addItem("Chiapas");
		estado.addItem("Chihuahua");
		estado.addItem("Coahuila");
		estado.addItem("Colima");
		estado.addItem("Distrito Federal");
		estado.addItem("Durango");
		estado.addItem("Estado de Mexico");
		estado.addItem("Guanajuato");
		estado.addItem("Guerrero");
		estado.addItem("Hidalgo");
		estado.addItem("Jalisco");
		estado.addItem("Michoacan");
		estado.addItem("Morelos");
		estado.addItem("Nayarit");
		estado.addItem("Nuevo Leon");
		estado.addItem("Oaxaca");
		estado.addItem("Puebla");
		estado.addItem("Queretaro");
		estado.addItem("Quintana Roo");
		estado.addItem("San Luis Potosi");
		estado.addItem("Sinaloa");
		estado.addItem("Sonora");
		estado.addItem("Tabasco");
		estado.addItem("Tamaulipas");
		estado.addItem("Tlaxcala");
		estado.addItem("Veracruz");
		estado.addItem("Yucatan");
		estado.addItem("Zacatecas");
		this.add(estado);
		
		JButton generar = new JButton("Generar CURP");
		generar.setFont(new Font("Arial", 1, 18));
		generar.setBounds(5, 280, 265, 50);
		this.add(generar);
		
		JButton limpiar = new JButton("C");
		limpiar.setFont(new Font("Arial", 1, 18));
		limpiar.setBounds(275, 280, 50, 50);
		this.add(limpiar);
		
		JTextField curp = new JTextField("");
		curp.setEditable(false);
		curp.setBounds(5, 335, 320, 50);
		this.add(curp);
		
		apeido_p.addFocusListener(new FocusListener() {
			public void focusGained(FocusEvent e) {
			}
			public void focusLost(FocusEvent e) {
				apeido_p.setText(apeido_p.getText().trim().toUpperCase());
		    }
		});
		
		apeido_m.addFocusListener(new FocusListener() {
			public void focusGained(FocusEvent e) {
			}
			public void focusLost(FocusEvent e) {
				apeido_m.setText(apeido_m.getText().trim().toUpperCase());
		    }
		});
		
		nombre.addFocusListener(new FocusListener() {
			public void focusGained(FocusEvent e) {
			}
			public void focusLost(FocusEvent e) {
				nombre.setText(nombre.getText().trim().toUpperCase());
		    }
		});
		
		agno.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent arg0) { 
				if((Integer)agno.getValue() % 4 == 0)
					bisiesto = true;
				else
					bisiesto = false;
		    	dia.setValue(1);
		    	switch(mes.getSelectedItem().toString()){
		    	case "Enero":
		    		parte_mes = "01";
		    		dia_limite = 31;
		    		break;
		    	case "Marzo":
		    		parte_mes = "03";
		    		dia_limite = 31;
		    		break;
		    	case "Mayo":
		    		parte_mes = "05";
		    		dia_limite = 31;
		    		break;
		    	case "Julio":
		    		parte_mes = "07";
		    		dia_limite = 31;
		    		break;
		    	case "Agosto":
		    		parte_mes = "08";
		    		dia_limite = 31;
		    		break;
		    	case "Octubre":
		    		parte_mes = "10";
		    		dia_limite = 31;
		    		break;
		    	case "Diciembre":
		    		parte_mes = "12";
		    		dia_limite = 31;
		    		break;
		    	case "Abril":
		    		parte_mes = "04";
		    		dia_limite = 30;
		    		break;
		    	case "Junio":
		    		parte_mes = "06";
		    		dia_limite = 30;
		    		break;
		    	case "Septiembre":
		    		parte_mes = "09";
		    		dia_limite = 30;
		    		break;
		    	case "Noviembre":
		    		parte_mes = "11";
		    		dia_limite = 30;
		    		break;
		    	case "Febrero":
		    		parte_mes = "02";
		    		if(bisiesto)
		    			dia_limite = 29;
		    		else
		    			dia_limite = 28;
		    		break;
		    	}
			}
		});
		
		mes.addActionListener (new ActionListener () {
		    public void actionPerformed(ActionEvent e) {
		    	if((Integer)agno.getValue() % 4 == 0)
					bisiesto = true;
				else
					bisiesto = false;
		    	dia.setValue(1);
		    	switch(mes.getSelectedItem().toString()){
		    	case "Enero":
		    		parte_mes = "01";
		    		dia_limite = 31;
		    		break;
		    	case "Marzo":
		    		parte_mes = "03";
		    		dia_limite = 31;
		    		break;
		    	case "Mayo":
		    		parte_mes = "05";
		    		dia_limite = 31;
		    		break;
		    	case "Julio":
		    		parte_mes = "07";
		    		dia_limite = 31;
		    		break;
		    	case "Agosto":
		    		parte_mes = "08";
		    		dia_limite = 31;
		    		break;
		    	case "Octubre":
		    		parte_mes = "10";
		    		dia_limite = 31;
		    		break;
		    	case "Diciembre":
		    		parte_mes = "12";
		    		dia_limite = 31;
		    		break;
		    	case "Abril":
		    		parte_mes = "04";
		    		dia_limite = 30;
		    		break;
		    	case "Junio":
		    		parte_mes = "06";
		    		dia_limite = 30;
		    		break;
		    	case "Septiembre":
		    		parte_mes = "09";
		    		dia_limite = 30;
		    		break;
		    	case "Noviembre":
		    		parte_mes = "11";
		    		dia_limite = 30;
		    		break;
		    	case "Febrero":
		    		parte_mes = "02";
		    		if(bisiesto)
		    			dia_limite = 29;
		    		else
		    			dia_limite = 28;
		    		break;
		    	}
		    }
		});
		
		dia.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent arg0) {
				if((Integer) dia.getValue() > dia_limite)
					dia.setValue(dia_limite);
				else if((Integer) dia.getValue() < 1)
					dia.setValue(1);
			}
		});
		
		hombre.addActionListener (new ActionListener () {
		    public void actionPerformed(ActionEvent e) {
		    	parte_sexo = "H";
		    }
		});
		
		mujer.addActionListener (new ActionListener () {
		    public void actionPerformed(ActionEvent e) {
		    	parte_sexo = "M";
		    }
		});
		
		estado.addActionListener (new ActionListener () {
		    public void actionPerformed(ActionEvent e) {
		    	switch(estado.getSelectedItem().toString()){
		    	case "Aguascalientes":
		    		parte_estado = "AS";
		    		break;
		    	case "Baja California":
		    		parte_estado = "BC";
		    		break;
		    	case "Baja California Sur":
		    		parte_estado = "BS";
		    		break;
		    	case "Campeche":
		    		parte_estado = "CC";
		    		break;
		    	case "Chiapas":
		    		parte_estado = "CS";
		    		break;
		    	case "Chihuahua":
		    		parte_estado = "CH";
		    		break;
		    	case "Coahuila":
		    		parte_estado = "CL";
		    		break;
		    	case "Colima":
		    		parte_estado = "CM";
		    		break;
		    	case "Distrito Federal":
		    		parte_estado = "DF";
		    		break;
		    	case "Durango":
		    		parte_estado = "DG";
		    		break;
		    	case "Estado de Mexico":
		    		parte_estado = "MC";
		    		break;
		    	case "Guanajuato":
		    		parte_estado = "GT";
		    		break;
		    	case "Guerrero":
		    		parte_estado = "GR";
		    		break;
		    	case "Hidalgo":
		    		parte_estado = "HG";
		    		break;
		    	case "Jalisco":
		    		parte_estado = "JC";
		    		break;
		    	case "Michoacan":
		    		parte_estado = "MN";
		    		break;
		    	case "Morelos":
		    		parte_estado = "MS";
		    		break;
		    	case "Nayarit":
		    		parte_estado = "NT";
		    		break;
		    	case "Nuevo Leon":
		    		parte_estado = "NL";
		    		break;
		    	case "Oaxaca":
		    		parte_estado = "OC";
		    		break;
		    	case "Puebla":
		    		parte_estado = "PL";
		    		break;
		    	case "Queretaro":
		    		parte_estado = "QT";
		    		break;
		    	case "Quintana Roo":
		    		parte_estado = "QR";
		    		break;
		    	case "San Luis Potosi":
		    		parte_estado = "SP";
		    		break;
		    	case "Sinaloa":
		    		parte_estado = "SL";
		    		break;
		    	case "Sonora":
		    		parte_estado = "SR";
		    		break;
		    	case "Tabasco":
		    		parte_estado = "TC";
		    		break;
		    	case "Tamaulipas":
		    		parte_estado = "TS";
		    		break;
		    	case "Tlaxcala":
		    		parte_estado = "TL";
		    		break;
		    	case "Veracruz":
		    		parte_estado = "VZ";
		    		break;
		    	case "Yucatan":
		    		parte_estado = "YN";
		    		break;
		    	case "Zacatecas":
		    		parte_estado = "ZS";
		    		break;
		    	}
		    }
		});
		
		generar.addActionListener (new ActionListener () {
		    public void actionPerformed(ActionEvent e) {
		    	curp_final = apeido_p.getText().substring(0, 1);
		    	for(int n = 1; n < apeido_p.getText().length(); n++){
		    		if(apeido_p.getText().charAt(n) == 'A' ||
		    		   apeido_p.getText().charAt(n) == 'E' ||
		    		   apeido_p.getText().charAt(n) == 'I' ||
		    		   apeido_p.getText().charAt(n) == 'O' ||
		    		   apeido_p.getText().charAt(n) == 'U'){
		    			curp_final += apeido_p.getText().charAt(n);
		    			break;
		    		}
		    	}
		    	curp_final += apeido_m.getText().substring(0, 1);
		    	curp_final += nombre.getText().substring(0, 1);
		    	curp_final += agno.getValue().toString().substring(2, 4);
		    	curp_final += parte_mes;
		    	if((Integer) dia.getValue() < 10)
		    		curp_final += "0" + dia.getValue().toString();
		    	else
		    		curp_final += dia.getValue().toString();
		    	curp_final += parte_sexo;
		    	curp_final += parte_estado;
		    	for(int n = 1; n < apeido_p.getText().length(); n++)
		    		if(apeido_p.getText().charAt(n) != 'A' &&
		    		   apeido_p.getText().charAt(n) != 'E' &&
		    		   apeido_p.getText().charAt(n) != 'I' &&
		    		   apeido_p.getText().charAt(n) != 'O' &&
		    		   apeido_p.getText().charAt(n) != 'U'){
		    			curp_final += apeido_p.getText().charAt(n);
		    			break;
		    		}
		    	for(int n = 1; n < apeido_p.getText().length(); n++)
		    		if(apeido_m.getText().charAt(n) != 'A' &&
		    		   apeido_m.getText().charAt(n) != 'E' &&
		    		   apeido_m.getText().charAt(n) != 'I' &&
		    		   apeido_m.getText().charAt(n) != 'O' &&
		    		   apeido_m.getText().charAt(n) != 'U'){
		    			curp_final += apeido_m.getText().charAt(n);
		    			break;
		    		}
		    	for(int n = 1; n < nombre.getText().length(); n++)
		    		if(nombre.getText().charAt(n) != 'A' &&
		    		   nombre.getText().charAt(n) != 'E' &&
		    		   nombre.getText().charAt(n) != 'I' &&
		    		   nombre.getText().charAt(n) != 'O' &&
		    		   nombre.getText().charAt(n) != 'U'){
		    			curp_final += nombre.getText().charAt(n);
		    			break;
		    		}
		    	//Math.random();
		    	curp.setText(curp_final);
		    }
		});
		
		limpiar.addActionListener (new ActionListener () {
		    public void actionPerformed(ActionEvent e) {
		    	apeido_p.setText("");
		    	apeido_m.setText("");
		    	nombre.setText("");
		    	dia_limite = 31;
		    	agno.setValue(2016);
		    	dia.setValue(1);
		    	mes.setSelectedItem("Enero");
		    	hombre.setSelected(true);
		    	mujer.setSelected(false);
		    	estado.setSelectedItem("Aguascalientes");
		    	curp.setText("");
		    }
		});
	}
	
	public static void main(String[] args){
		CURP ob = new CURP();
	}
}

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class AREAS {
	
	private JFrame w_def, w_triangulo, w_cuadrado, w_circulo;
	private JButton botonTri, botonCua, botonCir, botonReg;
	private Label msj_predef1, msj_predef2;
	
	private Label msj_tri1, msj_tri2, msj_tri3, msj_tri4;
	private JButton calc_tri, regreso_tri;
	private JTextField tri_ing1, tri_ing2, tri_ing3;
	
	private Label msj_cua1, msj_cua2, msj_cua3;
	private JButton calc_cua, regreso_cua;
	private JTextField cua_ing1, cua_ing2;
	
	private Label msj_cir1, msj_cir2, msj_cir3;
	private JButton calc_cir, regreso_cir;
	private JTextField cir_ing1, cir_ing2;
	
	AREAS(){
		w_def = new JFrame("Areas de figuras");
		w_def.setSize(450, 750);
		w_def.setResizable(false);
		w_def.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		w_triangulo = new JFrame("Area de un triangulo");
		w_triangulo.setSize(450, 750);
		w_triangulo.setResizable(false);
		
		w_cuadrado = new JFrame("Area de un cuadrado");
		w_cuadrado.setSize(450, 750);
		w_cuadrado.setResizable(false);
		
		w_circulo = new JFrame("Area de un circulo");
		w_circulo.setSize(450, 750);
		w_circulo.setResizable(false);
		
		predef();
		A_triangulo();
		A_cuadrado();
		A_circulo();
	} //constructor
	
	public void A_circulo(){
		w_circulo.setLayout(null);
		
		msj_cir1 = new Label("Porfavor ingrese datos");
		msj_cir1.setFont(new Font("Arial", 1, 26));
		msj_cir1.setBounds(50, 50, 350, 50);
		
		msj_cir2 = new Label("Radio:");
		msj_cir2.setFont(new Font("Arial", 0, 18));
		msj_cir2.setBounds(25, 150, 75, 50);
		
		msj_cir3 = new Label("Area del circulo:");
		msj_cir3.setFont(new Font("Arial", 1, 22));
		msj_cir3.setBounds(50, 525, 200, 50);
		
		cir_ing1 = new JTextField("");
		cir_ing1.setHorizontalAlignment(SwingConstants.RIGHT);
		cir_ing1.setFont(new Font("Arial", 0, 20));
		cir_ing1.setBounds(100, 150, 300, 50);
		
		cir_ing2 = new JTextField("");
		cir_ing2.setHorizontalAlignment(SwingConstants.RIGHT);
		cir_ing2.setFont(new Font("Arial", 0, 20));
		cir_ing2.setEditable(false);
		cir_ing2.setBounds(250, 525, 150, 50);
		
		calc_cir = new JButton("Calcular Area");
		calc_cir.setFont(new Font("Arial", 1, 24));
		calc_cir.setBounds(100, 350, 300, 100);
		
		regreso_cir = new JButton("Regresar");
		regreso_cir.setFont(new Font("Arial", 0, 20));
		regreso_cir.setBounds(275, 650, 150, 50);
		
		w_circulo.add(msj_cir1);
		w_circulo.add(msj_cir2);
		w_circulo.add(msj_cir3);
		w_circulo.add(cir_ing1);
		w_circulo.add(cir_ing2);
		w_circulo.add(calc_cir);
		w_circulo.add(regreso_cir);
	}
	
	public void A_cuadrado(){
		w_cuadrado.setLayout(null);
		
		msj_cua1 = new Label("Porfavor ingrese datos");
		msj_cua1.setFont(new Font("Arial", 1, 26));
		msj_cua1.setBounds(50, 50, 350, 50);
		
		msj_cua2 = new Label("Lado:");
		msj_cua2.setFont(new Font("Arial", 0, 18));
		msj_cua2.setBounds(25, 150, 75, 50);
		
		msj_cua3 = new Label("Area del cuadrado:");
		msj_cua3.setFont(new Font("Arial", 1, 22));
		msj_cua3.setBounds(50, 525, 200, 50);
		
		cua_ing1 = new JTextField("");
		cua_ing1.setHorizontalAlignment(SwingConstants.RIGHT);
		cua_ing1.setFont(new Font("Arial", 0, 20));
		cua_ing1.setBounds(100, 150, 300, 50);
		
		cua_ing2 = new JTextField("");
		cua_ing2.setHorizontalAlignment(SwingConstants.RIGHT);
		cua_ing2.setFont(new Font("Arial", 0, 20));
		cua_ing2.setEditable(false);
		cua_ing2.setBounds(250, 525, 150, 50);
		
		calc_cua = new JButton("Calcular Area");
		calc_cua.setFont(new Font("Arial", 1, 24));
		calc_cua.setBounds(100, 350, 300, 100);
		
		regreso_cua = new JButton("Regresar");
		regreso_cua.setFont(new Font("Arial", 0, 20));
		regreso_cua.setBounds(275, 650, 150, 50);
		
		w_cuadrado.add(msj_cua1);
		w_cuadrado.add(msj_cua2);
		w_cuadrado.add(msj_cua3);
		w_cuadrado.add(cua_ing1);
		w_cuadrado.add(cua_ing2);
		w_cuadrado.add(calc_cua);
		w_cuadrado.add(regreso_cua);
	}
	
	public void A_triangulo(){
		w_triangulo.setLayout(null);
		
		msj_tri1 = new Label("Porfavor ingrese datos");
		msj_tri1.setFont(new Font("Arial", 1, 26));
		msj_tri1.setBounds(50, 50, 350, 50);
		
		msj_tri2 = new Label("Base:");
		msj_tri2.setFont(new Font("Arial", 0, 18));
		msj_tri2.setBounds(25, 150, 75, 50);
		
		msj_tri3 = new Label("Altura:");
		msj_tri3.setFont(new Font("Arial", 0, 18));
		msj_tri3.setBounds(25, 250, 75, 50);
		
		msj_tri4 = new Label("Area del triangulo:");
		msj_tri4.setFont(new Font("Arial", 1, 22));
		msj_tri4.setBounds(50, 525, 200, 50);
		
		regreso_tri = new JButton("Regresar");
		regreso_tri.setFont(new Font("Arial", 0, 20));
		regreso_tri.setBounds(275, 650, 150, 50);
		
		tri_ing1 = new JTextField("");
		tri_ing1.setHorizontalAlignment(SwingConstants.RIGHT);
		tri_ing1.setFont(new Font("Arial", 0, 20));
		tri_ing1.setBounds(100, 150, 300, 50);
		
		tri_ing2 = new JTextField("");
		tri_ing2.setHorizontalAlignment(SwingConstants.RIGHT);
		tri_ing2.setFont(new Font("Arial", 0, 20));
		tri_ing2.setBounds(100, 250, 300, 50);
		
		tri_ing3 = new JTextField("");
		tri_ing3.setHorizontalAlignment(SwingConstants.RIGHT);
		tri_ing3.setFont(new Font("Arial", 0, 20));
		tri_ing3.setEditable(false);
		tri_ing3.setBounds(250, 525, 150, 50);
		
		calc_tri = new JButton("Calcular Area");
		calc_tri.setFont(new Font("Arial", 1, 24));
		calc_tri.setBounds(100, 350, 300, 100);
		
		w_triangulo.add(msj_tri1);
		w_triangulo.add(msj_tri2);
		w_triangulo.add(msj_tri3);
		w_triangulo.add(msj_tri4);
		w_triangulo.add(regreso_tri);
		w_triangulo.add(tri_ing1);
		w_triangulo.add(tri_ing2);
		w_triangulo.add(tri_ing3);
		w_triangulo.add(calc_tri);
	}
	
	public void predef(){
		w_def.setLayout(null);
		
		msj_predef1 = new Label("Bienvenido!");
		msj_predef1.setFont(new Font("Arial", 1, 26));
		msj_predef1.setBounds(50, 50, 350, 50);
		
		msj_predef2 = new Label("Presione el boton de su eleccion");
		msj_predef2.setFont(new Font("Arial", 1, 22 ));
		msj_predef2.setBounds(50, 100, 350, 50);
		
		botonTri = new JButton("Triangulo");
		botonTri.setFont(new Font("Arial", 0, 35));
		botonTri.setBounds(50, 200, 350, 100);
		
		botonCua = new JButton("Cuadrado");
		botonCua.setFont(new Font("Arial", 0, 35));
		botonCua.setBounds(50, 350, 350, 100);
		
		botonCir = new JButton("Circulo");
		botonCir.setFont(new Font("Arial", 0, 35));
		botonCir.setBounds(50, 500, 350, 100);
		
		botonReg = new JButton("Salir");
		botonReg.setFont(new Font("Arial", 0, 20));
		botonReg.setBounds(325, 650, 100, 50);
		
		w_def.add(msj_predef1);
		w_def.add(msj_predef2);
		w_def.add(botonTri);
		w_def.add(botonCua);
		w_def.add(botonCir);
		w_def.add(botonReg);
	}
	
	public void ev_predef(){
		botonReg.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				System.exit(0);
			}
		});
		
		botonTri.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				w_def.setVisible(false);
				w_triangulo.setVisible(true);
				inicio();
			}
		});
		
		botonCua.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				w_def.setVisible(false);
				w_cuadrado.setVisible(true);
				inicio();
			}
		});
		
		botonCir.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				w_def.setVisible(false);
				w_circulo.setVisible(true);
				inicio();
			}
		});
	}
	
	public void ev_tri(){
		w_triangulo.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				w_def.setVisible(true);
				w_triangulo.setVisible(false);
			}
		});
		
		regreso_tri.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				w_def.setVisible(true);
				w_triangulo.setVisible(false);
			}
		});
		
		calc_tri.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				a_tri();
			}
		});
	}
	
	public void ev_cua(){
		w_cuadrado.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				w_def.setVisible(true);
				w_cuadrado.setVisible(false);
			}
		});
		
		regreso_cua.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				w_def.setVisible(true);
				w_cuadrado.setVisible(false);
			}
		});
		
		calc_cua.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				a_cua();
			}
		});
	}
	
	public void ev_cir(){
		w_circulo.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				w_def.setVisible(true);
				w_circulo.setVisible(false);
			}
		});
		
		regreso_cir.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				w_def.setVisible(true);
				w_circulo.setVisible(false);
			}
		});
		
		calc_cir.addMouseListener(new MouseAdapter(){
			public void mouseReleased(MouseEvent e){
				a_cir();
			}
		});
	}
	
	public void mostrar(){
		w_def.setVisible(true);
		w_triangulo.setVisible(false);
		w_cuadrado.setVisible(false);
		w_circulo.setVisible(false);
		
		ev_predef();
		ev_tri();
		ev_cua();
		ev_cir();
	}
	
	public static void main(String[] args){
		AREAS m = new AREAS();
		m.mostrar();
	}
	
	private double lado, base, resultado;
	
	public void a_tri(){
		try{
			lado = Double.parseDouble(tri_ing1.getText().trim());
			base = Double.parseDouble(tri_ing2.getText().trim());
			resultado = (base * lado) / 2;
			tri_ing3.setText(String.valueOf(resultado));
		}
		catch(NumberFormatException v){
			tri_ing3.setText("Error");
		}
	}
	
	public void a_cua(){
		try{
			lado = Double.parseDouble(cua_ing1.getText().trim());
			resultado = lado * lado;
			cua_ing2.setText(String.valueOf(resultado));
		}
		catch(NumberFormatException v){
			cua_ing2.setText("Error");
		}
	}
	
	public void a_cir(){
		try{
			lado = Double.parseDouble(cir_ing1.getText().trim());
			resultado = Math.PI * Math.pow(lado, 2);
			cir_ing2.setText(String.valueOf(String.format( "%.5f", resultado )));
		}
		catch(NumberFormatException v){
			cir_ing2.setText("Error");
		}
	}
	
	public void inicio(){
		lado = 0;
		base = 0;
		resultado = 0;
		
		tri_ing1.setText("");
		tri_ing2.setText("");
		tri_ing3.setText("");
		cua_ing1.setText("");
		cua_ing2.setText("");
		cir_ing1.setText("");
		cir_ing2.setText("");
	}
}
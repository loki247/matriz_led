#include "LedControlMS.h" 

LedControl lc=LedControl(7,5,6,1); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales

/* 12 para el DIN, 11 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/ 

byte A[] = {B00011000, B00100100, B01000010, B01000010, B01000010, B01111110, B01000010, B01000010};
byte B[] = {B01111000, B01000100, B01000100, B01111000, B01000100, B01000100, B01000100, B01111000};

void setup(){
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
  lc.shutdown(0,false);
  lc.setIntensity(0,8);// La valores estan entre 1 y 15 
  lc.clearDisplay(0);
}

void loop(){
  //trans();
  //delay(500);
  representar(A,5000);
  trans();
  delay(500);
  representar(B,5000);
  trans();
  delay(500);
  lc.clearDisplay(0);
}

// Funcion para representar una transicion animada
void trans(){ //Funcion de transicion para llenar y vaciar la pantalla de puntos
  for (int row=0; row<8; row++){
    for (int col=0; col<8; col++){
      lc.setLed(0,col,row,true); // 
      delay(25);
    }
  }
  
  for (int row=0; row<8; row++){
    for (int col=0; col<8; col++){
      lc.setLed(0,col,row,false); // 
      delay(25);
    }
  }
}

// Definimos una funcion para representar las figuras
//Funcion para la representacion de bytes de datos para una matriz de 8x8
void representar(byte *Datos,int retardo){
  for (int i = 0; i < 8; i++)  {
    lc.setColumn(0,i,Datos[7-i]);
  }
  
  delay(retardo);
}

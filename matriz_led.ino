#include "LedControlMS.h" 
#include "letras.h" 

LedControl lc=LedControl(7,5,6,1); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales

/* 7 para el DIN, 5 para el CLK, 6 para el CS y el 1 se refiere a la asignacion de la matriz*/ 

void setup(){
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
  lc.shutdown(0,false);
  lc.setIntensity(0,8);// La valores estan entre 1 y 15 
  lc.clearDisplay(0);
}

void loop(){
  //trans();
  //delay(500);
  representar(A,1000);
  representar(B,1000);
  representar(C,1000);
  representar(D,1000);
  representar(E,1000);
  representar(F,1000);
  representar(G,1000);
  representar(H,1000);
  representar(I,1000);
  representar(J,1000);
  representar(K,1000);
  representar(L,1000);
  representar(M,1000);
  representar(N,1000);
  representar(NN,1000);
  representar(O,1000);
  representar(P,1000);
  representar(Q,1000);
  representar(R,1000);
  representar(S,1000);
  representar(T,1000);
  representar(U,1000);
  representar(V,1000);
  representar(W,1000);
  representar(X,1000);
  representar(Y,1000);
  representar(Z,1000);
  
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

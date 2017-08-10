int rs = 10;
int enable = 7;
int clk = 13;
int data = 11;
//comandos reconhecidos pelo LCD do lab, detalhados no datasheet. 
byte a = 0b00111100; //2 linhas, display on
byte b = 0b00001111; //display om, cursosr on
byte c = 0b00000001; // clear display
byte d = 0b00000110; //incremente on, entire shifft off


void setup() {
  
//inicializa SPI
 pinMode(rs,OUTPUT);
 pinMode(enable, OUTPUT);
 pinMode(clk, OUTPUT);
 pinMode(data,OUTPUT);

//imicializa LCD

comando(a);
comando(b);
comando(c);
comando(d);
}


void loop() {
imprimir(0x031);
}

//Função que envia comandos ao LCD via spi.
//
void comando(byte x){
  digitalWrite(rs,LOW);
  digitalWrite(enable,LOW);
  delay(100);
  shiftOut(data,clk,MSBFIRST,x);
  delay(100);
  digitalWrite(enable,HIGH);
  digitalWrite(rs,HIGH);

}

//Função que envia caracteres a serem imprimidos pelo spi
void imprimir(byte y){
  digitalWrite(rs,HIGH);
  digitalWrite(enable,LOW);
  delay(100);
  shiftOut(data,clk,MSBFIRST,y);
  delay(100);
  digitalWrite(enable,HIGH);
  digitalWrite(rs,LOW);
}


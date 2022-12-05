/*
Create by Yazmin Gómez Flores 
*/
#include<Servo.h>
#define init_value_base 90
#define init_value_hombro 72
#define init_value_codo 90
#define init_value_muneca 120
#define init_value_pinza 61
Servo base;
Servo hombro;
Servo codo;
Servo muneca;
Servo pinza;
 int temp1=init_value_base, temp2=init_value_hombro, temp3=init_value_codo, temp4=init_value_muneca, temp5=init_value_pinza;
 int data1, data2, data3, data4, data5;
void setup() {
  // put your setup code here, to run once:
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  //base.attach(init_value_base);
  hombro.attach(8);
  codo.attach(7);
  muneca.attach(6);
  pinza.attach(5);
  _home();
}

void _home(){
    base.write(init_value_base);
  hombro.write(init_value_hombro);
  codo.write(init_value_codo);
  muneca.write(init_value_muneca);
  pinza.write(init_value_pinza);
  
  }

void _move(int t1, int t2, int t3, int t4, int t5, int v, int w, int x, int y, int z){
int i, j, k, l, m;

//inicio de base
if(t1>v){
    for(i=t1;i>v;i--){
        base.write(i);
        delay(15);
        delay(1000);
      }
  }else if(t1<v){
    for(i=t1;i<v;i++){
        base.write(i);
        delay(15);
        //delay(1000);
      }
    }else{
    base.write(init_value_base);
    delay(15);
    delay(1000);
}
 //fin de base
//inicio de hombro
if(t2>w){
    for(j=t2;j>w;j--){
        hombro.write(j);
        delay(15);
        delay(1000);
      }
  }else if(t2<w){
    for(j=t2;j<w;j++){
        hombro.write(j);
        delay(15);
        //delay(1000);
      }
    }else{
    hombro.write(init_value_hombro);
    delay(15);
    delay(1000);
}
//fin de hombro
//inicio de codo
if(t3>x){
    for(k=t3;k>x;k--){
        codo.write(k);
        delay(15);
        delay(1000);
      }
  }else if(t3<x){
    for(k=t3;k<x;k++){
        codo.write(k);
        delay(15);
        //delay(1000);
      }
    }else{
    codo.write(init_value_codo);
    delay(15);
    delay(1000);
}
//fin de codo
//inicio de muneca
if(t4>y){
    for(l=t4;l>y;l--){
        muneca.write(l);
        delay(15);
       delay(1000);
      }
  }else if(t4<y){
    for(l=t4;l<y;l++){
        muneca.write(l);
        delay(15);
        //delay(1000);
      }
    }else{
    muneca.write(init_value_muneca);
    delay(15);
    delay(1000);
}
//fin de muneca
//inicio de pinza
if(t5>z && z>60){
    for(m=t5;m>z;m--){
        pinza.write(m);
        delay(15);
        delay(1000);
      }
  }else if(t5<z  && z<120){
    for(m=t5;m<z;m++){
        pinza.write(m);
        delay(15);
        //delay(500);
      }
    }else{
    pinza.write(init_value_pinza);
    delay(15);
    delay(1000);
}
//fin de pinza
    
  }


void loop() {
  // put your main code here, to run repeatedly:
while(1){
while(Serial.available()>0){
 data1=Serial.parseInt();
 data2=Serial.parseInt();
 data3=Serial.parseInt();
 data4=Serial.parseInt();
 data5=Serial.parseInt();
 _move(temp1, temp2, temp3, temp4, temp5, data1, data2, data3, data4, data5);

 temp1= data1;
 temp2= data2;
 temp3= data3;
 temp4 = data4;
 temp5= data5;

}
}
}

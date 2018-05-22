#include <SoftwareSerial.h>

const int in1 = 7;
const int in2 = 6;
const int enArka = 3;

const int in3 = 4;
const int in4 = 2;
const int enOn = 5;


const int far = 9;
const int farOn = 22;
const int korna = 8;
int btRx = 11;
int btTx = 12;
SoftwareSerial bt(btRx,btTx);  

char okunan;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);

  pinMode(enArka,OUTPUT);
  
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(enOn,OUTPUT);

  pinMode(korna,OUTPUT);
  pinMode(far,OUTPUT);

  pinMode(farOn,OUTPUT);

  Serial.begin(9600);
  Serial.setTimeout(5);

  bt.begin(9600);
  bt.setTimeout(5); 

}

void loop() {
  // put your main code here, to run repeatedly:

if(bt.available() > 0)
  { 
    okunan = bt.read();
     
     if(okunan == 'f')
     {
        digitalWrite(far,HIGH);  
        digitalWrite(farOn,HIGH);             
     }
     else if(okunan == 'g')
     {
        digitalWrite(far,LOW); 
        digitalWrite(farOn,LOW);
     }

     if(okunan == 'h')
     {
        digitalWrite(korna,HIGH);
     }
     else if(okunan == 'j')
     {
        digitalWrite(korna,LOW);
     }

     if(okunan == '9' )
      { 
        //sağa       
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enOn,100);

        //ileri geri yok
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enArka,0);
      }
      else if( okunan == '8')
      {
        //dur
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
       analogWrite(enOn,0);

       digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       analogWrite(enArka,0);
      }

      else if( okunan == '7')
      {
        //sola
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enOn,100);
        //ileri geri yok
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enArka,0);    
      }
     
      ///////////////////////               İLERİ                  /////////////////////////
      //Hızlı
      else if( okunan == 'w')
      {
        //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,255); 
        //düz
       digitalWrite(in3,HIGH);
       digitalWrite(in4,HIGH);       
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
       analogWrite(enOn,0);        
      }
      //Normal
      else if( okunan == 'n')
      {
        //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,150);  
        //düz
       digitalWrite(in3,HIGH);
       digitalWrite(in4,HIGH);       
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
       analogWrite(enOn,0);        
      }

      //Yavaş
      else if( okunan == 'b')
      {
        //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,100);   
        //düz
       digitalWrite(in3,HIGH);
       digitalWrite(in4,HIGH);       
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
       analogWrite(enOn,0);        
      }
      ///////////////////////               İLERİ SON             /////////////////////////

      ///////////////////////               GERİ                  /////////////////////////
      //Hızlı
      else if(okunan == 's')
      {
        //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,255);

       //düz
       digitalWrite(in3,HIGH);
       digitalWrite(in4,HIGH);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
       analogWrite(enOn,0);        
      }
      //Normal
      else if(okunan == 'p')
      {
        //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,150); 

       //düz
       digitalWrite(in3,HIGH);
       digitalWrite(in4,HIGH);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
       analogWrite(enOn,0);        
      }
      //Yavaş
      else if(okunan == 'm')
      {
        //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,100);   

       //düz
       digitalWrite(in3,HIGH);
       digitalWrite(in4,HIGH);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
       analogWrite(enOn,0);        
      }

      ///////////////////////               GERİ SON              /////////////////////////

      ///////////////////////               İLERİ SAĞA            /////////////////////////
      //Hızlı
      else if( okunan == 'e')
      {
        //ileri sağa
       
       //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,255); 
       
       //sağa
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       analogWrite(enOn,100);         
      }
      //Normal
      else if( okunan == 'x')
      {
        //ileri sağa
       
       //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,150); 
       
       //sağa
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       analogWrite(enOn,100);         
      }
      //Yavaş
      else if( okunan == 'z')
      {
        //ileri sağa
       
       //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,100);   
       
       //sağa
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       analogWrite(enOn,100);         
      }

      ///////////////////////               İLERİ SAĞA SON          /////////////////////////

      ///////////////////////               İLERİ SOLA SON          /////////////////////////
       //Hızlı
       else if( okunan == 'q')
      {
       //ileri sola
       //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,255);
       
       //sola
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);
       analogWrite(enOn,100);
      }

      //Normal
       else if( okunan == '.')
      {
       //ileri sola
       //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,150); 
       
       //sola
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);
       analogWrite(enOn,100);
      }

      //Yavaş
       else if( okunan == 'o')
      {
       //ileri sola
       //ileri
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       analogWrite(enArka,100);   
       
       //sola
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);
       analogWrite(enOn,100);
      }

      ///////////////////////               İLERİ SOLA SON          /////////////////////////

      ///////////////////////               GERİ SAĞA               /////////////////////////

      //Hızlı
      else if(okunan == 'd')
      {
        //geri sağa
       //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,255);
       
       //sağa
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       analogWrite(enOn,100); 
      }

      //Normal
      else if(okunan == 'v')
      {
        //geri sağa
       //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,150); 
       
       //sağa
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       analogWrite(enOn,100); 
      }

      //Yavaş
      else if(okunan == 'c')
      {
        //geri sağa
       //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,100);   
       
       //sağa
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       analogWrite(enOn,100); 
      }

      ///////////////////////               GERİ SAĞA SON           /////////////////////////

      ///////////////////////               GERİ SOLA               /////////////////////////

      //Hızlı
      else if(okunan == 'a')
      {
        //geri sola
       //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,255);
       
       //sola
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);
       analogWrite(enOn,100);  
      }   
      //Normal
      else if(okunan == 'l')
      {
        //geri sola
       //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,150); 
       
       //sola
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);
       analogWrite(enOn,100);  
      }
      //Yavaş
      else if(okunan == 'k')
      {
        //geri sola
       //geri
       digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       analogWrite(enArka,100);   
       
       //sola
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);
       analogWrite(enOn,100);  
      }  

      ///////////////////////               GERİ SOLA SON           /////////////////////////
               
      Serial.println(okunan);    
   
    }
    else 
    {    
      Serial.println("Bağlantı Yok");        
    }
}

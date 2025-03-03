#include <SoftwareSerial.h>
const byte Rx = D6;
const byte Tx = D7;
SoftwareSerial mySerial = SoftwareSerial (Rx, Tx);
long lastUART = 0;
void Read_Uart(); //UART STM
String LED1 = "OFF", LED2 = "OFF" ;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 mySerial.begin(115200);

 Serial.println("UART Start");

 lastUART = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  Read_Uart();
   if (millis() - lastUART > 1000)
  {
    mySerial.print("1ON2ON3OFF4");
    Serial.println("Truyen : 1ON2ON3OFF4");
    lastUART = millis();
  }
}

void Read_Uart()
{
  String st = "";
  while (mySerial.available())
  {
    char inChar = (char)mySerial.read();
    st += inChar;
    if (inChar == 'C')
    {
      Serial.println("shreyas :" +st);
      int A = st.indexOf("A");
      int B = st.indexOf("B");
      int C = st.indexOf("C");

      LED1 = st.substring(A + 1, B);
      LED2 = st.substring(B + 1, C);
      Serial.println("LED1 : "+LED1+" LED2: "+ LED2 );
      break;
    }
  }
}
    
  

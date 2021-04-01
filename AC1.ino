//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

//estado do led vermelho
bool estadoLedVermelho = false;

//variaveis dos botoes
const int botao1 = 2;
const int botao2 = 8;
unsigned long lastDebounceTime1 = 0;
const int botaoDelay = 5;

//usado para começar o programa e serve para configurar os pinos para comunicação do serial
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("AC1-Meu Primeiro Projeto 2021");
  Serial.println("            V1.0");
  Serial.println(Grupo: LUNATIC WOLVES");
 } 
//executa os comandos 
void loop()
{
 if(millis() - lastDebouceTime1)>botaoDelay && digitalReed(botao1))
  {
   Serial.println("botao 1 apertado");
   ledVermelho();
   lastDebounceTime1 = millis();
}   
if((millis()-lastDebouceTime1)>botaoDelay && digitalReed(botao2))  
{
 Serial.println("botao 2 apertado") 
 ledVermelho();
 lastDebounceTime1=millis();
} 
  
//verificador de temperatura
if(getTemperatura()>=15)  
{
 ledAzul(true);
 }else
 {
 ledAzul(false);
 }

  if(getTemperatura()==15)
  {
    Serial.println("Temperatura chegou a 15 graus");
    delay(2000);
  }
  
 if(getLuminosidade()>5)
  {
    ledVerde(true);
    Serial.println("Luminosidade esta muito alta");
    delay(2000);
 }else
  {
    ledVerde(false);
  }
  
  delay(10);
  
  
}
                   
void ledVermelho(){                   
  estadoLedVermelho =!estadoLedVermelho;
  digitalWrite(vermelho,estadoLedVermelho)
 }
 void ledVerde(bool estado){     
   digitalWrite(verde,estado);  

 }
 void ledAzul(bool estado){      
   digitalWrite(azul,estado);
 }
                 
  int getTemperatura();
   int TemperaturaC;
  temperaturaC= map(((analogRead(A0)-20)*3.04),0,1023,-40,125);
  return temperaturaC;
 }
                 
 //funcao de leitura da luminosidade               
 int getLuminosidade(){                
  int luminosidade;               
 luminosidade=map(analogRead(A1),6,619,-3,10);
  return luminosidade;
   
   
 
}

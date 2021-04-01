//variaveis do led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

//estado do led vermelho
bool estadoLedVermelho = false;

//variaveis dos botoes
const int botao1 = 2;
const int botao2 = 8;
unsigned long lastDebounceTime1 = 0;
const int botaoDelay = 100;

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
if((millis()-lastDebouceTime1)>botaoDelay && digitalReed(botao1))  
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

  if(gatTemperatura()==15)
  {
    Serial.println("Temperatura chegou a 15 graus");
    delay(2000);
  }
  
 if(gatLuminosidade()>5)
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
                   
                   

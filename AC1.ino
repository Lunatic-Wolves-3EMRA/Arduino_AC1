//Variáveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

//Estado do led vermelho
bool estadoLedVermelho = false;

//Variáveis dos botões
const int botao1 = 2;
const int botao2 = 8;
unsigned long lastDebounceTime1 = 0;
const int botaoDelay = 5;

//Essa parte é usada para começar o programa, fazer a comunicação do serial e configurar os pinos
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("AC1-Meu Primeiro Projeto 2021");
  Serial.println("V1.0");
  Serial.println("Grupo: LUNATIC WOLVES");
 } 
//Executa os comandos 
void loop()
{
 if((millis() - lastDebounceTime1)>botaoDelay && digitalRead(botao1))
  {
   Serial.println("Botão 1 apertado");
   ledVermelho();
   lastDebounceTime1 = millis();
}   
if((millis()-lastDebounceTime1)>botaoDelay && digitalRead(botao2))  
{
 Serial.println("Botão 2 apertado"); 
 ledVermelho();
 lastDebounceTime1=millis();
} 
  
//Verifica a temperatura e a luminosidade
if(getTemperatura()>=15)  
{
 ledAzul(true);
 }else
 {
 ledAzul(false);
 }

  if(getTemperatura()==15)
  {
    Serial.println("Temperatura chegou a 15 graus!");
    delay(2000);
  }
  
 if(getLuminosidade()>5)
  {
    ledVerde(true);
    Serial.println("A luminosidade está muito alta!");
    delay(2000);
 }else
  {
    ledVerde(false);
  }
  
  delay(10);
  
  
}
                   
void ledVermelho(){                   
  estadoLedVermelho =!estadoLedVermelho;
  digitalWrite(vermelho,estadoLedVermelho);
 }
 void ledVerde(bool estado){     
   digitalWrite(verde,estado);  

 }
 void ledAzul(bool estado){      
   digitalWrite(azul,estado);
 }
  
//Função leitura da temperatura
  int getTemperatura(){
   int temperaturaC;
  temperaturaC= map(((analogRead(A0)-20)*3.04),0,1023,-40,125);
  return temperaturaC;
 }
                 
 //Função leitura da luminosidade               
 int getLuminosidade(){                
  int luminosidade;               
 luminosidade=map(analogRead(A1),6,619,-3,10);
  return luminosidade;
   
   
 
}

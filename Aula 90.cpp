Atividade de entrega Aula 90


//NÃO ALTERAR------------------------------------------------------------------------------------------------
float temperatura; //Variável que vai amarmazenar a informações sobre a temperatura do sensor
int pinoAnalogico0 = 0;
//NÃO ALTERAR------------------------------------------------------------------------------------------------
 
int key=13;

void setup() {
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
  Serial.begin(9600); //Inicia o monitor Serial
  pinMode(A0,INPUT); //Define o pino A0 como entrada
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
   
  pinMode (key, INPUT_PULLUP);
pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {

  int status = digitalRead(key);
  
  while (status == HIGH)
  {
     
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
  temperatura = ((analogRead(pinoAnalogico0) * (5.0/1024))-0.5)/0.01; //Executa a leitura da temperatura e armazena na variável 'temperatura'
  
  //Exibe no Monitor Serial a temperatura do Rack
  Serial.print("A temperatura do Rack esta em: "); 
  Serial.print(temperatura);
  Serial.print(char(176));
  Serial.println("C");
  delay(1000); //Aguarde 1 segundo
  //NÃO ALTERAR------------------------------------------------------------------------------------------------

  if (temperatura <=25 ) {
digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
      digitalWrite(4, LOW);
  delay(5000);
}

  if (temperatura >25 && temperatura<=70) {

   digitalWrite(2, LOW);
     digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
delay(5000);
    
}

  if(temperatura >=70){
digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4 , HIGH); 
delay(5000);
  }
    
 
  int status = digitalRead(key);
    
  if (status == LOW)
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    break;
  
  }


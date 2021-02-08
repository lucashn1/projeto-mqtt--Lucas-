//Monitoramento remoto com Arduino e protocolo MQTT

#include <UIPEthernet.h>

#include <PubSubClient.h>

#include <SPI.h>

//MacAdress 29-77-D8-1E-A9-A5
//Define o endereço MAC que será utilizado
byte mac[] = {0xEC, 0x49, 0xF5, 0xFA, 0xBD,0x0C};
bool mensagem;
int pino2 =2;
bool estado_sensor;


//Inicia o cliente Ethernet
EthernetClient client;
PubSubClient mqttClient(client);

void setup() {

    
     pinMode (pino2,INPUT_PULLUP);
     Serial.begin(9600);
    
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);
    
    //Definição de IP e porta TCP do Broker MQTT
    mqttClient.setServer("54.173.148.114",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

  
}

void loop() {

    estado_sensor = digitalRead(pino2);
 //Nome do client que será acessado remotamente
 mqttClient.connect ("rack");

if (estado_sensor == 0){
mensagem = mqttClient.publish("rack", "Rack Fechado.");
Serial.print("O estado do sensor e: ");
Serial.println(estado_sensor);


}else {
    mensagem = mqttClient.publish("rack", "Rack Aberto.");
    Serial.print("O estado do sensor e: ");
    Serial.println(estado_sensor);
    
  
}
  mqttClient.loop();
}
 
 
    

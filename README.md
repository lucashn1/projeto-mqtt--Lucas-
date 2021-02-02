# Repositorio Sprint 8

## :dart: **Objetivo**

Utilizar um Arduino Uno e um sensor magnetico para monitoramento de um rack de rede. O programa deve informar se o rack esta ABERTO ou FECHADO e enviar essa informação via internet utilizando o protocolo MQTT, essa informação será enviada para um servidor MQTT hospedado na AWS, e irá fornecer essa informação para um cliente MQTT, que estará utiliznado o aplicativo MQTT Dash em seu smartphone.

## :satellite: Bibliotecas utilizadas:
* UIPEthernet
* PubSubClient
* SPI

## :notebook_with_decorative_cover: **Projeto:**
![Projeto](https://user-images.githubusercontent.com/78046298/106601097-05845800-653a-11eb-86c5-d1b6fb4cc116.png)

## :nut_and_bolt: **Materiais Utilizados:**

* Placa Arduino Uno
* Módulo Ethernet (ENC28J60)
* Sensor Magnetico (MC-38)
* Jumpers
* Smartphone

## :electric_plug: **Circuito:**

 
![Circuito](https://user-images.githubusercontent.com/78046298/106600827-b0484680-6539-11eb-8e03-3ae240c8656e.png)

//GRUPO VPX - FORMIGA MECATRONICA

//Inicialmente como eram vários grupos, dividimos que dois grupos faria a comunicação, e outros dois fariam a lógica da caminhada;
//E o nosso grupo primeiro focou na lógica da caminhada
//Esse é o código da mbed que recebe o valor de 3 pernas e só repassa esses valores pros motores
//A outra mbed seria identica, apenas trocando os motores

#include "mbed.h"
#include "math.h"
#include "Servo.h"

// Valores empíricos para normalizar o controle dos motores (0 a 1)

#define P1_LEV_MAX 10 
#define P1_LEV_MIN 0
#define P1_ROT_MAX 10
#define P1_ROT_MIN 0

#define P3_LEV_MAX 10 
#define P3_LEV_MIN 0
#define P3_ROT_MAX 10 
#define P3_ROT_MIN 0

#define P5_LEV_MAX 10 
#define P5_LEV_MIN 0
#define P5_ROT_MAX 10 
#define P5_ROT_MIN 0



// Criacao dos servos

// Perna 1
Servo P2_SERVO_LEV; // servo elevacao
Servo P2_SERVO_ROT; // servo rotacao
// Perna 3  
Servo P4_SERVO_LEV; // servo elevacao
Servo P4_SERVO_ROT; // servo rotacao
// Perna 5
Servo P6_SERVO_LEV; // servo elevacao
Servo P6_SERVO_ROT; // servo rotacao


// Configuracao e definicao da pinagem dos motores
void main() {


  // ### CONFIGURAR CAN ###


  // Criar objetos (Servos)

  // Perna 1
  Servo P1_SERVO_LEV(p21);
  Servo P1_SERVO_ROT(p22);
  // Perna 3
  Servo P3_SERVO_LEV(p23);
  Servo P3_SERVO_ROT(p24);
  // Perna 5
  Servo P5_SERVO_LEV(p25);
  Servo P5_SERVO_ROT(p26);


  while(1) {

    // ### ESPERAR RECEBIMENTO DE MENSAGEM CAN (2 bits = [MOTOR, ANG]) ###

    MOTOR = CAN_msg[0];
    ANG = CAN_msg[1];

    switch(MOTOR){
      case 0:
        // P1_LEV
        P1_LEV = (P1_LEV - P1_LEV_MIN) / (P1_LEV_MAX - P1_LEV_MIN);  // Normalizar valores pros Servos
        P1_SERVO_LEV = P1_LEV;   // Atualizar valores dos Servos (outputs) com novos valores normalizados
      break;
      case 1:
        // P1_ROT
        P1_ROT = (P1_ROT - P1_ROT_MIN) / (P1_ROT_MAX - P1_ROT_MIN);  // Normalizar valores pros Servos
        P1_SERVO_ROT = P1_ROT;   // Atualizar valores dos Servos (outputs) com novos valores normalizados
      break;
      case 2:
        // P3_LEV
        P3_LEV = (P3_LEV - P3_LEV_MIN) / (P3_LEV_MAX - P3_LEV_MIN);  // Normalizar valores pros Servos
        P3_SERVO_LEV = P3_LEV;   // Atualizar valores dos Servos (outputs) com novos valores normalizados
      break;
      case 3:
        // P3_ROT
        P3_ROT = (P3_ROT - P3_ROT_MIN) / (P3_ROT_MAX - P3_ROT_MIN);  // Normalizar valores pros Servos
        P3_SERVO_ROT = P3_ROT;   // Atualizar valores dos Servos (outputs) com novos valores normalizados
      break;
      case 4:
        // P5_LEV
        P5_LEV = (P5_LEV - P5_LEV_MIN) / (P5_LEV_MAX - P5_LEV_MIN);  // Normalizar valores pros Servos
        P5_SERVO_LEV = P5_LEV;   // Atualizar valores dos Servos (outputs) com novos valores normalizados
      break;
      case 5:
        // P5_ROT
        P5_ROT = (P5_ROT - P5_ROT_MIN) / (P5_ROT_MAX - P5_ROT_MIN);  // Normalizar valores pros Servos
        P5_SERVO_ROT = P5_ROT;   // Atualizar valores dos Servos (outputs) com novos valores normalizados
      break;
    }
  }
}

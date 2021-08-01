//GRUPO VPX - FORMIGA MECATRÔNICA

//Inicialmente como eram vários grupos, dividimos que dois grupos faria a comunicação, e outros dois fariam a lógica da caminhada;
//Porém como tivemos problems com o hardware, acabou que não teve muita utilidade a lógica da caminhada, mas já haviamos feito bastante coisa
//Por isso esse código já está mais completo sobre essa parte (caminhada)

//Definir posições iniciais (repouso) das pernas: Elevação (LEV) e Rotação (ROT) (Empíricos)

//PERNA 1
#define P1_INICIAL_LEV 60 // Elevação
#define P1_INICIAL_ROT 100 // Rotação

//PERNA 2
#define P2_INICIAL_LEV 50 // Elevação
#define P2_INICIAL_ROT 75 // Rotação

//PERNA 3
#define P3_INICIAL_LEV 50 // Elevação
#define P3_INICIAL_ROT 80 // Rotação

//PERNA 4
#define P4_INICIAL_LEV 65 // Elevação
#define P4_INICIAL_ROT 40 // Rotação

//PERNA 5
#define P5_INICIAL_LEV 80 // Elevação
#define P5_INICIAL_ROT 25 // Rotação

//PERNA 6
#define P6_INICIAL_LEV 90 // Elevação
#define P6_INICIAL_ROT 60 // Rotação


// Criar objetos dos Servos (motores)

// PERNA 1
// P1_SERVO_LEV = Servo de elevação da perna 1
// P1_SERVO_ROT = Servo de rotação da perna 1

// PERNA 2
// P2_SERVO_LEV = Servo de elevação da perna 2
// P2_SERVO_ROT = Servo de rotação da perna 2

// PERNA 3  
// P3_SERVO_LEV = Servo de elevação da perna 3
// P3_SERVO_ROT = Servo de rotação da perna 3

// PERNA 4
// P4_SERVO_LEV = Servo de elevação da perna 4
// P4_SERVO_ROT = Servo de rotação da perna 4

// PERNA 5
// P5_SERVO_LEV = Servo de elevação da perna 5
// P5_SERVO_ROT = Servo de rotação da perna 5

// PERNA 6
// P6_SERVO_LEV = Servo de elevação da perna 6
// P6_SERVO_ROT = Servo de rotação da perna 6


// Ângulos para controlar os movimentos das pernas (incrementos)
// Perna 1 serve de referência para Pernas (1, 3, 5) e Perna 2 serve de referência para Pernas (2 4, 6)

int P1_LEV_SUBIR = 0;
int P1_ROT_AVANCAR = 0;
int P1_LEV_DESCER = 0;
int P1_ROT_RECUAR = 0;

int P2_LEV_SUBIR = 0;
int P2_ROT_AVANCAR = 0;
int P2_LEV_DESCER = 0;
int P2_ROT_RECUAR = 0;


// Ângulos atuais das pernas

// PERNA 1
int P1_LEV = P1_INICIAL_LEV;
int P1_ROT = P1_INICIAL_ROT;

// PERNA 2
int P2_LEV = P2_INICIAL_LEV;
int P2_ROT = P2_INICIAL_ROT;

// PERNA 3
int P3_LEV = P3_INICIAL_LEV;
int P3_ROT = P3_INICIAL_ROT;

// PERNA 4
int P4_LEV = P4_INICIAL_LEV;
int P4_ROT = P4_INICIAL_ROT;

// PERNA 5
int P5_LEV = P5_INICIAL_LEV;
int P5_ROT = P5_INICIAL_ROT;

// PERNA 6
int P6_LEV = P6_INICIAL_LEV;
int P6_ROT = P6_INICIAL_ROT;

// Variáveis para sincronização dos movimentos (fase entre os dois conjuntos de pernas)

boolean P1_SINC = LOW;
boolean P2_SINC = LOW;


int dir = 0; // Direção do movimento: Repouso (0), Frente (1), Direita (2), Esquerda (3), Trás (4)
int delay_speed = 50; // Velocidade da formiga (através do controle do delay entre incrementos)
int delay_inicial = 1; // Velocidade de retorno à posição inicial (para evitar movimento abrupto e brusco)

//Variáveis DUMMY simulando comunicação Linux
int DUMMY_LINUX_CONNECTION; // Checar se a conexão está funcionando
int DUMMY_LINUX_DATA; // Dado recebido pela comunicação

void main() {
  
  // Garantir posição inicial para Servos
  
  // PERNA 1
  // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_LEV) E VALOR (P1_INICIAL_LEV) ###
  // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_ROT) E VALOR (P1_INICIAL_ROT) ###
  
  // PERNA 2
  // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_LEV) E VALOR (P2_INICIAL_LEV) ###
  // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_ROT) E VALOR (P2_INICIAL_ROT) ###
  
  // PERNA 3
  // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_LEV) E VALOR (P3_INICIAL_LEV) ###
  // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_ROT) E VALOR (P3_INICIAL_ROT) ###

  // PERNA 4
  // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_LEV) E VALOR (P4_INICIAL_LEV) ###
  // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_ROT) E VALOR (P4_INICIAL_ROT) ###
  
  // PERNA 5
  // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_LEV) E VALOR (P5_INICIAL_LEV) ###
  // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_ROT) E VALOR (P5_INICIAL_ROT) ###
  
  // PERNA 6
  // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_LEV) E VALOR (P6_INICIAL_LEV) ###
  // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_ROT) E VALOR (P6_INICIAL_ROT) ###


  while(1) {

  // Checar recebimento de dados (LINUX)
    if (DUMMY_LINUX_CONNECTION > 0) {
      dir = DUMMY_LINUX_DATA;  // Leitura do dado
      // FRENTE
      if (dir == 1) {
        moverPerna1();
        moverPerna3();
        moverPerna5();
        if (P1_SINC == HIGH) {
          moverPerna2();
          moverPerna4();
          moverPerna6();
        }
      }
      // DIREITA
      if (dir == 2) {
        moverPerna1Rev();
        moverPerna3Rev();
        moverPerna5();
        if (P1_SINC == HIGH) {
          moverPerna2Rev();
          moverPerna4();
          moverPerna6();
        }
      }
      // ESQUERDA
      if (dir == 3) {
        moverPerna1();
        moverPerna3();
        moverPerna5Rev();
        if (P1_SINC == HIGH) {
          moverPerna2();
          moverPerna4Rev();
          moverPerna6Rev();
        }
      }
      // TRÁS
      if (dir == 4) {
        moverPerna1Rev();
        moverPerna3Rev();
        moverPerna5Rev();
        if (P1_SINC == HIGH) {
          moverPerna2Rev();
          moverPerna4Rev();
          moverPerna6Rev();
        }
      }
      // POSIÇÃO INICIAL (REPOUSO) 
      if (dir == 0) {
        PosicaoInicial();
      }
    }

    // Sem sinal (Bluetooth) => Posição Inicial (Repouso)
    else {
      dir = 0;
      PosicaoInicial();
    }
    
    delay(delay_speed); // Delay para controlar velocidade do movimento
    
  }
}

void moverPerna1() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P1_LEV_SUBIR <= 10) {
    P1_LEV = P1_INICIAL_LEV + P1_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_LEV) E VALOR (P1_LEV) ###
    P1_LEV_SUBIR++;
  }
  
  // Rotacionar a perna para frente
  if (P1_ROT_AVANCAR <= 30) {
    P1_ROT = P1_INICIAL_ROT + P1_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_ROT) E VALOR (P1_ROT) ###
    P1_ROT_AVANCAR++;
  }
  
  // Abaixar a perna para tocar o solo
  if (P1_ROT_AVANCAR > 20 & P1_LEV_DESCER <= 10) {
    P1_LEV = (P1_INICIAL_LEV + P1_LEV_SUBIR * 2) - P1_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_LEV) E VALOR (P1_LEV) ###
    P1_LEV_DESCER++;
  }
  
  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P1_ROT_AVANCAR >= 30) {
    P1_ROT = (P1_INICIAL_ROT + P1_ROT_AVANCAR) - P1_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_ROT) E VALOR (P1_ROT) ###
    P1_ROT_RECUAR++;
    P1_SINC = HIGH;
  }
  
  // Reset das variáveis de controle dos movimentos (ângulos de incremento)
  if (P1_ROT_RECUAR >= 30) {
    P1_LEV_SUBIR = 0;
    P1_ROT_AVANCAR = 0;
    P1_LEV_DESCER = 0;
    P1_ROT_RECUAR = 0;
  }

}
void moverPerna2() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P2_LEV_SUBIR <= 10) {
    P2_LEV = P2_INICIAL_LEV + P2_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_LEV) E VALOR (P2_LEV) ###
    P2_LEV_SUBIR++;
  }
  
  // Rotacionar a perna para frente
  if (P2_ROT_AVANCAR <= 30) {
    P2_ROT = P1_INICIAL_ROT + P2_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_ROT) E VALOR (P2_ROT) ###
    P2_ROT_AVANCAR++;

  }

  // Abaixar a perna para tocar o solo
  if (P2_ROT_AVANCAR > 20 & P2_LEV_DESCER <= 10) {
    P2_LEV = (P2_INICIAL_LEV + P2_LEV_SUBIR * 2) - P2_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_LEV) E VALOR (P2_LEV) ###
    P2_LEV_DESCER++;

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  }
  if (P2_ROT_AVANCAR >= 30) {
    P2_ROT = (P1_INICIAL_ROT + P2_ROT_AVANCAR) - P2_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_ROT) E VALOR (P2_ROT) ###
    P2_ROT_RECUAR++;
  }

  // Reset das variáveis de controle dos movimentos (ângulos de incremento)
  if (P2_ROT_RECUAR >= 30) {
    P2_LEV_SUBIR = 0;
    P2_ROT_AVANCAR = 0;
    P2_LEV_DESCER = 0;
    P2_ROT_RECUAR = 0;
  }
}

void moverPerna3() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P1_LEV_SUBIR <= 10) {
    P3_LEV = P3_INICIAL_LEV + P1_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_LEV) E VALOR (P3_LEV) ###
  }

  // Rotacionar a perna para frente
  if (P1_ROT_AVANCAR <= 30) {
    P3_ROT = P3_INICIAL_ROT + P1_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_ROT) E VALOR (P3_ROT) ###

  }

  // Abaixar a perna para tocar o solo
  if (P1_ROT_AVANCAR > 20 & P1_LEV_DESCER <= 10) {
    P3_LEV = (P3_INICIAL_LEV + P1_LEV_SUBIR * 2) - P1_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_LEV) E VALOR (P3_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P1_ROT_AVANCAR >= 30) {
    P3_ROT = (P3_INICIAL_ROT + P1_ROT_AVANCAR) - P1_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_ROT) E VALOR (P3_ROT) ###
  }
}

void moverPerna4() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P2_LEV_SUBIR <= 10) {
    P4_LEV = P4_INICIAL_LEV + P2_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_LEV) E VALOR (P4_LEV) ###
  }
  
  // Rotacionar a perna para frente
  if (P2_ROT_AVANCAR <= 30) {
    P4_ROT = P1_INICIAL_ROT + P2_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_ROT) E VALOR (P4_ROT) ###

  }

  // Abaixar a perna para tocar o solo
  if (P2_ROT_AVANCAR > 20 & P2_LEV_DESCER <= 10) {
    P4_LEV = (P4_INICIAL_LEV + P2_LEV_SUBIR * 2) - P2_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_LEV) E VALOR (P4_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P2_ROT_AVANCAR >= 30) {
    P4_ROT = (P4_INICIAL_ROT + P2_ROT_AVANCAR) - P2_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_ROT) E VALOR (P4_ROT) ###
  }
}

void moverPerna5() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P1_LEV_SUBIR <= 10) {
    P5_LEV = P5_INICIAL_LEV + P1_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_LEV) E VALOR (P5_LEV) ###
  }
  
  // Rotacionar a perna para frente
  if (P1_ROT_AVANCAR <= 30) {
    P5_ROT = P5_INICIAL_ROT + P1_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_ROT) E VALOR (P5_ROT) ###

  }

  // Abaixar a perna para tocar o solo
  if (P1_ROT_AVANCAR > 20 & P1_LEV_DESCER <= 10) {
    P5_LEV = (P5_INICIAL_LEV + P1_LEV_SUBIR * 2) + P1_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_LEV) E VALOR (P5_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P1_ROT_AVANCAR >= 30) {
    P5_ROT = (P5_INICIAL_ROT + P1_ROT_AVANCAR) - P1_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_ROT) E VALOR (P5_ROT) ###
  }
}

void moverPerna6() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P2_LEV_SUBIR <= 10) {
    P6_LEV = P6_INICIAL_LEV + P2_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_LEV) E VALOR (P6_LEV) ###
  }

  // Rotacionar a perna para frente
  if (P2_ROT_AVANCAR <= 30) {
    P6_ROT = P6_INICIAL_ROT + P2_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_ROT) E VALOR (P6_ROT) ###
  }

  // Abaixar a perna para tocar o solo
  if (P2_ROT_AVANCAR > 20 & P2_LEV_DESCER <= 10) {
    P6_LEV = (P6_INICIAL_LEV + P2_LEV_SUBIR * 2) - P2_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_LEV) E VALOR (P6_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P2_ROT_AVANCAR >= 30) {
    P6_ROT = (P6_INICIAL_ROT + P2_ROT_AVANCAR) - P2_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_ROT) E VALOR (P6_ROT) ###
  }
}

void moverPerna1Rev() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P1_LEV_SUBIR <= 10) {
    P1_LEV = P1_INICIAL_LEV + P1_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_LEV) E VALOR (P1_LEV) ###
    P1_LEV_SUBIR++;
  }
  
  // Rotacionar a perna para trás
  if (P1_ROT_AVANCAR <= 30) {
    P1_ROT = P1_INICIAL_ROT - P1_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_ROT) E VALOR (P1_ROT) ###
    P1_ROT_AVANCAR++;

  }

  // Abaixar a perna para tocar o solo
  if (P1_ROT_AVANCAR > 20 & P1_LEV_DESCER <= 10) {
    P1_LEV = (P1_INICIAL_LEV + P1_LEV_SUBIR * 2) - P1_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_LEV) E VALOR (P1_LEV) ###
    P1_LEV_DESCER++;
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P1_ROT_AVANCAR >= 30) {
    P1_ROT = (P1_INICIAL_ROT - P1_ROT_AVANCAR) + P1_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_ROT) E VALOR (P1_ROT) ###
    P1_ROT_RECUAR++;
    P1_SINC = HIGH;
  }

  // Reset das variáveis de controle dos movimentos (ângulos de incremento)
  if (P1_ROT_RECUAR >= 30) {
    P1_LEV_SUBIR = 0;
    P1_ROT_AVANCAR = 0;
    P1_LEV_DESCER = 0;
    P1_ROT_RECUAR = 0;
  }
}
void moverPerna2Rev() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P2_LEV_SUBIR <= 10) {
    P2_LEV = P2_INICIAL_LEV + P2_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_LEV) E VALOR (P2_LEV) ###
    P2_LEV_SUBIR++;
  }

  // Rotacionar a perna para trás
  if (P2_ROT_AVANCAR <= 30) {
    P2_ROT = P2_INICIAL_ROT - P2_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_ROT) E VALOR (P2_ROT) ###
    P2_ROT_AVANCAR++;

  }

  // Abaixar a perna para tocar o solo
  if (P2_ROT_AVANCAR > 20 & P2_LEV_DESCER <= 10) {
    P2_LEV = (P2_INICIAL_LEV + P2_LEV_SUBIR * 2) - P2_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_LEV) E VALOR (P2_LEV) ###
    P2_LEV_DESCER++;
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P2_ROT_AVANCAR >= 30) {
    P2_ROT = (P2_INICIAL_ROT - P2_ROT_AVANCAR) + P2_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_ROT) E VALOR (P2_ROT) ###
    P2_ROT_RECUAR++;
  }

  // Reset das variáveis de controle dos movimentos (ângulos de incremento)
  if (P2_ROT_RECUAR >= 30) {
    P2_LEV_SUBIR = 0;
    P2_ROT_AVANCAR = 0;
    P2_LEV_DESCER = 0;
    P2_ROT_RECUAR = 0;
  }
}

void moverPerna3Rev() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P1_LEV_SUBIR <= 10) {
    P3_LEV = P3_INICIAL_LEV + P1_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_LEV) E VALOR (P3_LEV) ###
  }

  // Rotacionar a perna para trás
  if (P1_ROT_AVANCAR <= 30) {
    P3_ROT = P3_INICIAL_ROT - P1_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_ROT) E VALOR (P3_ROT) ###

  }

  // Abaixar a perna para tocar o solo
  if (P1_ROT_AVANCAR > 20 & P1_LEV_DESCER <= 10) {
    P3_LEV = (P3_INICIAL_LEV + P1_LEV_SUBIR * 2) - P1_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_LEV) E VALOR (P3_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P1_ROT_AVANCAR >= 30) {
    P3_ROT = ((P3_INICIAL_ROT - P1_ROT_AVANCAR)) + P1_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_ROT) E VALOR (P3_ROT) ###
  }
}

void moverPerna4Rev() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P2_LEV_SUBIR <= 10) {
    P4_LEV = P4_INICIAL_LEV + P2_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_LEV) E VALOR (P4_LEV) ###
  }

  // Rotacionar a perna para trás
  if (P2_ROT_AVANCAR <= 30) {
    P4_ROT = P4_INICIAL_ROT - P2_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_ROT) E VALOR (P4_ROT) ###

  }

  // Abaixar a perna para tocar o solo
  if (P2_ROT_AVANCAR > 20 & P2_LEV_DESCER <= 10) {
    P4_LEV = (P4_INICIAL_LEV + P2_LEV_SUBIR * 2) - P2_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_LEV) E VALOR (P4_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P2_ROT_AVANCAR >= 30) {
    P4_ROT = (P4_INICIAL_ROT - P2_ROT_AVANCAR) + P2_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_ROT) E VALOR (P4_ROT) ###
  }
}

void moverPerna5Rev() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P1_LEV_SUBIR <= 10) {
    P5_LEV = P5_INICIAL_LEV + P1_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_LEV) E VALOR (P5_LEV) ###
  }

  // Rotacionar a perna para trás
  if (P1_ROT_AVANCAR <= 30) {
    P5_ROT = P5_INICIAL_ROT - P1_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_ROT) E VALOR (P5_ROT) ###

  }

  // Abaixar a perna para tocar o solo
  if (P1_ROT_AVANCAR > 20 & P1_LEV_DESCER <= 10) {
    P5_LEV = (P5_INICIAL_LEV + P1_LEV_SUBIR * 2) - P1_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_LEV) E VALOR (P5_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P1_ROT_AVANCAR >= 30) {
    P5_ROT = (P5_INICIAL_ROT - P1_ROT_AVANCAR) + P1_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_ROT) E VALOR (P5_ROT) ###
  }
}

void moverPerna6Rev() {
  // Movimento da perna no ar
  
  // Levantar a Perna
  if (P2_LEV_SUBIR <= 10) {
    P6_LEV = P6_INICIAL_LEV + P2_LEV_SUBIR * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_LEV) E VALOR (P6_LEV) ###
  }

  // Rotacionar a perna para trás
  if (P2_ROT_AVANCAR <= 30) {
    P6_ROT = P6_INICIAL_ROT - P2_ROT_AVANCAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_ROT) E VALOR (P6_ROT) ###
  }

  // Abaixar a perna para tocar o solo
  if (P2_ROT_AVANCAR > 20 & P2_LEV_DESCER <= 10) {
    P6_LEV = (P6_INICIAL_LEV + P2_LEV_SUBIR * 2) - P2_LEV_DESCER * 2;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_LEV) E VALOR (P6_LEV) ###
  }

  // Movimento da perna no solo (alavanca)
  
  // Rotacionar de volta para a posição inicial
  if (P2_ROT_AVANCAR >= 30) {
    P6_ROT = (P6_INICIAL_ROT - P2_ROT_AVANCAR) + P2_ROT_RECUAR;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_ROT) E VALOR (P6_ROT) ###
  }
}

void PosicaoInicial() {
  // Reset de todas as variáveis e retorno das Pernas para as posições iniciais
  
  dir = 0;
  P1_SINC = LOW;
  P2_SINC = LOW;

  //Retornar às posições iniciais
  
  // PERNA 1 -> Posição Inicial
  while (P1_ROT > P1_INICIAL_ROT) {
    P1_ROT--;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_ROT) E VALOR (P1_ROT) ###
    delay(delay_inicial);
  }

  while (P1_ROT < P1_INICIAL_ROT) {
    P1_ROT++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_ROT) E VALOR (P1_ROT) ###
    delay(delay_inicial);
  }

  while (P1_LEV < P1_INICIAL_LEV) {
    P1_LEV++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P1_SERVO_LEV) E VALOR (P1_LEV) ###
    delay(delay_inicial);
  }

  // PERNA 3 -> Posição Inicial
  while (P3_ROT > P3_INICIAL_ROT) {
    P3_ROT--;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_ROT) E VALOR (P3_ROT) ###
    delay(delay_inicial);
  }

  while (P3_ROT < P3_INICIAL_ROT) {
    P3_ROT++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_ROT) E VALOR (P3_ROT) ###
    delay(delay_inicial);
  }

  while (P3_LEV < P3_INICIAL_LEV) {
    P3_LEV++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P3_SERVO_LEV) E VALOR (P3_LEV) ###
    delay(delay_inicial);
  }

  // PERNA 5 -> Posição Inicial
  while (P5_ROT > P5_INICIAL_ROT) {
    P5_ROT--;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_ROT) E VALOR (P5_ROT) ###
    delay(delay_inicial);
  }

  while (P5_ROT < P5_INICIAL_ROT) {
    P5_ROT++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_ROT) E VALOR (P5_ROT) ###
    delay(delay_inicial);
  }

  while (P5_LEV < P5_INICIAL_LEV) {
    P5_LEV++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P5_SERVO_LEV) E VALOR (P5_LEV) ###
    delay(delay_inicial);
  }

  // PERNA 2 -> Posição Inicial
  while (P2_ROT > P2_INICIAL_ROT) {
    P2_ROT--;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_ROT) E VALOR (P2_ROT) ###
    delay(delay_inicial);
  }

  while (P2_ROT < P2_INICIAL_ROT) {
    P2_ROT++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_ROT) E VALOR (P2_ROT) ###
    delay(delay_inicial);
  }

  while (P2_LEV < P2_INICIAL_LEV) {
    P2_LEV++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P2_SERVO_LEV) E VALOR (P2_LEV) ###
    delay(delay_inicial);
  }

  // PERNA 4 -> Posição Inicial
  while (P4_ROT > P4_INICIAL_ROT) {
    P4_ROT--;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_ROT) E VALOR (P4_ROT) ###
    delay(delay_inicial);
  }

  while (P4_ROT < P4_INICIAL_ROT) {
    P4_ROT++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_ROT) E VALOR (P4_ROT) ###
    delay(delay_inicial);
  }

  while (P4_LEV < P4_INICIAL_LEV) {
    P4_LEV++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P4_SERVO_LEV) E VALOR (P4_LEV) ###
    delay(delay_inicial);
  }

  // PERNA 6 -> Posição Inicial
  while (P6_ROT > P6_INICIAL_ROT) {
    P6_ROT--;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_ROT) E VALOR (P6_ROT) ###
    delay(delay_inicial);
  }

  while (P6_ROT < P6_INICIAL_ROT) {
    P6_ROT++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_ROT) E VALOR (P6_ROT) ###
    delay(delay_inicial);
  }

  while (P6_LEV < P6_INICIAL_LEV) {
    P6_LEV++;
    // ### ENVIAR CAN INFORMANDO MOTOR (P6_SERVO_LEV) E VALOR (P6_LEV) ###
    delay(delay_inicial);
  }

  // Reset das variáveis de controle dos movimentos (ângulos de incremento)
  
  P1_LEV_SUBIR = 0;
  P1_ROT_AVANCAR = 0;
  P1_LEV_DESCER = 0;
  P1_ROT_RECUAR = 0;

  P2_LEV_SUBIR = 0;
  P2_ROT_AVANCAR = 0;
  P2_LEV_DESCER = 0;
  P2_ROT_RECUAR = 0;
}
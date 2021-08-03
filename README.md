# Grupo VPX

Projeto da Formiga Mecatrônica para a matéria **SEM0544 - Sistemas Embarcados (2021)**. 

## Alunos:

* [Giovanna Martins Losacco](https://github.com/gilosacco) (nº 9783491)
* [Paulo Henrique Couto de Resende Silva](https://github.com/paulohenriquecrs) (nº 10308818)
* [Vivian Coutinho Nascimento](https://github.com/vivcoutinho) (nº 10377434)

## Proposta

A ideia do projeto é implementar a caminhada do robô formiga (com seis pernas). O hardware é composto por uma placa Toradex com compatibilidade Linux, duas MBEDS e 12 servomotores de aeromodelismo (2 em cada perna). E como ele foi decidido previamente, o foco do projeto foi na implementação do software no robô.

O trabalho foi então dividido em duas partes. A primeira pensando na lógica da movimentação para a caminhada, pensando mais nos momentos em que cada motor seria acionado. Já a segunda foi voltada mais para a comunicação entre as duas placas (e a divisão de processamento entre elas).

## Desenvolvimento

Primeiro começamos pensando na lógica da movimentação para a caminhada. E antes de escrever o código em C, fizemos os diagramas abaixo para ajudar no nosso processo de desenvolvimento. O primeiro diagrama é sobre a rotina geral da leitura/tomada de decisão de acordo com o que o usuário envia para o robô. Já o segundo é mais voltado para a movimentação em si das pernas, representando a função *mover frente*. Pode-se notar que a lógica é de movimentar sempre 3 pernas intercaladas ao mesmo tempo, de forma que as outras 3 permaneçam no chão durante esse tempo para maior estabilidade da formiga.

<p align="center">
<img src="diagrama1.png" width ="400">
<img src="diagrama2.png" width="366">
</p>

A partir desses diagramas começamos a desenvolver o código [FormigaCaminhadaVPX](FormigaCaminhadaVPX.c), que realiza o controle da trajetória das pernas através de uma lógica incremental em loop dos motores. Também consideramos uma variação inicial dos parâmetros de cada motor, que seriam calculados empiricamente (caso fosse possível). A comunicação nesse código ficou apenas indicada através de comentários, simbolizando onde seria realizada o envio e o recebimento de dados.

O outro código [(mbedVPX.c)](mbedVPX.c) roda dentro das duas MBEDS. Ele recebe os ângulos via CAN da Toradex, normaliza com valores máximos e mínimos definidos empiricamente, e envia isso pros motores usando a biblioteca *Servo.h*. Cada MBED é responsável por repassar os valores para 3 motores, o código apenas varia os números dos motores (1,3,5 por 2,4,6).

O objetivo final então do nosso grupo seria que toda a lógica da caminhada fosse realizada dentro da Toradex (que receberia os comandos *frente, trás, direita e esquerda* do usuário), e ela enviaria os ângulos necessários para as MBEDS. As MBEDS por sua vez, apenas teriam o código para repassar os valores para cada motor executar. Infelizmente a comunicação CAN entre a Toradex e a MBED não foi bem sucedida.

## Apêndice

Apenas para ficar documentado, em sala de aula aprendemos a comunicar com a Toradex pelo terminal do Linux (enviar o código ARM).

1. Verificar se o SDK está instalado
2. Realizar o *Cross Compiling*:
```
> ${CC} -Wall codigo.c -o codigoARM
```
3. Enviar o código para Toradex:
```
> scp codigoARM root@172.17.2.XXX/home/root
```
4. Em outro terminal, executar o código dentro da Toradex:
```
> ssh root@172.17.2.XXX
> ./codigoARM
```


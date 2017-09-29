/*  Arduino task library example: 2 tasks
    by: marlon soares

*/

#include <task.h>

//Protótipos
void blink(void);
void sendInfo(void);

//Criação dos objetos
task task1 = task(blink,500);     //cria e configura a task1 para executar a 
                                  //função "blink" a cada 500ms

task task2 = task();              //apenas cria a task2


void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  task2.setInterval(1000);        //configura o intervalo de execução da task2
  task2.setCall(sendInfo);        //configura a função a ser executada da task2
}

void loop() {
	task1.check();                 //verifica se a tarefa deve executar
  task2.check();                 //verifica se a tarefa deve executar
}


//funções
void blink(void){
  digitalWrite(13,!digitalRead(13));
}

void sendInfo(void){
	Serial.print("Millis: ");
	Serial.print(millis());
	Serial.println();
}
/*  Arduino task library example: simple task
    by: marlon soares

*/
#include <task.h>

//Protótipos
void blink(void);

//Criação dos objetos
task task1 = task(blink,500);     //cria e configura a task1 para executar a 
                                  //função "blink" a cada 500ms


void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
	task1.check();                 //verifica se a tarefa deve executar
}


//funções
void blink(void){
  digitalWrite(13,!digitalRead(13));
}

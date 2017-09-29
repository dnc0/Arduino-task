/*
	Arduino task library
	by: Marlon soares
	marlonslbr@gmail.com
	v1.1
	task.cpp
*/
#include "task.h"

task::task(void (*callback)(void), unsigned long _interval){
	_onRun = callback;//configura a função a ser chamada quando executar a tarefa
	interval = _interval;// Save interval
	last = 0; //reseta a variável
};

void task::setInterval(unsigned long _interval){
	interval = _interval;//Configura o intervalo de execução da tarefa
}

void task::setCall(void (*callback)(void)){
	_onRun = callback; //configura a função a ser executada
}

void task::check(void){
	if(millis() - last == interval) { //se a tarefa dve ser executada...
		if(_onRun != NULL)_onRun(); //execute a função.
		last= millis(); //atualize a contagem.
	}
}


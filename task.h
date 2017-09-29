/*
	Arduino task library
	by: Marlon soares
	marlonslbr@gmail.com
	v1.1
	task.h
*/

#ifndef Task_h
#define Task_h
#include <Arduino.h>

class task{
protected:
	unsigned long interval; // Intervalo para nova execucao
	unsigned long last;// Ultima vez que foi executado
	void (*_onRun)(void);// Guarda o endereço da função a ser executada para tarefa
public:
	task(void (*callback)(void) = NULL, unsigned long _interval = 0); //Construtor do objeto task
	void setInterval(unsigned long _interval);// configura o invervalo de execucao
	void setCall(void (*callback)(void));// configura a funcao que deve ser chamada
	void check(void);// verifica se a tarefa deve ser executada e executa.
};
#endif

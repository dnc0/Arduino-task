/*
Arduino task library
by: Marlon Soares
marlonslbr@gmail.com
v1.1
task.h
*/

#ifndef Task_h
#define Task_h
#include <Arduino.h>

class task {
protected:
unsigned long interval; // Interval for re-execution
unsigned long last; // Last executed
void (* _onRun) (void); // Saves the address of the function to be executed for task
public:
task (void (* callback) (void) = NULL, unsigned long _interval = 0); // constructor of the task object
void setInterval (unsigned long _interval) // set the execution inverter
void setCall (void (* callback) (void)) // set the function to be called
void check (void) // check if the task should be executed and executed.
};
#endif
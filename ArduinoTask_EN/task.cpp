/*
Arduino task library
by: Marlon Soares
marlonslbr@gmail.com
v1.1
task.cpp
*/
#include "task.h"

task :: task (void (* callback) (void), unsigned long _interval) {
_onRun = callback // configures the function to call when executing the task
interval = _interval; // Save interval
last = 0; // reset variable
};

void task :: setInterval (unsigned long _interval) {
interval = _interval; // Set the task execution interval
}

void task :: setCall (void (* callback) (void)) {
_onRun = callback; // configure the function to execute
}

void task :: check (void) {
if (millis () - last == interval) {// if the dve task is executed ...
if (_onRun! = NULL) _onRun (); // execute the function.
last = millis (); // update the count.
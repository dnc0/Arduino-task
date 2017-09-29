/* Arduino task library example: 2 tasks
     by: marlon soares

*/

#include <task.h>

// Prototypes
void blink (void);
void sendInfo (void);

// Creating objects
task task1 = task (blink, 500); // create and configure task1 to execute the
                                   // function "blink" every 500ms

task task2 = task (); // just create task2


void setup () {
   pinMode (13, OUTPUT);
   Serial.begin (9600);
   task2.setInterval (1000); // sets the execution interval of task2
   task2.setCall (sendInfo); // set the function to be executed from task2
}

void loop () {
task1.check (); // check if the task should execute
   task2.check (); // check if the task should execute
}


// functions
void blink (void) {
   digitalWrite (13,! digitalRead (13));
}

void sendInfo (void) {
Serial.print ("Millis:");
Serial.print (millis ());
Serial.println ();
}
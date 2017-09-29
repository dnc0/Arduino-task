/* Arduino task library example: simple task
     by: marlon soares

*/
#include <task.h>

// Prototypes
void blink (void);

// Creating objects
task task1 = task (blink, 500); // create and configure task1 to execute the
                                   // function "blink" every 500ms


void setup () {
   pinMode (13, OUTPUT);
}

void loop () {
task1.check (); // check if the task should execute
}


// functions
void blink (void) {
   digitalWrite (13,! digitalRead (13));
}
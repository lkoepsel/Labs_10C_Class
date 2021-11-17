/* Sound - exploring how to make sounds using the Uno
*/

/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>
#include "tone.h"
#include "delay.h"

/* Put your global variables here */
int speakerPin = 8;
//String allNotes = "cCdDefFgGaAb";
int allPitches[] =
{261,277,294,311,330,349,370,392,415,440,466,494};

/* Main - is the function which C will look for to run at initialization*/ 
int main() {
/* initialize code goes here, similar to setup in the Arduino*/

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        tone(speakerPin,NOTE_C4, d4);
        delay(200);
        noTone(speakerPin);

        tone(speakerPin,NOTE_C4, d4);
        delay(200);
        noTone(speakerPin);

        tone(speakerPin,NOTE_G4, d4);
        delay(200);
        noTone(speakerPin);

        tone(speakerPin,NOTE_G4, d4);
        delay(200);
        noTone(speakerPin);
    }
    return(0);
}

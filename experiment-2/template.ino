// vars and libs go here
#include "DaisyDuino.h"
DaisyHardware hw;


void setup() { 
    //daisyseed setup 
    DAISY.init(DAISY_SEED, AUDIO_SR_48K); // initialise the daisySeed with a sample rate of 48k
    float sampleRate = DAISY.get_samplerate();


    DAISY.begin(ProcessAudio); // Always need this 
}

//Audio Processing 
void ProcessAudio(float **in, float **out, size_t size){ // ** is a pointer to an array of pointers. size_t is an unassigned integer type.
for (size_t i = 0; i < size; i++ ){
    out[0][i] = //filter.Process(osc.Process());
}
}

//main loop
void loop(){
    
}

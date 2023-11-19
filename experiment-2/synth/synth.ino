// vars and libs
#include "DaisyDuino.h"
DaisyHardware hw;

int filterPot = A0; //filter potentiometer
int oscPot = A1; // oscillator potentiometer

static Oscillator = osc; // use daisy oscillator class and define as osc
static MoogLadder = filter; // use moog class and define as filter

void setup() { 
    //daisyseed setup 
    DAISY.init(DAISY_SEED, AUDIO_SR_48K); // initialise the daisySeed with a sample rate of 48k
    float sampleRate = DAISY.get_samplerate();

    //oscillator setup
    osc.Init(sampleRate);//init with sample rate
    osc.setFreq(44);// set an initial Hz frequency
    osc.SetWaveForm(osc.WAVE_SAW);//Waveform sawtooth

    //filter set-up
    filter.Init(sampleRate);

    //start audio!
    DAISY.begin(ProcessAudio); // Always need this 
}

//Audio Processing 
void ProcessAudio(float **in, float **out, size_t size){ // ** is a pointer to an array of pointers. size_t is an unassigned integer type.
for (size_t i = 0; i < size; i++ ){
    out[0][i] = filter.Process(osc.Process());
}
}

void loop(){
    filter.SetFreq(analogRead(filterPot));
}

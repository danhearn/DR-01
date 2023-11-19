// vars and libs go here
#include "DaisyDuino.h"
DaisyHardware hw;

//#include "HX711.h"

//#define LOADCELL_DOUT_PIN  4
//#define LOADCELL_SCK_PIN  5

//HX711 scale;

static Oscillator osc1;
static MoogLadder filter;

int loadcellWhite = A2;
int loadcellGreen = A3;


void setup() { 
    //daisyseed setup 
    DAISY.init(DAISY_SEED, AUDIO_SR_48K); // initialise the daisySeed with a sample rate of 48k
    float sampleRate = DAISY.get_samplerate();

    //oscillator setups
    osc1.Init(sampleRate);
    osc1.SetFreq(440);
    osc1.SetWaveform(osc1.WAVE_TRI);

    //filter setup
    filter.Init(sampleRate);

    DAISY.begin(ProcessAudio); // Always need this 

    //scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    //scale.set_scale(0); //This value is obtained by using the SparkFun_HX711_Calibration sketch
    //scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
}

//Audio Processing 
void ProcessAudio(float **in, float **out, size_t size){ // ** is a pointer to an array of pointers. size_t is an unassigned integer type.
for (size_t i = 0; i < size; i++ ){
   float processedSample = filter.Process(osc1.Process()); 
   out[0][i] = processedSample;
}
}

//main loop
void loop(){
    //int voltageDifference = analogRead(loadcellWhite) - analogRead(loadcellGreen);
    //float frequency = map(voltageDifference, -1023, 1023, 220, 880);
    //float sclNum = scale.get_units();
    //float convertedScl = map(sclNum, 0, 20000, 44, 1000); 
    osc1.SetFreq(analogRead(A0));
    filter.SetFreq(analogRead(A1));
}

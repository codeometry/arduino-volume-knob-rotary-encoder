/*
 * Tutorial by: Codeometry
 * Website: codemetry.in
 * 
 * A simple volume knob/macro controller built with Arduino Leonardo and a rotary encoder.
 *  
 * Parts:
 *  Arduino Leonardo* - https://amzn.to/2zkbxWq
 *  Rotary Encoder* - https://amzn.to/3hqnslX
 *  
 * * = Affilate
 *  
 * Video Tutorial on: https://youtube.com/codeometry
 * Written Tutorial on: https://codeometry.in
 * 
 * Links: 
 *  Keyboard Library documentation: https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h
 *  HID-Project library documentation: https://github.com/NicoHood/HID/wiki/Consumer-API
*/
#include <HID-Project.h>

// Rotary Encoder Inputs
#define inputCLK 1
#define inputDT 2
#define inputSW 3

int currentStateCLK;
int previousStateCLK; 

void setup() { 
	// Set encoder pins as inputs  
	pinMode (inputCLK,INPUT);
	pinMode (inputDT,INPUT);
	pinMode(inputSW, INPUT_PULLUP);

	// Setup Serial Monitor
	Serial.begin (9600);
	Consumer.begin();
	Keyboard.begin();

	// Read the initial state of inputCLK
	// Assign to previousStateCLK variable
	previousStateCLK = digitalRead(inputCLK);
} 

void loop() { 
	// Read the current state of inputCLK
	currentStateCLK = digitalRead(inputCLK);

	// If the previous and the current state of the inputCLK are different then a pulse has occured
	if (currentStateCLK != previousStateCLK){ 
		// If the inputDT state is different than the inputCLK state then 
		// the encoder is rotating counterclockwise
		if (digitalRead(inputDT) != currentStateCLK) { 
			rotateRight();
		} else {
			rotateLeft();
		}
	} 
	// Update previousStateCLK with the current state
	previousStateCLK = currentStateCLK; 
}

void rotateRight() {
	// Increase the volume.
	Consumer.write(MEDIA_VOLUME_UP);  
}

void rotateLeft() {
	// Increase the volume.
	Consumer.write(MEDIA_VOLUME_DOWN);
}

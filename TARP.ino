#include <Servo.h>

Servo servo;
int eastLDRPin = A0; // Analog pin for east LDR
int westLDRPin = A1; // Analog pin for west LDR
int eastLDRReading = 0;
int westLDRReading = 0;
int servoPosition = 90;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  servo.attach(9); // Attach servo to pin 9
}

void loop() {
  eastLDRReading = analogRead(eastLDRPin); // Read east LDR value
  westLDRReading = analogRead(westLDRPin); // Read west LDR value
  
  Serial.print("East LDR Reading: ");
  Serial.println(eastLDRReading); // Print east LDR value
  Serial.print("West LDR Reading: ");
  Serial.println(westLDRReading); // Print west LDR value
  
  if (eastLDRReading < westLDRReading) {
    moveServoClockwise(); // Move servo clockwise (east side better)
  } else if (eastLDRReading > westLDRReading) {
    moveServoCounterClockwise(); // Move servo counterclockwise (west side better)
  }
  delay(1000); // Delay between readings
}

void moveServoClockwise() {
  if (servoPosition < 180) { // Ensure servo position is within limits
    servoPosition += 10; // Increase servo position by 10 degrees
    servo.write(servoPosition); // Move servo to new position
    Serial.print("Moving servo clockwise to position: ");
    Serial.println(servoPosition); // Print new servo position
    delay(500); // Delay for servo movement
  }
}

void moveServoCounterClockwise() {
  if (servoPosition > 0) { // Ensure servo position is within limits
    servoPosition -= 10; // Decrease servo position by 10 degrees
    servo.write(servoPosition); // Move servo to new position
    Serial.print("Moving servo counterclockwise to position: ");
    Serial.println(servoPosition); // Print new servo position
    delay(500); // Delay for servo movement
  }
}
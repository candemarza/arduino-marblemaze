#include <Servo.h>

// ---------- Configuracion de pines ----------
const int SERVO_X_PIN = 8;
const int SERVO_Y_PIN = 10;
const int AXIS_X_PIN   = A0;
const int AXIS_Y_PIN   = A1;

// ---------- Posiciones home ----------
const int SERVO_X_HOME = 127; //calibrar manualmente a tu resting position
const int SERVO_Y_HOME = 124; //calibrar manualmente a tu resting position

int posX = SERVO_X_HOME;
int posY = SERVO_Y_HOME;

// ---------- Limite ----------
const int MAX_OFFSET = 20; 

// ---------- Parametros del joystick ----------
const int JOY_RANGE    = 12; 
const int JOY_CENTER   = JOY_RANGE / 2;
const int JOY_THRESHOLD = JOY_RANGE / 4; 

Servo servoX;
Servo servoY;

void setup() {
  servoX.attach(SERVO_X_PIN);
  servoY.attach(SERVO_Y_PIN);

  posX = SERVO_X_HOME;
  posY = SERVO_Y_HOME;

  servoX.write(posX);
  servoY.write(posY);

  Serial.begin(9600);
}

void loop() {
  int axisX = readAxis(AXIS_X_PIN);
  int axisY = readAxis(AXIS_Y_PIN);

  Serial.print(axisX, DEC);
  Serial.print(" - ");
  Serial.println(axisY, DEC);

  updateServoPosition(posX, axisX, SERVO_X_HOME, servoX);
  updateServoPosition(posY, axisY, SERVO_Y_HOME, servoY);

  delay(5);
}

void updateServoPosition(int &pos, int axisValue, int homePos, Servo &servo) {
  if (axisValue != 0) {

    pos += axisValue;

    int minPos = homePos - MAX_OFFSET;
    int maxPos = homePos + MAX_OFFSET;
    pos = constrain(pos, minPos, maxPos);

    servo.write(pos);
  }
}

int readAxis(int axisPin) {
  int reading = analogRead(axisPin);
  reading = map(reading, 0, 1023, 0, JOY_RANGE);

  int distance = reading - JOY_CENTER;
  if (abs(distance) < JOY_THRESHOLD) {
    distance = 0;
  }
  return distance;
}

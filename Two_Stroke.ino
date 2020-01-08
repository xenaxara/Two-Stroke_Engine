#include <Adafruit_NeoPixel.h>

// The Time the Solenoid will stay on if the engine stops when Solenoid HIGH
// This will overheat the Solenoid and melt the plastic
const int Solenoid = 7; // be sure to put a blocking diode across Solenoid coil
#define TOUT_SOLENOID       3000ul // Max time solenoid on when engine stopped
#define SOL_ANGLE_LOW       160    // Angle after solenoid HIGH
#define SOL_ANGLE_HIGH      280    // Angle after Solenoid LOW

const int PIN_DATA = 10; // Absolute Rotary Encoder Pins
const int PIN_CS = 9;    
const int PIN_CLOCK = 8; 

// Pixel numbers to set depending on how you wire up your Neopixels
const int C_P_Spark_Plug = 0;
const int C_P_Crank_Port_LED = 4;
const int C_P_Lower_top_left = 7;
const int C_P_Lower_top_mid = 6;
const int C_P_Lower_top_right = 5;
const int C_P_Lower_bot_left = 1;
const int C_P_Lower_bot_mid = 2;
const int C_P_Lower_bot_right = 3;
const int C_P_Below_Piston_top_left = 15;
const int C_P_Below_Piston_mid_left = 14;
const int C_P_Below_Piston_bot_left = 13;
const int C_P_Below_Piston_top_mid = 22;
const int C_P_Below_Piston_mid_mid = 23;
const int C_P_Below_Piston_bot_mid = 24;
const int C_P_Below_Piston_top_right = 27;
const int C_P_Below_Piston_mid_right = 26;
const int C_P_Below_Piston_bot_right = 25;
const int C_P_Fifth_of_Transfer_Tube = 12;
const int C_P_Fourth_of_Transfer_Tube = 11;
const int C_P_Third_of_Transfer_Tube = 10;
const int C_P_Second_of_Transfer_Tube = 9;
const int C_P_First_of_Transfer_Tube = 8;
const int C_P_Above_Piston_top_left = 18;
const int C_P_Above_Piston_mid_left = 17;
const int C_P_Above_Piston_bot_left = 16;
const int C_P_Above_Piston_top_mid = 19;
const int C_P_Above_Piston_mid_mid = 20;
const int C_P_Above_Piston_bot_mid = 21;
const int C_P_Above_Piston_top_right = 30;
const int C_P_Above_Piston_mid_right = 29;
const int C_P_Above_Piston_bot_right = 28;
const int C_P_Exhaust_Rear = 31;
const int C_P_Exhaust_Mid = 32;
const int C_P_Exhaust_Front = 33;

const int P_P_Spark_Plug = 0;
const int P_P_Lower_top_left = 6;
const int P_P_Lower_top_mid = 5;
const int P_P_Lower_top_right = 4;
const int P_P_Lower_bot_left = 1;
const int P_P_Lower_bot_mid = 2;
const int P_P_Lower_bot_right = 3;
const int P_P_Below_Piston_mid_left = 13;
const int P_P_Below_Piston_bot_left = 12;
const int P_P_Below_Piston_mid_mid = 20;
const int P_P_Below_Piston_bot_mid = 21;
const int P_P_Below_Piston_mid_right = 23;
const int P_P_Below_Piston_bot_right = 22;
const int P_P_Fifth_of_Transfer_Tube = 11;
const int P_P_Fourth_of_Transfer_Tube = 10;
const int P_P_Third_of_Transfer_Tube = 9;
const int P_P_Second_of_Transfer_Tube = 8;
const int P_P_First_of_Transfer_Tube = 7;
const int P_P_Above_Piston_top_left = 16;
const int P_P_Above_Piston_mid_left = 15;
const int P_P_Above_Piston_bot_left = 14;
const int P_P_Above_Piston_top_mid = 17;
const int P_P_Above_Piston_mid_mid = 18;
const int P_P_Above_Piston_bot_mid = 19;
const int P_P_Above_Piston_top_right = 26;
const int P_P_Above_Piston_mid_right = 25;
const int P_P_Above_Piston_bot_right = 24;
const int P_P_Exhaust_Rear = 27;
const int P_P_Exhaust_Mid = 28;
const int P_P_Exhaust_Front = 29;

const int V_P_Spark_Plug = 0;
const int V_P_Lower_top_left = 1;
const int V_P_Lower_top_mid = 2;
const int V_P_Lower_top_right = 3;
const int V_P_Lower_bot_left = 6;
const int V_P_Lower_bot_mid = 5;
const int V_P_Lower_bot_right = 4;
const int V_P_Below_Piston_top_left = 14;
const int V_P_Below_Piston_mid_left = 13;
const int V_P_Below_Piston_bot_left = 12;
const int V_P_Below_Piston_top_mid = 21;
const int V_P_Below_Piston_mid_mid = 22;
const int V_P_Below_Piston_bot_mid = 23;
const int V_P_Below_Piston_top_right = 26;
const int V_P_Below_Piston_mid_right = 25;
const int V_P_Below_Piston_bot_right = 24;
const int V_P_Fifth_of_Transfer_Tube = 11;
const int V_P_Fourth_of_Transfer_Tube = 10;
const int V_P_Third_of_Transfer_Tube = 9;
const int V_P_Second_of_Transfer_Tube = 8;
const int V_P_First_of_Transfer_Tube = 7;
const int V_P_Above_Piston_top_left = 17;
const int V_P_Above_Piston_mid_left = 16;
const int V_P_Above_Piston_bot_left = 15;
const int V_P_Above_Piston_top_mid = 18;
const int V_P_Above_Piston_mid_mid = 19;
const int V_P_Above_Piston_bot_mid = 20;
const int V_P_Above_Piston_top_right = 29;
const int V_P_Above_Piston_mid_right = 28;
const int V_P_Above_Piston_bot_right = 27;
const int V_P_Exhaust_Rear = 30;
const int V_P_Exhaust_Mid = 31;
const int V_P_Exhaust_Front = 32;


int Timing = 0; // variable to store timng value for NeoPixels
// or you could just turn the encoder / crankshaft pulley
                // Pixel Pins
#define LED_PIN_A    6  //  crankshaft port
#define LED_PIN_B    5  //  piston port
#define LED_PIN_C    4  //  vacuum port
#define TIMING_PIN   A1 //  POT for adjusting NeoPixels timing
#define SPEEDPIN     A5 //  POT for adjusting Motor Speed

// These pins are hardwired in the motor shield
const int MotorDir = 12;      //  output pin for the Motor Direction
const int MotorSpeed = 3;     //  output pin for the Motor Speed 

int MotorPot = 0;       //  variable to store the value coming from the Motor POT
int TimingPot = 0;      //  variable to store the value coming from the Timing POT

#define LED_COUNT_A  34 // Number of Neopixels in each Cylinder
#define LED_COUNT_B  30
#define LED_COUNT_C  33

Adafruit_NeoPixel CrankPort(LED_COUNT_A, LED_PIN_A, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel PistonPort(LED_COUNT_B, LED_PIN_B, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel VacuumPort(LED_COUNT_C, LED_PIN_C, NEO_RGBW + NEO_KHZ800);


void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_CS, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, INPUT);

  pinMode (MotorDir, OUTPUT);
  pinMode (TimingPot, INPUT);
  pinMode (MotorPot, INPUT);

  pinMode (Solenoid, OUTPUT);

  digitalWrite(PIN_CLOCK, HIGH);
  digitalWrite(PIN_CS, LOW);

  CrankPort.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  PistonPort.begin(); 
  VacuumPort.begin(); 
  CrankPort.show();  // Turn OFF all pixels ASAP
  PistonPort.show();
  VacuumPort.show();

}

void loop() 
{
 // This bit for the speed control for the Electric Motor

  digitalWrite(MotorDir, HIGH); // Motor direction
  int SpeedPin = analogRead(SPEEDPIN);
  int Speed = map(SpeedPin,0,1024,0,255);
  analogWrite (MotorSpeed, Speed);

  // Serial.print ("  Motor Direction  ");  Serial.print (digitalRead (MotorDir));
  // Serial.print (" SPEEDPIN  ");  Serial.print (analogRead (SPEEDPIN));
  // Serial.print (" Speed  ");  Serial.println(Speed);

  // This bit for the Absolute Rotary Encoder

  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
  int pos = 0;
  for (int i=0; i<10; i++) 
  {
    digitalWrite(PIN_CLOCK, LOW);
    digitalWrite(PIN_CLOCK, HIGH);

    byte b = digitalRead(PIN_DATA) == HIGH ? 1 : 0;
    pos += b * pow(2, 10-(i+1));
  }
  for (int i=0; i<6; i++) 
  {
    digitalWrite(PIN_CLOCK, LOW);
    digitalWrite(PIN_CLOCK, HIGH);
  }
  digitalWrite(PIN_CLOCK, LOW);
  digitalWrite(PIN_CLOCK, HIGH);

  int EncoderAngle = map(pos,0,1024, 0, 360);

  // This bit to adjust / tune the fine timing and 
  // keep the angle less than 360 degrees

  int AdjAngle = analogRead(TIMING_PIN);
  AdjAngle = map(AdjAngle, 0, 1024, 0, 360);

  int Angle = (AdjAngle + EncoderAngle);

  if (Angle >= 360) {
     (Angle -= 360);
  }
     // This bit for turning on the Solenoid
       DoSolenoid( Angle ); 
/*
  Serial.print("  Adjustment Angle  "); 
  Serial.print(AdjAngle);
  Serial.print(" Encoder Angle  "); 
  Serial.print(EncoderAngle);
  Serial.print(" Angle  "); 
  Serial.println(Angle);
  Serial.print( "   Solenoid  " );
  Serial.println (digitalRead (Solenoid));
*/
  // This bit is for the NeoPixels

  if (Angle > 0 && Angle <= 10)  { 
    //                              Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 200);        // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
     //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Lower_top_left, 10, 0, 0, 0);     // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 10, 0, 0, 0);      // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 10, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 10, 0, 0, 0);     // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 10, 0, 0, 0);      // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 10, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 5, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 5, 0, 0, 0);     // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 5, 0, 0, 0);     // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 5, 0, 0, 0);     // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 5, 0, 0, 0);   // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 5, 0, 0, 0);   // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 5, 0, 0, 0);   // Below Piston bot right
    //                                        Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    //                                            Green, Red, Blue, White 
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                            Green, Red, Blue, White 
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White 
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);              // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);               // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);             // Exhaust Front

    CrankPort.show();   
    //                                 Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                   Green, Red, Blue, White     
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 15, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 15, 0, 0, 0);    // Lower bot right
    //                                       Green, Red, Blue, White 
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White 
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left 
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White 
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    //                                   Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                   Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 11 && Angle <= 20) { 
    //                              Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
      //                                  Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                        Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 5, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 5, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show();     
    //                                 Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                      Green, Red, Blue, White     
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White 
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
    //                                          Green, Red, Blue, White     
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    //                                   Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                 Green, Red, Blue, White 
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 21 && Angle <= 30) {
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                   Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 5, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 5, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White      
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 6, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
    //                                          Green, Red, Blue, White   
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 10, 15, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 10, 15, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 10, 15, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 10, 15, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 10, 15, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 10, 15, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 31 && Angle <= 40) {  
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                   Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Lower_top_left, 6, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 6, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 6, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 6, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 6, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 6, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 6, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 6, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 6, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 6, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 6, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 6, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 6, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 6, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 6, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 6, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 6, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

    //                          Green, Red, Blue, White   
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White     
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 7, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 7, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White 
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White 
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 15, 20, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 15, 20, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 15, 20, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 15, 50, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 15, 20, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 15, 20, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White     
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White 
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front 

    VacuumPort.show();

  }

  if (Angle > 41 && Angle <= 50)  {  
    //                                 Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                   Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Lower_top_left, 7, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 7, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 7, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 7, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 7, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 7, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 7, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 7, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 7, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 7, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 7, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 7, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 7, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 7, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 100, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 100, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 100, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 5, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 5, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 5, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
    //                                          Green, Red, Blue, White 
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White 
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 51 && Angle <= 60)  {    
    //                                Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 100, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                    Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 8, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 8, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 8, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 8, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 8, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 8, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 8, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 8, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 8, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 8, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 8, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 8, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 8, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 8, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 100, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 100, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 100, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

    //                                          Green, Red, Blue, White  
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White   
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 5, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 5, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 5, 0);    // Below Piston bot right 
    //                                          Green, Red, Blue, White     
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
    //                                          Green, Red, Blue, White 
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White 
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    //                                          Green, Red, Blue, White   
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 61 && Angle <= 70)  {    
    //                                Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                    Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 9, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 9, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 9, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 9, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 9, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 9, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 9, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 9, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 9, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 9, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 9, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 9, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 9, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 9, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 10, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 10, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 10, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 10, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 10, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 10, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 71 && Angle <= 80)  {
    //                               Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                      Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 10, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 10, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 10, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 10, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 10, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 10, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 10, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 10, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 10, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 10, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 10, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 10, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 10, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 20, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 11, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 11, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 11, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 11, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 11, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 11, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 81 && Angle <= 90)  {   
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                    Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 11, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 11, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 11, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 11, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 11, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 11, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 11, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 11, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 11, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 11, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 11, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 20, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 12, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 12, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 12, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 91 && Angle <= 100)  {  
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                  Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 12, 0, 0, 0);   // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 12, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 12, 0, 0, 0);  // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 12, 0, 0, 0);   // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 12, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 12, 0, 0, 0);  // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);     // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);     // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);     // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);      // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);      // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);      // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 12, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 12, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 12, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 12, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 12, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);     // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);     // Above Piston bot right
    //                                    Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 20, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);      // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 40, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 13, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 13, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 13, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 101 && Angle <= 110)  {  
    //                              Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                     Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 15, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 40, 50, 0, 200);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 14, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 14, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 14, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 14, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 14, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 14, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show(); 

  }

  if (Angle > 111 && Angle <= 120)  {  
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                    Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                    Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                    Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                   Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 20, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 200);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 15, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 15, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 15, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 121 && Angle <= 130)  {  
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 20, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 15, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 15, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 15, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 131 && Angle <= 140)  {      
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                      Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 15, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 15, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 15, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 15, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 15, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 15, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 141 && Angle <= 150)  {   
    //                               Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 15, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 15, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 15, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 5, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 5, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 151 && Angle <= 160)  {    
    //                                   Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
     //                                      Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
     //                                          Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 100, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 100, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 100, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 10, 15, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 10, 15, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 10, 15, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 10, 15, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 10, 15, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 10, 15, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 161 && Angle <= 170)  {      
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                   Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
     //                                          Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                   Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 100, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 8, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 8, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 8, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 8, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 8, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 8, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 10, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 10, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 10, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 10, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 10, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 10, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 8, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 8, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 8, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 8, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 8, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 100, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 100, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 100, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 5, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 5, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 5, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 15, 20, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 15, 20, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 15, 20, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 15, 20, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 15, 20, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 15, 20, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 171 && Angle <= 180)  {     
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 0, 0);    // Crank Port LED
    //                                    Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
     //                                          Green, Red, Blue, White
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 15, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 15, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 15, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 15, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 15, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 15, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 15, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 15, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 15, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 15, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 15, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 15, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 9, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 9, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 9, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 9, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 9, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 10, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 10, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 10, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 5, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 5, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 5, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 5, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 5, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }
  if (Angle > 181 && Angle <= 190)  {   
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 20, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 20, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 20, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 20, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 20, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 20, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 20, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 20, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(C_P_Above_Piston_mid_mid, 20, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 20, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 20, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 20, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 10, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 10, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 10, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 10, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 10, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 10, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 10, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 20, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 5, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 5, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 5, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 191 && Angle <= 200)  {  
    //                                     Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                   Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 25, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 25, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 25, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 25, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 25, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 25, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 25, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 25, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 25, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 25, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 25, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 25, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 11, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 11, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 11, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 11, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 11, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 20, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 5, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 5, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 5, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 201 && Angle <= 210)  {   
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                   Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 12, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 12, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 12, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 12, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 12, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 12, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 12, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 12, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 12, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 12, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 12, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 20, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 5, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 5, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 5, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 5, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 5, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 211 && Angle <= 220)  {   
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                      Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 5, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 13, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 13, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 15, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 5, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 5, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 5, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 221 && Angle <= 230)  {   
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 5, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 15, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 15, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 20, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 5, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 5, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 5, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 231 && Angle <= 240)  {  
    //                                Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                    Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 20, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 200);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 5, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 5, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 5, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 5, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 5, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 5, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 5, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 5, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 5, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 5, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 5, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 241 && Angle <= 250)  {   
    //                                Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 5, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 5, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 5, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 5, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 5, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 5, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 5, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 5, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 5, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 5, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 5, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 5, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 5, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 251 && Angle <= 260)  {
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                    Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 5, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 5, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                         Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 5, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 5, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 261 && Angle <= 270)  {
    //                                Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 5, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 5, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 5, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                   Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 6, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 5, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 5, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 200, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 200, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 200, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 271 && Angle <= 280)  {   
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 6, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 6, 0);    // Lower bot right
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 6, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 10, 15, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 10, 15, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 10, 15, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 10, 15, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 10, 15, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 10, 15, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 15, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 15, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 200, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 5, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 5, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 100, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 100, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 100, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 281 && Angle <= 290)  {    
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 7, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 7, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 7, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 15, 20, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 15, 20, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 15, 20, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 15, 20, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 15, 20, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 15, 20, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 15, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 15, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 100, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 5, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 5, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 100, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 100, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 100, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 291 && Angle <= 300)  { 
    //                                  Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 8, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 8, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 8, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                 Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 15, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 15, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 50, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 5, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 5, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 5, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 10, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 10, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 10, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 301 && Angle <= 310)  {    
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 9, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 9, 0);    // Lower bot right
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 9, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 9, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                Green, Red, Blue, White     
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 15, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 15, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 20, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 10, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 10, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 20, 0, 0);    // Exhaust Front

    VacuumPort.show();
  }

  if (Angle > 311 && Angle <= 320)  {   
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 10, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 10, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 10, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 10, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 15, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 15, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 10, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 20, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 321 && Angle <= 330)  {  
    //                                  Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 15, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 15, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 5, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 5, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 5, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 5, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 5, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 5, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 5, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 10, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 20, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 331 && Angle <= 340)  { 
    //                                    Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White        
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 12, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 12, 0);    // Lower bot right
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 12, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 12, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 12, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                  Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 15, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 15, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 5, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 5, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 5, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 20, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 5, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 5, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 15, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 15, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 15, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 341 && Angle <= 350)  {   
    //                                   Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 0);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 13, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 13, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 13, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 13, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 13, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                                    Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 15, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 15, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 5, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 0, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 5, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 0, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 5, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 0, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 15, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 0, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 5, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 5, 0, 0, 0);    // Above Piston bot mid
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 20, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }

  if (Angle > 351 && Angle <= 359)  {     
    //                                 Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Spark_Plug, 40, 50, 0, 200);    // Spark Plug
    CrankPort.setPixelColor(C_P_Crank_Port_LED, 0, 0, 200, 0);    // Crank Port LED
    //                                          Green, Red, Blue, White    
    CrankPort.setPixelColor(C_P_Lower_top_left, 0, 0, 14, 0);    // Lower top left
    CrankPort.setPixelColor(C_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    CrankPort.setPixelColor(C_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    CrankPort.setPixelColor(C_P_Lower_bot_left, 0, 0, 14, 0);    // Lower bot left
    CrankPort.setPixelColor(C_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    CrankPort.setPixelColor(C_P_Lower_bot_right, 0, 0, 10, 0);    // Lower bot right
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Below_Piston_top_left, 0, 0, 14, 0);    // Below Piston top left
    CrankPort.setPixelColor(C_P_Below_Piston_mid_left, 0, 0, 14, 0);    // Below Piston mid left 
    CrankPort.setPixelColor(C_P_Below_Piston_bot_left, 0, 0, 14, 0);    // Below Piston bot left
    CrankPort.setPixelColor(C_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    CrankPort.setPixelColor(C_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    CrankPort.setPixelColor(C_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    CrankPort.setPixelColor(C_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    CrankPort.setPixelColor(C_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    CrankPort.setPixelColor(C_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White      
    CrankPort.setPixelColor(C_P_Fifth_of_Transfer_Tube, 0, 0, 5, 0);     // Top of Transfer tube
    CrankPort.setPixelColor(C_P_Fourth_of_Transfer_Tube, 0, 0, 5, 0);      
    CrankPort.setPixelColor(C_P_Third_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_Second_of_Transfer_Tube, 0, 0, 5, 0);
    CrankPort.setPixelColor(C_P_First_of_Transfer_Tube, 0, 0, 5, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_left, 20, 25, 0, 0);    // Above Piston top left
    CrankPort.setPixelColor(C_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    CrankPort.setPixelColor(C_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    CrankPort.setPixelColor(C_P_Above_Piston_top_mid, 20, 25, 0, 0);    // Above Piston top mid
    CrankPort.setPixelColor(C_P_Above_Piston_mid_mid, 0, 0, 0, 0);    // Above Piston mid mid
    CrankPort.setPixelColor(C_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White   
    CrankPort.setPixelColor(C_P_Above_Piston_top_right, 20, 25, 0, 0);    // Above Piston top right
    CrankPort.setPixelColor(C_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    CrankPort.setPixelColor(C_P_Above_Piston_bot_right, 0, 0, 0, 0);    // Above Piston bot right
    //                               Green, Red, Blue, White       
    CrankPort.setPixelColor(C_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear
    CrankPort.setPixelColor(C_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    CrankPort.setPixelColor(C_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    CrankPort.show(); 

     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Lower_top_left, 15, 0, 0, 0);    // Lower top left
    PistonPort.setPixelColor(P_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    PistonPort.setPixelColor(P_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    PistonPort.setPixelColor(P_P_Lower_bot_left, 15, 0, 0, 0);    // Lower bot left
    PistonPort.setPixelColor(P_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    PistonPort.setPixelColor(P_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
     //                                          Green, Red, Blue, White
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top left
    PistonPort.setPixelColor(P_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    PistonPort.setPixelColor(P_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    //PistonPort.setPixelColor(9999, 0, 0, 0, 10);    // Below Piston top mid
    PistonPort.setPixelColor(P_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    PistonPort.setPixelColor(P_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    //PistonPort.setPixelColor(9999, 0, 0, 0, 0);    // Below Piston top right 
    PistonPort.setPixelColor(P_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    PistonPort.setPixelColor(P_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right 
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    PistonPort.setPixelColor(P_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    PistonPort.setPixelColor(P_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    PistonPort.setPixelColor(P_P_First_of_Transfer_Tube, 0, 0, 0, 0);    // Bottom of Transfer tube
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    PistonPort.setPixelColor(P_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    PistonPort.setPixelColor(P_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left 
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    PistonPort.setPixelColor(P_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    PistonPort.setPixelColor(P_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
     //                                          Green, Red, Blue, White
    PistonPort.setPixelColor(P_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right 
    PistonPort.setPixelColor(P_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    PistonPort.setPixelColor(P_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White    
    PistonPort.setPixelColor(P_P_Exhaust_Rear, 0, 0, 0, 0);    // Exhaust Rear 
    PistonPort.setPixelColor(P_P_Exhaust_Mid, 20, 0, 0, 0);    // Exhaust Middle 
    PistonPort.setPixelColor(P_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    PistonPort.show();

    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Spark_Plug, 0, 0, 0, 0);    // Spark Plug
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Lower_top_left, 5, 0, 0, 0);    // Lower top left
    VacuumPort.setPixelColor(V_P_Lower_top_mid, 0, 0, 0, 0);    // Lower top mid
    VacuumPort.setPixelColor(V_P_Lower_top_right, 0, 0, 0, 0);    // Lower top right
    VacuumPort.setPixelColor(V_P_Lower_bot_left, 5, 0, 0, 0);    // Lower bot left
    VacuumPort.setPixelColor(V_P_Lower_bot_mid, 0, 0, 0, 0);    // Lower bot mid
    VacuumPort.setPixelColor(V_P_Lower_bot_right, 0, 0, 0, 0);    // Lower bot right
    // Pixel No. Green, Red, Blue, White
    VacuumPort.setPixelColor(V_P_Below_Piston_top_left, 0, 0, 0, 0);    // Below Piston top left
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_left, 0, 0, 0, 0);    // Below Piston mid left 
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_left, 0, 0, 0, 0);    // Below Piston bot left
    VacuumPort.setPixelColor(V_P_Below_Piston_top_mid, 0, 0, 0, 0);    // Below Piston top mid
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_mid, 0, 0, 0, 0);    // Below Piston mid mid
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_mid, 0, 0, 0, 0);    // Below Piston bot mid
    VacuumPort.setPixelColor(V_P_Below_Piston_top_right, 0, 0, 0, 0);    // Below Piston top right 
    VacuumPort.setPixelColor(V_P_Below_Piston_mid_right, 0, 0, 0, 0);    // Below Piston mid right
    VacuumPort.setPixelColor(V_P_Below_Piston_bot_right, 0, 0, 0, 0);    // Below Piston bot right
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Fifth_of_Transfer_Tube, 0, 0, 0, 0);     // Top of Transfer tube
    VacuumPort.setPixelColor(V_P_Fourth_of_Transfer_Tube, 15, 0, 0, 0);      
    VacuumPort.setPixelColor(V_P_Third_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_Second_of_Transfer_Tube, 0, 0, 0, 0);
    VacuumPort.setPixelColor(V_P_First_of_Transfer_Tube, 15, 0, 0, 0);    // Bottom of Transfer tube
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Above_Piston_top_left, 5, 0, 0, 0);    // Above Piston top left
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_left, 0, 0, 0, 0);    // Above Piston mid left
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_left, 0, 0, 0, 0);    // Above Piston bot left
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Above_Piston_top_mid, 0, 0, 0, 0);    // Above Piston top mid
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_mid, 5, 0, 0, 0);    // Above Piston mid mid
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_mid, 0, 0, 0, 0);    // Above Piston bot mid
    //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Above_Piston_top_right, 0, 0, 0, 0);    // Above Piston top right
    VacuumPort.setPixelColor(V_P_Above_Piston_mid_right, 0, 0, 0, 0);    // Above Piston mid right
    VacuumPort.setPixelColor(V_P_Above_Piston_bot_right, 5, 0, 0, 0);    // Above Piston bot right
     //                                          Green, Red, Blue, White  
    VacuumPort.setPixelColor(V_P_Exhaust_Rear, 0, 20, 0, 0);    // Exhaust Rear
    VacuumPort.setPixelColor(V_P_Exhaust_Mid, 0, 0, 0, 0);    // Exhaust Middle
    VacuumPort.setPixelColor(V_P_Exhaust_Front, 0, 0, 0, 0);    // Exhaust Front

    VacuumPort.show();

  }
}
#define ST_OFF          0
#define ST_ON           1
#define ST_RESET        2
//
void DoSolenoid( int Angle )
{
    unsigned long
        timeNow;
    static unsigned long
        timeSolenoid;
    static byte
        stateSolenoid = ST_OFF;

    timeNow = millis();
    switch( stateSolenoid )
    {
        case    ST_OFF:
            //solenoid is LOW now. Is the angle correct to turn it HIGH?
            if( Angle > SOL_ANGLE_LOW && Angle <= SOL_ANGLE_HIGH )
            {
                //yes; set pin HIGH
                digitalWrite( Solenoid, HIGH );       
                //grab millis count now
                timeSolenoid = timeNow;
                //and move to ON state
                stateSolenoid = ST_ON;
               
            }//if
           
        break;

        case    ST_ON:
            //is ON now; has it been HIGH too long?
            if( timeNow - timeSolenoid >= TOUT_SOLENOID )
            {
                //yes, shut it LOW and move to reset state
                digitalWrite( Solenoid, LOW );
                stateSolenoid = ST_RESET;                                       
            }//if
            //not HIGH too long yet; still within valid angle?
            else if( Angle <= SOL_ANGLE_LOW || Angle > SOL_ANGLE_HIGH )
            {
                //no; turn it LOW and return to LOW state
                digitalWrite( Solenoid, LOW );
                stateSolenoid = ST_OFF;                                       
                               
            }//else
       
        break;

        case    ST_RESET:
            //solenoid was HIGH too long. Wait until angle reading shows "LOW" before
            //returning to top of state machine
            if( Angle <= SOL_ANGLE_LOW || Angle > SOL_ANGLE_HIGH )
                stateSolenoid = ST_OFF;                                       
               
        break;
       
    }//switch
   
}



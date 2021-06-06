
//**************************************************************************
int Sieve_A_Valve = 7; //Defined Pin as Variable
int Sieve_B_Valve = 6; //Defined Pin as Variable
int PreCharge_Valve = 2; //Defined Pin as Variable


//unsigned long Relay_Test_Delay; //delay variable creation
//unsigned long Startup_Purge_Delay; //delay variable creation
unsigned long Production_Delay; //delay variable creation
unsigned long Flush_Delay; //delay variable creation
unsigned long PreCharge_Delay; //delay variable creation

//**************************************************************************
void setup()
{


  Serial.begin(9600);


  // SET PIN MODE FOR PINS IN PROGRAM
  //**************************************************************************
  pinMode(Sieve_A_Valve, OUTPUT);
  pinMode(Sieve_B_Valve, OUTPUT);
  pinMode(PreCharge_Valve, OUTPUT);
  //pinMode(Fan, OUTPUT);


  //  SET DELAY TIMING HERE
  //**************************************************************************
  //Relay_Test_Delay = 0;
  //Startup_Purge_Delay = 1000;
  Production_Delay = 3500;
  Flush_Delay = 450;
  PreCharge_Delay = 700;

}

void loop()
{

  //CYCLE 1
  //**************************************************************************
  Serial.println("Sieve A Charge / Sieve B Purge");
  digitalWrite(Sieve_A_Valve, LOW);
  digitalWrite(Sieve_B_Valve, HIGH );
  digitalWrite(PreCharge_Valve, HIGH);
  delay(Production_Delay);


  //CYCLE 2
  //**************************************************************************
  Serial.println("Sieve A Charge / Sieve B Purge / Flush/PreCharge");
  digitalWrite(Sieve_A_Valve, LOW);
  digitalWrite(Sieve_B_Valve, HIGH);
  digitalWrite(PreCharge_Valve, LOW);
  delay(Flush_Delay) ;

  //CYCLE 3
  //**************************************************************************
  Serial.println("Sieve A Charge / Sieve B Charge / Flush/PreCharge");
  digitalWrite(Sieve_A_Valve, LOW);
  digitalWrite(Sieve_B_Valve, LOW);
  digitalWrite(PreCharge_Valve, LOW);
  delay(PreCharge_Delay);

  //CYCLE 4
  //**************************************************************************
  Serial.println("Sieve A Purge / Sieve B Charge");
  digitalWrite(Sieve_A_Valve, HIGH);
  digitalWrite(Sieve_B_Valve, LOW);
  digitalWrite(PreCharge_Valve, HIGH);
  delay(Production_Delay);

  //CYCLE 5
  //**************************************************************************
  Serial.println("Sieve A Purge / Sieve B Charge / Flush/PreCharge");
  digitalWrite(Sieve_A_Valve, HIGH);
  digitalWrite(Sieve_B_Valve, LOW);
  digitalWrite(PreCharge_Valve, LOW);
  delay(Flush_Delay);


  //CYCLE 6
  //**************************************************************************
  Serial.println("Sieve A Charge / Sieve B Charge / Flush/PreCharge");
  digitalWrite(Sieve_A_Valve, LOW);
  digitalWrite(Sieve_B_Valve, LOW);
  digitalWrite(PreCharge_Valve, LOW);
  delay(PreCharge_Delay) ;

} 

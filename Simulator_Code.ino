// C++ code
// SOS Morse Code LED Blinking Simulation Project

// Initialising necessary variables
int powerLED = 13, dotLED = 12, dashLED = 8, unitTime = 300;
String message;

void setup()
{
  // Setting the LED pins as Output
  pinMode(powerLED, OUTPUT);
  pinMode(dotLED, OUTPUT);
  pinMode(dashLED, OUTPUT);
  
  Serial.begin(9600);	// Starting the Serial Port
  
  // Setup animation
  digitalWrite(powerLED, HIGH);
  delay(600);
  digitalWrite(dotLED, HIGH);
  delay(600);
  digitalWrite(dashLED, HIGH);
  delay(600);
  digitalWrite(powerLED, LOW);
  digitalWrite(dotLED, LOW);
  digitalWrite(dashLED, LOW);
  delay(300);
  digitalWrite(powerLED, HIGH);
  digitalWrite(dotLED, HIGH);
  digitalWrite(dashLED, HIGH);
  delay(300);
  digitalWrite(powerLED, LOW);
  digitalWrite(dotLED, LOW);
  digitalWrite(dashLED, LOW);
}

void loop()
{
  // Asking for the text by the user
  Serial.print("Enter your mesage: ");
  while (!(Serial.available())) {}
  message = Serial.readString();
  Serial.println(message);
  Serial.println("Powering on...");
  delay(3*unitTime);
  Serial.println("Converting...");
  delay(3*unitTime);
  digitalWrite(powerLED, HIGH);
  
  // Converting the message to SOS
  message.toLowerCase();
  String sosCode, sosMessage = "", demo = "";	// Initializing variable to store SOS converted message
  
  // Displaying the code
  for (int i=0; i < message.length(); i++) { demo += encoder(message[i]); }
  Serial.println("Your desired output SOS code is: " + demo);
  
  // Simulating LEDs
  for (int i=0; i < message.length(); i++) {
    
    sosCode = encoder(message[i]);	// Converting each letter
    Serial.println("Blinking for (" + sosCode + ")");
    sosMessage += sosCode;			// SOS message
      
    for (int j=0; j < sosCode.length(); j++) {
      
      if (sosCode[j] == '.') {
        digitalWrite(dotLED, HIGH);
        delay(unitTime);
        digitalWrite(dotLED, LOW);
      } else if (sosCode[j] == '-') {
        digitalWrite(dashLED, HIGH);
        delay(3*unitTime);
        digitalWrite(dashLED, LOW);
      } else {
        delay(4*unitTime);
      }
      delay(unitTime);
      
    }
    
    delay(3*unitTime);
    
  }
  
  digitalWrite(powerLED, LOW);
}

// Defining encoder function to take letter as input and return SOS code as output
String encoder(char letter) {
	switch (letter) {
      case 'a': return ".-"; 
      case 'b': return "-..."; 
      case 'c': return "-.-."; 
      case 'd': return "-.."; 
      case 'e': return ".";
      case 'f': return "..-.";
      case 'g': return "--.";
      case 'h': return "....";
      case 'i': return "..";
      case 'j': return ".---";
      case 'k': return "-.-";
      case 'l': return ".-..";
      case 'm': return "--";
      case 'n': return "-.";
      case 'o': return "---";
      case 'p': return ".--.";
      case 'q': return "--.-";
      case 'r': return ".-.";
      case 's': return "...";
      case 't': return "-";
      case 'u': return "..-"; 
      case 'v': return "...-"; 
      case 'w': return ".--"; 
      case 'x': return "-..-"; 
      case 'y': return "-.--"; 
      case 'z': return "--.."; 

      case '0': return "-----"; 
      case '1': return ".----"; 
      case '2': return "..---"; 
      case '3': return "...--"; 
      case '4': return "....-"; 
      case '5': return "....."; 
      case '6': return "-...."; 
      case '7': return "--..."; 
      case '8': return "---.."; 
      case '9': return "----."; 
      
      default: return " ";
    }
}
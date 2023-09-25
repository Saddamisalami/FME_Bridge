#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int busyPin = 9;
const int rxPin = 10;
const int txPin = 11;
SoftwareSerial mySoftwareSerial(rxPin, txPin); // RX, TX

DFRobotDFPlayerMini myDFPlayer;

const int folderSpeechStreet = 1;
const int folderSpeechCity = 2;
const int folderSpeechPLZ = 3;
const int folderSpeechLetters = 4;
const int folderSpeechNumbers = 5;

const int numbersSpeechMax = 15;
int numbersSpeechValues[numbersSpeechMax] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const int letterSpeechMax = 5;
int letterSpeechValues[letterSpeechMax] = {0, 0, 0, 0, 0};

const int track_0 = 1;
const int track_1 = 2;
const int track_2 = 3;
const int track_3 = 4;
const int track_4 = 5;
const int track_5 = 6;
const int track_6 = 7;
const int track_7 = 8;
const int track_8 = 9;
const int track_9 = 10;
const int track_ein = 11;
const int track_elf = 12;
const int track_hundert = 13;
const int track_sech = 14;
const int track_sieb = 15;
const int track_tausend = 16;
const int track_und = 17;
const int track_zehn = 18;
const int track_zig = 19;
const int track_zwan = 20;
const int track_zwoelf = 21;

const int track_a = 1;
const int track_b = 2;
const int track_c = 3;
const int track_d = 4;
const int track_e = 5;
const int track_f = 6;
const int track_g = 7;
const int track_h = 8;
const int track_i = 9;
const int track_j = 10;
const int track_k = 11;
const int track_l = 12;
const int track_m = 13;
const int track_n = 14;
const int track_o = 15;
const int track_p = 16;
const int track_q = 17;
const int track_r = 18;
const int track_s = 19;
const int track_t = 20;
const int track_u = 21;
const int track_v = 22;
const int track_w = 23;
const int track_x = 24;
const int track_y = 25;
const int track_z = 26;
const int track_ae = 27;
const int track_oe = 28;
const int track_ue = 29;
const int track_ss = 30;

void printDetail(uint8_t type, int value)
{
  switch (type)
  {
  case TimeOut:
    Serial.println(F("Time Out!"));
    break;
  case WrongStack:
    Serial.println(F("Stack Wrong!"));
    break;
  case DFPlayerCardInserted:
    Serial.println(F("Card Inserted!"));
    break;
  case DFPlayerCardRemoved:
    Serial.println(F("Card Removed!"));
    break;
  case DFPlayerCardOnline:
    Serial.println(F("Card Online!"));
    break;
  case DFPlayerPlayFinished:
    Serial.print(F("Number:"));
    Serial.print(value);
    Serial.println(F(" Play Finished!"));
    break;
  case DFPlayerError:
    Serial.print(F("DFPlayerError:"));
    switch (value)
    {
    case Busy:
      Serial.println(F("Card not found"));
      break;
    case Sleeping:
      Serial.println(F("Sleeping"));
      break;
    case SerialWrongStack:
      Serial.println(F("Get Wrong Stack"));
      break;
    case CheckSumNotMatch:
      Serial.println(F("Check Sum Not Match"));
      break;
    case FileIndexOut:
      Serial.println(F("File Index Out of Bound"));
      break;
    case FileMismatch:
      Serial.println(F("Cannot Find File"));
      break;
    case Advertise:
      Serial.println(F("In Advertise"));
      break;
    default:
      break;
    }
    break;
  default:
    break;
  }
}

void playPLZ(uint32_t plz)
{
  myDFPlayer.playFolder(folderSpeechPLZ, plz);
}

void playCity(uint32_t city)
{
  myDFPlayer.playFolder(folderSpeechCity, city);
}

void playStreet(uint32_t street)
{
  myDFPlayer.playMp3Folder(street);
}

void playLetters(String letters)
{
  uint32_t speechCounter = 0;
  letters.toLowerCase();
  for (int i = 0; i < letterSpeechMax; i++)
  {
    letterSpeechValues[i] = 0;
  }

  int lettersLength = letters.length();
  for (int x = 0; x < lettersLength; x++)
  {
    char character = letters.charAt(x);
    if (character == 'a')
    {
      letterSpeechValues[speechCounter] = track_a;
    }
    else if (character == 'b')
    {
      letterSpeechValues[speechCounter] = track_b;
    }
    else if (character == 'c')
    {
      letterSpeechValues[speechCounter] = track_c;
    }
    else if (character == 'd')
    {
      letterSpeechValues[speechCounter] = track_d;
    }
    else if (character == 'e')
    {
      letterSpeechValues[speechCounter] = track_e;
    }
    else if (character == 'f')
    {
      letterSpeechValues[speechCounter] = track_f;
    }
    else if (character == 'g')
    {
      letterSpeechValues[speechCounter] = track_g;
    }
    else if (character == 'h')
    {
      letterSpeechValues[speechCounter] = track_h;
    }
    else if (character == 'i')
    {
      letterSpeechValues[speechCounter] = track_i;
    }
    else if (character == 'j')
    {
      letterSpeechValues[speechCounter] = track_j;
    }
    else if (character == 'k')
    {
      letterSpeechValues[speechCounter] = track_k;
    }
    else if (character == 'l')
    {
      letterSpeechValues[speechCounter] = track_l;
    }
    else if (character == 'm')
    {
      letterSpeechValues[speechCounter] = track_m;
    }
    else if (character == 'n')
    {
      letterSpeechValues[speechCounter] = track_n;
    }
    else if (character == 'o')
    {
      letterSpeechValues[speechCounter] = track_o;
    }
    else if (character == 'p')
    {
      letterSpeechValues[speechCounter] = track_p;
    }
    else if (character == 'q')
    {
      letterSpeechValues[speechCounter] = track_q;
    }
    else if (character == 'r')
    {
      letterSpeechValues[speechCounter] = track_r;
    }
    else if (character == 's')
    {
      letterSpeechValues[speechCounter] = track_s;
    }
    else if (character == 't')
    {
      letterSpeechValues[speechCounter] = track_t;
    }
    else if (character == 'u')
    {
      letterSpeechValues[speechCounter] = track_u;
    }
    else if (character == 'v')
    {
      letterSpeechValues[speechCounter] = track_v;
    }
    else if (character == 'w')
    {
      letterSpeechValues[speechCounter] = track_w;
    }
    else if (character == 'x')
    {
      letterSpeechValues[speechCounter] = track_x;
    }
    else if (character == 'y')
    {
      letterSpeechValues[speechCounter] = track_y;
    }
    else if (character == 'z')
    {
      letterSpeechValues[speechCounter] = track_z;
    }
   /*else if (character == 'ä')
    {
      letterSpeechValues[speechCounter] = track_ae;
    }
    else if (character == 'ö')
    {
      letterSpeechValues[speechCounter] = track_oe;
    }
    else if (character == 'ü')
    {
      letterSpeechValues[speechCounter] = track_ue;
    }
    else if (character == 'ß')
    {
      letterSpeechValues[speechCounter] = track_ss;
    }*/
    else
    {
    }
    speechCounter = speechCounter + 1;
  }

  for (int i = 0; i < letterSpeechMax; i++)
  {
    int speechFile = letterSpeechValues[i];

    if (speechFile > 0)
    {
      myDFPlayer.playFolder(folderSpeechLetters, speechFile);
      while (digitalRead(busyPin) == HIGH)
      {
      }
      while (digitalRead(busyPin) == LOW)
      {
      }
    }
  }
}

void playNumbers(uint32_t numbers)
{
  for (int i = 0; i < numbersSpeechMax; i++)
  {
    numbersSpeechValues[i] = 0;
  }

  uint32_t speechCounter = 0;
  uint32_t hunderttausender = (numbers / 100000) % 10;
  uint32_t zehntausender = (numbers / 10000) % 10;
  uint32_t tausender = (numbers / 1000) % 10;
  uint32_t hundertder = (numbers / 100) % 10;
  uint32_t zehner = (numbers / 10) % 10;
  uint32_t einer = numbers % 10;
  // Serial.print(hunderttausender);
  // Serial.print(zehntausender);
  // Serial.print(tausender);
  // Serial.print(hundertder);
  // Serial.print(zehner);
  // Serial.println(einer);

  if (hunderttausender != 0)
  {
    switch (hunderttausender)
    {
    case 1:
      numbersSpeechValues[speechCounter] = track_ein;
      break;
    case 2:
      numbersSpeechValues[speechCounter] = track_2;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_6;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_7;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_hundert;
    speechCounter = speechCounter + 1;
  }
  // 10
  if (zehntausender == 1 && tausender == 0)
  {
    numbersSpeechValues[speechCounter] = track_zehn;
    speechCounter = speechCounter + 1;
  }
  // 11
  else if (zehntausender == 1 && tausender == 1)
  {
    numbersSpeechValues[speechCounter] = track_elf;
    speechCounter = speechCounter + 1;
  }
  // 12
  else if (zehntausender == 1 && tausender == 2)
  {
    numbersSpeechValues[speechCounter] = track_zwoelf;
    speechCounter = speechCounter + 1;
  }
  // 13 - 19
  else if (zehntausender == 1 && tausender > 2)
  {
    switch (hunderttausender)
    {
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_sech;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_sieb;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_zehn;
    speechCounter = speechCounter + 1;
  }
  // 20,30,40,50,60,70,80,90
  else if (zehntausender > 1 && tausender == 0)
  {
    switch (zehntausender)
    {
    case 2:
      numbersSpeechValues[speechCounter] = track_zwan;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_sech;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_sieb;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_zig;
    speechCounter = speechCounter + 1;
  }
  // 21 -99
  else if (zehntausender != 0 && tausender != 0)
  {
    switch (tausender)
    {
    case 1:
      numbersSpeechValues[speechCounter] = track_ein;
      break;
    case 2:
      numbersSpeechValues[speechCounter] = track_2;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_6;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_7;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_und;
    speechCounter = speechCounter + 1;
    switch (zehntausender)
    {
    case 2:
      numbersSpeechValues[speechCounter] = track_zwan;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_sech;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_sieb;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_zig;
    speechCounter = speechCounter + 1;
  }
  else
  {
    switch (tausender)
    {
    case 1:
      numbersSpeechValues[speechCounter] = track_ein;
      break;
    case 2:
      numbersSpeechValues[speechCounter] = track_2;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_6;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_7;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
  }
  if (hunderttausender != 0 || zehntausender != 0 || tausender != 0)
  {
    numbersSpeechValues[speechCounter] = track_tausend;
    speechCounter = speechCounter + 1;
  }
  if (hundertder != 0)
  {
    switch (hundertder)
    {
    case 1:
      numbersSpeechValues[speechCounter] = track_ein;
      break;
    case 2:
      numbersSpeechValues[speechCounter] = track_2;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_6;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_7;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_hundert;
    speechCounter = speechCounter + 1;
  }

  if (zehner == 1 && einer == 0)
  {
    numbersSpeechValues[speechCounter] = track_zehn;
    speechCounter = speechCounter + 1;
  }
  // 11
  else if (zehner == 1 && einer == 1)
  {
    numbersSpeechValues[speechCounter] = track_elf;
    speechCounter = speechCounter + 1;
  }
  // 12
  else if (zehner == 1 && einer == 2)
  {
    numbersSpeechValues[speechCounter] = track_zwoelf;
    speechCounter = speechCounter + 1;
  }
  // 13 - 19
  else if (zehner == 1 && einer > 2)
  {
    switch (einer)
    {
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_sech;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_sieb;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_zehn;
    speechCounter = speechCounter + 1;
  }
  // 20,30,40,50,60,70,80,90
  else if (zehner > 1 && einer == 0)
  {
    switch (zehner)
    {
    case 2:
      numbersSpeechValues[speechCounter] = track_zwan;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_sech;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_sieb;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_zig;
    speechCounter = speechCounter + 1;
  }
  // 21 -99
  else if (zehner != 0 && einer != 0)
  {
    switch (einer)
    {
    case 1:
      numbersSpeechValues[speechCounter] = track_ein;
      break;
    case 2:
      numbersSpeechValues[speechCounter] = track_2;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_6;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_7;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_und;
    speechCounter = speechCounter + 1;
    switch (zehner)
    {
    case 2:
      numbersSpeechValues[speechCounter] = track_zwan;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_sech;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_sieb;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
    numbersSpeechValues[speechCounter] = track_zig;
    speechCounter = speechCounter + 1;
  }
  else if (einer != 0)
  {
    switch (einer)
    {
    case 1:
      numbersSpeechValues[speechCounter] = track_1;
      break;
    case 2:
      numbersSpeechValues[speechCounter] = track_2;
      break;
    case 3:
      numbersSpeechValues[speechCounter] = track_3;
      break;
    case 4:
      numbersSpeechValues[speechCounter] = track_4;
      break;
    case 5:
      numbersSpeechValues[speechCounter] = track_5;
      break;
    case 6:
      numbersSpeechValues[speechCounter] = track_6;
      break;
    case 7:
      numbersSpeechValues[speechCounter] = track_7;
      break;
    case 8:
      numbersSpeechValues[speechCounter] = track_8;
      break;
    case 9:
      numbersSpeechValues[speechCounter] = track_9;
      break;
    default:
      break;
    }
    speechCounter = speechCounter + 1;
  }
  else
  {
    numbersSpeechValues[speechCounter] = track_0;
  }
  for (int i = 0; i < numbersSpeechMax; i++)
  {
    int speechFile = numbersSpeechValues[i];
    if (speechFile > 0)
    {
      myDFPlayer.playFolder(folderSpeechNumbers, speechFile);
      while (digitalRead(busyPin) == HIGH)
      {
      }
      while (digitalRead(busyPin) == LOW)
      {
      }
    }
  }
}

void setup()
{
  pinMode(busyPin, INPUT);
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial))
  { // Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true)
      ;
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); // Set serial communictaion time out 500ms
  myDFPlayer.volume(30);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
 
  //playStreet(727);
}

void loop()
{
  playPLZ(3);
  delay(2000);
  playCity(5);
  delay(2000);
  playStreet(727);
  delay(2000);
  playNumbers(13);
  delay(2000);
  playLetters("A");
}
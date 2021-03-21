
//READ THIS
//THIS CODE RUNS IN THE SERIAL MONITOR
//baud rate is 9600
//return setting is Newline
//dont attach any wires to the arduino
//numsys is the character decoder. it holds all the base 64 characters, but if i put them out of order you can copy the correct one and paste it into numsys.
//you can put anything into numsys to make your own number system to in you want. just swap the current numsys characters with your own set.
/*
01233456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+/
ABCDEFGHIJKLMNOPQRSTUVWXYZ01233456789abcdefghijklmnopqrstuvwxyz+/
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz01233456789+/
*/
//
char numsys[124] = {"01233456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/"};//this is a storage for the correct characters in the number systems. for example, base 25 would have the first 25 characters in here
//^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^
String input;//this is a buffer that stores the serial read info before i want to use it
char ending = 10;//this is a place to store the key code ten, or enter, so that the serial read stops at the right point
unsigned long num[9];//this is an array i made so that i didnt have to declare a bunch of variables indivudialy
int output[100];//an integer array, this stores the output in number form. for example, instead of storing the letter A this would store 11.
char output1[100];//a character array, this is where the actual output is stored.
int i;//this is for the FOR loop
int place;//this holds the digit/place value that the script is on
void setup() {
  num[1] = -1;
  num[5] = 1;
Serial.begin(9600);
Serial.print("\n\n\n\n    _..:::.._\n  .:::::/|::::.\n ::::::/ V|:::::\n::::::/'  |::::::\n::::<_,   (::::::\n :::::|    ""\"::::\n  '::/      ""\":'\n ma""de b""y awe""so""me""_to""rn""ado_#4""22""7 on dis""co""rd");
Serial.print("\nstarted");
Serial.print("\njust a couple setup questions...\ndo you want the ones place on the left (like binary) or on the right (like our base ten number system)\ntype L for left or R for right\n");
while(num[7] != 1){
  input = Serial.readStringUntil(ending);
  if(input == "L"){
    num[6] = 1;
    num[7] = 1;
  }
  if(input == "R"){
    num[6] = 0;
    num[7] = 1;
  }
  if(input == "l"){
    num[6] = 1;
    num[7] = 1;
  }
  if(input == "r"){
    num[6] = 0;
    num[7] = 1;
  }
}
Serial.print("ok, thanks!");
Serial.print("\nnow what base number system do you want to convert to?");
}
void loop() {
  if(num[5] == 1){//numbersystem loop, lets the user input a base number system
 input = Serial.readStringUntil(ending);
 num[0] = input.toInt();
  }
if(num[0] > 1){
  if(num[5] == 1){
    Serial.print("\n\nbase ");//gui screen
   Serial.print(num[0]);//gui screen
    Serial.print(" number system ");
  Serial.write("\ntype any number to convert it,");//gui screen
   Serial.write("\nor type esc to start over\n");//gui screen
  }
  num[3] = num[0];
  for(i = 0;i < 50;i = i + 1){//this needs to reset all of the output counters, so that outputs dont just keep adding on to each other
  output[i] = '\0';
  output1[i] = ' ';
  }
   while(num[1] != 0){
 input = Serial.readStringUntil(ending);//probs reads till the wrong point, im telling it to read untill 10 (the key code for enter)
 if(input != "esc"){//check if the input was 'esc' to determine whether or not to break out of the loop
  num[5] = 0;//stop the numbersystem loop
num[1] = input.toInt();//convert the string to an int(this is for math)
num[4] = input.toInt();//convert the string to an int(this is for gui)
 if(num[1] > 4294967294/num[0]){//2147483647 is the highest number that the code can handle
  Serial.print("sorry, your number is too big. try something else\n");
  num[1] = -1;
 }
if(num[1] == 0){//this keeps the loop running untill you input a valid number  
   num[1] = -1;//without this the while loop will only run one time because serial read deafults to zero
}
if(num[1] != -1){
while(num[1] > 0){
while(num[1] >= num[3]){
  num[3] = num[3] * num[0];//this is to find the highest place value (digit) in the answer
  place = place + 1;
} 
 num[3] = num[3] / num[0];//this lowers the place value/digit by the nuber systems correct amount
while(num[1] >= num[3]){
num[1] = num[1] - num[3];
output[place] = output[place] + 1;//add one to the current didgit
}

output1[place] = numsys[output[place]];//convert the number into the correct base system charicter
place = place - 1;//num2 is the digit counter, the variable that tells the script which didgit to put the number into.
}
while(place >= 0){
  output1[place] = numsys[0];
    place = place - 1;
}
}
 }else{
    Serial.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    Serial.print("started\n");
      num[1] = -1;
      place = 0;
      num[0] = 0;
      num[5] = 1;
    break;
 }
   }
   if(num[5] == 0){
     Serial.print("\nbase ");
    Serial.print(num[0]);
     Serial.write(" number system decoder\n  in[");
     Serial.print(num[4]);
    Serial.print("]\n out[");
    if(num[6] == 1){
       Serial.print(output1);
    }else if(num[6] == 0){
      for(i = 50;i > -1;i = i - 1){
        if(output1[i] != ' '){
          Serial.print(output1[i]);
        }
      }
    }else{}
      Serial.print("\n");
   place = 0;
   num[1] = -1;
   }
}
}

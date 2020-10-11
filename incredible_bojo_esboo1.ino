static int rightf = 11;
static int rightb=10;
static int leftf =6;
static int leftb=5;

void setup()
{
  //allows for console to work (Console not used)
  Serial.begin(9600);
}

void loop()
{
  float val;
  float dip;
  val = analogRead(5);
  dip= analogRead(1);
  //val is the output of the potentiometer
  //dip is the output of the dip switch
  
  val= (255.0*val)/1023.0;//Converts the val to an output for 
  						  //the motors
    
  if(dip==176)//if switch 1 of dipswitch is on
  {
  	forward(val);
  }
  else if(dip==165)//if switch 2 of dipswitch is on
  {
  	backward(val);
  }
  else if(dip==144)//if switch 3 of dipswitch is on
  {
  	left(val);
  }
  else if(dip==94)//if switch 4 of dipswitch is on
  {
  	right(val);
  }
  else //any other combo of switches turns off motors
  {
  	stop();
  }
  
}
void forward(float val)//sets motors to spin forward at
  					   //speed based on potentiometer
{
	
  	analogWrite(rightf, 0);
  	analogWrite(rightb, val);
  
  	analogWrite(leftf, val);
  	analogWrite(leftb, 0);
}
void backward(float val)//sets motors to spin backwards at
  					    //speed based on potentiometer
{
	
  	analogWrite(rightf, val);
  	analogWrite(rightb, 0);
  
  	analogWrite(leftf, 0);
  	analogWrite(leftb, val);
}
void right(float val)//sets motors to turn right at
  					 //speed based on potentiometer
{
	
  	analogWrite(rightf, 0);
  	analogWrite(rightb, val);
  
  	analogWrite(leftf, 0);
  	analogWrite(leftb, val);
}
void left(float val)//sets motors to turn left at
  					 //speed based on potentiometer
{
	
  	analogWrite(rightf, val);
  	analogWrite(rightb, 0);
  
  	analogWrite(leftf, val);
  	analogWrite(leftb, 0);
}
void stop()//stops both motors
{
	
  	analogWrite(rightf, 0);
  	analogWrite(rightb, 0);
  
  	analogWrite(leftf, 0);
  	analogWrite(leftb, 0);
}
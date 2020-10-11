static int rightf = 11;
static int rightb=10;
static int leftf =6;
static int leftb=5;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float val;
  float dip;
  val = analogRead(5);
  dip= analogRead(1);
  val= (255.0*val)/1023.0;
    
  if(dip==176)
  {
  	forward(val);
  }
  else if(dip==165)
  {
  	backward(val);
  }
  else if(dip==144)
  {
  	left(val);
  }
  else if(dip==94)
  {
  	right(val);
  }
  else
  {
  	stop();
  }
  
}
void forward(float val)
{
	
  	analogWrite(rightf, 0);
  	analogWrite(rightb, val);
  
  	analogWrite(leftf, val);
  	analogWrite(leftb, 0);
}
void backward(float val)
{
	
  	analogWrite(rightf, val);
  	analogWrite(rightb, 0);
  
  	analogWrite(leftf, 0);
  	analogWrite(leftb, val);
}
void right(float val)
{
	
  	analogWrite(rightf, 0);
  	analogWrite(rightb, val);
  
  	analogWrite(leftf, 0);
  	analogWrite(leftb, val);
}
void left(float val)
{
	
  	analogWrite(rightf, val);
  	analogWrite(rightb, 0);
  
  	analogWrite(leftf, val);
  	analogWrite(leftb, 0);
}
void stop()
{
	
  	analogWrite(rightf, 0);
  	analogWrite(rightb, 0);
  
  	analogWrite(leftf, 0);
  	analogWrite(leftb, 0);
}
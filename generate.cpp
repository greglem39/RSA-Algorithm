//program for RSA algorithm for assignment one
//per recommendation by Dr. Rauscher, I will be keeping the initial numbers small

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int greatestDenominator(int i, int j) // will be needed for finding a co prime value so e > 1 in main
{
  int temp; // set up a temporary int for modulation

 
  while(1) //setting up a while loop to produce the greatest common denominator between the two numbers
    {
      temp = i % j; // modulate i and j
      if(temp == 0) // set up an if loop in the event that there is no remainder
	return j; //return the second int 
      i = j; //the first int will become the second int
      j = temp; //j becomes the result of modulation
    }
  return 0;
} /*note: cannot have greatestDenominator after main or the compiler believes that it has not been
     declared*/

//set up a main method which will generate the public and private keys
int main()
{

  ofstream outpub{"pub.key"}; //initialize outpub and create pub.key
  
   if (!outpub.is_open()) {
      cerr << "File could not be opened.\n"; //display message that the file failed to open
      exit(EXIT_FAILURE); //exit code FAILURE
      }

 
 ofstream outpriv{"priv.key"}; // naming the file private.key

  //exit the program if unable to create the file
  if (!outpriv)//conditional if statement with overloaded ! operator
    {
      cerr << "File could not be opened.\n"; //display message that the file failed to open
      exit(EXIT_FAILURE); //exit code FAILURE
      }
  

  //two prime numbers needed to generate the keys for the RSA algorithm
  double p = 2; // the first prime number will be 2
  double q = 11; // second prime number will be 11
  double n = p * q; // multiply the two prime numbers to get n
  double counting; //will be used to find a co-prime that satisfies e > 1
  double totient = (p - 1) * (q - 1); //declare and calculate the totient 

  //e will be used to help encrypt the public key
  double e = 7; // I have chosen 7 for e as it falls between 3 and the totient

  //testing variable values
  cout << "p: " << p << " q: " << q << " n: " << n << " totient: " << totient << " e: " << e << "\n";

  //find a co-prime such that e is greater than 1
  while (e < totient) //set up while loop to find the co-prime value
    {
      counting = greatestDenominator(e, totient); //impliment greatestDenominator method to pass the two
      //values through
      if(counting == 1) // if counting is 1 after greatest denominator is implimented
	{
	  break; //break out of the while loop
	}
      else //otherwise, the loop will continue
	{
	  e++; //and 1 will be added to e until count is equal to 1
	}

    };

   double d; //d will be used to help decrypt the message

  double k = 4; //selecting an arbitrary value for k - I chose 4

  //calculate d * e = 1 + (k * totient)
  d = (1 + (k * totient)) / e; // divide both sides by e to find d

  //check the value for d
  cout << "d: " << d << "\n";

  cout << "The public key is: " << e << " " << n << "\n" << "The private key is: " << d << " " << n << "\n"; // display the results for the keys

  outpub << e << " " << n << endl; //putting e and n into pub.key
  outpriv << d << " " << n << endl; // putting d and n into priv.key

  return 0;
}
  

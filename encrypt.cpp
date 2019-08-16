//This file will encrypt my original message

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h> 

using namespace std;

class encryption
{
  double a; //placeholder value for e
  double b; //placeholder value for n

public:



}
/*
class Message
{
 
private:

public:
  /*cout << "message: " << message << "\n";
  
  return message;
};*/

int main()
{
  double e, n; //setting e and n to get value from pub.key
  ifstream inpub{"pub.key"};  //open the  file to acquire the public.key

  inpub >> e >> n; //inputting values into e and n

   if (!inpub) //exit program if ifstream can't open file
    {
      cerr << "File could not be opened.\n"; //error message to be displayed if the file fails to open
      exit(EXIT_FAILURE); //exit code FAILURE
      } 

   cout << e << " " << n << endl; //testing values

  double message; //storing the random number in message

  cout << "Please enter a number between 1 and 50:\n"; //prompt user for a number between 1 and 50
  cin >> message; //take input into message

  while (message > 50 || message < 1) //ensure that message is between 1 and 50
    {
      cout << "Sorry! That number is invalid! Please enter a new number!\n"; //output if number is greater than 50
      cin >> message; //take in new input
  }

  while (message >= n) //prevent message from being greater than n
    {
      cout << "Your number cannot be greater than the totient. Please enter a new number.\n"; //prompt for new entry
      cin >> message; // take in new input
    }


  cout << "The secret number is: " << message << endl; //testing values

  long long f =(( long long)pow(message, e)); //increasing the message value exponentially by e

  f = fmod(f, n); //modulating by n

  cout << "modulation yields: " << f << "\n"; //testing my value

}

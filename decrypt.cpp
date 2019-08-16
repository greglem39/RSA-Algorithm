//this program will decrypt the encrypted message
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  ifstream outpriv("priv.key"); //constructor opens the priv.key file

  //exit program if could not open file
  if (!outpriv)
    {
      cerr << "File could not be opened.\n"; //message displayed if file can't be opened
      exit(EXIT_FAILURE);//exit with code FAILURE
    }

  double d; //double value to store d from private key
  double n; //double value to store n from private key

  outpriv >> d >> n; //retrieve values from private key

  cout << "d: "<< d << " " << "n: " <<n << "\n"; // display values

}

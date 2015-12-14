#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

int main(){
  long double pi = 0.0; //long double for better precision
  int in;
  cin >> in;
  if(in > 1000000)
    return 0;
  for(int i = 1; i <= in; i++){
    pi = pi + (1/pow(i,2));
  }
  cout << setprecision(15) << sqrt(pi*6) << endl; //setprecision to output 15 digits 
  return 0;
}

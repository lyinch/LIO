#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int num)
{
  if (num == 1)
    return false;
  if (num == 2)
    return true;
  if (num %2 == 0)
    return false;
  for (int i = 3; i <= (int)sqrt(num); i++) { //we only need to check until sqrt(num)
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, const char * argv[]) {
  int a,b,c;
  vector<int> primes;
  cin >> a >> b;

  //make sure that the interval starts at the lowest number
  if (a > b)
    {
      c = a;
      a = b;
      b = c;
    }
  if(a==b)
    return 0;
  for (int i = a; i < b; i++)
    {
      if (isPrime(i))
	primes.push_back(i); //save all primes in the vector
    }
  for (vector<int>::iterator it = primes.begin(); it != primes.end()-1; ++it) //until index-1, because we're checking iterator+1 in the loop.
    {
      if ((*(it+1) - *it) <= 2) { //increase the vector iterator, and check the distance between the primes
	cout << *it << " " << *(it+1) << endl;
      }
    }
  return 0;
}

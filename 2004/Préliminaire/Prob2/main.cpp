#include <iostream>

using namespace std;


bool isgood(int n){
  if(n == 1)
    return false;
  if(n == 2)
    return true;
  if(n % 2 != 0)
    return false;
  while(n > 1){ //divide by 2 until it's one, if there is a rest then there are other prime dividers than 2
    if(n % 2 == 0)
      n /= 2;
    else
      return false;
  }
  return true;
  
}

int main(){
  int n;
  cin >> n;
  if(isgood(n))
    cout << "VRAI" << endl;
  else
    cout << "FAUX" << endl;
  return 0;
}

#include <iostream>
using namespace std;

int main(){
  int i,c,n; //first number, the constant and the repetitions
  char t; //type
  cin >> i >> c >> n >> t;
  //check if input is correct, by checking wheter one of the values is false (the ! at the beginning) 
  if(!((i == (int)i) && (c == (int)c) && (n == (int)n) && (abs(i) <= 100) && (abs(c) <= 100) && (abs(n) <= 100) && ((t == 'A') || t == 'G')))
    return 0;
  if(t == 'A'){
    cout << i  << " ";
    for(int q = 0; q < n-1; q++){
      i += c;
      cout << i << " ";
    }
    cout << endl;
  }
  if(t == 'G'){
    cout << i << " ";
    for(int q = 0; q < n-1; q++){
      i *= c;
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}

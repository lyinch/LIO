#include <iostream>
using namespace std;
//ignore the stupid rule of the ' and ç character... 
int main(){
  string input;
  char c;
  int counter;
  bool error = false;
  getline(cin,input); //read input until new line appears
  cin >> c;
  if(!isalpha(c)) //check if c contains only characters
    error = true;
  if(input.size() > 100)
    error = true;
  
  for(int i = 0; i < input.size(); i++){
    if(input[i] == c)
      counter++;
    if(!(((int)input[i] == 32) || ((int)input[i] >= 65 && (int)input[i] <= 90) || ((int)input[i] >= 97 && (int)input[i] <= 122 ))) //check if string contains valid character based on ASCII code. We could also use isalpha and check only the special cases such as the white space.
      error = true;
  }
  if(error)
    cout << "There was an error" << endl;
  cout << counter << endl;
  return 0;
}

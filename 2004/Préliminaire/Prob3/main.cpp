#include <iostream>
#include <fstream>

using namespace std;

int main(){
  string cipher;
  string msg;
  int length_c; //length of cipher
  int length_m; //length message
  int pos;
  int offset;
  ifstream input;
  string tmp;
  input.open("input.txt");
  
  if(input.is_open()){
    input >> length_c;
    getline(input,tmp);
    input >> length_m;
    getline(input,tmp);
    input >> pos;
    getline(input,tmp); //skip line, because getline needs a string instead of an int
    input >> offset;
    getline(input, tmp); //read offset
    getline(input,cipher); //read cipher
  }else{
    cout << "ERROR OPENING FILE!" << endl;
    return 0;
  }

  for(int i = pos; i < length_c-offset; i+=offset){
    cout << cipher[i+1];
  }
  cout << "\n";
  
  return 0;
}

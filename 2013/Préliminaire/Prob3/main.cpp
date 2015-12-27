#include <iostream>
#include <fstream>

using namespace std;

void fill_array(int (&arr)[10]){
  for(int i = 0; i < 10; i++){
    arr[i] = 0;
  }
}

int main(){
  string input;
  int sudoku[9][9];
  int check[10];
  bool error = false;
  cin >> input;
  ifstream file(input);
  if(file.is_open()){
    for(int y = 0; y < 9; y++){
      for(int x = 0; x < 9; x++){
	file >> sudoku[y][x];
      }
    }
    file.close();
  }else
    cout << "ERROR OPENING FILE" << endl;
  
  //check line
  for(int y = 0; y < 9; y++){
    for(int x = 0; x < 9 ;x++)
      check[sudoku[y][x]]++;
    for(int i = 1; i < 10; i++){
      if(check[i] > 1)
	error = true; 
    }
    fill_array(check);
  }
  //check column
  for(int y = 0; y < 9; y++){  
    for(int x = 0; x < 9 ;x++)
      check[sudoku[x][y]]++;
    for(int i = 1; i < 10; i++){
      if(check[i] > 1)
	error = true; 
    }
    fill_array(check);
  }

  //check 3*3
  for(int a = 0; a < 9; a += 3){
    for(int b = 0; b < 9; b += 3){
      for(int x = 0; x < 3; x++){
	for(int y = 0; y < 3; y++){
	  check[sudoku[a+x][y+b]]++;
	}
      }
      for(int i = 1; i < 10; i++)
	if(check[i] > 1)
	  error = true;
      fill_array(check);
    }
  }

  if(error)
    cout << "error" << endl;
  else
    cout << "correct" << endl;
  
  return 0;
}

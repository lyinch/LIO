#include <iostream>
#include <fstream>

using namespace std;

void fill_array(int (&arr)[10]){
  for(int i = 0; i < 10; i++){
    arr[i] = 0;
  }
}

int main(void){
  int check[10];
  int sudoku[9][9];
  int val  = 0;
  int pos = 0;
  int t_x = 0;
  int t_y = 0; //target_x / y
  bool found = false;
  ifstream input("sudo_in.txt");

  if(input.is_open()){
    cout << "ORIGINAL SUDOKU" << endl;
    for(int y = 0; y < 9; y++){
      for(int x = 0; x < 9; x++){
	input >> sudoku[y][x];
	cout << sudoku[y][x] << " ";
      }
      cout << "\n";
    }
  }else{
    cout << "ERROR READING FILE" << endl;
    return 0;
  }
 
  do{
    found = false;
    
    //check line by line
    for(int y = 0; y < 9; y++){
      for(int x = 0; x < 9 ;x++)
	check[sudoku[y][x]]++;
      //check if there is a line with 8 filled in numbers
      if(check[0] == 1){
	found = true;
	for(int x = 0; x < 9 ;x++){
	  if(sudoku[y][x] == 0)
	    pos = x;
	}
	//search for the empty position
	for(int i = 1; i < 10; i++){
	  //set val the value of the empty position
	  if(check[i] == 0)
	    val  = i;
	}
	sudoku[y][pos] = val;
      }
      fill_array(check);
    }

    //check column
    for(int y = 0; y < 9; y++){
      for(int x = 0; x < 9 ;x++)
	check[sudoku[x][y]]++;
      //check if there is a column with 8 filled in numbers
      if(check[0] == 1){
	found = true;
	for(int x = 0; x < 9 ;x++){
	  if(sudoku[x][y] == 0)
	    pos = x;
	}
	//search for the empty position
	for(int i = 1; i < 10; i++){
	  //set val the value of the empty position
	  if(check[i] == 0)
	    val  = i;
	}
	sudoku[pos][y] = val;
      }
      fill_array(check);
    }
    
    cout << "3*3 check" << endl;
    
    //check 3*3
    for(int a = 0; a < 9; a += 3){
      for(int b = 0; b < 9; b += 3){
	
	for(int x = 0; x < 3; x++){
	  for(int y = 0; y < 3; y++){
	    check[sudoku[a+x][y+b]]++;
	  }
	}
	
	//check if 3*3 is filled with 8 numbers
	if(check[0] == 1){
	  found = true;
	  
	  //search for the empty pos. in the 3*3 grid
	  for(int x = 0; x < 3; x++){
	    for(int y = 0; y < 3; y++){
	      if(sudoku[a+x][y+b] == 0){
		t_x = a+x;
		t_y = b+y;
	      }
	    }
	  }
	  //search for the missing value
	  for(int i = 1; i < 10; i++){
	    //set val the value of the empty position
	    if(check[i] == 0)
	      val  = i;
	  }
	  sudoku[t_x][t_y] = val;
	} //end found missing number

	fill_array(check);
      }    
    }
    
    
  }while(found);

  cout << "FILLED IN VERSION:" << endl;
  for(int y = 0; y < 9; y++){
    for(int x = 0; x < 9; x++){
      cout << sudoku[y][x] << " ";
    }
    cout << "\n";
  }
  
  return 0;
}

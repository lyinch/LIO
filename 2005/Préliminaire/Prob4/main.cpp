
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct t_pos{
  int x;
  int y;
  int piece;
};

enum pieces {empty = 0, king = 1, queen = 2, rook = 3, bishop = 4};
int counter = 0; //counts the checks on the king

//mark line of sight with the number 5 on the board
bool mark_los(int (&chess)[8][8],int x, int y,int dir_x, int dir_y){
  x += dir_x;
  y += dir_y;

  //check position is out of range or it is on another piece
  if((x > 7) || (x < 0) || (y > 7) || (y < 0) || (chess[x][y]  > 1 && chess[x][y] < 5 ))
    return false;

  //check if hits the king
  if(chess[x][y] == 1){
    counter++;
    return true;
  }

  //mark the position as line of sight
  chess[x][y] = 5;
  
  //recursive call to continue in the initialised direction
  mark_los(chess,x,y,dir_x,dir_y);
  
  return false;
}

//calls the appropriate function to mark the line of sight according the the piece
bool call_mark_los(int (&chess)[8][8] ,int x, int y,int piece){

  //horizontal & vertical checks
  if((piece == rook) || (piece == queen)){
    //right
    mark_los(chess,x,y,1,0);
    //left
    mark_los(chess,x,y,-1,0);
    //up
    mark_los(chess,x,y,0,-1);
    //down
    mark_los(chess,x,y,0,1);   
  }
  
  //diagonal checks
  if((piece == bishop) || (piece == queen)){
    mark_los(chess,x,y,1,1);
    mark_los(chess,x,y,-1,1);  
    mark_los(chess,x,y,1,-1);    
    mark_los(chess,x,y,-1,-1);
  }
  
  return false;
}


int main(void){
  ifstream file("echec_in.txt");
  int chess[8][8] = {0};
  int x,y;
  string input; //tmp reading by console
  vector<t_pos> p_pos;
  
  int tmp_size = 0;
  if(file.is_open()){
    
    for(int i = 0; i <6; i++){
      file >> input; //reads until whitespace
      //cout << input << endl; //debuggingy
      if(((int)input[0]-(int)'A' == -17)) //skip if piece is 00
	continue;
      
      //converts chars to integer positions
      x = (int)input[0]-int('A'); 
      y = (int)input[1]-int('0')-1; 

      //increment the size of the list for a new piece
      p_pos.resize(p_pos.size()+1);
      tmp_size = p_pos.size()-1;

      //position every piece on the board and save it to the list p_pos (vector)
       switch(i){
      case 0:
	p_pos[tmp_size].x = x;
       	p_pos[tmp_size].y = y;
	p_pos[tmp_size].piece = king;
	chess[x][y] = king;
	break;
      case 1:
	p_pos[tmp_size].x = x;
       	p_pos[tmp_size].y = y;
	p_pos[tmp_size].piece = queen;
	chess[x][y] = queen;
	break;
      case 2:
      case 3:
	p_pos[tmp_size].x = x;
       	p_pos[tmp_size].y = y;
	p_pos[tmp_size].piece = rook;
	chess[x][y] = rook;
	break;
      case 4:
      case 5:
	p_pos[tmp_size].x = x;
       	p_pos[tmp_size].y = y;
	p_pos[tmp_size].piece = bishop;
	chess[x][y] = bishop;
	break;
      }
    }
  }else{
    cout << "COULD NOT READ FROM FILE!" << endl;
    return 0; //exit ;) 
  }
  
  //call for every piece in the list the function
  for(int i = 0; i <= p_pos.size(); i++)
    call_mark_los(chess,p_pos[i].x,p_pos[i].y,p_pos[i].piece);
    
  cout << "Checks: " << counter << endl;
  
  return 0;
}

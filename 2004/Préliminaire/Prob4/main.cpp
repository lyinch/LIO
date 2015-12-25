#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//position coordinates
int x,y; 
int x_g,y_g;

//recursive step counters
int iterp = 1;
int iterm = 0;

bool reached = false;
//prototyping
void output2d_vector(vector<vector<int> > &field);


bool check_steps(vector<vector<int> > field,int x_pos, int y_pos){
 
  
  //check that coords are in range
  if( (x_pos < 0) || (x_pos >= x) || (y_pos < 0) || (y_pos >= y) || (field[y_pos][x_pos] >= 1) )
    return false;
  
  //check if goal has been reached
  if( (x_pos == x_g) && (y_pos == y_g)){
    reached = true; //mark that a solution has been found
    return true;
  }
  //if wall hit
  if(field[y_pos][x_pos] == 1)
    return false;
  
  //mark path as part of the solution - set 2 as checked
  field[y_pos][x_pos] = 2;
  iterp++;
  
  
  //check south
  if(check_steps(field,x_pos,y_pos+1) == true)
    return true; //if solution found, terminate

  //check east
  if(check_steps(field,x_pos+1,y_pos) == true)
    return true;

  //check west
  if(check_steps(field,x_pos-1,y_pos) == true)
    return true;
  
  //unmark, path as part of the solution - set 3 as checked
   field[y_pos][x_pos] = 3;
   iterm--;

   return false;
}

void output2d_vector(vector<vector<int> > &field)
{
  for(int i=0; i < field.size(); i++){
    for(int j = 0; j < field[i].size();j++){
      cout << field[i][j]; 
    }
    cout << endl;
  }  
}

int main(){
    
  ifstream input("input.txt");
  string in_tmp;
  vector<int> v2; //tmp vector for the y space
  vector<vector<int> > field(0,v2); //2d vector
  int min_steps;
  int tmp = -1;
  
  if(input.is_open()){
    input >> x >> y;
    getline(input,in_tmp); //switch to the first line of the field
    
    field.resize(y,vector<int>(x)); //resize vector to [x][y]
      
    for(int i = 0; i < y; i++){
      getline(input,in_tmp);
      for(int j = 0; j < x; j++){
	if((int)in_tmp[j]-48 == 1)
	  field[i][j] = 1; //use 1 for wall
	else
	  field[i][j] = 0; //use 0 for a free field
      }
    }
    input.close();
  }

  min_steps = x*y;
 
 
  y_g = y-1;
  
  //check every possible starting position on y=0
  for(int a = 0; a < field[0].size(); a++){
    if(field[0][a] == 1)
      continue; //skip if starting field is a wall
    
    for(int b = 0; b < field[0].size(); b++){ //check every possible end position on y_g = y-1
      
      if(field[y_g][b] == 1) //skip field if goal is a wall
	continue; 
      if(field[y_g-1][b] == 1) //skip field if not reachable from above
	continue;
      
      x_g = b;
      
     
      check_steps(field,a,0);
     
      if(((iterp+iterm) < min_steps) && (iterp+iterm != 1))
	min_steps = iterp+iterm;
      iterp = 1;
      iterm = 0;
    }
  }
  
  if(reached)
    cout << min_steps << endl;
  else
    cout << "-1" << endl;
  
  return 0;
}

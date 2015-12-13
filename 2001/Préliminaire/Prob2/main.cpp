#include <iostream>
using namespace std;

int main()
{
  struct month_t
  {
    string name;
    int days;
  };
  month_t month[13];
  
  month[1].name = "janvier";
  month[1].days = 31;
  month[2].name = "fevrier";
  month[2].days = 28;
  month[3].name = "mars";
  month[3].days = 31;
  month[4].name = "avril";
  month[5].days = 30;
  month[5].name = "mai"; 
  month[5].days = 31;
  month[6].name = "juin";
  month[6].days = 30;
  month[7].name = "juillet";
  month[7].days = 31;
  month[8].name = "aout"; 
  month[8].days = 31;
  month[9].name = "septembre";
  month[9].days = 30;
  month[10].name = "octobre"; 
  month[10].days = 31;
  month[11].name = "novembre"; 
  month[11].days = 30;
  month[12].name = "decembre"; 
  month[12].days = 31;

  bool found = false; //if double month found
  bool foundb = false; // if single month found
  for(int i = 111; i < 1000; i++)
  {
    foundb = false;
    found = false;
    // i/100 -> single day
    // i/10 -> 2 days
    // i%10 -> single month
    // i%100 -> double month
    if((i%100 <=12)&&(i%100 != 0)){
      cout << i << " " << i/100 << " " << month[i%100].name;
      found = true;
    }
    if((i/10 <= month[i%10].days)){
      if(found)
	cout << " ou ";
      if(!found) //output the current number of the double month is false
	cout << i << " ";
      cout << i/10 << " " << month[i%10].name << endl;
      foundb = true;
    }
    
    if(found && !foundb)
      cout << endl;      
  }
  return 0;
}

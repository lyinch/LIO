#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, to; //n: number of first terms; to: index of term to show
  int tmp;
  vector<int> terms;
  int ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++){ //reads in the first n terms
    cin >> tmp;
    terms.push_back(tmp);
  }
  cin >> to;
  vector<int>::iterator it = terms.end();
  for(int j = 0; j < to-n; j++){ // loop until to-n because we have the first n digits
    for (int q = 1; q < n+1; q++){ //go to the last term in the vector and add the q previous terms
      ans += *(it-q);
      }
    terms.push_back(ans);
    ans = 0;
    it = terms.end();
  }
  cout << terms.back() << endl;
  return 0;
}

#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<queue> 


using namespace std; 

class Solution{
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
      int n = chargeTimes.size(); 
      deque<int> dq; 
      int l=0; 
      int maxLen=0; 
      long long sumRunCost=0; 
      for(int r=0; r<n; ++r){
        sumRunCost +=runningCosts[r]; 
        while(!dq.empty() && chargeTimes[dq.back()] <=chargeTimes[r]) dq.pop_back(); 
        dq.push_back(r); 
        while(!dq.empty() &&((long long)chargeTimes[dq.front()]+(long long)(r-l+1)*sumRunCost)>budget){
          if(dq.front()==l) dq.pop_front(); 
          sumRunCost -=runningCosts[l]; 
          ++l;
        }
        maxLen= max(maxLen, (r-l+1)); 
      }
      return maxLen; 
    }
};
int main(){
  vector<int> chargeTimes={3,6,1,3,4};
  vector<int> runningCosts={2,1,3,4,5};
  int budget = 25; 
  Solution sol; 
  cout << sol.maximumRobots(chargeTimes, runningCosts, budget) <<endl; 
  return 0; 
}

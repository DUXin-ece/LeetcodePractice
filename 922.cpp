#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
    	/* Another solution.  Use a separate array to hold the result. 
        vector<int> Result(A.size(),0);
        int even = 0;
        int odd = 1;
        for(int i=0;i<A.size();i++){
            if(A[i]%2 ==0){
                Result[even] = A[i];
                even+=2;
            }
            else{
                Result[odd] = A[i];
                odd+=2;
            }
        }
        return Result;
        */

    
        int odd=1;
        for(int even=0;even<A.size();even+=2){
            if(A[even]%2 != 0){
                while(odd<A.size()){
                    if(A[odd]%2 == 0){
                        swap(A[even],A[odd]);
                        break;
                    }
                    else{
                        odd+=2;
                    }
                }
            }
        }
        return A;

    }
};

int main(void){
	Solution solution;
	vector<int> A(4) ;
	vector<int> Result(4);
	
	A[0] = 4;
	A[1] = 2;
	A[2] = 5;
	A[3] = 7;
	
	Result = solution.sortArrayByParityII(A);
	
	for(int i = 0;i<Result.size();i++){
		if(i == 0){
			cout << "{"<<Result[i]<<", "; 
		}
		else if(i == Result.size()-1){
			cout << Result[i]<<"}"<<endl;
		}
		else{
			cout << Result[i]<<", ";
		}
		
	}
	
	return 0;
}

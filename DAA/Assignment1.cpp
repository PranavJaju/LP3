// Write a program non-recursive and recursive program to calculate Fibonacci 
// numbers and analyze their time and space complexity.
#include<iostream>
#include<vector>
using namespace std;

int IterativeFibonacci(int n, int & steps){
    steps = 1;
    if(n<=1){
        return n;
    }
    int f1 = 0;
    int f2 = 1;
    for(int i = 2;i<=n;i++){
        steps++;
        int temp = f2;
        f2 = f1+f2;
        f1 = temp;
    }
    return f2;
}
int RecursiveFibonacci(int n,int & steps){
    steps++;
    if(n<=1){
        return n;
    }
    return RecursiveFibonacci(n-1,steps)+RecursiveFibonacci(n-2,steps);
}
int MemoizationFibonacci(int n,vector<int> &dp ,int & steps){
     steps++;
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
   
    dp[n] = MemoizationFibonacci(n-1,dp,steps)+MemoizationFibonacci(n-2,dp,steps);
    return dp[n];
}
int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    int steps;
    cout<<"----------------Iterative Approach----------------"<<endl;
    cout<<"Fibonacci number at "<<n<<" position is: "<<IterativeFibonacci(n,steps)<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    cout<<"Time Complexity: O(n)"<<endl;
    cout<<"Space Complexity: O(1)"<<endl;
    steps = 0;
    cout<<"----------------Recursive Approach----------------"<<endl;
    cout<<"Fibonacci number at "<<n<<" position is: "<<RecursiveFibonacci(n,steps)<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    cout<<"Time Complexity: O(2^n)"<<endl;
    cout<<"Space Complexity: O(n)"<<endl;
    steps = 0;
    vector<int> dp(n+1,-1);
    cout<<"----------------Memoization Approach----------------"<<endl;
    cout<<"Fibonacci number at "<<n<<" position is: "<<MemoizationFibonacci(n,dp,steps)<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    cout<<"Time Complexity: O(n)"<<endl;
    cout<<"Space Complexity: O(n)"<<endl;
    return 0;
}
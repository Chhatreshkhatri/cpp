#include<bits/stdc++.h>
using namespace std;
class NStack
{
public:
    // Initialize your data structure.
	int *arr;
	int *top;
	int *next;
	int n,s;
	int freespot;
	
    NStack(int N, int S)
    {
		n=N;
		s=S;
        arr=new int[s];
		top=new int[n];
		next=new int[s];
		//top initialization
		for(int i=0;i<n;i++){top[i]=-1;}
		//next initialization
		for(int i=0;i<s;i++){next[i]=i+1;}
		//update last index to -1
		next[s-1]=-1;
		//freespot to 0
		freespot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for stack overflow
		if(freespot==-1){return false;}
		//find index
		int index=freespot;
		//update freespot
		freespot=next[index];
		//insert element into array
		arr[index]=x;
		//update next
		next[index]=top[m-1];
		//update top
		top[m-1]=index;
		
		return true;
		
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow
		if(top[m-1]==-1){return -1;}
		//reverse push operation left to right 
		int index=top[m-1];		
		top[m-1]=next[index];
		next[index]=freespot;
		freespot=index;
		return arr[index];
    }
};
int main()
{
    

return 0;
}
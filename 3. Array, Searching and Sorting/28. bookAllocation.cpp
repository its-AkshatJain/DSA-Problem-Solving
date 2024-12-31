//*** Very Very IMP ***//

// Akshat is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.

// 1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.

// 2. If he starts some chapter on a particular day he completes it that day itself.

// 3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.

// Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.

#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

bool isPossibleSol(long long n, long long m, vector<int> time, long long mid){
	long long timeSum=0;
	long long daysSum=1;
	
	for(long long i=0;i<m;i++){
		if(timeSum+time[i]<=mid){
			timeSum+=time[i];
		}else{
			daysSum++;
			if(daysSum>n || time[i]>mid){
				return false;
			}
			timeSum=time[i];
		}
	}
	return true;
}
//                             days   chapters    time array
long long akshatGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long s =0;
    // So that mid value is not less than max element
	// long long s= *max_element(time.begin(),time.end());

	long long sum=0;
	for(long long i=0;i<m;i++){
		sum +=time[i];
	}
	long long e = sum;
	long long mid,ans=-1;

	while(s<=e){
		mid=s+(e-s)/2;

		if(isPossibleSol(n,m,time,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
}

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);

    cout<<"The maximum time in a day he will have to give : "<<akshatGivesNinjatest(3,5,vec);
    return 0;
}
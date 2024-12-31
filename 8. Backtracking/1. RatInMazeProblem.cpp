#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int newX, int newY, vector < vector < int >> & arr, vector<vector<bool>> visited, int n){
    if( (newX>=0 && newX<n) &&  (newY>=0 && newY<n) && visited[newX][newY] != 1 && arr[newX][newY] == 1){
        return true;
    }else{
        return false;
    }
}

void solve(int x, int y, vector < vector < int >> & arr, int n, 
        vector<string> &ans, vector<vector<bool>> visited, string path){
            if(x == n-1 && y == n-1){
                ans.push_back(path);
                return;
            }

            // 4 movements - D,L,R,U
            visited[x][y] = 1;
            // Down
            if(isSafe(x+1 ,y, arr, visited, n)){
                solve(x+1, y, arr, n, ans, visited, path + 'D');
            }

            // left
            if(isSafe(x ,y-1, arr, visited, n)){
                solve(x, y-1, arr, n, ans, visited, path + 'L');
            }

            // Right
            if(isSafe(x ,y+1, arr, visited, n)){
                solve(x, y+1, arr, n, ans, visited, path + 'R');
            }

            // Up
            if(isSafe(x-1 ,y, arr, visited, n)){
                solve(x-1, y, arr, n, ans, visited, path + 'U');
            }

            visited[x][y] = 0;  //Backtrack
        } 
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    if(arr[0][0] == 0){
        return ans;
    }

    solve(0,0, arr, n, ans, visited, path);
    return ans;
}
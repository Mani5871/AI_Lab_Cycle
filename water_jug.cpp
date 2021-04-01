#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<vector<int>, bool>map1;
int nx, ny;
string rule;

bool check(int x, int y)
{
    if(map1[{x, y}])
        return true;
    
    return false;
}

void rules(int x, int y)
{

    nx = 5;
    ny = y;
    rule = "R1";
    if(!check(5, y) && x < 5)
        return;
    
    nx = 0;
    ny = y;
    rule = "R2";
    if(!check(0, y) && x > 0)
        return;
    
    nx = x;
    ny = 3;
    rule = "R3";
    if(!check(nx, ny) && y < 3)
        return;
    
    nx = x;
    ny = 0;
    rule = "R4";
    if(!check(nx, ny) && y > 0)
        return;
    
    nx = x + y;
    ny = 0;
    rule = "R5";
    if(!check(nx, ny) && (x + y <= 5 && y > 0))
        return;
    
    nx = 0;
    ny = x + y;
    rule = "R6";
    if(!check(nx, ny) && (x > 0 && x + y <= 3))
        return;

    nx = 5;
    ny = y - (5 - x);
    rule = "R7";
    if(!check(nx, ny) && (x + y >= 5))
        return;
        
    nx = x - (3 - y);
    y = 3;
    rule = "R8";
    if(!check(nx, ny) && (x + y >= 3))
        return;
    
}

void water_jug(int x, int y, int target)
{
    map1[{x, y}] = true;
    while(x != target)
    {
        rules(x, y);
        x = nx;
        y = ny;
        cout << rule <<" ";
        cout << x <<" " << y << endl;
        map1[{x, y}] = true;
    }
    
}


int main() {
    
    int k;
    cin >> k;
    water_jug(0, 0, k);
}

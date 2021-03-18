#include<bits/stdc++.h>
using namespace std;

unordered_map<int, char>board;
unordered_map<int, int>magic;

void display()
{
    for(int i = 1; i <= 9; i ++)
    {
        cout << board[i] << " ";
        
        if(i % 3 == 0)
            cout << endl;
            
    }
}

void init()
{
    for(int i = 1; i <= 9; i ++)
        board[i] = '-';;
        
        
    magic[1] = 2;
    magic[2] = 7;
    magic[3] = 6;
    
    magic[4] = 9;
    magic[5] = 5;
    magic[6] = 1;
    
    magic[7] = 4;
    magic[8] = 3;
    magic[9] = 8;
}

int position(int x)
{
    switch(x)
    {
        case 2: return 1;
        case 7: return 2;
        case 6: return 3;
        
        case 9: return 4;
        case 5: return 5;
        case 1: return 6;
        
        case 4: return 7;
        case 3: return 8;
        case 8: return 9;
    }
}

int input()
{
    cout <<"Your turn" << endl;
    int x;
    cin  >> x;
    
    while(board[x] != '-')
    {
        cout <<"It is invalid. Enter again" << endl;
        cin >> x;
    }
    board[x] = 'X';
    return x;
}


int poss(char x)
{
    int sum = 0, i;
    
    for(i = 1; i <= 9; i ++)
    {
        if(board[i] == x)
            sum += magic[i];
    }
    
    return position(15 - sum);
    
}


void tic_tac_toe()
{
    int x = input();
    
    
    if(board[5] == '-')
        board[5] = 'O';
    
    else
        board[1] = 'O';
    
    display();
    
    x = input();
    
    int mv = poss('X');
    
    if(board[mv] == '-')
        board[mv] = 'O';
    else
        board[2] = 'O';
    
    display();
    
    x = input();
    mv = poss('O');
    
    if(board[mv] == '-')
    {
        board[mv] = 'O';
        display();
        cout << "Computer Won !!" << endl;
        return;
    }
    
    mv = poss('X');
    if(board[mv] == '-')
        board[mv] = 'O';
    
    else
        board[2] = 'O';
    display();
    
    x = input();
    mv = poss('O');
    
    if(board[mv] == '-')
    {
        board[mv] = 'O';
        display();
        cout << "Computer Won !!" << endl;
        return;
    }
    
    mv = poss('X');
    if(board[mv] == '-')
        board[mv] = 'O';
    
    else
        board[2] = 'O';
    display();
        
}


int main()
{
    init();
    tic_tac_toe();
}

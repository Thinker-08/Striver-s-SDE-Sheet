#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
bool fill(vector<vector<char>> &board,vector<set<char>> &row,vector<set<char>> &col,vector<pair<int,int>> &slots,int idx,vector<vector<set<char>>> &unit)
{
    if(idx>=slots.size())
        return true;
    for(char x='1';x<='9';x++)
    {
        if(row[slots[idx].first].find(x)==row[slots[idx].first].end() and col[slots[idx].second].find(x) == col[slots[idx].second].end() and unit[slots[idx].first/3][slots[idx].second/3].find(x)==unit[slots[idx].first/3][slots[idx].second/3].end())
        {
            board[slots[idx].first][slots[idx].second]=x;
            row[slots[idx].first].insert(x);
            col[slots[idx].second].insert(x);
            unit[slots[idx].first/3][slots[idx].second/3].insert(x);
            if(fill(board,row,col,slots,idx+1,unit))
                return true;
            row[slots[idx].first].erase(row[slots[idx].first].find(x));
            col[slots[idx].second].erase(col[slots[idx].second].find(x));
            unit[slots[idx].first/3][slots[idx].second/3].erase(unit[slots[idx].first/3][slots[idx].second/3].find(x));
            board[slots[idx].first][slots[idx].second]='.';       
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    vector<set<char>> row(9);
    vector<set<char>> col(9);
    vector<vector<set<char>>> unit(3,vector<set<char>>(3));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                unit[i/3][j/3].insert(board[i][j]);
            }
        }
    }
    vector<pair<int,int>> slots;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
                slots.push_back({i,j});
        }
    }
    bool t=fill(board,row,col,slots,0,unit);
}
int32_t main()
{
    fast;
    vector<vector<char>> board(9,vector<char>(9));
    rep(i,0,9)
        rep(j,0,9)
            cin>>board[i][j];
    solveSudoku(board);
    rep(i,0,9)
    {
        rep(j,0,9)
            cout<<board[i][j]<<" ";
        newline;
    }
    return 0;  
}
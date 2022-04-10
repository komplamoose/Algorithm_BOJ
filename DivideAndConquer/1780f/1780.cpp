#include <iostream>
#include <stdio.h>
using namespace std;

int nCount=0;
int zCount=0;
int pCount=0;
int paper[2187][2187] = {2,};

int check=0;

int origami(int paper[][2187], int n, int row, int col);
int checker(int paper[][2187],int n, int row, int col);

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            scanf("%d",&paper[i][j]);
        }
    } // Initialize

    origami(paper,n,0, 0);

    cout << nCount << endl;
    cout << zCount << endl;
    cout << pCount << endl;
}



int origami(int paper[][2187], int n, int row, int col)
{
    if (n==1){
        if(paper[row][col]==-1)
            nCount+=1;
        else if (paper[row][col]==0)
            zCount+=1;
        else if (paper[row][col]==1)
            pCount+=1;
        return 2;
    }
    if (checker(paper,n,row, col)){
        if(paper[row][col]==-1)
            nCount+=1;
        else if (paper[row][col]==0)
            zCount+=1;
        else if (paper[row][col]==1)
            pCount+=1;
        return 1;
    }else{
        origami(paper,n/3,row,col);
        origami(paper,n/3,row,col+(n/3));
        origami(paper,n/3,row,col+((n/3)*2));
        origami(paper,n/3,row+(n/3),col);
        origami(paper,n/3,row+(n/3),col+(n/3));
        origami(paper,n/3,row+(n/3),col+((n/3)*2));
        origami(paper,n/3,row+((n/3)*2),col);
        origami(paper,n/3,row+((n/3)*2),col+(n/3));
        origami(paper,n/3,row+((n/3)*2),col+((n/3)*2));
        return 0;
    }
}


int checker(int paper[][2187],int n, int row, int col) // Checker 함수 수정 필요. 
{
    int standard = paper[row][col];
    for (int i=row ; i<row+n ; i++){
        for (int j=col ; j<col+n ; j++){
            if (paper[i][j] == standard)
                continue;
            else{
                return 0;
                break;
            }
        }
    }
    return 1;
}
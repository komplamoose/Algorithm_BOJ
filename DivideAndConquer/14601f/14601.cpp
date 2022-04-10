// 14601, Gold 1, 샤워실 바닥 깔기
// https://www.acmicpc.net/problem/14601
#include <iostream>

using namespace std;

int n, w, h;
int board[250][250] = {0,};

int cnt=0;

void tromino(int n, int bd[][250],int x, int y)
{
    int h1=0, h2=0, h3=0, h4=0;
    cnt++;

    int temp[250][250];
    if (n <=2){

        for (int i=0;i<n;i++){
            for (int j=0; j<n;j++){
                if ((i!=x||j!=y)){
                    bd[i][j]=cnt;
                }
            }
        }
    }else{
        if (x<n/2&&y<n/2){

            h1=1;
            bd[n/2-1][n/2]=cnt;
            bd[n/2][n/2-1]=cnt;
            bd[n/2][n/2]=cnt;
        }else if (x<n/2&&n/2<=y){

            bd[n/2-1][n/2-1]=cnt;
            bd[n/2][n/2-1]=cnt;
            bd[n/2][n/2]=cnt;
            h2=1;
        }else if (n/2<=x&&y<n/2){

            bd[n/2-1][n/2]=cnt;
            bd[n/2][n/2]=cnt;
            bd[n/2-1][n/2-1]=cnt;
            h3=1;
        }else if (n/2<=x&&n/2<=y){

            bd[n/2][n/2-1]=cnt;
            bd[n/2-1][n/2-1]=cnt;
            bd[n/2-1][n/2]=cnt;
            h4=1;
        }
        if (h1==0){ // 구멍이 없는 면이라면
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i][j];
                }
            }
            int a = n/2-1;
            if (a==0) a=1;
            tromino(n/2,temp,a,a);
            
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i][j]=temp[i][j];
                }
            }
        }else{ // 구멍이 존재하고 있다면
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i][j];
                }
            }
            tromino(n/2,temp,x,y);
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i][j]=temp[i][j];
                }
            }
        }
        if (h2==0){ // 구멍이 없는 면이라면
            
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i][j+n/2];
                }
            }
            tromino(n/2,temp,n/2-1,0);
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i][j+n/2]=temp[i][j];
                }
            }
        }else{ // 구멍이 존재하고 있다면
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i][j+n/2];
                }
            }
            int hX, hY;
            int trg=0;
            for (int i=0; i<n/2;i++){
                for (int j=0 ; j<n/2 ; j++){
                    if (temp[i][j]==-1){
                        hX=i;
                        hY=j;
                        trg=1;
                    }
                }
            }
            if (trg==1)
                tromino(n/2,temp,hX,hY);
            else
                tromino(n/2,temp,x,y/2);
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i][j+n/2]=temp[i][j];
                }
            }
        }
        if (h3==0){ // 구멍이 없는 면이라면
            
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i+n/2][j];
                }
            }
            tromino(n/2,temp,0,n/2-1);
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i+n/2][j]=temp[i][j];
                }
            }
        }else{ // 구멍이 존재하고 있다면
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i+n/2][j];
                }
            }
            int hX, hY, trg=0;
            for (int i=0; i<n/2;i++){
                for (int j=0 ; j<n/2 ; j++){
                    if (temp[i][j]==-1){
                        hX=i;
                        hY=j;
                        trg=1;
                    }
                }
            }
            if (trg==1)
                tromino(n/2,temp,hX,hY);
            else
                tromino(n/2,temp,x/2,y/2);
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i+n/2][j]=temp[i][j];
                }
            }
        }
        
        if (h4==0){ // 구멍이 없는 면이라면
            
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i+n/2][j+n/2];
                }   
            }
            tromino(n/2,temp,0,0);
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i+n/2][j+n/2]=temp[i][j];
                }   
            }
        }else{ // 구멍이 존재하고 있다면
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    temp[i][j]=bd[i+n/2][j+n/2];
                }   
            }
            int hX, hY, trg=0;
            for (int i=0; i<n/2;i++){
                for (int j=0 ; j<n/2 ; j++){
                    if (temp[i][j]==-1){
                        hX=i;
                        hY=j;
                        trg=1;
                    }
                }
            }
            if (trg==1)
                tromino(n/2,temp,hX,hY);
            else
                tromino(n/2,temp,x/2,y/2);
            for (int i=0; i<n/2;i++){
                for (int j=0; j<n/2 ;j++){
                    bd[i+n/2][j+n/2]=temp[i][j];
                }   
            }
        }
    }
}

void solve()
{
    int k=2;
    for (int i=1 ; i<n;i++){
        k*=2;
    }

    /*
    1 1 => 2k-1, 0
    1,2 => 2k-2, 0
    1,3 => 2k-3, 0
    -
    1 1 => 2k-1, 0
    2,1 => 2k-1, 1;
    3,1 => 2k-1, 2;
    3,2 => 2k-2, 2;
    2k 2k => 0, 2k
    */

    int tw = k-h;
    int th = w-1;

    board[tw][th]=-1; // Hole Setup.

    tromino(k,board,tw,th);


    for (int i=0;i<k;i++){
        for (int j=0 ; j<k ; j++){
            cout << board[i][j];
            if (j!=k-1) cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> w >> h;

    solve();

    return 0;
}
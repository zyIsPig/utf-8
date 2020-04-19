#include "iostream"
using namespace std;
void printf_arr(int **arr,int m,int n){

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout <<arr[i][j]<<"   ";
        }
        cout<<"\n";
    }
}
void spiral(int m,int n,int **arr){
    int top=0;
    int bottom=m-1;
    int left=0;
    int right=n-1;
    int pos_x=0;
    int pos_y=n-1;
    int cnt=0;
    while(cnt<m*n-1){
        while(pos_y>left && arr[pos_x][pos_y]==0){
            arr[pos_x][pos_y--]=++cnt;
        }
        top++;
        while(pos_x<bottom && arr[pos_x][pos_y]==0){
            arr[pos_x++][pos_y]=++cnt;
        }
        left++;
        while(pos_y<right && arr[pos_x][pos_y]==0){
            arr[pos_x][pos_y++]=++cnt;
        }
        bottom--;
        while(pos_x>top && arr[pos_x][pos_y]==0){
            arr[pos_x--][pos_y]=++cnt;
        }
        right--;
    }
    if(!arr[pos_x][pos_y])arr[pos_x][pos_y]=++cnt;
}

int main(){
    int m,n;
    do{
    cout <<"plz enter two integer m,n:";
    cin >> m;
    cin >> n;
    if(m>0 && n>0){
        int **arr=(int **)malloc(sizeof(int *)*m);
        for (int i = 0; i < m; i++)
        {
            arr[i]=(int *)malloc(sizeof(int)*n);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j]=0;
            }
        }
        spiral(m,n,arr);
        printf_arr(arr,m,n);
        for (int i = 0; i < m; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
    }while(m<=0 || n<=0);
}

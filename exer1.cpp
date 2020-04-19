#include "iostream"
using namespace std;

struct bullets{
   int pos_x;
   int pos_y;
   int dir_x;
   int dir_y;
};

int update(int ** pointer,int pos_x,int pos_y,int dir_x,int dir_y,int n,int m){
   int cnt=0;
   int temp_x=pos_x;
   int temp_y=pos_y;
   while(temp_x>=0 && temp_x<n && temp_y>=0 &&temp_y<m){
      if(pointer[temp_x][temp_y]==0){
         cnt++;
         pointer[temp_x][temp_y]=1;
      }
      temp_x+=dir_x;
      temp_y+=dir_y;

   }
   return cnt;

 }

int main(){
   int n,m,k,fir,sec,dir1,dir2,ans=0;
   cout <<"plz enter n,m,k";
   cin>>n>>m>>k;
   //malloc
   int **pointer=(int **)malloc(sizeof(int *)*n);
   for (int  i = 0; i < n; i++)pointer[i]=(int *)malloc(sizeof(int)*m);
   
   bullets *bullets_arr=(bullets*)malloc(sizeof(bullets)*k);
   //init
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j <m; j++)pointer[i][j]=0;
   }

   //debug
   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = 0; j <m; j++)cout <<pointer[i][j]<<" ";
   //    cout <<""<<endl;
   // }
   cout <<"plz enter next part~"<<endl;
   for (int i = 0; i < k; i++)
   {
      cin >> fir>>sec>>dir1>>dir2;
      bullets_arr[i].pos_x=fir;
      bullets_arr[i].pos_y=sec;
      bullets_arr[i].dir_x=dir1;
      bullets_arr[i].dir_y=dir2;
   }

   for (int i = 0; i < k; i++) 
   ans+=update(pointer,bullets_arr[i].pos_x,
   bullets_arr[i].pos_y,bullets_arr[i].dir_x,bullets_arr[i].dir_y,n,m);
     
   for (int i = 0; i < n; i++)free(pointer[i]);
   free(pointer);

   cout << n*m-ans<<endl;
   return 0;

}

#include "iostream"
#include "fstream"
#include "math.h"
#include "map"
using namespace std;

ifstream input;

struct block{
    string block_name;
    int sta;
    int end;
} block_list[300];
int cnt=0;

map<string,int> cnt_map;//<name,times>
int max_val=0;
string max_string="";


int utf8_2_unicode(unsigned char *c,int len){
    int ans=0;
    if(len==1)//01xx xxxx
    {
        ans=int(c[0]);
    }
    else if (len==2)//110x xxxx  |  10xx xxxx
    {
        ans+=int((c[0]-128-64));
        ans<<=6;
        ans+=int(c[1]-128);
    }
    else if(len==3)//1110 xxxx | 10xx xxxx | 10xx xxxx
    {
        ans+=int(c[0]-128-64-32);
        ans<<=6;
        ans+=int(c[1]-128);
        ans<<=6;
        ans+=int(c[2]-128);
    }
    else //1111 0xxx | 10xx xxxx | 10xx xxxx| 10xx xxxx
    {
        ans+=int(c[0]-128-64-32-16);
        ans<<=6;
        ans+=int(c[1]-128);
        ans<<=6;
        ans+=int(c[2]-128);
        ans<<=6;
        ans+=int(c[3]-128);
    }
    return ans;
}

void check_range(int c){
    bool bug=true;
    for (int i = 0; i < cnt; i++)
    {
        if(c>= block_list[i].sta && c<=block_list[i].end){//hit
            if(cnt_map.count(block_list[i].block_name)==0){
                cnt_map[block_list[i].block_name]=1;
            }
            else{
                cnt_map[block_list[i].block_name]+=1;
            }
            if(cnt_map[block_list[i].block_name]>max_val){
                max_val=cnt_map[block_list[i].block_name];
                max_string=block_list[i].block_name;
            }
            bug=false;
        }
    }
    if(bug){
        cout <<"!!!!!!!!!!!!!!!"<<endl;
    }
}

int hex_string_to_int(string &s){
    int ans=0;

    for (int i = s.length()-1; i>=0; i--)
    {
        if(s[i]>='A'){
            ans+=(s[i]-'A'+10)*pow(16,s.length()-1-i);
        }
        else{
            ans+=(s[i]-'0')*pow(16,s.length()-1-i);
        }
    }
    return ans;

}

void store(string &s){
    int sta=0;
    int end=0;
    string name="";
    int pos=0;
    while(s[pos]!='.'){
        name+=s[pos++];
    }
    block_list[cnt].sta=hex_string_to_int(name);
    pos+=2;
    name="";
    while(s[pos]!=';'){
        name+=s[pos++];
    }
    block_list[cnt].end=hex_string_to_int(name);
    pos+=2;
    name="";

    for (int i = pos; i < s.length(); i++)
    {
        name+=s[i];
    }
    block_list[cnt++].block_name=name;
}

int main(){
    input.open("./Blocks.txt");
    string s;
    while(getline(input,s)){
        if(s[0]!='#' && s[0]!='\0')
            store(s);
    }
    unsigned char temp_c;
    unsigned char arr[4];
    int c=0;
    int c_max=0;
    int loop_cnt=0;
    while(cin>>temp_c){

        if(temp_c<=127)loop_cnt=1;//0xxx xxxx
        else if(temp_c<=223)loop_cnt=2;//110x xxxx
        else if(temp_c<=239)loop_cnt=3;//1110 xxxx
        else loop_cnt=4;//1111 0xxx
        arr[0]=temp_c;
        for (int i = 1; i < loop_cnt; i++)cin >>arr[i];

        int val=utf8_2_unicode(arr,loop_cnt);
        // cout << val << endl;
        check_range(val);
    }
    cout << max_string<<endl;
    cout << max_val<<endl;

}

#include<iostream>
using namespace std;
class arrlist{
    int size;
    int list[8];
    int cur_pos;
    public:
    arrlist(){
        size=8;
        cur_pos=0;
    }
    bool no_ins_nodes(int pos);
    void ins_at_pos(int pos, int item);
    int del_from_pos(int pos);
    int search(int key);
    void display();
};
bool arrlist::no_ins_nodes(int pos){
    return (cur_pos==size||pos>=cur_pos+1);
}
void arrlist::ins_at_pos(int pos, int item){
    if(no_ins_nodes(pos)){
        cout<<"Cannot insert or delete at this position!"<<endl;
    }
    else{
        int temp;
        temp=cur_pos;
        while(temp!=pos){
            list[temp]=list[temp-1];
            temp--;
        }
        list[pos]=item;
        cur_pos++;
    }
}
int arrlist::del_from_pos(int pos){
    if (no_ins_nodes(pos))
}

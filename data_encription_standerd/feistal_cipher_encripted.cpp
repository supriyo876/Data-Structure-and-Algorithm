#include<iostream>
using namespace std;

 int f(int r,int k){
     return (r+k)%256;

 }
 void encrypt(int &l, int &r,int key[],int round){

    for(int i=0; i<round; i++){
        int newl=r;
        int newr= l ^ f(r,key[i]);

         l = newl;
         r= newr;
    }
}
int main(){

    int l=12;
    int r=34;
    int round=4;
    int key[4] = {5,9,2,7};
    cout << "original :" << l << " "<< r <<endl;

    encrypt(l, r, key, round);

    cout << "encrypted :" << l <<" "<< r <<endl;

    return 0;

}

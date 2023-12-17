#include <iostream>
using namespace std;
#include <vector>
#include<chrono>
void display(vector<int> d1){
    for (int i=0; i<d1.size()-1;i++){
        cout<<d1[i]<<",";
    }
    cout<<d1[d1.size()-1];
}
bool search (int set_num , vector <int> v1){
    for (int i=0; i<v1.size();i++){
        if (v1[i]==set_num){
            return true;
        }
    }
    return false;
}



//bool search(int set_num,vector <int> v1){
//    int a=0;
//    int b =v1.size()-1;
//    while (a<=b){
//        int mid=(a+b)/2;
//        if (v1[mid]==set_num){
//            return (true);
//        }
//        else if (v1[mid]>set_num){
//            b=mid-1;
//        }
//        else{
//            a=mid+1;
//        }
//
//    }
//    return (false);
//}





int binarySearchPosition(vector<int> s1, int data) {
    int low = 0;
    int high = s1.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (s1[mid] == data) {
            return mid;
        } else if (s1[mid] < data) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
int position(vector<int> s1, int data) {
    return binarySearchPosition(s1, data);
}
class object{
public:
    vector <int> v;
    void pushback(int a){
        v.push_back(a);
    }
    void displayed (){
        display(v);
    }
    bool searched(int a){
        bool c;
        c=search(a, v);
        return(c);
    }
    int positioned(int a){
        return (position(v, a));
    }
    int size(){
        return v.size();
    }
    void insertelement(int a, int c){
        vector <int> :: iterator itr = v.begin();
        v.insert (itr+c, a);
    }
    void erased (int a){
        v.erase(v.begin()+a);
    }
};
int insert (vector <object> &v1,int set, int data){
    if (v1[set].searched (data)){
        return (v1[set].size());
    }
    else{
        v1[set].insertelement(data, v1[set].positioned(data));
        return(v1[set].size());
    }
}
int deleteElement (vector <object> &v1,int set, int data){
    if (v1[set].searched(data)){
        v1[set].erased(v1[set].positioned(data));
        return (v1[set].size());
    }
    else{
        return (v1[set].size());
    }
}
int belongto(vector <object> &v1, int set , int data){
    if (v1[set].searched (data)){
        return (1);
    }
    else{
        return (0);
    }
}
int unions(vector <object> &v1, int set1 , int set2){
    vector <int> temp;
    int i,j;
    i=0;
    j=0;
    while (i<v1[set1].size() && j <v1[set2].size()){
        if (v1[set1].v.at(i)==v1[set2].v.at(j)){
            temp.push_back(v1[set2].v.at(j));
            j=j+1;
            i=i+1;}
        else if (v1[set1].v.at(i)<v1[set2].v.at(j)){
            temp.push_back(v1[set1].v.at(i));
            i=i+1;
        }
        else{
            temp.push_back(v1[set2].v.at(j));
            j=j+1;
        }
    }
    while (i<v1[set1].size()){
        temp.push_back(v1[set1].v.at(i));
        i++;
    }
    while (j<v1[set2].size()){
        temp.push_back(v1[set2].v.at(j));
        j++;
    }
    v1[set1].v=temp;
    return v1[set1].size();
}
int intersections(vector <object> &v1, int set1 , int set2){
    vector <int> temp;
    int i,j;
    i=0;
    j=0;
    while (i<v1[set1].size() && j <v1[set2].size()){
        if (v1[set1].v.at(i)<v1[set2].v.at(j)){
            i=i+1;
        }
        else if (v1[set1].v.at(i)==v1[set2].v.at(j)){
            temp.push_back(v1[set2].v.at(j));
            j=j+1;
            i=i+1;
        }
        else{
            j=j+1;
        }
    }
    v1[set1].v=temp;
    return v1[set1].size();
}
int diffs(vector <object> &v1, int set1 , int set2){
    vector <int> temp;
    int i,j;
    i=0;
    j=0;
    while (i<v1[set1].size() && j <v1[set2].size()){
        if (v1[set1].v.at(i)<v1[set2].v.at(j)){
            temp.push_back(v1[set1].v.at(i));
            i=i+1;

        }
        else if (v1[set1].v.at(i)==v1[set2].v.at(j)){
            j=j+1;
            i=i+1;
        }
        else{
            j=j+1;
        }
    }
    while (i<v1[set1].size()){
        temp.push_back(v1[set1].v.at(i));
        i++;
    }
    v1[set1].v=temp;
    return v1[set1].size();
}
int simmdiff(vector <object> &v1, int set1 , int set2){
    vector <int> temp;
    int i,j;
    i=0;
    j=0;
    while (i<v1[set1].size() && j <v1[set2].size()){
        if (v1[set1].v.at(i)==v1[set2].v.at(j)){
            j=j+1;
            i=i+1;}
        else if (v1[set1].v.at(i)<v1[set2].v.at(j)){
            temp.push_back(v1[set1].v.at(i));
            i=i+1;
        }
        else{
            temp.push_back(v1[set2].v.at(j));
            j=j+1;
        }
    }
    while (i<v1[set1].size()){
        temp.push_back(v1[set1].v.at(i));
        i++;
    }
    while (j<v1[set2].size()){
        temp.push_back(v1[set2].v.at(j));
        j++;
    }
    v1[set1].v=temp;
    return v1[set1].size();
}
int size(vector <object> &v1, int set1 ){
    return(v1[set1].size());
}
void displaying(vector <object> &v1, int set1){
    if ((v1[set1].size())==0){

    }
    else{
        v1[set1].displayed();}
}

void mainfunc(vector <object> &v1,int a , int b , int c){
    if (a==1){
        cout<<insert (v1,b,c);
    }
    else if (a==2){
        cout<<deleteElement(v1, b,c);
    }
    else if (a==3){
        cout<<belongto(v1,b,c);
    }
    else if (a==4){
        cout<<unions(v1,b,c);
    }
    else if (a==5){
        cout<<intersections(v1,b,c);
    }
    else if (a==6){
        cout<<size(v1, b);
    }
    else if (a==7){
        cout<<diffs(v1,b,c);
    }
    else if (a==8){
        cout<<simmdiff(v1,b,c);
    }
    else if (a==9){
        displaying(v1,b);
    }
    cout<<endl;
}
int main(){
    auto start_time = std::chrono::high_resolution_clock::now();
    vector <object> v1(100001);
    int a=-1,b=-1,temp;
    while (cin>>temp){
        if (a==-1){
            a=temp;
            temp=0;
        }
        else{
            if (b==-1){
                b=temp;
                if (a==6 || a==9){
//                    cout<<"here1";
                    mainfunc(v1,a,b,temp);
                    temp=0;
                    a=-1;
                    b=-1;
                }
                temp=0;
            }
            else{
//                cout<<"here2";
                mainfunc(v1,a,b,temp);
                temp=0;
                a=-1;
                b=-1;
            }
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
        std::cout << "Time taken: " << duration << " microseconds" << std::endl;

    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    std::cout << "Time taken: " << duration << " microseconds" << std::endl;
}
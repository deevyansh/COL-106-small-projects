#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "BaseClass.h"
#include <iostream>
#include<string>
using namespace std;

class LinearProbing : public BaseClass {
public:
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;

private:
    int sum=0;
    vector <int> balances;
//    int getbluff(string id){
//        int index=hash(id);
//        if (bankStorage1d.size()<=index){
//            bankStorage1d.resize(index+1);
//        }
//        while (bankStorage1d[index].id!=""){
//            if (bankStorage1d.size()<=index){
//                bankStorage1d.resize(index+1);
//            }
//            index++;
//        }
//        return (index);
//    }
//    int getposition(string id){
//        int index=hash(id);
//        if (index>=bankStorage1d.size()){
//            return (-1);
//        }
//        for (int i=index; i<bankStorage1d.size(); i++){
//            if (bankStorage1d[i].id==id){
//                return (i);
//            }
//        }
//        return (-1);
//    }
    int getbluff(const std::string& id) {
        int index = hash(id);

        while (index < bankStorage1d.size() && (bankStorage1d[index].id !="" && bankStorage1d[index].id!="x")) {
            index++;
        }

        // If the index is out of bounds, resize the vector
        if (index >= bankStorage1d.size()) {
            bankStorage1d.resize(index + 1);
        }

        return index;
    }

    int getposition(const std::string& id) {
        for (int i = hash(id); i < bankStorage1d.size(); i++) {
            if (bankStorage1d[i].id == id) {
                return i;
            }
            if (bankStorage1d[i].id==""){
                return -1;
            }

        }
        return -1; // Not found
    }


    int binarySearchPosition(vector<int> &s1, int data) {
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
    int position(vector<int> &s1, int data) {
        return binarySearchPosition(s1, data);
    }
    void insertelement(vector<int> &v,int a, int c){
        vector <int> :: iterator itr = v.begin();
        v.insert (itr+c, a);
    }
//    void deleteElement (vector <int> &v1 ,int data) {
//        for (int i=0; i<v1.size();i++){
//            if (v1[i]==data){
//                v1.erase(v1.begin()+i);
//                break;
//            }
//        }
//    }
    void deleteElement(vector<int> &v1, int data) {
        int index = binarySearchPosition(v1, data); // Find the position of the data using binary search
        if (index < v1.size() && v1[index] == data) {
            v1.erase(v1.begin() + index); // If the element is found, erase it
        }
    }
};

#endif // LINEARPROBING_H
#ifndef COMP_H
#define COMP_H

#include "BaseClass.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Comp : public BaseClass {
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
    vector <int> balances;
    int get_index(string id){
        int index=hash(id);
        if (bankStorage2d.size()<index){
            bankStorage2d.resize(index+1);
        }
        for (int i=0; i<bankStorage2d[hash(id)].size();i++){
            if ((bankStorage2d[hash(id)][i].id)==id){
                return (i);
            }
        }
        return (-1);
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





    // Other data members and functions specific to Your implementation
};

#endif // COMP_H
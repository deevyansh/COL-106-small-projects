#include "LinearProbing.h"
using namespace std;
void LinearProbing::createAccount(std::string id, int count) {
    if (getposition(id)==-1){
        sum++;
        int index= getbluff(id);
        bankStorage1d[index].id=id;
        bankStorage1d[index].balance=count;
        insertelement(balances,count, binarySearchPosition(balances,count));}
    else{
        deleteElement(balances,bankStorage1d[getposition(id)].balance);
        bankStorage1d[getposition(id)].balance=count;
        insertelement(balances,count, binarySearchPosition(balances,count));
    }
    // IMPLEMENT YOUR CODE HERE
}

std::vector<int> LinearProbing::getTopK(int k) {
    if (balances.size()<=k){
        vector<int>v2;
        for (int i=0; i<balances.size();i++){
            v2.push_back(balances[balances.size()-i-1]);
        }
        return (v2);
    }
    else{
        vector<int>v2;
        for (int i=0; i<k;i++){
            v2.push_back(balances[balances.size()-i-1]);
        }
        return (v2);
    }
    // IMPLEMENT YOUR CODE HERE// Placeholder return value
}

int LinearProbing::getBalance(std::string id) {
    if (getposition(id)!=-1){
        return(bankStorage1d[getposition(id)].balance);
    }
    else{
        return (-1);
    }
    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}

void LinearProbing::addTransaction(std::string id, int count) {
    if (getposition(id)!=-1){
        deleteElement(balances,bankStorage1d[getposition(id)].balance);
        bankStorage1d[getposition(id)].balance+=count;
        insertelement(balances,bankStorage1d[getposition(id)].balance, binarySearchPosition(balances,bankStorage1d[getposition(id)].balance));
    }
    else{
        createAccount(id,count);
    }
    // IMPLEMENT YOUR CODE HERE
}

bool LinearProbing::doesExist(std::string id) {
    if (getposition(id)!=-1){
        return true;
    }
    // IMPLEMENT YOUR CODE HERE
    return false; // Placeholder return value
}

bool LinearProbing::deleteAccount(std::string id) {
    if (getposition(id)!=-1){
        sum--;
        int index=getposition(id);
        deleteElement(balances,bankStorage1d[index].balance);
        bankStorage1d[index].id="x";
        bankStorage1d[index].balance=0;
        return true;
    }
    // IMPLEMENT YOUR CODE HERE
    return false; // Placeholder return value
}
int LinearProbing::databaseSize() {
    return (sum);
    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}

int LinearProbing::hash(std::string id) {
    int num =0;
    int i=26;
    for( char c:id){
        num=num+(static_cast<int> (c)*i);
        i=i+1;
    }
    return (num%100003);
//    return (1);

    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}

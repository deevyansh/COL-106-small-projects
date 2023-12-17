#include "Chaining.h"

void Chaining::createAccount(std::string id, int count) {
    Account h;
    h.balance=count;
    h.id=id;
    if (get_index(id)==-1){
        bankStorage2d[hash(id)].push_back(h);
        insertelement(balances,count, position(balances,count));
    }
    else {
        deleteElement(balances,bankStorage2d[hash(id)][get_index(id)].balance);
        bankStorage2d[hash(id)][get_index(id)]=h;
        insertelement(balances,count, position(balances,count));
    }
}

std::vector<int> Chaining::getTopK(int k) {
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
}


int Chaining::getBalance(std::string id) {
    if ((get_index(id))==-1){
        return (-1);
    }
    else{
        return (bankStorage2d[hash(id)][get_index(id)].balance);
    }
    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    if(get_index(id)==-1){
        createAccount(id,count);
    }
    else{
        deleteElement(balances,bankStorage2d[hash(id)][get_index(id)].balance);
        bankStorage2d[hash(id)][get_index(id)].balance+=count;
        int num=bankStorage2d[hash(id)][get_index(id)].balance;
        insertelement(balances,num, binarySearchPosition(balances,num));
    }

    // IMPLEMENT YOUR CODE HERE
}

bool Chaining::doesExist(std::string id) {
    if (get_index(id)!=-1){
        return true;
    }
    // IMPLEMENT YOUR CODE HERE
    return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
    if (get_index(id)!=-1){
        int num =bankStorage2d[hash(id)][get_index(id)].balance;
        deleteElement(balances,num);
        bankStorage2d[hash(id)].erase(bankStorage2d[hash(id)].begin()+ get_index(id));
        return true;
    }

    // IMPLEMENT YOUR CODE HERE
    return false;
    // Placeholder return value
}
int Chaining::databaseSize() {
    return(balances.size());}


    // IMPLEMENT YOUR CODE HERE// Placeholder return value

int Chaining::hash(std::string id) {
    int num =0;
    for( char c:id){
        num=num+static_cast<int> (c);
    }
    return (num%100003);
    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}






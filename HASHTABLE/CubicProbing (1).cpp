#include "CubicProbing.h"
using namespace std;
void CubicProbing::createAccount(std::string id, int count) {

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

std::vector<int> CubicProbing::getTopK(int k) {
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
    // IMPLEMENT YOUR CODE HERE
    // Placeholder return value
}

int CubicProbing::getBalance(std::string id) {
    if (getposition(id)!=-1){
        return(bankStorage1d[getposition(id)].balance);
    }
    else{
        return (-1);
    }
    // IMPLEMENT YOUR CODE HERE
    // Placeholder return value
}

void CubicProbing::addTransaction(std::string id, int count) {
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

bool CubicProbing::doesExist(std::string id) {
    if (getposition(id)!=-1){
        return true;
    }
    // IMPLEMENT YOUR CODE HERE
    return false;
    // IMPLEMENT YOUR CODE HERE
    // Placeholder return value
}

bool CubicProbing::deleteAccount(std::string id) {
    if (getposition(id)!=-1){
        sum--;
        int index=getposition(id);
        deleteElement(balances,bankStorage1d[index].balance);
        bankStorage1d[index].id="x";
        bankStorage1d[index].balance=0;
        return true;
    }
    // IMPLEMENT YOUR CODE HERE
    return false;
    // IMPLEMENT YOUR CODE HERE
    // Placeholder return value
}
int CubicProbing::databaseSize() {

    // IMPLEMENT YOUR CODE HERE
    return (sum); // Placeholder return value
}

int CubicProbing::hash(std::string id) {
    int num =0;
    int i=26;
    for( char c:id){
        num=num+(static_cast<int> (c)*i);
        i=i+1;
    }
    return (num%100003);
}

//#include <chrono> // Include the chrono library
//
//int main() {
//    // Start measuring time
//    auto start = std::chrono::high_resolution_clock::now();
//
//    BaseClass *db = new CubicProbing;
//    db->createAccount("Alice", 400);
//    db->createAccount("Bob", 300);
//    db->createAccount("map", 500);
//    db->getBalance("Alice");
//    db->deleteAccount("Alice");
//    db->addTransaction("Bob", 300);
//    db->getBalance("Bob");
//
//    // Stop measuring time
//    auto stop = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//
//    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
//
//    // Don't forget to clean up memory by deleting db
//    delete db;
//
//    return 0;
//}
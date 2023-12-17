#include "Comp.h"

void Comp::createAccount(std::string id, int count) {
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



    // IMPLEMENT YOUR CODE HERE
}

std::vector<int> Comp::getTopK(int k) {
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

int Comp::getBalance(std::string id) {
    if ((get_index(id))==-1){
        return (-1);
    }
    else{
        return (bankStorage2d[hash(id)][get_index(id)].balance);
    }

    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}

void Comp::addTransaction(std::string id, int count) {
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

bool Comp::doesExist(std::string id) {
    if (get_index(id)!=-1){
        return true;
    }
    // IMPLEMENT YOUR CODE HERE
    return false;
    // IMPLEMENT YOUR CODE HERE
    return false; // Placeholder return value
}

bool Comp::deleteAccount(std::string id) {
    if (get_index(id)!=-1){
        int num =bankStorage2d[hash(id)][get_index(id)].balance;
        deleteElement(balances,num);
        bankStorage2d[hash(id)].erase(bankStorage2d[hash(id)].begin()+ get_index(id));
        return true;
    }

    // IMPLEMENT YOUR CODE HERE
    return false;
    // IMPLEMENT YOUR CODE HERE
     // Placeholder return value
}
int Comp::databaseSize() {
    return(balances.size());
    // IMPLEMENT YOUR CODE HERE
     // Placeholder return value
}

int Comp::hash(std::string id) {
    int num =0;
    for( char c:id){
        num=num+static_cast<int> (c);
    }
    return (num%9971);
    // IMPLEMENT YOUR CODE HERE
     // Placeholder return value
}

//#include <chrono> // Include the chrono library
//
//int main() {
//    // Start measuring time
//    auto start = std::chrono::high_resolution_clock::now();
//
//    BaseClass *db = new Comp;
//    db->createAccount("Alice", 400);
//    db->createAccount("Bob", 300);
//    db->createAccount("map", 500);
//    cout<<db->getBalance("Alice");
//    db->deleteAccount("Alice");
//    db->addTransaction("Bob", 300);
//    cout<<db->getBalance("Bob");
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
// Feel free to add any other helper functions you need
// Good Luck!
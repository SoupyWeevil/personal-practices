#include <iostream>
#include <string>
using namespace std;

int F(int n);

int main(){
    int userChoice;
    cout << "Enter a choice: ";
    cin >> userChoice;

    if(!cin || (userChoice < 0)){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "This is not a valid option! Try again: ";
        cin >> userChoice;
    }
    cin.ignore();

    cout << F(userChoice + 1) << endl;
}

int F(int n){
    if(n <= 1){
        return n;
    }else{
        return F(n - 1) + F(n - 2);
    }
}
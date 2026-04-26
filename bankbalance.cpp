#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
private:
    unordered_map<int, long long> accounts;

public:

    bool CREATE(int X, long long Y) {
        if (accounts.find(X) == accounts.end()) {
            accounts[X] = Y;
            return true;
        }
        else {
            accounts[X] += Y;
            return false;
        }
    }

    bool DEBIT(int X, long long Y) {
        if (accounts.find(X) == accounts.end() || accounts[X] < Y)
            return false;

        accounts[X] -= Y;
        return true;
    }

    bool CREDIT(int X, long long Y) {
        if (accounts.find(X) == accounts.end())
            return false;

        accounts[X] += Y;
        return true;
    }

    long long BALANCE(int X) {
        if (accounts.find(X) == accounts.end())
            return -1;

        return accounts[X];
    }
};

int main() {

    int Q;
    cin >> Q;

    Bank obj;

    while(Q--) {

        string query;
        cin >> query;

        if(query == "CREATE") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (obj.CREATE(X,Y) ? "true" : "false") << endl;
        }

        else if(query == "DEBIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (obj.DEBIT(X,Y) ? "true" : "false") << endl;
        }

        else if(query == "CREDIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (obj.CREDIT(X,Y) ? "true" : "false") << endl;
        }

        else if(query == "BALANCE") {
            int X;
            cin >> X;
            cout << obj.BALANCE(X) << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, set<int>> movieBookings;
    unordered_map<int, int> available;

public:

    bool BOOK(int X, int Y) {
        if(available[Y] == 0 && movieBookings.find(Y) != movieBookings.end())
            return false;

        if(movieBookings[Y].count(X))
            return false;

        if(available[Y] == 0)
            return false;

        movieBookings[Y].insert(X);
        available[Y] = (available[Y] == 0 ? 99 : available[Y] - 1);
        return true;
    }

    bool CANCEL(int X, int Y) {
        if(!movieBookings[Y].count(X))
            return false;

        movieBookings[Y].erase(X);
        available[Y]++;
        return true;
    }

    bool IS_BOOKED(int X, int Y) {
        return movieBookings[Y].count(X);
    }

    int AVAILABLE_TICKETS(int Y) {
        if(available.find(Y) == available.end())
            return 100;
        return available[Y];
    }
};

int main() {

    int Q;
    cin >> Q;

    MovieTicket obj;

    while(Q--) {

        string query;
        cin >> query;

        if(query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (obj.BOOK(X, Y) ? "true" : "false") << endl;
        }

        else if(query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (obj.CANCEL(X, Y) ? "true" : "false") << endl;
        }

        else if(query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (obj.IS_BOOKED(X, Y) ? "true" : "false") << endl;
        }

        else if(query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << obj.AVAILABLE_TICKETS(Y) << endl;
        }
    }

    return 0;
}
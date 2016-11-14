#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void kill () {
        cout << -1 << endl;
        exit (EXIT_FAILURE);
}

class SSN {
        public:
                long ssn = 0;
                string address = "";
                string name = "";
                bool operator<(const SSN& rhs) const {
                        return ssn < rhs.ssn;
                }
                bool operator<(const long rhs) const {
                        return ssn < rhs;
                }
};

int main() {
        vector<SSN> db;
        map<string,long> dbMap;
        int counter = 0;
        while (true) {
                db.push_back(SSN());
                string newName, newAddress;
                long newSSN = 0;

                getline(cin, newName);
                if (isdigit(newName[0])) kill();
                if (newName == "done") break;
                db.back().name = newName;

                getline(cin, newAddress);
                db.back().address = newAddress;

                cin >> newSSN;
                if (!cin) kill();
                db.back().ssn = newSSN;
                if (db.front().ssn == db.back().ssn && counter == 1) kill();

                dbMap[newName] = newSSN;
                counter++;
                cin.ignore();
        }
        sort(db.begin(), db.end());
        while (true) {
                int c = cin.peek();
                if (c == EOF) break;
                long numSearch;
                string strSearch;

                if (isdigit(cin.peek())) {
                        cin >> numSearch;
                        vector<SSN>::iterator it = lower_bound(db.begin(), db.end(), numSearch);
                        if(it != db.end() && !(numSearch < it->ssn)) {
                                cout << it->name << endl;
                                cout << it->address << endl;
                                cout << it->ssn << endl;
                        }
                        cin.ignore();
                }
                else {
                        getline(cin, strSearch);
                        if (strSearch == "done") return 0;
                        if(dbMap.count(strSearch) == 0) kill();
                        vector<SSN>::iterator it = lower_bound(db.begin(), db.end(), dbMap[strSearch]);
                        if (it != db.end()) {
                                        cout << it->name << endl;
                                        cout << it->address << endl;
                                        cout << it->ssn << endl;
                        }
                }
        }
}


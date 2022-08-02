#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main () {
    //creation
    unordered_map<string, int> m;

    //insertion

    //1
    pair<string, int> p = make_pair("shreyansh", 3);
    m.insert(p);

    //2
    pair<string,int>  pair2("thakur", 2);
    m.insert(pair2);

    //3
    m["my"] = 1;

    //what will happen
    m["my"] = 2;


    //Search
    cout << m["my"] << endl;
    cout << m.at("shreyansh") << endl;

    cout << m["unknownKey"] << endl;//isse entry create hogi with 0 value
    cout << m.at("unknownKey") << endl;//isse uss jagah kya value hai vo ayegi

    //size
    cout << m.size() << endl;

    //to check presence 
    cout << m.count("shreyansh") << endl;//koi key absent to 0 dega vrna 1 dega 

    //erase
    m.erase("shreyansh");
    cout << m.size();


    //for traversal
    //1
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    //2
    unordered_map<string, int> :: iterator it = m.begin();

    while (it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }


    return 0;
}
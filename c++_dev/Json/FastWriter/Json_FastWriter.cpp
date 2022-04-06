#include </usr/include/json/json.h>
#include <iostream>
#include <map>

using namespace std;

map<int, string> m;

#define KEY "key"
#define KEY_PROFILE_ID "profileid"
#define KEY_USER_ID "userid"

int main(void)
{

    m.insert(pair<int, string>(0, "user_A"));

    m.insert(pair<int, string>(1, "user_B"));
    m.insert(pair<int, string>(3, "user_C"));
    m.insert(pair<int, string>(55, "user_D"));

    Json::FastWriter writer;
    Json::Value root;

    for (auto it = m.begin(); it != m.end(); it++) {
        Json::Value item;
        item[KEY_PROFILE_ID] = it->first;
        item[KEY_USER_ID] = it->second.c_str();
        root[KEY].append(item);
    }

    std::string data = writer.write(root);
    cout << __func__ << " data : " << data.c_str() << endl;

    return 0;
}
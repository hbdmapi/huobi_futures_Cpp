#include <string>
using std::string;

#include <map>
using std::map;
using std::pair;

map<string, string> config;

void init_config()
{
    config.insert(pair<string,string>("Host", "api.hbdm.com"));
    config.insert(pair<string,string>("AccessKey", "x-x-x-x"));
    config.insert(pair<string,string>("SecretKey", "x-x-x-x"));
    config.insert(pair<string,string>("AccountId", "xxxxxxxx"));
    config.insert(pair<string,string>("SubUid", "xxxxxxxx"));
}
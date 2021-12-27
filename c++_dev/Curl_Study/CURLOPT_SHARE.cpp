#include "/home/kukjin.chung/proteus_work/QNX/qnx700/target/qnx7/usr/include/curl/curl.h"
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

    CURL* curl = curl_easy_init();
    CURL* curl2 = curl_easy_init(); /* a second handle */
    if (curl) {
        CURLSH* shobject = curl_share_init();
        curl_share_setopt(shobject, CURLSHOPT_SHARE, CURL_LOCK_DATA_COOKIE);

        curl_easy_setopt(curl, CURLOPT_URL, "https://google.com/");
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/home/kukjin.chung/SWstudy/github/SWstudy/Curl_Study/cookie");
        curl_easy_setopt(curl, CURLOPT_SHARE, shobject);
        int ret = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        /* the second handle shares cookies from the first */
        curl_easy_setopt(curl2, CURLOPT_URL, "https://example.com/second");
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/home/kukjin.chung/SWstudy/github/SWstudy/Curl_Study/cookie");
        curl_easy_setopt(curl2, CURLOPT_SHARE, shobject);
        ret = curl_easy_perform(curl2);
        curl_easy_cleanup(curl2);

        curl_share_cleanup(shobject);
    }

    return 0;
}

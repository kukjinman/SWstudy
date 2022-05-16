#include "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Curl_Study/curl_files/curl.h"
#include <algorithm>
#include <iostream>

using namespace std;
static constexpr const long MAX_TOTAL_CONNECTIONS = 15;

void get_message()
{
    cout << " get_message() " << endl;

    CURLM* g_multi_handle;
    g_multi_handle = curl_multi_init();

    if (g_multi_handle) {
        CURLMcode errCode = CURLM_OK;

        /* never do more than 15 connections */
        errCode = curl_multi_setopt(g_multi_handle, CURLMOPT_MAX_TOTAL_CONNECTIONS, MAX_TOTAL_CONNECTIONS);
        if (CURLM_OK != errCode) {
            // log error
            cout << "CURL Setup Error = " << curl_multi_strerror(errCode) << endl;
        }

        // CURLPIPE_MULTIPLEX (bit 2) : For multiplexing, this means that follow-up requests can re-use an existing connection and send
        // the new request multiplexed over that at the same time as other transfers are already using that single connection.
        errCode = curl_multi_setopt(g_multi_handle, CURLMOPT_PIPELINING, CURLPIPE_MULTIPLEX);
        if (CURLM_OK != errCode) {
            // log error
            cout << "[CURL] ipelining Option Error = " << curl_multi_strerror(errCode) << endl;
        }
    }

    CURLMsg* msg; /* for picking up messages with the transfer status */
    int msgs_left; /* how many messages are left */

    /* See how the transfers went */
    while ((msg = curl_multi_info_read(g_multi_handle, &msgs_left))) {
        if (msg->msg == CURLMSG_DONE) {
            CURL* handle = msg->easy_handle;

            curl_multi_remove_handle(g_multi_handle, handle);

            const CURLcode curlCode = msg->data.result;

            if (curlCode != CURLE_OK) {
                //2021-06-07 Applied new patch from SXM triage team
                /*char *last_url = nullptr;
                curl_easy_getinfo (handle, CURLINFO_EFFECTIVE_URL, &last_url);
                LOGE() << "ERROR: HTTP transfer completed with status " << msg->data.result << ", url: " << last_url;*/
                cout << "ERROR: HTTP transfer completed with status " << msg->data.result << endl;
            }
        }
    }
}

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

    get_message();

    return 0;
}

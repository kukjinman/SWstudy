#include <cstring>
#include <errno.h>
#include <iostream>
#include <spawn.h>
#include <stdio.h>
#include <sys/wait.h>

using namespace std;

int execute(const char* path, char* const argv[])
{
    pid_t pid;
    int ret = posix_spawn(&pid, path, NULL, NULL, argv, NULL);

    cout << "ret : " << ret << endl;

    if (ret != 0) {
        printf("posix_spawn() failed: %s\n", strerror(ret));
        return EXIT_FAILURE;
    }

    int status;
    waitpid(pid, &status, 0);

    return ret;
}

int main(int argc, char* argv[])
{
    const char* path = "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Thread_Study/4_posix_spawn/test.out";
    char* const argv_A[] = { "1 3", NULL };

    execute(path, argv_A);

    return 0;
}
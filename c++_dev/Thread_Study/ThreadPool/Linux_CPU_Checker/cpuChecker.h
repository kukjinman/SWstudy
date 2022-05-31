
//This code is refferanced by https://hashcode.co.kr/questions/290/%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4-%EC%95%88%EC%97%90%EC%84%9C-cpu-memory-%EC%86%8C%EB%B9%84%EB%9F%89-%EC%95%8C%EC%95%84%EB%82%B4%EB%8A%94-%EB%B2%95

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/times.h"
#include "sys/vtimes.h"

static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

void cpuChcker_init()
{
    FILE* file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "processor", 9) == 0)
            numProcessors++;
    }
    fclose(file);
}

double getCurrentValue()
{
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU || timeSample.tms_utime < lastUserCPU) {
        //오버플로우 감지
        percent = -1.0;
    } else {
        percent = (timeSample.tms_stime - lastSysCPU) + (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}

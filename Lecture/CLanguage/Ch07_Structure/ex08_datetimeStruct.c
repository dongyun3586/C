#include <stdio.h>
#include <time.h>

struct TIME {
    int seconds;
    int minutes;
    int hours;
};

void differenceBetweenTimePeriod(struct TIME t1, struct TIME t2, struct TIME* diff);

int main() {
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    struct TIME currentTime, alarmTime, diff;

    // 알람 시간 입력
    printf("Alarm time(hours, minutes, seconds) : ");
    scanf("%d %d %d", &alarmTime.hours, &alarmTime.minutes, &alarmTime.seconds);

    // 현재 시간 저장
    currentTime.hours = t->tm_hour;
    currentTime.minutes = t->tm_min + 1;
    currentTime.seconds = t->tm_sec;

    // 알람이 울릴 때까지 남은 시간 구하기
    differenceBetweenTimePeriod(currentTime, alarmTime, &diff);
    printf("%d:%d:%d - ", alarmTime.hours, alarmTime.minutes, alarmTime.seconds);
    printf("%d:%d:%d = ", currentTime.hours, currentTime.minutes, currentTime.seconds);

    printf("%d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);
    return 0;
}

// 알람이 울릴 때까지 남은 시간 구하기
void differenceBetweenTimePeriod(struct TIME currentTime, struct TIME alarmTime, struct TIME* diff) {
    if (currentTime.seconds > alarmTime.seconds) {
        alarmTime.minutes--;
        alarmTime.seconds += 60;
    }
    diff->seconds = alarmTime.seconds - currentTime.seconds;
    if (currentTime.minutes > alarmTime.minutes) {
        --alarmTime.hours;
        alarmTime.minutes += 60;
    }
    diff->minutes = alarmTime.minutes - currentTime.minutes;
    if (currentTime.hours > alarmTime.hours) {
        alarmTime.hours += 24;
    }
    diff->hours = alarmTime.hours - currentTime.hours;
}
#include <stdio.h>

int compareTo (int dayInput, int monthInput, int yearInput);

int main() {
    int m[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

    int dayStart = 4, monthStart = 10, yearStart = 2019, dayOfWeek = 6;
    int dayInput, monthInput, yearInput;
    scanf("%d %d %d", &dayInput, &monthInput, &yearInput);

    if ((yearInput % 400 == 0) || (yearInput % 4 == 0 && yearInput % 100 != 0)) {
        m[2] = 29;
    }

    if (dayInput > m[monthInput % 12] || dayInput < 0) {
        printf("Error");
        return 0;
    }
    
    if (monthInput > 12 || monthInput < 0) {
        printf("Error");
        return 0;
    }
    
    if (yearInput < 1000 || yearInput > 9999) {
        printf("Error");
        return 0;
    }

    int tempCheckCompare = compareTo(dayInput, monthInput, yearInput);

    if (tempCheckCompare < 0) {
        while (dayStart != dayInput || monthStart != monthInput || yearStart != yearInput) {
            dayStart--;
            dayOfWeek = ((dayOfWeek - 1) + 7) % 7;
            if (dayStart < 1) {
                monthStart = ((monthStart - 1) + 12) % 12;
                dayStart = m[monthStart % 12];
                if (monthStart < 1) {
                    monthStart = 12;
                    yearStart--;
                }
            }
        }
    }
    else if (tempCheckCompare > 0) {
        while (dayStart != dayInput || (monthStart != monthInput % 12)|| yearStart != yearInput) {
            dayStart++;
            dayOfWeek = (dayOfWeek + 1) % 7;
            if (dayStart > m[monthStart % 12]) {
                dayStart = 1;
                monthStart = (monthStart + 1) % 12;
                if (monthStart == 1) {
                    yearStart++;
                }
            }
        }
    }
    else {
        printf("%d", dayOfWeek);
        return 0;
    }

    if (dayOfWeek == 1) {
        printf("CN");
    }
    else if (dayOfWeek == 0) {
        printf("7");
    }
    else {
        printf("%d", dayOfWeek);
    }

    return 0;
}

int compareTo (int dayInput, int monthInput, int yearInput) {
    int dayStart = 4, monthStart = 10, yearStart = 2019;

    if (yearInput > yearStart) {
        return 1;
    }
    if (yearInput < yearStart) {
        return -1;
    }

    if (monthInput > monthStart) {
        return 1;
    }
    if (monthInput < monthStart) {
        return -1;
    }

    if (dayInput > dayStart) {
        return 1;
    }
    if (dayInput < dayStart) {
        return -1;
    }

    return 0;
}
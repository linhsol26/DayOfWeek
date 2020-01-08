#include <stdio.h>

int compareTo (int dayInput, int monthInput, int yearInput);
int isLeapYear (int yearInput);

int main() {
    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* thu[7] = {"2", "3", "4", "5", "6", "7", "CN"};

    int dayStart = 4, monthStart = 10, yearStart = 2019, dayOfWeek = 4;
    int dayInput, monthInput, yearInput;
    scanf("%d %d %d", &dayInput, &monthInput, &yearInput);

    if (isLeapYear(yearInput) == 1) {
        m[2] = 29; //thang 2
    }
    else {
        m[2] = 28;
    }

    if (dayInput > m[monthInput] || dayInput < 0) {
        printf("Error");
        return 0;
    }
    
    if (monthInput > 12 || monthInput < 1) {
        printf("Error");
        return 0;
    }
    
    if (yearInput < 1000 || yearInput > 9999) {
        printf("Error");
        return 0;
    }
    
    int tempCheckCompare = compareTo(dayInput, monthInput, yearInput);
    int count = 0;
    if (isLeapYear(yearStart) == 1) {
        m[2] = 29;
    }
    else {
        m[2] = 28;
    }

    if (tempCheckCompare < 0) {
        while (dayStart != dayInput || monthStart != monthInput || yearStart != yearInput) {
            dayStart--;
            dayOfWeek = ((dayOfWeek - 1) + 7) % 7; //roll back
            if (dayStart == 0) {
                monthStart--;
                if (monthStart == 0) { //thang 12
                    monthStart = 12; 
                    yearStart--; //lui nam
                    if (isLeapYear(yearStart) == 1) {
                        m[2] = 29; //thang 2
                    }
                    else {
                        m[2] = 28;
                    }
                }
                dayStart = m[monthStart];
            }
        }
    }
    else if (tempCheckCompare > 0) {
        while (dayStart != dayInput || (monthStart != monthInput) || yearStart != yearInput) {
            dayStart++;
            dayOfWeek = (dayOfWeek + 1) % 7;
            if (dayStart > m[monthStart]) {
                dayStart = 1;
                monthStart = (monthStart + 1);
                if (monthStart == 13) {
                    monthStart = 1;
                    yearStart++;
                    if (isLeapYear(yearStart) == 1) {
                        m[2] = 29;
                        count++;
                    }
                    else {
                        m[2] = 28;
                    }
                }
            }
        }
    }

    printf("%s", thu[dayOfWeek]);
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

int isLeapYear (int yearStart) {
    if (yearStart % 400 == 0) {
        return 1;
    }  
    if ((yearStart % 4 == 0 && yearStart % 100 != 0)) {
        return 1;
    }
    return 0;
}
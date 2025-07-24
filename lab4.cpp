#include <stdio.h>

int main() {
    char empID[20];
    float hoursWorked, hourlyRate, totalPay;

    // รับค่าข้อมูลจากผู้ใช้
    printf("ป้อนรหัสพนักงาน: ");
    scanf("%19s", empID);

    printf("ป้อนจำนวนชั่วโมงที่ทำงาน: ");
    scanf("%f", &hoursWorked);

    printf("ป้อนรายได้ต่อชั่วโมง: ");
    scanf("%f", &hourlyRate);

    // คำนวณรายได้ทั้งหมด
    totalPay = hoursWorked * hourlyRate;

    // แสดงผล
    printf("\nรหัสพนักงาน: %s\n", empID);
    printf("รายได้ทั้งหมด: %.2f บาท\n", totalPay);

    return 0;
}
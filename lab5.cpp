#include <stdio.h>

int main(void) {
    float score;
    char *grade;  // เปลี่ยนเป็น pointer ไปยัง string สำหรับ C+ D+

    printf("กรุณาใส่คะแนนดิบ: ");
    if (scanf("%f", &score) != 1) {
        printf("ข้อมูลไม่ถูกต้อง\n");
        return 1;
    }

    // ตรวจสอบเกรดตามเกณฑ์
    if (score < 0 || score > 100) {
        grade = "Invalid";
    } else if (score < 50) {
        grade = "F";
    } else if (score < 55) {
        grade = "D";
    } else if (score < 60) {
        grade = "D+";
    } else if (score < 65) {
        grade = "C";
    } else if (score < 70) {
        grade = "C+";
    } else if (score < 75) {
        grade = "B";
    } else if (score < 80) {
        grade = "B+";
    } else {
        grade = "A";
    }

    printf("คะแนนดิบ: %.2f -> เกรด: %s\n", score, grade);
    return 0;
}

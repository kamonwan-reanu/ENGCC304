#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    int secret, guess;
    int score = 100;

    // สุ่มตัวเลขระหว่าง 1 ถึง 100
    secret = rand() % 100 + 1;

    printf("เริ่มเกมทายตัวเลข (1 ถึง 100)\n");

    while (1) {
        printf("กรุณาใส่ตัวเลขที่คุณทาย: ");
        scanf("%d", &guess);

        if (guess == secret) {
            printf("ยินดีด้วย! คุณทายถูกต้อง คะแนนของคุณคือ %d\n", score);
            break;
        } else {
            score -= 10;
            if (score <= 0) {
                printf("คุณแพ้! คะแนนของคุณหมดแล้ว คำตอบที่ถูกคือ %d\n", secret);
                break;
            }

            if (guess < secret) {
                printf("มากกว่า! คะแนนปัจจุบันของคุณคือ %d\n", score);
            } else {
                printf("น้อยกว่า! คะแนนปัจจุบันของคุณคือ %d\n", score);
            }
        }
    }
}

int main() {
    int choice;

    // สุ่มเลขตามเวลาปัจจุบัน
    srand(time(NULL));

    do {
        playGame();

        printf("\nหากต้องการเล่นอีกครั้ง พิมพ์ 1\nหากต้องการออกจากเกม พิมพ์ -1\n");
        printf("กรุณาใส่ตัวเลือกของคุณ: ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("ขอบคุณที่เล่นเกม!\n");

    return 0;
}

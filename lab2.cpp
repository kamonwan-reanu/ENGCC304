#include <stdio.h>

#define NUM_ITEMS 7

typedef struct {
    const char *name;
    int price;  // ราคาเป็นบาท (หน่วย: บาทตรง)
    int qty;
} Item;

void displayItems(Item items[]) {
    printf("\n=== รายการสินค้า ===\n");
    for(int i=0;i<NUM_ITEMS;i++){
        printf("%d. %-15s %2d บาท (คงเหลือ %d)\n",
               i+1, items[i].name, items[i].price, items[i].qty);
    }
}

void giveChange(int change) {
    printf("เงินทอน: %d บาท\n", change);
    int denom[] = {20,10,5,1};
    int count;
    for(int i=0;i<4;i++){
        count = change / denom[i];
        if(count){
            printf("  %d x %d บาท\n", count, denom[i]);
            change -= count * denom[i];
        }
    }
}

int main(){
<<<<<<< HEAD
    Item items[NUM_ITEMS] = {
        {"โค้ก",10,10},
        {"น้ำเขียว",12,10},
        {"เมล็ดทานตะวัน",13,10},
        {"ถั่วแปบ",20,10},
        {"จิ้นส้มหมก",15,10},
        {"อเมริกาโน่",30,10},
        {"ลาเต้ หวานเจี๊ยบ",35,10}
    };
    int balance = 0;
    int choice, done = 0;
    int totalCost = 0;

    printf("=== เครื่องขายน้ำ \"ตะพาบลอย\" ===\n");

    while(!done) {
        printf("\n1=หยอดเงิน  2=เลือกสินค้า  3=จบการซื้อ\n");
        printf("เลือก: "); scanf("%d",&choice);

        if(choice == 1){
            int amt;
            printf("หยอดเงิน (ใส่จำนวนบาท): "); scanf("%d",&amt);
            balance += amt;
            printf("ยอดเงินสะสม: %d บาท\n", balance);
        }
        else if(choice == 2){
            displayItems(items);
            printf("เลือกสินค้า (หมายเลข): "); scanf("%d",&choice);
            if(choice < 1 || choice > NUM_ITEMS){
                printf("ไม่มีรายการนั้น\n");
            } else if(items[choice-1].qty <= 0){
                printf("สินค้าหมด\n");
            } else if(balance < items[choice-1].price){
                printf("เงินไม่พอ ต้อง %d บาท\n", items[choice-1].price);
            } else {
                items[choice-1].qty--;
                balance -= items[choice-1].price;
                totalCost += items[choice-1].price;
                printf("คุณซื้อ %s ราคา %d บาท\n",
                       items[choice-1].name, items[choice-1].price);
            }
        }
        else if(choice == 3){
            done = 1;
        }
        else {
            printf("คำสั่งไม่ถูกต้อง\n");
=======
    cout << "*** เครื่องขายน้ำอัตโนมัติ ***\n";
    while(true) {
        cout << "\nใส่เหรียญหรือธนบัตร (1,5,10,20,50,100) หรือ 0 เพื่อยกเลิก\n> ";
        int coin;
        cin >> coin;
        if (coin == 0) {
            if (balance > 0) {
                auto ret = make_change(balance);
                cout << "คืนเงินเต็มจำนวน:\n";
                for (auto &c : ret)
                    if (c.second > 0)
                        cout << c.first << " บาท x " << c.second << "\n";
                balance = 0;
            }
            continue;
        }
        insert_coin(coin);

        cout << "ต้องการซื้อสินค้าหรือไม่? พิมพ์ 'y' เพื่อเลือก , อื่นๆ เพื่อใส่เงินต่อ\n> ";
        char cmd;
        cin >> cmd;
        if (cmd == 'y' || cmd == 'Y') {
            select_product();
>>>>>>> a6e8563 (adsf)
        }
    }

    printf("\n=== สรุปยอด ===\n");
    printf("ยอดจ่ายทั้งหมด: %d บาท\n", totalCost);
    printf("ยอดเงินเหลือในตู้อีก: %d บาท\n", balance);
    if(balance>0){
        giveChange(balance);
    }
    printf("ขอบคุณที่ใช้บริการครับ\n");
    return 0;
}

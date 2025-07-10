#include <iostream>
#include <map>
#include <vector>
using namespace std;

// สินค้าและราคา
map<string,int> prices = {
    {"Coke", 10}, {"Sunflower", 13}, {"GreenTea", 12},
    {"PeanutBar", 20}, {"Americano", 30},
    {"OrangeSnack", 15}, {"LatteSweet", 35}
};

// พื้นที่เก็บสินค้า
map<string,int> inventory = {
    {"Coke", 10}, {"Sunflower", 5}, {"GreenTea", 5},
    {"PeanutBar", 5}, {"Americano", 5},
    {"OrangeSnack", 5}, {"LatteSweet", 5}
};

// เหรียญที่รับ
vector<int> accepted = {1,5,10,20,50,100};

int balance = 0;

// ฟังก์ชันรับเงิน
void insert_coin(int amount) {
    bool ok = false;
    for (int v : accepted)
        if (v == amount) { ok = true; break; }
    if (ok) {
        balance += amount;
        cout << "ยอดเงินปัจจุบัน: " << balance << " บาท\n";
    } else {
        cout << "เหรียญไม่รับ กรุณาใส่ใหม่!\n";
    }
}

// แสดงสินค้า
void show_products() {
    cout << "สินค้าที่มีจำหน่าย:\n";
    for (auto &p : prices) {
        cout << "- " << p.first
             << " ราคา " << p.second
             << " บาท (เหลือ " << inventory[p.first] << ")\n";
    }
}

// คืนเงินทอน
map<int,int> make_change(int money) {
    map<int,int> coins;
    for (int v : accepted) coins[v] = 0;
    for (int i = accepted.size()-1; i>=0; --i) {
        int v = accepted[i];
        coins[v] = money / v;
        money %= v;
    }
    return coins;
}

// ฟังก์ชันเลือกสินค้า
void select_product() {
    show_products();
    cout << "เลือกสินค้า (พิมพ์ชื่อสินค้าที่ตรง), หรือ 'cancel' เพื่อคืนเงิน\n> ";
    string choice;
    cin >> choice;

    if (choice == "cancel") {
        auto ret = make_change(balance);
        cout << "คืนเงินทอน:\n";
        for (auto &c : ret)
            if (c.second > 0)
                cout << c.first << " บาท x " << c.second << "\n";
        balance = 0;
        return;
    }

    if (!prices.count(choice)) {
        cout << "สินค้าไม่มีในระบบ\n";
        return;
    }
    if (inventory[choice] == 0) {
        cout << "สินค้าหมด\n";
        return;
    }
    int price = prices[choice];
    if (balance < price) {
        cout << "ยอดเงินไม่พอ! ยังขาดอีก " << (price - balance) << " บาท\n";
        return;
    }

    // จ่ายสินค้า
    balance -= price;
    inventory[choice]--;
    cout << "รับสินค้า: " << choice << " ราคา " << price << " บาท\n";

    if (balance > 0) {
        auto ret = make_change(balance);
        cout << "เงินทอนคืน:\n";
        for (auto &c : ret)
            if (c.second > 0)
                cout << c.first << " บาท x " << c.second << "\n";
    }
    balance = 0;
    cout << "ขอบคุณที่ใช้บริการ!\n";
}

int main(){
    cout << "*** เครื่องขายน้ำอัตโนมัติ ตะพาบลอย ***\n";
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

        cout << "ต้องการซื้อสินค้าหรือไม่? พิมพ์ 'y' เพื่อเลือก, อื่นๆ เพื่อใส่เงินต่อ\n> ";
        char cmd;
        cin >> cmd;
        if (cmd == 'y' || cmd == 'Y') {
            select_product();
        }
    }
    return 0;
}
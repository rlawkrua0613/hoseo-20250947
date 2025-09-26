#include <stdio.h>
#define MAX 100

void item_id(int* count) {
    printf("상품 id: ");
    for (int i = 0; i < *count; i++) {
        printf("%d ", i + 1);
    }
}

void items(int* count, int* item) {
    for (int i = 0; i < *count; i++) {
        printf("상품 id %d의 입고수량: ", i + 1);
        scanf("%d", &item[i]);
    }
}

void ITEM(int* id, int* item) {
    printf("입고량을 개별 입력할 상품id를 입력하세요: ");
    scanf("%d", id);
    printf("상품id %d의 입고수량을 입력하세요: ", *id);
    scanf("%d", &item[*id - 1]);
}

void sold(int* count, int* sale) {
    for (int i = 0; i < *count; i++) {
        printf("상품 id %d의 판매수량: ", i + 1);
        scanf("%d", &sale[i]);
    }
}

void sold_one(int* id, int* sale) {
    printf("판매량을 개별 입력할 상품id를 입력하세요: ");
    scanf("%d", id);
    printf("상품id %d의 판매수량을 입력하세요: ", *id);
    scanf("%d", &sale[*id - 1]);
}

void stock(int* count, int* item, int* sale) {
    printf("상품별 재고수량: ");
    for (int i = 0; i < *count; i++) {
        printf("%d ", item[i] - sale[i]);
    }
}

void total_sale(int* count, int* sale, int* item) {
    int sale_sum = 0;
    int item_sum = 0;
    for (int i = 0; i < *count; i++) {
        sale_sum += sale[i];
        item_sum += item[i];
    }
    float rate = ((float)sale_sum / item_sum) * 100;
    printf("총 판매량: %d (판매율: %.2f%%)", sale_sum, rate);
}

void sale_max(int* count, int* sale) {
    int max = sale[0];
    for (int i = 0; i < *count; i++) {
        if (sale[i] > max) {
            max = sale[i];
        }
    }
    printf("가장 많이 팔린 상품: ");
    for (int i = 0; i < *count; i++) {
        if (sale[i] == max) {
            printf("id: %d ", i + 1);
        }
    }
    printf("(판매량: %d)", max);
}

void sale_min(int* count, int* sale) {
    int min = sale[0];
    for (int i = 0; i < *count; i++) {
        if (sale[i] < min) {
            min = sale[i];
        }
    }
    printf("가장 적게 팔린 상품: ");
    for (int i = 0; i < *count; i++) {
        if (sale[i] == min) {
            printf("id: %d ", i + 1);
        }
    }
    printf("(판매량: %d)", min);
}

void stock_warning(int* count, int* item, int* sale) {
    for (int i = 0; i < *count; i++) {
        if (item[i] - sale[i] < 3) {
            printf("상품id %d: 재고부족(%d)\n", i + 1, item[i] - sale[i]);
        }
    }

}

int main() {
    int count;
    int menu;
    int item_menu;
    int sale_menu;
    int id;
    int item[MAX] = { 0 };
    int sale[MAX] = { 0 };

    printf("상품 개수를 입력하세요: ");
    scanf("%d", &count);

    item_id(&count);
    printf("\n");

    while (1) {
        printf("원하는 메뉴를 선택하세요.(1.입고 2.판매 3.상품현황 4.종료): ");
        scanf("%d", &menu);
               
        if (menu == 1) {
            printf("원하는 입고메뉴를 선택하세요.(1.전체 상품의 입고수량 입력 2.입고량 개별상품 입력): ");
            scanf("%d", &item_menu);
            printf("\n");
            if (item_menu == 1) {
                items(&count, item);
                printf("\n");
                continue;
            }
            else if (item_menu == 2) {
                ITEM(&id, item);
                printf("\n");
                continue;
            }
            else {
                printf("올바른 메뉴를 입력해주세요. 메뉴창으로 돌아갑니다.\n");
                continue;
            }
        }
        else if (menu == 2) {
            printf("원하는 판매메뉴를 선택하세요.(1.전체 상품의 판매수량 입력 2.판매량 개별상품 입력): ");
            scanf("%d", &sale_menu);
            printf("\n");
            if (sale_menu == 1) {
                sold(&count, sale);
                printf("\n");
                continue;
            }
            else if (sale_menu == 2) {
                sold_one(&id, sale);
                printf("\n");
                continue;
            }
            else {
                printf("올바른 메뉴를 입력해주세요. 메뉴창으로 돌아갑니다.\n");
                continue;
            }
        }
        else if (menu == 3) {
            printf("\n");
            
            stock(&count, item, sale);
            printf("\n");

            stock_warning(&count, item, sale);
            printf("\n");

            total_sale(&count, sale, item);
            printf("\n");
            
            sale_max(&count, sale);
            printf("\n");
            
            sale_min(&count, sale);
            printf("\n");

            printf("\n");
            continue;
        }
        else if (menu == 4) {
            printf("종료합니다.");
            break;
        }
        else {
            printf("메뉴를 입력하세요\n");
            continue;
        }
    }

    return 0;
}


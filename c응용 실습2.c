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

void sold(int* count, int* sale) {
    for (int i = 0; i < *count; i++) {
        printf("상품 id %d의 판매수량: ", i + 1);
        scanf("%d", &sale[i]);
    }
}

void stock(int* count, int* item, int* sale) {
    printf("재고수량: ");
    for (int i = 0; i < *count; i++) {
        printf("%d ", item[i] - sale[i]);
    }
}

void total_sale(int* count, int* sale, int *item) {
    int sale_sum = 0;
    int item_sum = 0;
    for (int i = 0; i < *count; i++) {
        sale_sum += sale[i];
        item_sum += item[i];
    }
    float rate = ((float)sale_sum / item_sum) * 100;
    printf("총 판매량: %d (판매율: %.2f%%)", sale_sum, rate);
}

void sale_max(int *count, int *sale) {
    int max = 0;
    for (int i = 0; i < *count; i++) {      
       if (sale[max] < sale[i]) {
                max = i;
       }   
    }
    printf("가장 많이 팔린 상품: id %d, 판매량: %d", max + 1, sale[max]);
}

void sale_min(int* count, int* sale) {
    int min = 0;
    for (int i = 0; i < *count; i++) {
        if (sale[min] > sale[i]) {
            min = i;
        }
    }
    printf("가장 적게 팔린 상품: id %d, 판매량: %d", min + 1, sale[min]);
}

void stock_warning(int *count, int *item, int *sale) {
    for (int i = 0; i < *count; i++) {
        if (item[i] - sale[i] < 3) {
            printf("상품id %d: 재고부족(%d)\n", i + 1, item[i] - sale[i]);
        }
    }

}

int main() {
    int count;
    int item[MAX] = {0};
    int sale[MAX] = {0};
   
    printf("상품 개수를 입력하세요: ");
    scanf("%d", &count);

    item_id(&count);

    printf("\n");
    items(&count, item);

    printf("\n");
    sold(&count, sale);

    printf("\n");
    stock(&count, item, sale);

    printf("\n");
    total_sale(&count, sale, item);

    printf("\n");
    sale_max(&count, sale);

    printf("\n");
    sale_min(&count, sale);
   
    printf("\n");
    stock_warning(&count, item, sale);
    
    return 0;
}


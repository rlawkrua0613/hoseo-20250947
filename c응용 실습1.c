#include <stdio.h>

int main() {
    int count;
    int item[100] = { 0 };
    int sale[100] = { 0 };
    int id;

    printf("상품 개수를 입력하세요: ");
    scanf("%d", &count);

    printf("상품들 id: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", i + 1);
    }
   
    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("상품 id %d의 입고수량: ", i + 1);
        scanf("%d", &item[i]);
    }

    printf("\n");
    
    for (int i = 0; i < count; i++) {
        printf("상품id %d의 판매수량: ", i + 1);
        scanf("%d", &sale[i]);
    }
   
    printf("\n");
   
    printf("재고량을 확인할 상품id를 입력하세요: ");
    scanf("%d", &id);
    int index = id - 1;
    printf("선택한 상품의 재고 수량: %d", item[index] - sale[index]);

    printf("\n");
    
    printf("모든 상품들의 재고 수량: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", item[i] - sale[i]);
    }
    
    return 0;
}

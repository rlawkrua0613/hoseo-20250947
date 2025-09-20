#include <stdio.h>
#define MAX 100

void item_id(int* count) {
    printf("��ǰ id: ");
    for (int i = 0; i < *count; i++) {
        printf("%d ", i + 1);
    }
}

void items(int* count, int* item) {
    for (int i = 0; i < *count; i++) {
        printf("��ǰ id %d�� �԰����: ", i + 1);
        scanf("%d", &item[i]);
    }
}

void sold(int* count, int* sale) {
    for (int i = 0; i < *count; i++) {
        printf("��ǰ id %d�� �Ǹż���: ", i + 1);
        scanf("%d", &sale[i]);
    }
}

void stock(int* count, int* item, int* sale) {
    printf("������: ");
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
    printf("�� �Ǹŷ�: %d (�Ǹ���: %.2f%%)", sale_sum, rate);
}

void sale_max(int *count, int *sale) {
    int max = 0;
    for (int i = 0; i < *count; i++) {      
       if (sale[max] < sale[i]) {
                max = i;
       }   
    }
    printf("���� ���� �ȸ� ��ǰ: id %d, �Ǹŷ�: %d", max + 1, sale[max]);
}

void sale_min(int* count, int* sale) {
    int min = 0;
    for (int i = 0; i < *count; i++) {
        if (sale[min] > sale[i]) {
            min = i;
        }
    }
    printf("���� ���� �ȸ� ��ǰ: id %d, �Ǹŷ�: %d", min + 1, sale[min]);
}

void stock_warning(int *count, int *item, int *sale) {
    for (int i = 0; i < *count; i++) {
        if (item[i] - sale[i] < 3) {
            printf("��ǰid %d: ������(%d)\n", i + 1, item[i] - sale[i]);
        }
    }

}

int main() {
    int count;
    int item[MAX] = {0};
    int sale[MAX] = {0};
   
    printf("��ǰ ������ �Է��ϼ���: ");
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


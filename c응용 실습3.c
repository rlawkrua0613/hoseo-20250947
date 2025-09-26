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

void ITEM(int* id, int* item) {
    printf("�԰��� ���� �Է��� ��ǰid�� �Է��ϼ���: ");
    scanf("%d", id);
    printf("��ǰid %d�� �԰������ �Է��ϼ���: ", *id);
    scanf("%d", &item[*id - 1]);
}

void sold(int* count, int* sale) {
    for (int i = 0; i < *count; i++) {
        printf("��ǰ id %d�� �Ǹż���: ", i + 1);
        scanf("%d", &sale[i]);
    }
}

void sold_one(int* id, int* sale) {
    printf("�Ǹŷ��� ���� �Է��� ��ǰid�� �Է��ϼ���: ");
    scanf("%d", id);
    printf("��ǰid %d�� �Ǹż����� �Է��ϼ���: ", *id);
    scanf("%d", &sale[*id - 1]);
}

void stock(int* count, int* item, int* sale) {
    printf("��ǰ�� ������: ");
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
    printf("�� �Ǹŷ�: %d (�Ǹ���: %.2f%%)", sale_sum, rate);
}

void sale_max(int* count, int* sale) {
    int max = sale[0];
    for (int i = 0; i < *count; i++) {
        if (sale[i] > max) {
            max = sale[i];
        }
    }
    printf("���� ���� �ȸ� ��ǰ: ");
    for (int i = 0; i < *count; i++) {
        if (sale[i] == max) {
            printf("id: %d ", i + 1);
        }
    }
    printf("(�Ǹŷ�: %d)", max);
}

void sale_min(int* count, int* sale) {
    int min = sale[0];
    for (int i = 0; i < *count; i++) {
        if (sale[i] < min) {
            min = sale[i];
        }
    }
    printf("���� ���� �ȸ� ��ǰ: ");
    for (int i = 0; i < *count; i++) {
        if (sale[i] == min) {
            printf("id: %d ", i + 1);
        }
    }
    printf("(�Ǹŷ�: %d)", min);
}

void stock_warning(int* count, int* item, int* sale) {
    for (int i = 0; i < *count; i++) {
        if (item[i] - sale[i] < 3) {
            printf("��ǰid %d: ������(%d)\n", i + 1, item[i] - sale[i]);
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

    printf("��ǰ ������ �Է��ϼ���: ");
    scanf("%d", &count);

    item_id(&count);
    printf("\n");

    while (1) {
        printf("���ϴ� �޴��� �����ϼ���.(1.�԰� 2.�Ǹ� 3.��ǰ��Ȳ 4.����): ");
        scanf("%d", &menu);
               
        if (menu == 1) {
            printf("���ϴ� �԰�޴��� �����ϼ���.(1.��ü ��ǰ�� �԰���� �Է� 2.�԰� ������ǰ �Է�): ");
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
                printf("�ùٸ� �޴��� �Է����ּ���. �޴�â���� ���ư��ϴ�.\n");
                continue;
            }
        }
        else if (menu == 2) {
            printf("���ϴ� �ǸŸ޴��� �����ϼ���.(1.��ü ��ǰ�� �Ǹż��� �Է� 2.�Ǹŷ� ������ǰ �Է�): ");
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
                printf("�ùٸ� �޴��� �Է����ּ���. �޴�â���� ���ư��ϴ�.\n");
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
            printf("�����մϴ�.");
            break;
        }
        else {
            printf("�޴��� �Է��ϼ���\n");
            continue;
        }
    }

    return 0;
}


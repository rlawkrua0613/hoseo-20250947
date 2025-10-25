#include <stdio.h>
#define MAX 100

typedef struct ITEMS {
    char name[MAX];
    int item;
    int price;
    int id;
    int sale;
}ITEMS;

void ITEM(int* id, ITEMS s[]) {
    while (1) {
        printf("��ǰid �Է�: ");
        scanf("%d", id);
        if (s[*id - 1].id == 0 | *id > 5) {
            printf("�������� �ʴ� id�Դϴ�.\n");
            continue;
        }
        else {
            printf("��ǰid: %d\n", s[*id - 1].id);
            printf("��ǰ��: %s\n", s[*id - 1].name);
            printf("����: %d\n", s[*id - 1].price);
            printf("����: %d\n", s[*id - 1].item - s[*id - 1].sale);
            printf("�Ǹŷ�: %d\n", s[*id - 1].sale);
            break;
        }
    }
}

void stock(int* count, ITEMS s[]) {
    printf("��ǰ�� ������: ");
    for (int i = 0; i < *count; i++) {
        printf("%d ", s[i].item - s[i].sale);
    }
}

void total_sale(int* count, ITEMS s[]) {
    int sale_sum = 0;
    int item_sum = 0;
    for (int i = 0; i < *count; i++) {
        sale_sum += s[i].sale;
        item_sum += s[i].item;
    }
    float rate = ((float)sale_sum / item_sum) * 100;
    printf("�� �Ǹŷ�: %d (�Ǹ���: %.2f%%)", sale_sum, rate);
}

void sale_max(int* count, ITEMS s[]) {
    int max = s[0].sale;
    for (int i = 0; i < *count; i++) {
        if (s[i].sale > max) {
            max = s[i].sale;
        }
    }
    printf("���� ���� �ȸ� ��ǰ: ");
    for (int i = 0; i < *count; i++) {
        if (s[i].sale == max) {
            printf("<id: %d ��ǰ��: %s> ", s[i].id, s[i].name);
        }
    }
    printf("[�Ǹŷ�: %d]", max);
}

void sale_min(int* count, ITEMS s[]) {
    int min = s[0].sale;
    for (int i = 0; i < *count; i++) {
        if (s[i].sale < min) {
            min = s[i].sale;
        }
    }
    printf("���� ���� �ȸ� ��ǰ: ");
    for (int i = 0; i < *count; i++) {
        if (s[i].sale == min) {
            printf("<id: %d ��ǰ��: %s> ", s[i].id, s[i].name);
        }
    }
    printf("[�Ǹŷ�: %d]", min);
}

void stock_warning(int* count, ITEMS s[]) {
    for (int i = 0; i < *count; i++) {
        if (s[i].item - s[i].sale < 3 && s[i].item != 0) {
            printf("��ǰid %d, ��ǰ��: %s ������(%d)\n", s[i].id, s[i].name, s[i].item - s[i].sale);
        }
    }

}

void menu1(int* id, ITEMS s[]) {
    while (1) {
        printf("\n");
        printf("��ǰ id(1 ~ 5): ");
        scanf("%d", id);
        if (*id > 5) {
            printf("��ǰ�� �ִ� ������ 5�� �Դϴ�.\n");
            continue;
        }
        else if (*id < 1) {
            printf("��ǰ�� id�� 1���� �����մϴ�.\n");
            continue;
        }
        else {
            break;
        }
    }
    s[*id - 1].id = *id;
    printf("��ǰ��: ");
    scanf("%s", &s[*id - 1].name);
    printf("��ǰ �԰�: ");
    scanf("%d", &s[*id - 1].item);
    printf("��ǰ ����: ");
    scanf("%d", &s[*id - 1].price);
}

void menu2(int* id, ITEMS s[]) {
    while (1) {
        printf("��ǰ id: ");
        scanf("%d", id);
        if (s[*id - 1].id == 0 | *id > 5) {
            printf("�������� �ʴ� id�Դϴ�.\n");
            continue;
        }
        else {
            break;
        }
    }
    printf("�Ǹż���: ");
    scanf("%d", &s[*id - 1].sale);
}

int id_count(int* count, ITEMS s[]) {
    *count = 0;
    for (int i = 0; i < 5; i++) {
        if (s[i].id != 0) {
            *count += 1;
        }
    }
    return *count;
}

int main() {
    int count;
    int menu;
    int id;
    ITEMS s[5] = { 0 };

    while (1) {
        printf("���ϴ� �޴��� �����ϼ���.(1.�԰� 2.�Ǹ� 3.������Ȳ 4.��ü��Ȳ 5.����): ");
        scanf("%d", &menu);

        if (menu == 1) {
            menu1(&id, s);
            printf("\n");
        }
        else if (menu == 2) {
            printf("\n");

            menu2(&id, s);
            printf("\n");
        }
        else if (menu == 3) {
            printf("\n");

            ITEM(&id, s);
            printf("\n");
            continue;
        }
        else if (menu == 4) {
            printf("\n");

            id_count(&count, s);

            stock(&count, s);
            printf("\n");

            stock_warning(&count, s);
            printf("\n");

            total_sale(&count, s);
            printf("\n");

            sale_max(&count, s);
            printf("\n");

            sale_min(&count, s);
            printf("\n");

            printf("\n");
            continue;
        }
        else if (menu == 5) {
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
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct ITEMS {
    char name[MAX];
    int item;
    int price;
    int id;
    int sale;
}ITEMS;

void stock(int* count, ITEMS s[]) {
    printf("상품별 재고수량: ");
    for (int i = 0; i < *count; i++) {
        printf("id%d:%d개 ", s[i].id, s[i].item - s[i].sale);
    }
}

void total_sale(int* count, ITEMS s[]) {
    int sale_sum = 0;
    int item_sum = 0;
    for (int i = 0; i < *count; i++) {
        sale_sum += s[i].sale;
        item_sum += s[i].item;
    }
    if (item_sum == 0) {
        printf("총 판매량: 0 (판매율: 0%%)");
        return;
    }
    float rate = ((float)sale_sum / item_sum) * 100;
    printf("총 판매량: %d (판매율: %.2f%%)", sale_sum, rate);
}

void sale_max(int* count, ITEMS s[]) {
    if (*count == 0) return;
    int max = s[0].sale;
    for (int i = 0; i < *count; i++) {
        if (s[i].sale > max) {
            max = s[i].sale;
        }
    }
    printf("가장 많이 팔린 상품: ");
    for (int i = 0; i < *count; i++) {
        if (s[i].sale == max) {
            printf("<id:%d 상품명:%s> ", s[i].id, s[i].name);
        }
    }
    printf("[판매량: %d]", max);
}

void sale_min(int* count, ITEMS s[]) {
    if (*count == 0) return;
    int min = s[0].sale;
    for (int i = 0; i < *count; i++) {
        if (s[i].sale < min) {
            min = s[i].sale;
        }
    }
    printf("가장 적게 팔린 상품: ");
    for (int i = 0; i < *count; i++) {
        if (s[i].sale == min) {
            printf("<id:%d 상품명:%s> ", s[i].id, s[i].name);
        }
    }
    printf("[판매량: %d]", min);
}

void stock_warning(int* count, ITEMS s[]) {
    for (int i = 0; i < *count; i++) {
        if (s[i].item - s[i].sale < 3 && s[i].item != 0) {
            printf("상품id %d, 상품명: %s 재고부족(%d)\n", s[i].id, s[i].name, s[i].item - s[i].sale);
        }
    }

}

void menu1(ITEMS **s, int *count, int *n) {
    
    if (*count >= *n) {
        *n *= 2;
        ITEMS* temp = realloc(*s, sizeof(ITEMS) * (*n));
        if (temp == NULL) {
            printf("메모리 재할당 실패\n");
            return;
        }
        *s = temp;
    }

    ITEMS* sc = &(*s)[*count];
    sc->id = *count + 1;

    printf("상품명: ");
    scanf("%s", sc->name);

    printf("상품 입고량: ");
    scanf("%d", &sc->item);

    printf("상품 가격: ");
    scanf("%d", &sc->price);

    sc->sale = 0;
    (*count)++;

}

void menu2(ITEMS s[], int count) {
    int id;
    printf("상품 id: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
      printf("존재하지 않는 id입니다.\n");
      return;
    }
        
    printf("판매수량: ");
    scanf("%d", &s[id - 1].sale);
}

void menu3(int count, ITEMS s[]) {
    int id;
    printf("상품id 입력: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("존재하지 않는 id입니다.\n");
        return;
    }

    ITEMS S = s[id - 1];

    printf("상품id: %d\n", S.id);
    printf("상품명: %s\n", S.name);
    printf("가격: %d\n", S.price);
    printf("재고량: %d\n", S.item - S.sale);
    printf("판매량: %d\n", S.sale);
    printf("총판매금액: %d\n", S.sale * S.price);
   
}

void save_items(int count, ITEMS s[]) {
    FILE* fp = fopen("items.txt", "w");
    if (fp == NULL) {
        printf("파일 저장 실패\n");
        return;
    }

    fprintf(fp, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d %d %d\n",
            s[i].id, s[i].name, s[i].item, s[i].price, s[i].sale);
    }

    fclose(fp);
    printf("상품 정보가 'items.txt' 파일에 저장되었습니다.\n");
}


void load_items(ITEMS** s, int* count, int* n) {
    FILE* fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("파일이 존재하지 않거나 열 수 없습니다.\n");
        return;
    }

    fscanf(fp, "%d", count);

    *n = *count;
    ITEMS* temp = realloc(*s, sizeof(ITEMS) * (*n));
    if (temp == NULL) {
        printf("메모리 재할당 실패\n");
        fclose(fp);
        return;
    }
    *s = temp;

    for (int i = 0; i < *count; i++) {
        fscanf(fp, "%d %s %d %d %d",
            &(*s)[i].id,
            (*s)[i].name,
            &(*s)[i].item,
            &(*s)[i].price,
            &(*s)[i].sale);
    }

    fclose(fp);
    printf("상품 정보를 파일에서 불러왔습니다.\n");
}

int main() {
    int count = 0;
    int menu;
    int n = 5;
    ITEMS *s = NULL;
    s = (ITEMS*)malloc(sizeof(ITEMS) * n);
    if (s == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    while (1) {
        printf("원하는 메뉴를 선택하세요.(1.입고 2.판매 3.개별현황 4.전체현황 5.저장 6.불러오기 7.종료): ");
        scanf("%d", &menu);

        if (menu == 1) {
            menu1(&s, &count, &n);
            printf("\n");
        }
        else if (menu == 2) {
            printf("\n");

            menu2(s, count);
            printf("\n");
        }
        else if (menu == 3) {
            printf("\n");

            menu3(count, s);
            printf("\n");
            continue;
        }
        else if (menu == 4) {
            printf("\n");

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
            save_items(count, s);
        }
        else if (menu == 6) {
            load_items(&s, &count, &n);
        }
        else if (menu == 7) {
            free(s);
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

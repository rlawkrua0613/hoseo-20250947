#include <stdio.h>

int main() {
    int count;
    int item[100] = { 0 };
    int sale[100] = { 0 };
    int id;

    printf("��ǰ ������ �Է��ϼ���: ");
    scanf("%d", &count);

    printf("��ǰ�� id: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", i + 1);
    }
   
    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("��ǰ id %d�� �԰����: ", i + 1);
        scanf("%d", &item[i]);
    }

    printf("\n");
    
    for (int i = 0; i < count; i++) {
        printf("��ǰid %d�� �Ǹż���: ", i + 1);
        scanf("%d", &sale[i]);
    }
   
    printf("\n");
   
    printf("����� Ȯ���� ��ǰid�� �Է��ϼ���: ");
    scanf("%d", &id);
    int index = id - 1;
    printf("������ ��ǰ�� ��� ����: %d", item[index] - sale[index]);

    printf("\n");
    
    printf("��� ��ǰ���� ��� ����: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", item[i] - sale[i]);
    }
    
    return 0;
}

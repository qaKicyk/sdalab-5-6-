#include <stdio.h>
#include <windows.h>
#include "data.h"

int main() {
    SetConsoleOutputCP(65001);
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Бинарное дерево поиска ---\n");
        printf("1. Добавить элемент\n");
        printf("2. Прямой обход (NLR)\n");
        printf("3. Центрированный обход (LNR)\n");
        printf("4. Обратный обход (LRN)\n");
        printf("5. Обход в ширину (BFS)\n");
        printf("6. Поиск ключа\n");
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите число: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("NLR: "); preorder(root); printf("\n");
                break;
            case 3:
                printf("LNR: "); inorder(root); printf("\n");
                break;
            case 4:
                printf("LRN: "); postorder(root); printf("\n");
                break;
            case 5:
                printf("BFS: "); bfs(root); printf("\n");
                break;
            case 6:
                printf("Искомый ключ: ");
                scanf("%d", &value);
                if (search(root, value)) printf("Найден!\n");
                else printf("Не найден.\n");
                break;
            case 0:
                freeTree(root);
                return 0;
        }
    }
}
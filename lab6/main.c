#include <stdio.h>
#include <windows.h>
#include "data.h"

int main() {
    SetConsoleOutputCP(65001);
    Node* root = NULL;
    int choice, value;
    FILE *fp;

    while (1) {
        printf("\n--- Расширенное дерево поиска ---\n");
        printf("1. Добавить\n");
        printf("2. Удалить\n");
        printf("3. Поиск ключа\n");
        printf("4. Обход NLR\n");
        printf("5. Обход LNR\n");
        printf("6. Обход LRN\n");
        printf("7. BFS\n");
        printf("8. Поиск Максимального\n");
        printf("9. Поиск минимального\n");
        printf("10. Высота дерева\n");
        printf("11. Сохранить в файл\n");
        printf("12. Загрузить из файла\n");
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите число: "); scanf("%d", &value);
                root = insert(root, value); break;
            case 2:
                printf("Удалить ключ: "); scanf("%d", &value);
                root = deleteNode(root, value); break;
            case 3:
                printf("Искомый ключ: "); scanf("%d", &value);
                if (search(root, value)) printf("Найден!\n");
                else printf("Не найден.\n"); break;
            case 4:
                printf("NLR: "); preorder(root); printf("\n"); break;
            case 5:
                printf("LNR: "); inorder(root); printf("\n"); break;
            case 6:
                printf("LRN: "); postorder(root); printf("\n"); break;
            case 7:
                printf("BFS: "); bfs(root); printf("\n"); break;
            case 8:
                if (root) 
                    printf("Максимальный: %d\n", findMax(root)->key);
                    else printf("Дерево пусто\n"); break;
            case 9:
                if (root) 
                    printf("Минимальный: %d\n", findMin(root)->key);
                    else printf("Дерево пусто\n"); break;
            case 10:
                 printf("Высота: %d\n", height(root)); break;
            case 11:
                fp = fopen("tree.txt", "w");
                if (fp) { saveToFile(root, fp); fclose(fp); printf("Сохранено.\n"); }
                break;
            case 12:
                freeTree(root);
                fp = fopen("tree.txt", "r");
                if (fp) { root = loadFromFile(fp); fclose(fp); printf("Загружено.\n"); }
                break;
            case 0:
                freeTree(root);
                return 0;
        }
    }
}
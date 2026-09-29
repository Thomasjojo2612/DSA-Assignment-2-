#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for BST node
struct Node {
    char id[20];
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(char id[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->id, id);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert an ID into BST
struct Node* insert(struct Node* root, char id[]) {
    if (root == NULL)
        return createNode(id);

    if (strcmp(id, root->id) < 0)
        root->left = insert(root->left, id);
    else if (strcmp(id, root->id) > 0)
        root->right = insert(root->right, id);

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->id);
        inorder(root->right);
    }
}

// BST search
struct Node* bstSearch(struct Node* root, char key[], int *comparisons) {
    while (root != NULL) {
        (*comparisons)++;

        int result = strcmp(key, root->id);

        if (result == 0)
            return root;
        else if (result < 0)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}

// Linear search
int linearSearch(char ids[][20], int n, char key[], int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        if (strcmp(ids[i], key) == 0)
            return i;
    }

    return -1;
}

// Calculate height of BST
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    char ids[][20] = {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    int n = 8;

    struct Node* root = NULL;

    // Construct BST
    for (int i = 0; i < n; i++) {
        root = insert(root, ids[i]);
    }

    printf("GOVERNMENT DATABASE - BST\n");
    printf("--------------------------\n");

    printf("\nIdentification Numbers:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", ids[i]);

    printf("\n\nInorder Traversal:\n");
    inorder(root);

    printf("\n\nBST Height: %d\n", height(root));

    // Selected searches
    char searchKeys[][20] = {
        "A120", "B3", "A45", "C10"
    };

    int searchCount = 4;

    printf("\nSearch Comparison:\n");
    printf("---------------------------------------------\n");
    printf("%-10s %-15s %-15s\n",
           "ID", "BST Search", "Linear Search");
    printf("---------------------------------------------\n");

    for (int i = 0; i < searchCount; i++) {

        int bstComparisons = 0;
        int linearComparisons = 0;

        struct Node* result =
            bstSearch(root, searchKeys[i], &bstComparisons);

        int linearResult =
            linearSearch(ids, n, searchKeys[i], &linearComparisons);

        printf("%-10s %-15d %-15d\n",
               searchKeys[i],
               bstComparisons,
               linearComparisons);

        if (result != NULL)
            printf("  BST Result: %s found\n", searchKeys[i]);
        else
            printf("  BST Result: %s not found\n", searchKeys[i]);

        if (linearResult != -1)
            printf("  Linear Result: %s found\n\n", searchKeys[i]);
        else
            printf("  Linear Result: %s not found\n\n", searchKeys[i]);
    }

    return 0;
}
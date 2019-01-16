#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../queue/queue.h"
#include "bst.h"


/**
 * A node contains key, item, its left and right subtrees
 */
typedef struct _Node {
    int key;
    void *item;
    int level;
    TreeType left, right;
} NodeType;

TreeType bstCreateNode(int key, void *item, int level) {
    TreeType treeNode = malloc(sizeof(NodeType));
    assert(treeNode != NULL);

    treeNode->key = key;
    treeNode->item = item;
    treeNode->level = level;
    treeNode->left = NULL;
    treeNode->right = NULL;

    return treeNode;
}


/**
 * Some useful marcos that would improve readability
 */
#define key(tree) ((tree)->key)
#define item(tree) ((tree)->item)
#define level(tree) ((tree)->level)
#define left(tree) ((tree)->left)
#define right(tree) ((tree)->right)

/**
 * Display content of root node of BST
 */
void bstDisplayRoot(NodeType *node) {
    printf("Node id:      %d\n", node->key);
    printf("Node item at: %lx\n", (long)node->item);
    printf("Node level:   %d\n", node->level);
}

/**
 * level-order traversal of BST (essentially BFS)
 */
int bstShow(TreeType tree) {
    if (tree == NULL) 
        return -1;
    
    Queue queueOfKeys = newQueue();
    enqueue(queueOfKeys, key(tree));
    int level = 0;
    while (!queueIsEmpty(queueOfKeys)) {
        int key = dequeue(queueOfKeys);
        TreeType currentTree = bstSearch(tree, key);
        if (level != level(currentTree)) {
            printf("\n");
            level = level(currentTree);
        }
        printf("%d\t", key(currentTree));
        if (left(currentTree) != NULL) 
            enqueue(queueOfKeys, key(left(currentTree)));
        if (right(currentTree) != NULL) 
            enqueue(queueOfKeys, key(right(currentTree)));
    }
    return 0;
}

/**
 * Insert node at leaf
 */
TreeType bstInsertRec(TreeType tree, int key, void *item, int level) {
    if (tree == NULL) 
        return bstCreateNode(key, item, level);
    if (key < key(tree)) 
        left(tree) = bstInsertRec(left(tree), key, item, level + 1);
    else if (key > key(tree)) 
        right(tree) = bstInsertRec(right(tree), key, item, level + 1);

    return tree; // avoid duplicate keys
}
TreeType bstInsert(TreeType tree, int key, void *item) {
    return bstInsertRec(tree, key, item, 0);
}

/**
 * Search node by key
 */
TreeType bstSearch(TreeType tree, int key) {
    if (tree == NULL) 
        return tree;
    if (key < key(tree)) 
        return bstSearch(left(tree), key);
    if (key > key(tree))
        return bstSearch(right(tree), key);
    return tree;
}
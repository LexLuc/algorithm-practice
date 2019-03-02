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
#define max(a, b) (((a)>(b))?(a):(b))

/**
 * Recursive version of an efficient algorithm 
 * to calculate base to the power of non-negative integers O(log n)
 */
unsigned int power(int b, int p) {
    if (p < 0) 
        return 0; // invalid power p
    if (p == 0) 
        return 1;

    if (p % 2 == 0) {
        unsigned int subPower = power(b, p / 2);
        return subPower * subPower;
    }
    return power(b, p-1) * 2;
}

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
void printSpace(int n) {
    for (int i = 0; i < n; i++) 
        putchar(' ');
}
void prettyPrintNode(TreeType treeNode, int numOfSpace) {
    printSpace(numOfSpace);  
    if (treeNode != NULL) 
        printf("%d", key(treeNode));
    else 
        putchar(' ');
    printSpace(numOfSpace + 1);
}
int bstShow(TreeType tree) {
    if (tree == NULL) 
        return -1;
    
    int treeHeight = bstGetHeight(tree);
    printf("Tree Height: %d\n", treeHeight);

    int numOfSpace;
    
    // display root:
    int level = level(tree);
    numOfSpace = power(2, treeHeight-level) - 1;
    printSpace(numOfSpace);
    printf("%d", key(tree));

    Queue queueOfKeys = newQueue();
    enqueue(queueOfKeys, key(tree));
    while (!queueIsEmpty(queueOfKeys)) {
        int numOfEmptyNode = 0;
        int key = dequeue(queueOfKeys);

        TreeType currentTree = bstSearch(tree, key);
        if (currentTree == NULL) {
            currentTree = bstInsert(currentTree, 0, NULL);
        }
        printf("\tlevel = %d", level);
        if (level != level(currentTree) + 1) { // next level
            putchar('\n');
            level = level(currentTree) + 1;
            numOfSpace = power(2, (treeHeight-level)) - 1;
        }

        prettyPrintNode(left(currentTree), numOfSpace);
        prettyPrintNode(right(currentTree), numOfSpace);

        if (left(currentTree) != NULL) {
            enqueue(queueOfKeys, key(left(currentTree)));
        } else {
            enqueue(queueOfKeys, -1);
            numOfEmptyNode ++;
        }
        if (right(currentTree) != NULL) {
            enqueue(queueOfKeys, key(right(currentTree)));
        } else {
            enqueue(queueOfKeys, -1);
            numOfEmptyNode ++;
        }

        if (numOfEmptyNode == power(2, level))
            break;
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
    assert(key >= 0);
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

/**
 * Get height of BST (potentially sub-BST)
 */
int bstGetHeightRec(TreeType tree) {
    int heightLeft = 0;
    int heightRight = 0;
    
    if (left(tree) == NULL && right(tree) == NULL) 
        return level(tree);

    if (left(tree) != NULL) 
        heightLeft = bstGetHeightRec(left(tree));

    if (right(tree) != NULL) 
        heightRight = bstGetHeightRec(right(tree));

    return max(heightLeft, heightRight);    
}

int bstGetHeight(TreeType tree) {
    int totalHeight = bstGetHeightRec(tree);
    int subBstHeight = totalHeight - level(tree);

    return subBstHeight;
}

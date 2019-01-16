/**
 * A tree is represented by a pointer to its root node
 */
typedef struct _Node *TreeType;

int bstShow(TreeType tree);
void bstDisplayRoot(TreeType node);
TreeType bstInsert(TreeType tree, int key, void *item);
TreeType bstSearch(TreeType tree, int key);

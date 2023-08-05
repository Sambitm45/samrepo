#include <stdio.h>
int linsearch_nonrec(int arr[], int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int linsearch_rec(int arr[], int size, int key)
{
    int i;
    if (size == 0)
        return -1;
    else if (arr[size - 1] == key)
        return size - 1;
    else
        return linsearch_rec(arr, size - 1, key);
}

int main()
{
    int array[100], search, i, n, op, pos;

    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d integer(s)\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    do
    {
        printf("\n==============MENU==============\n");
        printf("\n1.linear without recursive");
        printf("\n2.linear with recursive ");
        printf("\n3.exit");
        printf("enter your option\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter a number to search\n");
            scanf("%d", &search);
            pos = linsearch_nonrec(array, n, search);
            if (pos == -1)
            {
                printf("element not found\n");
            }
            else
            {
                printf("element position is:%d", pos);
            }
            break;
        case 2:
            printf("Enter a number to search\n");
            scanf("%d", &search);
            pos = linsearch_rec(array, n, search);
            if (pos == -1)
            {
                printf("element not found\n");
            }
            else
            {
                printf("element position is:%d", pos);
            }
            break;
        
        default:
            printf("enter valid \n");
            break;
        }
    } while (op != 3);
    return 0;
}
//############################################################################################3
/**#include <stdio.h>
int Binary_nonrec(int arr[], int lb, int ub, int key)
{
    int mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            ub = mid - 1;
        else
            lb = mid + 1;
    } // end of while loop
    return -1;
}
int Binary_rec(int arr[], int lb, int ub, int key)
{
    int mid;
    mid = (lb + ub) / 2;
    if (lb > ub)
        return -1;
    else if (arr[mid] == key)
        return mid;
    else if (key < arr[mid]) // search in lower half of the array
        return Binary_rec(arr, lb, mid - 1, key);
    else
        return Binary_rec(arr, mid + 1, ub, key); // search in upper of the array
}

int main()
{
    int p, size, arr[100], i, key;
    int lb, ub, op, pos;
    printf("Enter the size of the array\n");
    scanf("%d", &size);
    lb = 0, ub = size - 1;
    printf("Enter the elements of the array\n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("The elements in the array are :");
    for (i = 0; i < size; i++)
        printf(" %d \t", arr[i]);

    do
    {
        printf("\n==============MENU==============\n");
        printf("\n1.binary search without recursive");
        printf("\n2.binary search with recursive ");
        printf("\n3.exit");
        printf("enter your option\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("enter the element to be searched\n");
            scanf("%d", &key);
            pos = Binary_nonrec(arr, lb, ub, key);
            if (pos == -1)
            {
                printf("element not found\n");
            }
            else
            {
                printf("element position is:%d", pos);
            }
            break;
        case 2:
            printf("enter the element to be searched\n");
            scanf("%d", &key);
            pos = Binary_rec(arr, lb, ub, key);
            if (pos == -1)
            {
                printf("element not found\n");
            }
            else
            {
                printf("element position is:%d", pos);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("enter valid number\n");
            break;
        }
    } while (op != 3);
    return 0;
}
//############################################################################################
#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
    int info;
    struct bst *left, *right;
} bst;

bst *root = NULL;
bst *insert(bst *p, int item)
{
    bst *nw;
    nw = (bst *)malloc(sizeof(bst));
    nw->info = item;
    nw->left = nw->right = NULL;
    if (p == NULL)
        p = nw;
    else if (item < p->info)
        p->left = insert(p->left, item);
    else
        p->right = insert(p->right, item);
    return p;
}
void insert_nr(int item)
{
    bst *nw, *p1, *p2;
    nw = (bst *)malloc(sizeof(bst));
    nw->info = item;
    nw->left = nw->right = NULL;
    if (root == NULL)
        root = nw;
    else
    {
        for (p2 = root; p2;)
        {
            if (item < p2->info)
            {
                p1 = p2;
                p2 = p2->left;
            }
            else
            {
                p1 = p2;
                p2 = p2->right;
            }
        }
        if (item < p1->info)
            p1->left = nw;
        else
            p1->right = nw;
    }
}
int search(bst *p, int item)
{
    int l = 0;
    while (p)
    {
        if (item == p->info)
            return l;
        else if (item < p->info)
            p = p->left;
        else
            p = p->right;
        l++;
    }
    return -1;
}

void delet(int item)
{
    bst *p1, *p2, *p3;
    for (p2 = root; p2 && item != p2->info;)
    {
        if (item < p2->info)
        {
            p1 = p2;
            p2 = p2->left;
        }
        else
        {
            p1 = p2;
            p2 = p2->right;
        }
    }
    if (p2 == NULL)
    {
        printf("%d not found", item);
    }
    else if (p2->left == NULL && p2->right == NULL)
    {
        if (p2->info < p1->info)
            p1->left = NULL;
        else
            p1->right = NULL;
    }
    else if (p2->left && p2->right == NULL)
    {
        if (p2->info < p1->info)
            p1->left = p2->left;
        else
            p1->right = p2->left;
    }
    else if (p2->left == NULL && p2->right)
    {
        if (p2->info < p1->info)
            p1->left = p2->right;
        else
            p1->right = p2->right;
    }
    else
    {
        if (p2 == root)
        {
            for (p3 = p2->right; p3->left; p3 = p3->left)
                ;
            p3->left = p2->left;
            root = p2->right;
        }
        else
        {
            for (p3 = p2->right; p3->left; p3 = p3->left)
                ;
            p3->left = p2->left;
            if (p2->info < p1->info)
                p1->left = p2->right;
            else
                p1->right = p2->right;
        }
    }
    free(p2);
}
void preorder(bst *p)
{
    if (p == NULL)
        return;
    printf("%d\t", p->info);
    preorder(p->left);
    preorder(p->right);
}
void inorder(bst *p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    printf("%d\t", p->info);
    inorder(p->right);
}
void postorder(bst *p)
{
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("%d\t", p->info);
}
void print(bst *p, int l)
{
    int i;
    if (p == NULL)
        return;
    print(p->right, l + 1);
    for (i = 0; i < l; i++)
        printf("\t");
    printf("%d\n", p->info);
    print(p->left, l + 1);
}
int smallest(bst *p)
{
    if (p == NULL)
        return -1;
    else if (p->left == NULL)
        return p->info;
    else
        smallest(p->left);
}

void mirror(bst *p)
{
    bst *t;
    if (p)
    {
        mirror(p->left);
        mirror(p->right);
        t = p->left;
        p->left = p->right;
        p->right = t;
    }
}
int main()
{
    int n, i, item, l, op, s, c;
    do
    {
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.preopder");
        printf("\n4.inorder");
        printf("\n5.postorder");
        printf("\n6.search");
        printf("\nenter option \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("enter nodes to insert : ");
            scanf("%d", &item);
            insert_nr(item);
            break;
        case 2:
            printf("enter nodes to delete : ");
            scanf("%d", &item);
            delet(item);
            break;
        case 3:
            printf("\nnodes are :\n");
            preorder(root);
            break;
        case 4:
            printf("\nnodes are :\n");
            inorder(root);
            printf("\ntree is :\n");

            print(root, 0);
            break;
        case 5:
            printf("\nnodes are :\n");
            postorder(root);
            printf("mirror img is :\n");
            mirror(root);
            print(root, 0);

            break;
        case 6:
            printf("enter nodes to search : ");
            scanf("%d", &item);
            l = search(root, item);
            if (l == -1)
                printf("%d is not found", item);
            else
                printf("%d is found at level %d", item, l);
            break;
        case 7:
            exit(0);
        default:
            printf("\ninvalid option\n");
        }
    } while (op != 7);
    return 0;
}**/

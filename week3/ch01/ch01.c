#include <stdio.h>
#include <ctime>
template<typename T>
struct BinaryNode
{
    T element;
    BinaryNode<T> *left;
    BinaryNode<T> *right;

    BinaryNode(const T &theElement, BinaryNode *lt, BinaryNode *rt)
        : element(theElement), left(lt), right(rt) {}
};


template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() {
        root = nullptr;
    }
    BinarySearchTree(const BinarySearchTree& rhs) {  //复制构造函数
        root = clone(rhs.root);
    }
    ~BinarySearchTree();

    const T &findMin() const {
        return findMin(root)->element;
    }
    const T &findMax() const {
        return findMax(root)->element;
    }
    bool contains(const T& x) const;
    bool isEmpty() const {
        if (root == nullptr)
            return true;
        return false;
    }
    void printTree() const {
        printTree(root);
    }

    void makeEmpty();
    void insert(const T &x);
    void remove(const T &x);

    const BinarySearchTree& operator = (const BinarySearchTree& rhs);

private:

    BinaryNode<T> *root;                      //指向树根结点的指针

    void insert(const T & x, BinaryNode<T> * & t);
    void remove(const T & x, BinaryNode<T> * & t);
    BinaryNode<T> * findMin(BinaryNode<T> *t) const;
    BinaryNode<T> * findMax(BinaryNode<T> *t ) const;
    bool contains(const T & x, BinaryNode<T> *t) const;
    void makeEmpty( BinaryNode<T> * & t );
    void printTree( BinaryNode<T> * t ) const;
    BinaryNode<T> * clone( BinaryNode<T> * t ) const;
};

template<typename T>
bool BinarySearchTree<T>::contains(const T& x) const
{
    return contains(x, root);
}

template<typename T>
bool BinarySearchTree<T>::contains(const T & x, BinaryNode<T> *t) const
{
    if (t == nullptr)
        return false;
    else if (x < t->element)          // x 小， 说明应该在左边找
        return contains(x, t->left);
    else if (t->element < x)          // x 大， 说明应该在右面找
        return contains(x, t->right);
    else
        return true;
}

//findMin--返回指向树中包含最小元的结点的指针
template<typename T>
BinaryNode<T> * BinarySearchTree<T>::findMin(BinaryNode<T> *t) const
{
    if (t == nullptr)
        return  nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template<typename T>
BinaryNode<T>* BinarySearchTree<T>::findMax(BinaryNode<T> *t) const
{
    if (t != nullptr)
        while (t->right != nullptr) {
            t = t->right;
        }
    return t;
}

template<typename T>
void BinarySearchTree<T>::insert(const T &x)
{
    insert(x, root);
}

/************************************************************************/
/* x is the item to insert        */
/* t is the node that roots the subtree*/
/* Set the new root of the subtree*/
///* 只有当一个新树叶生成时候，t才改变.
///* t 是到p->left或p->right的引用.==> 意味着p->left或p->right将会改变为指向新结点.
/************************************************************************/
template<typename T>
void BinarySearchTree<T>::insert(const T & x, BinaryNode<T> * & t)
{
    if (t == nullptr)         //没有结点，在该位置处添加新结点
        t = new BinaryNode<T>(x, nullptr, nullptr);
    else if (x < t->element)  //x 小， 在左子树查询
        insert(x, t->left);
    else if (t->element < x)  //x 大， 在右子树查询
        insert(x, t->right);
    else;                     //Duplicate, do nothing;
}

template<typename T>
void BinarySearchTree<T>::remove(const T &x)
{
    remove(x, root);
}

///************************************************************************/
///* x is item to remove
/////* t is the node that roots the subtree
/////* Set the new root of the subtree
///* 1.结点是一片树叶时 -- 可被立即删除
///* 2.结点有一个儿子, 则该结点可以在其父节点调整他的链 以绕过该结点后被删除
///* 3.结点有两个儿子, 则其右子树的最小数据代替该结点的数据，并递归删除那个结点
///* 注: 右子树中的最小的结点不可能有左结点
///************************************************************************/
template<typename T>
void BinarySearchTree<T>::remove(const T &x, BinaryNode<T> * & t)
{
    if (t == nullptr) return;     //Item not found; do nothing
    if (x < t->element)           //x 小，在左子树递归查找
        remove(x, t->left);
    else if (t->element < x)      //x 大，在右子树递归查找
        remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr)  //two children
    {
        //在右子树中查找最小数据代替该结点数据.;
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);                    //删除该结点
    }
    else                         //只有一个结点或是树叶. 调整它的链,以绕过该结点后被删除.
    {
        BinaryNode<T> *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

/************************************************************************/
///* Destructor for the tree
/************************************************************************/
template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    makeEmpty();
}

template<typename T>
void BinarySearchTree<T>::makeEmpty()       //公有函数
{
    makeEmpty(root);
}

/************************************************************************/
///* Internal method to make subtree empty -- 私有函数
/************************************************************************/
template<typename T>
void BinarySearchTree<T>::makeEmpty(BinaryNode<T> * & t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

/************************************************************************/
///* Deep copy
/************************************************************************/
template<typename T>
const BinarySearchTree<T>& BinarySearchTree<T>::operator = (const BinarySearchTree &rhs)
{
    if (this != &rhs) {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

/************************************************************************/
///* Internal method to clone subtree.  --  递归复制结点
/************************************************************************/
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::clone(BinaryNode<T> * t) const
{
    if (t == nullptr)
        return nullptr;
    return new BinaryNode<T>( t->element, clone(t->left), clone(t->right) );
}

/************************************************************************/
///* printTree
/************************************************************************/
template<typename T>
void BinarySearchTree<T>::printTree(BinaryNode<T> * t) const
{

    if (t != nullptr) {
        printf(“%d ”,t-element);
        printTree(t->left);
        printTree(t->right);
    }
}

int main()
{
    srand((unsigned)time(nullptr));
    int testData, t = 0;
    BinarySearchTree<int> test;
    printf( "输入数字个数: \n");
    scanf("%d',t)
    printf("输入数字: \n");
    while (t--)
    {
        testData = rand() % 1000 + 1;
        test.insert(testData);
    }
    printf( "\n全部元素为: \n");
    test.printTree();
    printf( "\nMax = %d\n",  test.findMax());
    printf( "Min = %d\n", test.findMin() );
    printf( "输入查找元素: \n");
    scanf("%d", testData);
    printf( "是否包含%d : %d\n " ,testData, test.contains(testData) ;
    test.printTree();
    printf( "\n输入删除元素: \n");
scanf("%d", testData);    
test.remove(testData);
    test.printTree();
    printf("/n");
    return 0;
}

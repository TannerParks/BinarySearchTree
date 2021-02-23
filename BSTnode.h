struct BSTnode{
    int value;
    BSTnode *left;
    BSTnode *right;

    BSTnode(int new_value = 0){value=new_value; left=nullptr; right=nullptr;}   //somebody told me my create function was bad and shamed me into putting this in instead
};
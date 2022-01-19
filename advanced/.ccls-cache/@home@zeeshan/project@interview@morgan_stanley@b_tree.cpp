

void traverse(b_tree & tree)
{
    if(tree.left)
        traverse(tree.left);
    std::cout << tree.val << std::endl;
    if(tree.right)
        traverse(tree.right);
}

std::string child_dir(b_tree & root, b_tree & n)
{
    if(n.val < root.val)
    {
        if(root.left.val == n.val)
            return "left";

        return child_dir(root.left, n);
    }
    else
    {
        if(root.right.val == n.val)
            return "right";

        return child_dir(root.right, n);
    }
}

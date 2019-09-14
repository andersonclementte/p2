bt *montar(bt *bt, int item[], int left[], int right[], int i) {
  	if(i == -1) {
    	return NULL;
  	} else {
    	bt = create_binary_tree(item[i], NULL, NULL);
  	}
  	bt->left = montar(bt->left, item, left, right, left[i]);
  	bt->right = montar(bt->right, item, left, right, right[i]);
  	return bt;
}

void search(Tree* root, int target, Tree** aux)
{
    if (root == NULL) return; 
    else
    {
        if (root->item == target)
        {
            *aux = root;
            return;
        }
        search(root->left, target, &aux);
        if ((*aux) != NULL) return;
        search(root->right, target, &aux);
    }
    
}
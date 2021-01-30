	if(first==NULL){
		return NULL;
	}
	if(first->llink==first && first->data>k){
		return NULL;
	}
	NODE curr=first;
	NODE prev=first->llink;
	while(curr->rlink!=first)
	{
		if(curr->data>k){
			NODE dup=curr;
			prev->rlink=curr->rlink;
			curr->rlink->llink=prev;
			
			prev=curr->rlink;
			curr=prev->rlink;
			free(dup);
		}
		else{
			prev=curr;
			curr=curr->rlink;
		}

	}
	if(curr->data>k){
		curr->llink->rlink=first;
		first->llink=curr->llink;

	}
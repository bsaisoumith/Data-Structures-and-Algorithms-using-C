while(p != NULL)
	{
		if(p->rno == rollno)
			strcpy(name,p->name);	
		p = p->link;
		return 1;
	}
	
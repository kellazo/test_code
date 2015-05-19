tdata& operator [](const unsigned int index)
{
	long	pos;
	p2List_item<tdata>*	p_item;
	pos = 0;
	p_item = start;

	while (p_item != NULL)
	{
		if (pos == index)
		{
			break;
		}

		++pos;
		p_item = p_item->next;
	}

	ASSERT(p_item);

	return(p_item->data);
}

const tdata& operator [](const unsigned int index) const
{
	long	pos;
	p2List_item<tdata>*	p_item;
	pos = 0;
	p_item = start;

	while (p_item != NULL)
	{
		if (pos == index)
		{
			break;
		}

		++pos;
		p_item = p_item->next;
	}

	ASSERT(p_item);

	return(p_item->data);
}
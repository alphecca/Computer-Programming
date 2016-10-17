string s1 = "a string", *p = &si;
auto n = s1.size();
n = (*p).size();
n = p->size;
//ptr->mem == (*ptr).mem

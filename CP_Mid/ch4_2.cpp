//Assignment operator
int ival = 0, jval = 1;
ival = jval = 0;//ival is 0, jval is 0
(ival = jval) = 1; //ival = 1, jval =0

int i;
while ((i=get_value()) != 42){}//i has get_value()
while (i =get_value() != 42){} //i=1 if get_value()!=42 else 0

//Conditional operator
cout << ((gragde <60)? "fail" : "pass");//prints fail OR pass
cout << (grade < 60) ? "fail" : "pass";//prints 1 OR 0
cout << grade < 60 ? "fail" : "pass";//error: cannot compare stream & int

//sizeof operator
constexpr size_t sz = sizeof(ia)/sizeof(*ia);
int arr2[sz];//ok: sizeof returns constant expression

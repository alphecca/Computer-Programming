int v1, v2;
std::cin >> vi >> v2<<std::endl;
std::cin >> (v1>>v2);

//Out of evaluation
i = ++i + i++;//undefined behavior
i = i++ +1;//undefined behavior
i = ++i +1;//well defined in c++11
++ ++i;//well defined in c++11
f(++i, ++i);//undefined behavior
f(i=-1, i =-1)//undefined behavior

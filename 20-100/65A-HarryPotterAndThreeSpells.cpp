// Determines winner (Ron/Hermione) based on logical/spell power conditions.
#include <bits/stdc++.h>
int main(){

    long a,b,c,d,e,f; scanf("%ld %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e, &f);
	puts((!a && b && d) || (!c && d)|| (b * d * f > a * c * e) ? "Ron" : "Hermione");

    return 0;
}

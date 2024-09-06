#include <bits/stdc++.h>

int main(){	
    int x, y, w, h;	scanf("%d %d %d %d", &x, &y, &w, &h); 
    printf("%d", std::min(std::min(x, y), std::min(w - x, h - y)));}

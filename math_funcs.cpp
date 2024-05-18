int gcd(int a, int b) {
    int curr = 1;
    for (int i=1; i<=b; i++) {
	if (a % i == 0 && b % i == 0) {
	    curr = i;
	}
    }
    return curr;
}

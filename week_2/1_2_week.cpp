int Factorial(int n) {
	if (n <= 1) {

		return 1;	

	}
	
	int factorial = 1;

	for (int i = 1; i <= n; i++) {

		factorial *= i;	

	}

	return factorial;
}

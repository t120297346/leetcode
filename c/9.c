bool isPalindrome(int x){
    if (x < 0) {
        return 0;
    }
    
    int tmp = x;
    unsigned int sum = 0;

    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum == tmp;
}

int myAtoi(char * s){
    int res = 0;
    int index = 0;
    int negative = 0;

    while (s[index] == 32) {
        index++;
    }
    
    if (s[index] == '-') {
        negative = 1;
        index++;
    } else if (s[index] == '+') {
        index++;
    }

    while (s[index] != '\0') {
        if ((s[index] >= 48) && (s[index] <= 57)) {

            if (negative) {
                if (res < INT_MIN / 10) {
                    return INT_MIN;
                } else if (res == INT_MIN / 10) {
                    if ((s[index] - 48) > 8) {
                        return INT_MIN;
                    }
                }
                res = res * 10 + (s[index] - 48) * (-1);
            } else {
                if (res > INT_MAX / 10) {
                    return INT_MAX;
                } else if (res == INT_MAX / 10) {
                    if ((s[index] - 48) > 7) {
                        return INT_MAX;
                    }
                }
                res = res * 10 + (s[index] - 48);
            }
        } else {
            if (res != 0) {
                return res;
            } else {
                return 0;
            }
        }       
        index++;
    }

    return res;
}

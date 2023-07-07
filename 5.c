char * longestPalindrome(char * s){

    int s_len = strlen(s);

    int left = 0, tmp_l, tmp_r;
    int res_l = 0, len = 0;
    int* map = (int*)malloc(sizeof(int) * 256);
    memset(map, 0, sizeof(int) * 256);

    while(s[left] != '\0') {
        tmp_l = left - 1;
        tmp_r = left + 1;
        while (tmp_r < s_len) {
            if (s[left] != s[tmp_r]) {
                tmp_r--;
                break;
            }
            tmp_r++;
        }

        while(tmp_l >= 0) {
            if (s[left] != s[tmp_l]) {
                tmp_l++;
                break;
            }
            tmp_l--;
        }

        if (tmp_l < 0) {
            tmp_l = 0;
        }
        if (tmp_r >= s_len) {
            tmp_r = s_len - 1;
        }

        if ((tmp_r - tmp_l) == s_len) {
            return s;
        }

        while (tmp_l >= 0 && tmp_r < s_len) {
            if (s[tmp_l] != s[tmp_r]) {
                break;
            }
            tmp_l--;
            tmp_r++;
        }
        if (len < tmp_r - tmp_l - 2) {
            len = tmp_r - tmp_l - 2;
            res_l = tmp_l + 1;

            if ((len + 1) == s_len) {
                break;
            }
        }
        left++;
    }
    s += res_l;
    s[len + 1] = '\0';
    return s;
}

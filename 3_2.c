int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    int max = 0, left = -1;

    int* map = (int*) malloc(sizeof(int) * 256);
    memset(map, 0, sizeof(int) * 256);

    for (int i = 0; i < len; i++) {
        while(map[s[i]] > 0) {
            map[s[++left]]--;
        }

        if (max < i - left) {
            max = i - left;
        }

        map[s[i]]++;
    }

    return max;    
}
